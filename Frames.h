#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <sstream>

class Framerate
{
private:
	sf::Clock mcl_FPSclock;
	sf::Clock mcl_FrameTime;
	float mfl_FrameTime;
	int mi_count;
	int mi_countact;
	bool mi_shouldDraw;
	sf::Text mt_FPS;

	std::stringstream mss_ss;
	std::string ms_showFPS;
public:
	Framerate();
	~Framerate();
	/************************************************/
	/* function: countFPS     		                */
	/* description: counts the frames per seconds   */
	/*                                              */
	/* param: RenderWindow     				        */
	/* return:								        */
	/* Autor: Moritz Weichert     			        */
	/************************************************/
	void countFPS(sf::RenderWindow& win);
	/************************************************/
	/* function: showhideFPS    		            */
	/* description: show or hide the fpsdisplay     */
	/*                                              */
	/* param: RenderWindow					        */
	/* return:								        */
	/* Autor: Moritz Weichert     			        */
	/************************************************/
	void showhideFPS(sf::RenderWindow &win,sf::Event &Event);
	/************************************************/
	/* function: start/endPoint()    		        */
	/* description: stops the time between these    */
	/* 2 functions                                  */
	/* param:           					        */
	/* return:								        */
	/* Autor: Moritz Weichert     			        */
	/************************************************/
	void startPoint();
	void endPoint();
	/************************************************/
	/* function: getFrameTime   		            */
	/* description: returns the Frametime           */
	/*                                              */
	/* param: 				             	        */
	/* return: float						        */
	/* Autor: Moritz Weichert     			        */
	/************************************************/
	float getFrameTime();
	
};