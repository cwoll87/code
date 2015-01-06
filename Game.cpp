#include "Game.h"

Game::Game(void)
{
}


Game::~Game(void)
{
}

void Game::init()
{
	//create the window dd
	mwin_game.create(sf::VideoMode(800,800,32),"SFML_GAME");
	//mwin_game->setFramerateLimit(60);
	Log::write2("Window game created", (&mwin_game)? true : false);
	//load/init
	mt_tile.loadMap();

	//loadGraphics
	mt_tile.loadGraphic("Ressources/Graphic/gras.png");
	mt_tile.loadGraphic("Ressources/Graphic/brick_wall.png");
	mt_tile.loadGraphic("Ressources/Graphic/tree.png");
	mt_tile.loadGraphic("Ressources/Graphic/boden.png");
	mt_tile.loadGraphic("Ressources/Graphic/wand.png");
	mt_tile.loadGraphic("Ressources/Graphic/zellentuer.png");
	mt_tile.loadGraphic("Ressources/Graphic/kerkertuer.png");

	mpc_playcont.createPlayer(mwin_game);
	//mainloop
	GameHandle();
}

void Game::GameHandle()
{
	int waypoint = 0;
	while(mwin_game.isOpen())
	{
		//first fkt in loop
		mf_frame.startPoint();

		//logic
		mpc_playcont.playerAktion(mwin_game,mf_frame.getFrameTime(),mt_tile);
		mf_frame.countFPS(mwin_game);
	
		//Events
		me_event.EventHandle(mwin_game);

		//graphic

		//delete windowcontent
		mwin_game.clear();

		//draw
		mt_tile.drawMap(mwin_game,mpc_playcont.getPlayerPosX(),mpc_playcont.getPlayerPosY());
		mpc_playcont.drawPlayer(mwin_game);

		//display windowcontent
		mwin_game.display();	
		//last fkt in loop
		mf_frame.endPoint();
	}
}