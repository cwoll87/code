#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "../Player.h"
class Scene
{
private:
	Player mp_player;
	sf::Clock m_SceneTime;
	int m_SceneFrame;
	int waypoint;
public:
	Scene();
	~Scene();
	void Play(int SceneNumber,Player& s);
	void Begin(Player& s);
};