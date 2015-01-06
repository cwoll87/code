#include "Log.h"


Log::Log(void)
{
}


Log::~Log(void)
{
}

void Log::init()
{

}

void Log::write2(std::string text, int messageLevel)
{
	if(messageLevel == 0)
		std::cout<<"-ERROR in this message: "<<text<<std::endl;
	if(messageLevel == 1)
		std::cout<<"-"<<text<<std::endl;

	
	Log::appendToTextfile(text, messageLevel);
}

void Log::appendToTextfile(std::string text, int messageLevel)
{

}
