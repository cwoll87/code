#include "Frames.h"

Framerate::Framerate()
{
	mi_count = 0;
	mcl_FPSclock.restart();
	mi_shouldDraw = true;
	mt_FPS.setPosition(10,10);
	mt_FPS.setCharacterSize(30);
	mt_FPS.setColor(sf::Color::White);

}

Framerate::~Framerate()
{
}

void Framerate::countFPS(sf::RenderWindow &win)
{
	mt_FPS.setPosition(win.mapPixelToCoords(sf::Vector2i(10, 10)));
	if(mcl_FPSclock.getElapsedTime().asSeconds() < 1)
	{
		mi_count++;
	}
	else if(mcl_FPSclock.getElapsedTime().asSeconds() >= 1)
	{
		mi_countact = mi_count;
		mi_count = 0;
		mcl_FPSclock.restart();
	}
}

void Framerate::showhideFPS(sf::RenderWindow &win,sf::Event &Event)
{
	if(mi_shouldDraw == false)
	{
		//do nothing
	}
	else if(mi_shouldDraw == true)
	{
		mss_ss << mi_countact;
		mss_ss >> ms_showFPS;
		mt_FPS.setString(ms_showFPS);
		win.draw(mt_FPS);
		mss_ss.clear();
	}
	
}
//have to be first fkt in loop to get good times
void Framerate::startPoint()
{
	mcl_FrameTime.restart();
}
//have to be last fkt in loop to get good times
void Framerate::endPoint()
{
	mfl_FrameTime = static_cast<float>(mcl_FrameTime.getElapsedTime().asMicroseconds());
	mfl_FrameTime /= 10000;
}

float Framerate::getFrameTime()
{
	return mfl_FrameTime;
}