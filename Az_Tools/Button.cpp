#include "Button.h"


az::Button::Button(void)
{
	texture = NULL;
}

az::Button::~Button(void)
{
}

az::Button::Button(int xPos, int yPos, int width, int higth, std::string text_name, int text_size, const sf::Color &color, char* texturepath)
{

	this->but_xpos		= xPos;
	this->but_ypos		= yPos;
	this->but_width		= width;
	this->but_higth		= higth;

	int txt_right_space	= 0;
	int txt_down_space	= 0;

	//Create Text
	text =		az::Textline(text_name, text_size, but_xpos, but_ypos, color);

	int text_Width = (int)this->text.getFloatRect().width;
	int text_Height = (int)this->text.getFloatRect().height;

	//calculate text in the middle
	// for example
	// 29->
	// __________________
	// | 1            2 |
	// |---Play Game----|	by comparing on width from 1 < 2
	// |________________|
	//  ^  
	//  | 25

	//width
	for(int i = 0; i < but_width; i++)
	{
		txt_right_space = but_width - text_Width - i;
		if(i > txt_right_space) //HIT
		{
			break;
		}
	}

	//heigth
	for(int y = 0; y < but_higth; y++)
	{
		txt_down_space = but_higth - text_Height - y;
		if(y > txt_down_space) //HIT
		{
			break;
		}
	}

	//now set calcluated text pos 
	this->text.setPosition(xPos + txt_right_space, yPos + txt_down_space - (int)this->text.getFloatRect().top);

	//Create Vector Pos, Size
	this->vector2IntPos			= sf::Vector2i(this->but_xpos, this->but_ypos);
	this->vector2IntSize		= sf::Vector2i(this->but_width, this->but_higth);

	//create image
	if(texturepath != NULL)
	{
		image	=	az::Image(but_width, but_higth, (float)but_xpos, but_ypos, texturepath);
	}
	else
	{
		image		= az::Image(but_width, but_higth, (float)but_xpos, but_ypos, "");
	}
}

void az::Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{	
	target.draw(image);
	target.draw(text);
}

void az::Button::changeTexturePath(char* texturepath)
{
	this->image.changePath(texturepath);
}

void az::Button::changeTextColor(const sf::Color &color)
{
	this->text.text.setColor(color);
}

sf::Vector2i az::Button::getPos()
{
	return this->vector2IntPos;
}

sf::Vector2i az::Button::getSize()
{
	return this->vector2IntSize;
}