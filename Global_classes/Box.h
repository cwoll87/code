#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"../Az_Tools/Button.h"


#include <SFML\Graphics.hpp>

enum
{
	INFOBOX				= 0,
	MESSAGEBOX,
	EDITBOX
};

class Box
{
private:
	//Window
	sf::RenderWindow			*box_window;
	//Button
	az::Button					*newButton;
	int							buttonContainerSize;

	//var
	az::Textline				text;
	sf::Event					eventvar;
	sf::Vector2i				act_pos_mouse;

	int							button_interact_pressed;	//states are filled with the function getInteractButton; if no interacting Button = -1
	int							button_interact_released;	//states are filled with the function getInteractButton; if no interacting Button = -1
	int							button_interact_move;		//states are filled with the function getInteractButton; if no interacting Button = -1

	std::vector<az::Button*>	buttonContainer;

	//func
	int eventloopInfoBox();
	int eventloopMessageBox();
	int getInteractButton(sf::Vector2i act_pos_mouse);

public:
	Box(void);
	~Box(void);
	
	//typ 0: InfoBox; typ 1: MessageBox; typ 2: EditBox
	//return 0 = NO; 1: YES
	int create(int typ, std::string windowName, std::string handleMessage);
};