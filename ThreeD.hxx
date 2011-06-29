#ifndef ThreeD_hxx
#define ThreeD_hxx

#include <CLAM/Processing.hxx>
#include <CLAM/AudioInPort.hxx>
#include <CLAM/AudioOutPort.hxx>
#include <stdio.h>
#include <cmath>
#include <sys/time.h>
#include <bitset>
#include <iostream>
#include <fstream>
#include "MyInputDataType.hxx"
#include "MyOutputDataType.hxx"

namespace CLAM
{

class ThreeDConfig : public ProcessingConfig{

public:
	DYNAMIC_TYPE_USING_INTERFACE (ThreeDMixerConfig, 2, ProcessingConfig);
	DYN_ATTRIBUTE (0, public, int, ReceiverPositionX);
	DYN_ATTRIBUTE (1, public, int, ReceiverPositionY);

protected:	
	void DefaultInit(void){
        AddAll();
        UpdateData();
        unsigned int ReceiverPositionX = 0.0;
		unsigned int ReceiverPositionY = 0.0;
        
    }

}

class ThreeD : public CLAM::Processing{

private:
    ThreeDConfig  mConfig;
	
	AudioInPort _input;
	AudioOutPort _leftOutput;
	AudioOutPort _rightOutput;
	std::vector< FloatInControl* > mInputControls;
	std::string _name;

public:
	ThreeD(const Config& config = Config()) 
		: _input("Input", this)
		, _leftOutput("Left Output", this) 
		, _rightOutput("Right Output", this)
	{
		Configure( config );
		
/*******************************************************************/
/*-----------------------------SETUP-------------------------------*/
/*******************************************************************/
		
		CLAM::Network network;
		try
		{
			CLAM::XMLStorage::Restore(network, "/home/rahul/Project/MultiParty/emacspace/SNS5/windowing.clamnetwork");
			//CLAM::XMLStorage::Restore(network, "/home/christine/Project/sns5/windowing.clamnetwork");
			//CLAM::XMLStorage::Restore(network, argv[1]);			
		}
		catch (CLAM::XmlStorageErr & e)
		{
			return error("Could not open the network file");
		}
		
		CLAM::Processing& receiverPosition = network.GetProcessing("Receiver Position");
		CLAM::SendFloatToInControl(receiverPosition, "DefaultX", ReceiverPositionX);
		CLAM::SendFloatToInControl(receiverPosition, "DefaultY", ReceiverPositionY);
		
	}

	bool Do() //for each buffer
	{
		bool result = Do(mIn.GetData(), mOut.GetData()); 
		
		
		_input.Consume();
		return true;
	}

	
	void SetPName(char* d)
	{
		_name = d;
	}
	
	std::string getPName() {
		return _name;
	}
	
	const char* GetClassName() const
	{
		return "ThreeD";
	}

	
	

};

} //namespace

#endif

