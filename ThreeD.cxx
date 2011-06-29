#include "ThreeD.hxx"
#include <CLAM/ProcessingFactory.hxx>
static const char * metadata[] = {
	"key", "ThreeD",
	"category", "Analysis",
	0
};
	
static CLAM::FactoryRegistrator<CLAM::ProcessingFactory, CLAM::ThreeD> registrator(metadata);
