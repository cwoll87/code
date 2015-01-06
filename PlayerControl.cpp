#include "PlayerControl.h"

PlayerControl::PlayerControl()
{
	//Collision size of the player
	m_width		= 25;
	m_height	= 26;
}

PlayerControl::~PlayerControl()
{
}

void PlayerControl::createPlayer(sf::RenderWindow &win)
{
	mp_player.loadPlayer();
	mc_cam.createCam(win);
}

void PlayerControl::drawPlayer(sf::RenderWindow &win)
{
	win.draw(mp_player);
}

void PlayerControl::playerAktion(sf::RenderWindow &win,float frametime,Tilemap& t)
{
	mp_player.getFrameTime(frametime);
	//set top and left of the player
	m_top	= static_cast<int>(mp_player.getPosition().y);
	m_left	= static_cast<int>(mp_player.getPosition().x);

	if(m_sm.listen() == false)
	{
		//check if player collide
		if(t.isWalkable(m_left,m_top,m_width,m_height) == 1)
		{
			//set old position
			mp_player.SetOldPosition();
			
		}
		//move the player
		mp_player.movePlayer(win);

	}
	else if(m_sm.listen() == true)
	{
		//check if player collide
		if(t.isWalkable(m_left,m_top,m_width,m_height) == 1)
		{
			//set old position
			mp_player.SetOldPosition();
		}
		m_sm.checkScene(mp_player);
	}
	//update the cam
	mc_cam.updateCamPos(mp_player.getPosition().x,mp_player.getPosition().y,win);
}

float PlayerControl::getPlayerPosX()
{
	return mp_player.getPosition().x;
}

float PlayerControl::getPlayerPosY()
{
	return mp_player.getPosition().y;
}