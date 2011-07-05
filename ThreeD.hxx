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
	DYNAMIC_TYPE_USING_INTERFACE (SimpleConfig, 2, ProcessingConfig);
	DYN_ATTRIBUTE (0, public, int, ReceiverPositionX);
	DYN_ATTRIBUTE (1, public, int, ReceiverPositionY);

protected:	
	void DefaultInit(){

		Network network;
		XMLStorage::Restore(network, "/home/rahul/Project/MultiParty/emacspace/SNS5/impulse-response-database-surround-to-stereo.clamnetwork");
		//XMLStorage::Restore(network, "/home/christine/Project/sns5/windowing.clamnetwork");
		//XMLStorage::Restore(network, argv[1]);	

        AddAll();

        UpdateData();

		SetReceiverPositionX(0.0);
		SetReceiverPositionY(0.0);

		
        
	}

};

class ThreeD : public CLAM::Processing{

private:
	ThreeDConfig configurator;
	
	AudioInPort _input;
	AudioOutPort _output;
	std::vector< FloatInControl* > mInputControls;
	std::string _name;

public:
	ThreeD(const Config& config = Config()) 
		: _input("Input", this)
		, _output("Output", this)
	{
		Configure( configurator );
	}

	bool Do() //for each buffer
	{
	
		_input.Consume();
		_output.Produce();
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

