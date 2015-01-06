#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

#include "Global_classes\Log.h"

class Tilemap
{
private:
	
	int m_height;
	int m_width;
	int m_colwidth;
	const int mt_height;
	const int mt_width;
	std::vector <char> m_tilemap;
	std::vector<char> m_tilecollision;

	int m_right;
	int m_bottom;

	//sf::Texture mt_tilemap[10];
	//sf::Sprite ms_tilemap[10];

	std::vector<sf::Texture*> texture_tilemapList;
	std::vector<sf::Sprite> sprite_tilemapList;

public:
	Tilemap();
	~Tilemap();
	/*******************************************/
	/* function: void loadMap()				   */
	/* description: this funktion load the     */
	/* tilemap                                 */
	/*                                         */
	/* param:								   */
	/* return:								   */
	/* Autor: Moritz Weichert     			   */
	/*******************************************/
	void loadMap();
    /*******************************************/
	/* function: void loadGraphic()			   */
	/* description: this funktion load the     */
	/* graphics for the tilemap                */
	/*                                         */
	/* param:								   */
	/* return:								   */
	/* Autor: Moritz Weichert     			   */
	/*******************************************/
	void loadGraphic(std::string name);
	/*******************************************/
	/* function: void drawMap()  			   */
	/* description: this funktion draw's       */
	/* the tilemap                             */
	/*                                         */
	/* param: RenderWindow					   */
	/* return:								   */
	/* Autor: Moritz Weichert     			   */
	/*******************************************/
	void drawMap(sf::RenderWindow &win,float px, float py);
	/*************************************************/
	/* function: void isWalkable() 					 */
	/* description: this funktion check				 */
	/* if the sprite collide with something			 */
	/*												 */
	/* param: left, top, width, height of the player */
	/* return: bool									 */
	/* Autor: Moritz Weichert     					 */
	/* Modified by: Dennis Klapper					 */				
	/*************************************************/
	int isWalkable(int left, int top,int width,int height);

};