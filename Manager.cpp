#include "Manager.h"
#include<iostream>


Manager::Manager(void)
{
}

Manager::~Manager(void)
{
}

void Manager::init() 
{
	bool ret_bool;

	this->log.init();
	Log::write2("Log created", true);
	
	game_menu.init(300, 600, 32, "SFML_MEN�");
	Log::write2("Menu buttons created", true);

	ret_bool		=	game_menu.handle();				//if return 1 = Start Game; return 4 = End Game

	if(	ret_bool == true)
	{
		game.init();
		Log::write2("Game Setting created", true);
	}

	if(	ret_bool == false)
	{
		Log::write2("Exit Code 0x0", true);
	}
}