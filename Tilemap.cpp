#include "Tilemap.h"

Tilemap::Tilemap():mt_height(32),mt_width(32)
{	
}

Tilemap::~Tilemap()
{
}

void Tilemap::loadMap()
{
	//read header

	std::string header;
	std::ifstream Reader("Ressources/Map/Level1.map");
	//read first line
	getline(Reader,header);
	// convert to int
	std::stringstream ss;
	ss << header;
	ss >> m_width;
	//read second line
	getline(Reader,header);
	//convert to int
	ss.clear();
	ss << header;
	ss >> m_height;
	//read third line
	getline(Reader,header);
	//convert to int
	ss.clear();
	ss << header;
	ss >> m_colwidth;
	//read fourfth line
	for(int i = 0;i < m_colwidth;i++)
	{
		m_tilecollision.push_back(Reader.get());
	}
	//read map
	for(int y = 0;y < m_width;y++)
	{
		for(int x = 0;x < m_height;x++)
		{
			m_tilemap.push_back(Reader.get());
		}
	}
}

void Tilemap::loadGraphic(std::string name)
{
	sf::Texture *t_newTilemap = new sf::Texture;
	sf::Sprite s_newTilemap;

	if (!t_newTilemap->loadFromFile(name))
	{
		Log::write2("Could not load: " + name, 0);
		return;
	}
	else
	{
		s_newTilemap.setTexture(*t_newTilemap);

		//push
		texture_tilemapList.push_back(t_newTilemap);
		sprite_tilemapList.push_back(s_newTilemap);
	}

	//was without a param
	//load all tilemap textures
//	if (!mt_tilemap[0].loadFromFile(name))
//	{
//
//	}
//	if(!mt_tilemap[1].loadFromFile("Ressources/Graphic/brick_wall.png"))
//	{
//
//	}
//	if(!mt_tilemap[2].loadFromFile("Ressources/Graphic/tree.png"))
//	{
//
//	}
//	if(!mt_tilemap[3].loadFromFile("Ressources/Graphic/boden.png"))
//	{
//
//	}
//	if(!mt_tilemap[4].loadFromFile("Ressources/Graphic/wand.png"))
//	{
//
//	}
//	if(!mt_tilemap[5].loadFromFile("Ressources/Graphic/zellentuer.png"))
//	{
//
//	}
//	if(mt_tilemap[6].loadFromFile("Ressources/Graphic/kerkertuer.png"))
//	{
//
//	}
//	//bind all textures to sprites
//	ms_tilemap[0].setTexture(mt_tilemap[0]);
//	ms_tilemap[1].setTexture(mt_tilemap[1]);
//	ms_tilemap[2].setTexture(mt_tilemap[2]);
//	ms_tilemap[3].setTexture(mt_tilemap[3]);
//	ms_tilemap[4].setTexture(mt_tilemap[4]);
//	ms_tilemap[5].setTexture(mt_tilemap[5]);
//	ms_tilemap[6].setTexture(mt_tilemap[6]);
//
}

void Tilemap::drawMap(sf::RenderWindow &win,float px, float py)
{
	//draw the map
	for(int y = 0;y < m_height-1;y++)
	{
		for(int x = 0;x < m_width-1;x++)
		{
			if((y*mt_height <= (win.getSize().y/2 +50)+ py && x*mt_width <= (win.getSize().x/2 +50) + px) && (y*mt_height >= py - (win.getSize().y/2 + 50)  && x*mt_width >= px - (win.getSize().x/2 + 50) ))
				{
					//ms_tilemap[3].setPosition(static_cast<float>(x*mt_width),static_cast<float>(y*mt_height));
					sprite_tilemapList.at(3).setPosition(static_cast<float>(x*mt_width), static_cast<float>(y*mt_height));
					//win.draw(ms_tilemap[3]);
					win.draw(sprite_tilemapList.at(3));

					switch(m_tilemap[x+y * m_width])
					{
						case '0':
							//ms_tilemap[0].setPosition(static_cast<float>(x*mt_width),static_cast<float>(y*mt_height));
							//win.draw(ms_tilemap[0]);
							sprite_tilemapList.at(0).setPosition(static_cast<float>(x*mt_width),static_cast<float>(y*mt_height));
							win.draw(sprite_tilemapList.at(0));
							break;
						case '1':
							//ms_tilemap[1].setPosition(static_cast<float>(x*mt_width),static_cast<float>(y*mt_height));
							//win.draw(ms_tilemap[1]);
							sprite_tilemapList.at(1).setPosition(static_cast<float>(x*mt_width), static_cast<float>(y*mt_height));
							win.draw(sprite_tilemapList.at(1));
							break;
						case '2':
							//ms_tilemap[2].setPosition(static_cast<float>(x*mt_width),static_cast<float>(y*mt_height));
							//win.draw(ms_tilemap[2]);
							sprite_tilemapList.at(2).setPosition(static_cast<float>(x*mt_width), static_cast<float>(y*mt_height));
							win.draw(sprite_tilemapList.at(2));
							break;
						case '3':
							//ms_tilemap[3].setPosition(static_cast<float>(x*mt_width),static_cast<float>(y*mt_height));
							//win.draw(ms_tilemap[3]);
							sprite_tilemapList.at(3).setPosition(static_cast<float>(x*mt_width), static_cast<float>(y*mt_height));
							win.draw(sprite_tilemapList.at(3));
							break;
						case '4':
							//ms_tilemap[4].setPosition(static_cast<float>(x*mt_width),static_cast<float>(y*mt_height));
							//win.draw(ms_tilemap[4]);
							sprite_tilemapList.at(4).setPosition(static_cast<float>(x*mt_width), static_cast<float>(y*mt_height));
							win.draw(sprite_tilemapList.at(4));
							break;
						case '5':
							//ms_tilemap[5].setPosition(static_cast<float>(x*mt_width),static_cast<float>(y*mt_height));
							//win.draw(ms_tilemap[5]);
							sprite_tilemapList.at(5).setPosition(static_cast<float>(x*mt_width), static_cast<float>(y*mt_height));
							win.draw(sprite_tilemapList.at(5));
							break;
						case '6':
							//ms_tilemap[6].setPosition(static_cast<float>(x*mt_width),static_cast<float>(y*mt_height));
							//win.draw(ms_tilemap[6]);
							sprite_tilemapList.at(6).setPosition(static_cast<float>(x*mt_width), static_cast<float>(y*mt_height));
							win.draw(sprite_tilemapList.at(6));
							break;
					}
				}
			
		}
	}
}
int Tilemap::isWalkable(int left, int top,int width,int height)
{			
			//HERE IS MAX RIGHT  = 52 BLOCKS (* 32 SizeofBlock
			//HERE IS MAX BOT    = 21 BLOCKS (* 32 SizeofBlock)
			//note: Player is one Block 32x32 (Player icon INSIDE)

			m_right = (left+width)/32;	
			m_bottom = (top+height)/32;

			//check, if player is outside of the map
			if (m_right > 51 || m_bottom > 20 || left < 0 || top < 0)
				return 1;

			top /= 32;
			left /= 32;

			//check all solid tiles
			for(int i = 0;i < m_colwidth;i++)
			{
				//if corner collide with solid
				if(m_tilemap[left + top * m_width] == m_tilecollision[i] || m_tilemap[m_right + top * m_width] == m_tilecollision[i]
					|| m_tilemap[m_right + m_bottom * m_width] == m_tilecollision[i] || m_tilemap[left+ m_bottom * m_width] == m_tilecollision[i])
					return 1; //collision detected !
				else
					return 0; //no collision
			}
			return 2;
}
