#include "ThreeD.hxx"
#include <CLAM/ProcessingFactory.hxx>
static const char * metadata[] = {
	"key", "ThreeD",
	"category", "Analysis",
	0
};
	
AudioMixer::AudioMixer() : mOutputPort("Output Audio",this){
         Configure( mConfig );
}

void AudioMixer::CreatePortsAndControls(){
	unsigned portSize = BackendBufferSize();
        
    for( int i=0; i<mConfig.GetNumberOfInPorts(); i++ ){
        std::stringstream number("");
        number << i;
        AudioInPort * inPort = new AudioInPort( "Input " + number.str(), this );
        inPort->SetSize( portSize );
        inPort->SetHop( portSize );
        mInputPorts.push_back( inPort );
              
        mInputControls.push_back( new FloatInControl("Gain " + number.str(), this) );
    }
    unsigned int inPortsNumber=mConfig.GetNumberOfInPorts();
       
    mOutputPort.SetSize( portSize );
	mOutputPort.SetHop( portSize );
}

void AudioMixer::RemovePortsAndControls(){
    std::vector< AudioInPort* >::iterator itInPort;
    for(itInPort=mInputPorts.begin(); itInPort!=mInputPorts.end(); itInPort++)
        delete *itInPort;
    mInputPorts.clear();
    std::vector< FloatInControl* >::iterator itInControl;
	
    for(itInControl=mInputControls.begin(); itInControl!=mInputControls.end(); itInControl++)
		delete *itInControl;
    mInputControls.clear();
                      
    GetInPorts().Clear();
    GetInControls().Clear();
}

bool AudioMixer::ConcreteConfigure(const ProcessingConfig& c)
{
    CopyAsConcreteConfig(mConfig, c);
    RemovePortsAndControls();
    CreatePortsAndControls();
    return true;
}
 
bool AudioMixer::Do()
{
    unsigned int frameSize = BackendBufferSize(); 
    unsigned int numInPorts = mConfig.GetNumberOfInPorts();

    TData normConstant = (TData)1.0 /TData(numInPorts);
    TData * output = mOutputPort.GetAudio().GetBuffer().GetPtr();
    TData * inputs[numInPorts];
    TControlData controls[numInPorts];
    for (unsigned int i = 0; i<numInPorts; i++){
		inputs[i]=mInputPorts[i]->GetAudio().GetBuffer().GetPtr();
        controls[i]=mInputControls[i]->GetLastValue();
    }
 
    for (unsigned int sample=0; sample < frameSize; sample++) {
        TData sum=0.0;
        for (unsigned int inPort=0; inPort< numInPorts; inPort++){
            sum += inputs[inPort][sample] * controls[inPort];
        }
        output[sample] = sum * normConstant;
    }

    // execute consume/produce methods      
    or (unsigned int inPort=0; inPort<numInPorts; inPort++)
        mInputPorts[inPort]->Consume();
    mOutputPort.Produce();
       
    return true;
}
	
static CLAM::FactoryRegistrator<CLAM::ProcessingFactory, CLAM::ThreeD> registrator(metadata);