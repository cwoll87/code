#include "SceneManager.h"

SceneManager::SceneManager()
{
	m_onScene = false;
	m_Scene = 1;
}

SceneManager::~SceneManager()
{

}

bool SceneManager::listen()
{
	return m_onScene;
}

void SceneManager::checkScene(Player& s)
{
	m_sc.Play(m_Scene,s);
}