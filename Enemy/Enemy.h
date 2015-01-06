#pragma once

#include <SFML\Graphics.hpp>
#include "../Az_Tools/Image.h"
#include <iostream>
#include "../Frames.h"

class Enemy
{
private:
	sf::Sprite enemy;
	sf::Texture texture[12];
	sf::Image image;
	sf::Clock movetimer;
	int firstframe;
	float m_frametime;
public:
	Enemy();
	~Enemy();
	void Init(float posx,float posy);

	void moveTo(float x,float y);

	//Animations
	void MoveLeft();
	void MoveRight();
	void MoveTop();
	void MoveBottom();

	void getFrameTime(float ft);
	sf::Vector2f getPosition();

	
};