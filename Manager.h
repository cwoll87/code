#pragma once

#include "Menu.h"
#include "Global_classes\Log.h"
#include "Game.h"

class Manager
{
public:
	Manager(void);
	~Manager(void);

	/*******************************************/
	/* function: void init()				   */
	/* description: initialization of the	   */
	/* starting Window,LogWindow and GameWindow*/
	/* param:								   */
	/* return:								   */
	/* Autor: Dennis Klapper     			   */
	/*******************************************/
	void init();

	Menu		game_menu;		
	Log			log;
	Game		game;
};

