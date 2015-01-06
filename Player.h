#pragma once
#include <SFML\Graphics.hpp>
#include "Frames.h"
#include "Az_Tools\Image.h"
#include "Tilemap.h"

#include <iostream>
class Player : public sf::Drawable
{
private:
	float mx_pos;
	float my_pos;
	int m_tileposx;
	int m_tileposy;
	int m_gotox;
	int m_gotoy;
	float m_frametime; // actual frametime
	az::Image player;
	sf::Clock mcl_animation; //timer vor move animation 


	sf::Vector2f actPosition; //Position of this frame
	sf::Vector2f oldPosition; //Position of the last frame

	void update();
	
public:
	Player();
	~Player();
	/*******************************************/
	/* function: loadPlayer()   			   */
	/* description: this funktion load all     */
	/* data for the player                     */
	/*                                         */
	/* param:								   */
	/* return:								   */
	/* Autor: Moritz Weichert     			   */
	/*******************************************/
	void loadPlayer();
    /*******************************************/
	/* function: gets_player()    			   */
	/* description: this funktion return       */
	/* the player sprite                       */
	/*                                         */
	/* param: RenderWindow, Framerate	       */
	/* return:       						   */
	/* Autor: Moritz Weichert     			   */
	/*******************************************/
	void movePlayer(sf::RenderWindow &win);
	 /*******************************************/
	/* function: changeTexture:                 */
	/* description: this funktion changes       */	
	/* the texture for every movment            */
	/*                                          */
	/* param: 			               	        */
	/* return: 						            */
	/* Autor: Moritz Weichert     			    */
	/********************************************/
	void changeTexture(int direction);
	/********************************************/
	/* function: SetOldPosition	                */
	/* description: this funktion set the player*/	
	/* to his old position				        */
	/*                                          */
	/* param: 			               	        */
	/* return: 						            */
	/* Autor: Moritz Weichert     			    */
	/* modified by: Dennis Klapper				*/			
	/********************************************/
	void SetOldPosition();

	void moveTiles(float tx,float ty);

	void getFrameTime(float ft);

	int getTilePosX();
	int getTilePosY();
	sf::Vector2f getPosition();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	/********************************************************/
	/* function: draw										*/
	/* description: overloaded function from class drawable	*/
	/* param:												*/
	/* return:												*/
	/* Autor: Dennis Klapper     							*/
	/********************************************************/
};