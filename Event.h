#pragma once
#include <SFML\Graphics.hpp>
#include "PlayerControl.h"

class Events
{
private:
	PlayerControl m_pc;
	sf::Event m_Event;
	Framerate mf_frame;
public:
	Events();
	~Events();
	/*******************************************/
	/* function: void EventHandle() 		   */
	/* description: this funktion init the     */
	/* Eventloop                               */
	/*                                         */
	/* param: RenderWindow					   */
	/* return:								   */
	/* Autor: Moritz Weichert     			   */
	/*******************************************/
	void EventHandle(sf::RenderWindow &win);
};