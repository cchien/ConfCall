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
#include <CLAM/JACKNetworkPlayer.hxx>
#include <CLAM/XMLStorage.hxx>


namespace CLAM
{

class ThreeDConfig : public ProcessingConfig{

public:
	DYNAMIC_TYPE_USING_INTERFACE (ThreeDConfig, 2, ProcessingConfig);
	DYN_ATTRIBUTE (0, public, float, ReceiverPositionX);
	DYN_ATTRIBUTE (1, public, float, ReceiverPositionY);

protected:	
	void DefaultInit(){

		Network network;
		XMLStorage::Restore(network, "/home/rahul/Project/MultiParty/emacspace/SNS5/impulse-response-database-surround-to-stereo.clamnetwork");
		//XMLStorage::Restore(network, "/home/christine/Project/sns5/windowing.clamnetwork");
		//XMLStorage::Restore(network, argv[1]);

		network.start();	

	        AddAll();

	        UpdateData();

		SetReceiverPositionX(0.0);
		SetReceiverPositionY(0.0);

		
        
	}

};

class ThreeD : public Processing{

private:
	typedef ThreeDConfig Config;
	
	AudioInPort mIn;
	AudioOutPort mOut;
	std::vector< FloatInControl* > mInputControls;
	std::string _name;

public:
	ThreeD(const Config& config = Config()) 
		: mIn("Input", this)
		, mOut("Output", this)
	{
		Configure( config );
	}

	const CLAM::ProcessingConfig & GetConfig() const{
		return mConfig;
	}

	bool Do() //for each buffer
	{
		mIn.Consume();
		mOut.Produce();
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

protected:
	bool ConcreteConfigure(const CLAM::ProcessingConfig & config){
		CopyAsConcreteConfig(mConfig, config);
		return true;
	}

private:
	Config mConfig;

};

} //namespace

#endif

