#include "Enemy.h"

Enemy::Enemy()
{
	m_frametime = 0;
	firstframe = 0;
}

Enemy::~Enemy()
{
	//Here ist a changed ROW
}

void Enemy::Init(float posx,float posy)
{
	if(!image.loadFromFile("Data/Graphic/wache.png"))
	{
		std::cout << "Error" << std::endl;
	}
	//cut image into several textures
	int count = 0;
	for(int i = 0;i < 4;i++)
	{
		for(int j = 0;j < 3;j++)
		{
			for(int k = 0;k < 1;k++)
			{
				texture[count].loadFromImage(image,sf::IntRect(0+24*j,0+31*i,24,31));
				count++;
			}
		}
	}
	enemy.setPosition(posx,posy);	
	std::cout << enemy.getPosition().x << " " << enemy.getPosition().y;
}

void Enemy::moveTo(float x,float y)
{
	if(firstframe == 1)
	{
		std::cout << enemy.getPosition().x << " " << enemy.getPosition().y;
		if(static_cast<int>(enemy.getPosition().x) > x && m_frametime >= 0  && m_frametime <= 1)
		{
			enemy.move(-1*m_frametime,0);
			MoveLeft();
		}
		else if(static_cast<int>(enemy.getPosition().x) < x && m_frametime >= 0  && m_frametime <= 1)
		{
			enemy.move(1*m_frametime,0);
			MoveRight();
		}
		else if(static_cast<int>(enemy.getPosition().y) > y && m_frametime >= 0  && m_frametime <= 1)
		{
			enemy.move(0,-1*m_frametime);
			MoveTop();
		}
		else if(static_cast<int>(enemy.getPosition().y) < y && m_frametime >= 0  && m_frametime <= 1)
		{
			enemy.move(0,1*m_frametime);
			MoveBottom();
		}
	}
	else
		firstframe++;
}

void Enemy::MoveLeft()
{
	if(movetimer.getElapsedTime().asSeconds() >= 0.3)
	{
		movetimer.restart();
	}
	else if(movetimer.getElapsedTime().asSeconds() >= 0 && movetimer.getElapsedTime().asSeconds() <= 0.1)
	{
		enemy.setTexture(texture[9]);
	}
	else if(movetimer.getElapsedTime().asSeconds() >= 0.1 && movetimer.getElapsedTime().asSeconds() <= 0.2)
	{
		enemy.setTexture(texture[10]);
	}
	else if(movetimer.getElapsedTime().asSeconds() >= 0.2 && movetimer.getElapsedTime().asSeconds() <=0.3)
	{
		enemy.setTexture(texture[11]);
	}
	
}

void Enemy::MoveRight()
{
	if(movetimer.getElapsedTime().asSeconds() >= 0.3)
	{
		movetimer.restart();
	}
	else if(movetimer.getElapsedTime().asSeconds() >= 0 && movetimer.getElapsedTime().asSeconds() <= 0.1)
	{
		enemy.setTexture(texture[3]);
	}
	else if(movetimer.getElapsedTime().asSeconds() >= 0.1 && movetimer.getElapsedTime().asSeconds() <= 0.2)
	{
		enemy.setTexture(texture[4]);
	}
	else if(movetimer.getElapsedTime().asSeconds() >= 0.2 && movetimer.getElapsedTime().asSeconds() <=0.3)
	{
		enemy.setTexture(texture[5]);
	}
}

void Enemy::MoveTop()
{
	if(movetimer.getElapsedTime().asSeconds() >= 0.3)
	{
		movetimer.restart();
	}
	else if(movetimer.getElapsedTime().asSeconds() >= 0 && movetimer.getElapsedTime().asSeconds() <= 0.1)
	{
		enemy.setTexture(texture[0]);
	}
	else if(movetimer.getElapsedTime().asSeconds() >= 0.1 && movetimer.getElapsedTime().asSeconds() <= 0.2)
	{
		enemy.setTexture(texture[1]);
	}
	else if(movetimer.getElapsedTime().asSeconds() >= 0.2 && movetimer.getElapsedTime().asSeconds() <=0.3)
	{
		enemy.setTexture(texture[2]);
	}
}

void Enemy::MoveBottom()
{
	if(movetimer.getElapsedTime().asSeconds() >= 0.3)
	{
		movetimer.restart();
	}
	else if(movetimer.getElapsedTime().asSeconds() >= 0 && movetimer.getElapsedTime().asSeconds() <= 0.1)
	{
		enemy.setTexture(texture[6]);
	}
	else if(movetimer.getElapsedTime().asSeconds() >= 0.1 && movetimer.getElapsedTime().asSeconds() <= 0.2)
	{
		enemy.setTexture(texture[7]);
	}
	else if(movetimer.getElapsedTime().asSeconds() >= 0.2 && movetimer.getElapsedTime().asSeconds() <=0.3)
	{
		enemy.setTexture(texture[8]);
	}
}

sf::Vector2f Enemy::getPosition()
{
  sf::Vector2f position(enemy.getPosition().x,enemy.getPosition().y);
  return position;
}

void Enemy::getFrameTime(float ft)
{
	m_frametime = ft;
}

