#pragma once

#include "SFML\Graphics.hpp"

namespace az
{
	class Textline : public sf::Drawable
	{	
	public:
		sf::Text text;
		std::string stringName;
		sf::Font *font;

		Textline(void);
		Textline(std::string name, int size, int xpos, int ypos, const sf::Color &color);
		~Textline(void);

		std::string getString()const;
		void setString(std::string temp);
		void setColor(sf::Color color);
		sf::FloatRect getFloatRect();
		void setPosition(int x, int y);

		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	};
}
 
