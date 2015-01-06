#include "Textline.h"


az::Textline::Textline(void)
{

}

az::Textline::Textline(std::string name, int size, int xpos, int ypos, const sf::Color &color)
{
	//Font standart
	font = new sf::Font();

	font->loadFromFile("Ressources/arial.ttf");
	text.setFont(*font);

	//// Create a text	
	text.setString(name);
	text.setPosition(static_cast<float>(xpos), static_cast<float>(ypos));
	text.setCharacterSize(size);
	text.setStyle(sf::Text::Bold);
	text.setColor(color);

}

az::Textline::~Textline(void)
{  
}

void az::Textline::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(text);
}

std::string az::Textline::getString() const
{
	return text.getString();
}

void az::Textline::setString(std::string temp)
{
	this->text.setString(temp);
}

void az::Textline::setColor(sf::Color color)
{
	this->text.setColor(color);
}

void az::Textline::setPosition(int x, int y)
{
	text.setPosition((float)x, (float)y);
}
 
sf::FloatRect az::Textline::getFloatRect()
{
	return this->text.getLocalBounds();
}