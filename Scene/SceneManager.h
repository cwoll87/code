#pragma once
#include <SFML\Graphics.hpp>
#include "Scene.h"
#include <iostream>

class SceneManager
{
private:
	bool m_onScene;
	Scene m_sc;
	//Scene's
	int m_Scene;
public:	
	SceneManager();
	~SceneManager();
	bool listen();
	void checkScene(Player& s);
	
};