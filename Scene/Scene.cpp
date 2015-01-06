#include "Scene.h"

Scene::Scene()
{
	m_SceneFrame = 0;
	waypoint = 0;
}

Scene::~Scene()
{

}

void Scene::Play(int SceneNumber,Player& s)
{
	if(SceneNumber == 1)
	{
		Begin(s);
	}
}

/***** Scene's ******/

void Scene::Begin(Player& s)
{	if(m_SceneFrame == 0)
	{
		m_SceneTime.restart();
		m_SceneFrame++;
	}
	else if(m_SceneTime.getElapsedTime().asSeconds() >= 1 && waypoint == 0)
		s.moveTiles(400,65);

	if(s.getTilePosX() == 400 && s.getTilePosY() == 65)
		waypoint = 1;

	if(waypoint == 1)
		s.moveTiles(2185,256);
}