#pragma once

#include <SFML/Graphics.hpp>
#include "Event.h"
#include "Global_classes\Log.h"

//Test

class Game
{
private:
	Events me_event;
	PlayerControl mpc_playcont;
	Tilemap mt_tile;
	Framerate mf_frame;
	SceneManager m_sm;
	

	sf::RenderWindow mwin_game;
public:
	Game(void);
	~Game(void);
	/*******************************************/
	/* function: void init()      			   */
	/* description: this funktion init the     */
	/* window and the mainloop                 */
	/*                                         */
	/* param:								   */
	/* return:								   */
	/* Autor: Moritz Weichert     			   */
	/*******************************************/
	void init();
	/*******************************************/
	/* function: GameHandle()    			   */
	/* description: this funktion contains     */
	/* the mainloop                            */
	/*                                         */
	/* param:								   */
	/* return:								   */
	/* Autor: Moritz Weichert     			   */
	/*******************************************/
	void GameHandle();

};
