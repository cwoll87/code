#include "Event.h"

Events::Events()
{
}

Events::~Events()
{
}

void Events::EventHandle(sf::RenderWindow &win)
{
	while(win.pollEvent(m_Event))
	{
		if(m_Event.type == m_Event.Closed)
			win.close();
		mf_frame.showhideFPS(win,m_Event);
	}
}