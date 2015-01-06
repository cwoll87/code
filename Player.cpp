#include "Player.h"

/****** private *******/

void Player::update()
{
	oldPosition.x = player.getPosX();
	oldPosition.y = player.getPosY();
}
/******* public *******/
Player::Player()
{
	player = az::Image();
}

Player::~Player()
{
}

void Player::loadPlayer()
{
	//load sprit img
	player.loadImage("Ressources/Graphic/Player.png");

	//cut image into several textures
	player.TexturesLoadFromImage(3,4,20,27);
	//create player sprite
	player.SetTexture(1);
	player.SetPosition(32,32);
}

void Player::movePlayer(sf::RenderWindow &win)
{

	//move top
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		update();
		player.move(0,-4*m_frametime);
		changeTexture(0);
	}
	//move bottom
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		update();
		player.move(0,4*m_frametime);
		changeTexture(1);
	}
	//move left
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		update();
		player.move(-4*m_frametime,0);
		changeTexture(2);
	}
	//move right
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		update();
		player.move(4*m_frametime,0);
		changeTexture(3);
	}
	
}

void Player::changeTexture(int direction)
{

	if (mcl_animation.getElapsedTime().asSeconds() >= 0.3)
	{
		mcl_animation.restart();
	}
	if (mcl_animation.getElapsedTime().asSeconds() >= 0 && mcl_animation.getElapsedTime().asSeconds() <= 0.1)
	{
		if (direction == 0)
			player.SetTexture(6);
		else
			if (direction == 1)
				player.SetTexture(0);
			else
				if (direction == 2)
					player.SetTexture(3);
				else
					if (direction == 3)
						player.SetTexture(9);
	}
	if (mcl_animation.getElapsedTime().asSeconds() >= 0.1 && mcl_animation.getElapsedTime().asSeconds() <= 0.2)
	{
		if (direction == 0)
			player.SetTexture(7);
		if (direction == 1)
			player.SetTexture(1);
		else
			if (direction == 2)
				player.SetTexture(4);
			else
				if (direction == 3)
					player.SetTexture(10);
	}
	if (mcl_animation.getElapsedTime().asSeconds() >= 0.2 && mcl_animation.getElapsedTime().asSeconds() <= 0.3)
	{
		if (direction == 0)
			player.SetTexture(8);
		if (direction == 1)
			player.SetTexture(2);
		else
			if (direction == 2)
				player.SetTexture(5);
			else
				if (direction == 3)
					player.SetTexture(11);
	}
}

void Player::SetOldPosition()
{
	player.SetPosition(oldPosition.x,oldPosition.y);
}

void Player::moveTiles(float tx,float ty)
{
	m_gotox = static_cast<int>(m_tileposx + tx);
	m_gotoy = static_cast<int>(m_tileposy + ty);

	//right
	if(m_tileposx < tx)
	{
		update();
		changeTexture(0);
	}
	//bottom
	else if(m_tileposy < ty)
	{
		update();
		changeTexture(1);
	}
	//left
	else if(m_tileposx > tx)
	{
		update();
		changeTexture(2);
	}
	//top
	else if(m_tileposy > ty)
	{
		update();
		changeTexture(3);
	}
	

}

void Player::getFrameTime(float ft)
{
	m_frametime = ft;
}

int Player::getTilePosX()
{
	return m_tileposx;
}

int Player::getTilePosY()
{
	return m_tileposy;
}

sf::Vector2f Player::getPosition()
{
	actPosition.x = player.getPosX();
	actPosition.y = player.getPosY();

	return actPosition;
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states)const
{
	target.draw(player);
}