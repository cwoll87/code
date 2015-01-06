#include "Image.h"
#include <iostream>

az::Image::Image(void)
{
	this->texture = new sf::Texture;
	//texture->create(50, 40);
}

az::Image::Image(int width, int high, float xPos, int yPos, std::string pathname)
{
	this->texture = new sf::Texture;

	if(pathname != "")
	{
		if (!texture->loadFromFile(pathname))
			std::cout << "Could not load " << pathname << std::endl;
	}
	else
		texture->create(width, high);

	sprite.setPosition((float)xPos,(float) yPos);
	sprite.setTexture(*texture);
}

az::Image::~Image(void)
{
}

void az::Image::changePath(char* texturpath)
{
	texture->loadFromFile(texturpath);
	this->sprite.setTexture(*texture);
}


void az::Image::changePosition(int x, int y)
{
	sprite.setPosition(this->getPosX() + x, this->getPosY() + y);
}

void az::Image::loadImage(char* texturepath)
{
	if(!image.loadFromFile(texturepath))
	{
		std::cout << "Could not load " << texturepath << std::endl;
	}
}

void az::Image::SetPosition(float x,float y)
{
	sprite.setPosition(x,y);
}

void az::Image::TexturesLoadFromImage(int count_x,int count_y,int width,int height)
{
	int count = 0;
	sf::Texture temptext;
	for(int i = 0;i < count_y;i++)
	{
		for(int j = 0;j < count_x;j++)
		{
			for(int k = 0;k < 1;k++)
			{
				temptext.loadFromImage(image,sf::IntRect(j*width,i*height,width,height));
				texturelist.push_back(temptext);
			}
		}
	}
}

void az::Image::move(float x,float y)
{
	sprite.move(x,y);
}

void az::Image::SetTexture(int pos)
{
	sprite.setTexture(texturelist[pos]);
}

void az::Image::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
		target.draw(sprite);
}

float az::Image::getPosX()
{
	return this->sprite.getPosition().x;
}

float az::Image::getPosY()
{
	return this->sprite.getPosition().y;
}




