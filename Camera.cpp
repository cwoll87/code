#include "Camera.h"

Camera::Camera()
{
}

Camera::~Camera()
{
}

void Camera::createCam(sf::RenderWindow &win)
{
	m_PCam.setSize(800,800);
	m_PCam.setCenter(100,100);
	win.setView(m_PCam);
}
void Camera::updateCamPos(float pos_x,float pos_y,sf::RenderWindow &win)
{
	m_PCam.setCenter(pos_x,pos_y);
	win.setView(m_PCam);
}
