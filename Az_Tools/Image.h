#pragma once
 
#include "SFML\Graphics.hpp"
#include <vector>

namespace az
{
	class Image : public sf::Drawable
	{
	private:
		sf::Sprite			sprite;
		sf::Texture			*texture;
		sf::Image           image;
		std::vector<sf::Texture> texturelist; 
	public:
		Image(void);

		Image(int width, int high, float xPos, int yPos, std::string pathname = NULL);
		/********************************************************/
		/* function: Image										*/
		/* description: create a image without texture			*/
		/* needed if you want to create a button without a		*/
		/* texture temporary									*/
		/* Autor: Dennis Klapper     							*/
		/********************************************************/
		~Image(void);

		void changePath(char* texturpath);
		/********************************************************/
		/* function: changePath									*/
		/* description: change or set an texturepath			*/
		/* param: texturpath* new texturepath					*/
		/* Autor: Dennis Klapper     							*/
		/********************************************************/

		void changePosition(int x, int y);
		/********************************************************/
		/* function: changePosition								*/
		/* description: change the pos on main window			*/
		/* param: x, y											*/
		/* Autor: Dennis Klapper     							*/
		/********************************************************/

		void SetPosition(float x,float y);
		/********************************************************/
		/* function: SetPosition								*/
		/* description: set the position of the sprite			*/
		/* param: x, y											*/
		/* Autor: Moritz Weichert     							*/
		/********************************************************/
		void loadImage(char* imagepath);
		/********************************************************/
		/* function: loadImage   								*/
		/* description: load an image               			*/
		/* param: imagepath										*/
		/* Autor: Moritz Weichert     							*/
		/********************************************************/

		void TexturesLoadFromImage(int count_x,int count_y, int width,int height);
		/********************************************************/
		/* function: TexturesLoadFromImage						*/
		/* description: create textures out of an image			*/
		/* param: count_x,count_y, width, height        		*/
		/* Autor: Moritz Weichert     							*/
		/********************************************************/
		
		void SetTexture(int pos);
		/********************************************************/
		/* function: SetTexture									*/
		/* description: set a texture to the sprite 			*/
		/* param: texture							      		*/
		/* Autor: Moritz Weichert     							*/
		/********************************************************/

		void move(float x,float y);
		/********************************************************/
		/* function: move										*/
		/* description: move the sprite				 			*/
		/* param: x, y								      		*/
		/* Autor: Moritz Weichert     							*/
		/********************************************************/

		float getPosX();
		float getPosY();

		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		/********************************************************/
		/* function: draw										*/
		/* description: overloaded function from class drawable	*/
		/* param:												*/
		/* return:												*/
		/* Autor: Dennis Klapper     							*/
		/********************************************************/
	};
}

