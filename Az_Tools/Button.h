#pragma once
#include "Textline.h"
#include "Image.h"
#include <iostream>

namespace az
{
	class Button : public sf::Drawable
	{
	private:
		int but_width;
		int but_higth;
		int but_ypos;
		int but_xpos;

		az::Textline		text;					//Text
		az::Image			image;					//Image

		sf::Vector2i		vector2IntPos;			//x and y Pos	
		sf::Vector2i		vector2IntSize;			//size

		sf::IntRect			rectangle;
		sf::Sprite			sprite;
		sf::Texture			*texture;

	public:
		Button(void);

		Button(int xPos, int yPos, int width, int higth, std::string text_name, int text_size, const sf::Color &color, char* texturepath);
		/********************************************************/
		/* function: draw										*/
		/* description: create a button with texture			*/
		/* Autor: Dennis Klapper     							*/
		/********************************************************/

		~Button(void);

		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		/********************************************************/
		/* function: draw										*/
		/* description: overloaded function from class drawable	*/
		/* param:												*/
		/* return:												*/
		/* Autor: Dennis Klapper     							*/
		/********************************************************/

		void changeTexturePath(char* texturpath);
		/********************************************************/
		/* function: changeTexturePath							*/
		/* description: overloaded function from class drawable	*/
		/* param: char* for the texturpath of the new picture	*/
		/* Autor: Dennis Klapper     							*/
		/********************************************************/

		void changeTextColor(const sf::Color &color);
		/********************************************************/
		/* function: changeTextColor							*/
		/* description: change the textcolor					*/
		/* param: sf::Color the new Color						*/
		/* Autor: Dennis Klapper     							*/
		/********************************************************/

		sf::Vector2i getPos();
		/********************************************************/
		/* function: getPos										*/
		/* description:											*/
		/* param: sf::Vector2i gets the Pos						*/
		/* Autor: Dennis Klapper     							*/
		/********************************************************/

		sf::Vector2i getSize();
		/********************************************************/
		/* function: getSize									*/
		/* description:											*/
		/* param: sf::Vector2i gets the Size					*/
		/* Autor: Dennis Klapper     							*/
		/********************************************************/
	};
}

