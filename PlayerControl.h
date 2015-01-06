#pragma once
#include <SFML\Graphics.hpp>

#include "Camera.h"
#include "Scene\SceneManager.h"


class PlayerControl
{
private:
	Player mp_player;
	Camera mc_cam;
	Tilemap mt_tile;
	SceneManager m_sm;
	int m_top;
	int m_left;
	int m_width;
	int m_height;
public:
	PlayerControl();
	~PlayerControl();
	/*******************************************/
	/* function: createPlayer    			   */
	/* description: this funktion creates      */
	/* the player                              */
	/*                                         */
	/* param: RenderWindow					   */
	/* return:								   */
	/* Autor: Moritz Weichert     			   */
	/*******************************************/
	void createPlayer(sf::RenderWindow &win);
	/*******************************************/
	/* function: drawPlayer      			   */
	/* description: this funktion draws the    */
	/* player                                  */
	/*                                         */
	/* param: RenderWindow					   */
	/* return:              				   */
	/* Autor: Moritz Weichert     			   */
	/*******************************************/
	void drawPlayer(sf::RenderWindow &win);
	/************************************************/
	/* function: playerAktion     		            */
	/* description: handels the loop for all the    */
	/* player aktions                               */
	/* param: RenderWindow, Framerate, Tilemap		*/
	/* return:								        */
	/* Autor: Moritz Weichert     			        */
	/************************************************/
	void playerAktion(sf::RenderWindow &win,float frametime,Tilemap& t);


	float getPlayerPosX();
	float getPlayerPosY();
};