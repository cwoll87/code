#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
class Camera
{
private:
	sf::View m_PCam;
	int posX;
	int posY;
public:
	Camera();
	~Camera();
	/************************************************/
	/* function: createCam     		                */
	/* description: create the camera for the game  */
	/*                                              */
	/* param: RenderWindow					        */
	/* return:								        */
	/* Autor: Moritz Weichert     			        */
	/************************************************/
	void createCam(sf::RenderWindow &win);
	
	void updateCamPos(float pos_x,float pos_y,sf::RenderWindow &win);
	/************************************************/
	/* function: updateCamPos  		                */
	/* description: update the camera position      */
	/*                                              */
	/* param: x, y, RenderWindow			        */
	/* return:								        */
	/* Autor: Moritz Weichert     			        */
	/************************************************/
};
