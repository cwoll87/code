

#include<SFML\Graphics.hpp>

#include <vector>
#include <fstream>
#include "Global_classes\Log.h"
#include "Global_classes\Box.h"
#include "Az_Tools\Button.h"
#include "SFML\Audio.hpp"


class Menu
{
private:
	//GLOBAL
	sf::RenderWindow			*win_gameMenu;				//Main Men� Window
	sf::Event					my_event;					//eventLoop for main

	Box							box;						//boxes (Message, Info ....)
	bool						presentationVar;			//needed to different if the new info is read already

	std::vector<az::Button*>	buttonContainer;			//One Container for ALL Button Elements; 1-4 MAIN BUTTONS; 5-8 OPTION BUTTONS
	std::ofstream				writeFile;
	std::ifstream				readFile;

	unsigned int				mode;						//important for switching userinterface

	az::Textline				headlineText;				//headline for Options & Credits; Main is disabled
	az::Textline				version;

	sf::Vector2i				*pos;						//Global Pointer to actual coords
	sf::Vector2i				*size;						//Global Pointer to actual size

	sf::Vector2i				act_pos_mouse;				//actual position of the mouse

	unsigned int				min;						//needed for modes by directing in the buttonContainer 0-4 Main; 4-12 Option; 4-5 Credits
	unsigned int				max;						//needed for modes by directing in the buttonContainer 0-4 Main; 4-12 Option; 4-5 Credits

	int							button_interact_pressed;	//states are filled with the function getInteractButton; if no interacting Button = -1
	int							button_interact_released;	//states are filled with the function getInteractButton; if no interacting Button = -1
	int							button_interact_move;		//states are filled with the function getInteractButton; if no interacting Button = -1

	sf::Music					MusicMeue;					//MenueMusic
	sf::SoundBuffer				MenueSoundTest;
	sf::Sound					sound_test;

	//MAIN
	az::Image					mainLogo;					//Logo
	az::Image					mainBackground;
	az::Image					chain[2];					//Chain
	sf::Vector2i				position_main[4];			//Coordinates for Buttons in buttonContainer
	sf::Vector2i				size_main[4];				//Size for Buttons in buttonContainer

	//OPTIONS
	az::Image					optionBackground;
	az::Image					optionSoundSysImg[4];						
	//az::Textline				optionSoundSysTl[8];		//SoundSystem textlines 2x2 (2xheadline, 2xpercent view) 2x (1xON; 1xOFF) Difficult 2x2
	//vector erstellen
	std::vector<az::Textline>textlineVector;

	float						optionSoundSysTlVal[2]; 

	int							bloodState;
	int							DifficultState;	
	int							movementpoint;				//needed for Options to move the circle in music options
	bool						changedSettings;			//Needed for BackToMain, to difference if something was changed or not

	std::string					optionDifficultState[3];	//Difficult
	sf::Color					optionDifficultColor[3];	//Difficult Color

	sf::Vector2i				position_opt[8];			//Coordinates for Buttons in buttonContainer	OPTION ELEMENTS
	sf::Vector2i				size_opt[8];				//Size for Buttons in buttonContainer			OPTION ELEMENTS
		
	sf::Vector2i				position_cre[1];			//Coordinates for Buttons in buttonContainer	CREDITS ELEMENTS
	sf::Vector2i				size_cre[1];				//Size for Buttons in buttonContainer			CREDITS ELEMENTS

public:
	Menu(void);
	~Menu(void);

	void init(int width, int high, int bit, std::string name);
	/*******************************************/
	/* function: void init()				   */
	/* description: render a Window    		   */
	/* param: width, high, bit, name		   */
	/* return:								   */
	/* Autor: Dennis Klapper     			   */
	/*******************************************/
		
	void createButton(std::string name, int size, int xpos, int ypos, int typ, char* texturepath = "");
	/*******************************************/
	/* function: void createButton()		   */
	/* description: creating a button and push */
	/* it into the buttonContainer			   */
	/* param: s.t.							   */
	/* typ: 1. with texture; 2.without texture */
	/* and little rect; 3. same as 2 with big  */
	/* rect									   */
	/* Autor: Dennis Klapper     			   */
	/*******************************************/

	void initMainElements();
	/********************************************/
	/* function: initMainElements				*/
	/* description: change the Pointer to Main	*/
	/* pos and size								*/
	/* Autor: Dennis Klapper     				*/
	/********************************************/

	void initOptionElements();
	/********************************************/
	/* function: initOptionElements				*/
	/* description: change the Pointer to Option*/
	/* pos and size								*/
	/* Autor: Dennis Klapper     				*/
	/********************************************/

	void initCreditElements();
	/********************************************/
	/* function: initCreditElements				*/
	/* description: change the Pointer to Credit*/
	/* pos and size								*/
	/* Autor: Dennis Klapper     				*/
	/********************************************/

	void changeToMain();
	/********************************************/
	/* function: changeToMain					*/
	/* description: change ui and set mainmenu	*/
	/* Autor: Dennis Klapper     				*/
	/********************************************/

	void changeToOptions();
	/********************************************/
	/* function: changeToOptions				*/
	/* description: change ui and set optionmenu*/
	/* Autor: Dennis Klapper     				*/
	/********************************************/

	void changeToCredits();
	/********************************************/
	/* function: changeToCredits				*/
	/* description: change ui and set creditmenu*/
	/* Autor: Dennis Klapper     				*/
	/********************************************/

	void show();
	/*******************************************/
	/* function: void show()				   */
	/* description: show the Menu and iterating*/
	/* the text in the textContainer		   */
	/* param:								   */
	/* return:								   */
	/* Autor: Dennis Klapper     			   */
	/*******************************************/

	bool handle();
	/*******************************************/
	/* function: void handle()				   */
	/* description: this function handle       */
	/* the event of the menu                   */
	/*                                         */
	/* param:								   */
	/* return:	int							   */
	/* Autor: Dennis Klapper     			   */
	/*******************************************/

	int getInteractButton(sf::Vector2i act_pos_mouse);
	/********************************************************/
	/* function: interact_MouseMoved_event()				*/
	/* description: gets the interacting button				*/
	/* return int: if button is interacted, ifn returning -1*/
	/* Autor: Dennis Klapper     							*/
	/********************************************************/

	void interact_MouseMoved_event();
	/********************************************************/
	/* function: interact_MouseMoved_event()				*/
	/* description: coords the moving solutions over the	*/
	/* buttons - change color green							*/
	/* Autor: Dennis Klapper     							*/
	/********************************************************/

	void interact_MouseButtonLeft_event();
	/********************************************************/
	/* function: interact_MouseButtonLeft_event()			*/
	/* description: leaving the screenarea means that the	*/
	/* program have to change the buttons unclicked			*/
	/* Note: not all (optionsbutton + -)					*/
	/* Autor: Dennis Klapper     							*/
	/********************************************************/

	void interact_MouseButtonPressed_event();
	/********************************************************/
	/* function: interact_MouseButtonPressed_event()		*/
	/* description: changing the ButtonsStyle to clicked	*/
	/* Note: not all (optionsbutton + -)					*/
	/* Autor: Dennis Klapper     							*/
	/********************************************************/

	int interact_MouseButtonReleased_event();
	/********************************************************/
	/* function: interact_MouseButtonReleased_event()		*/
	/* description: interact mouse released depending		*/
	/* on which actual mode the program is					*/
	/*														*/
	/* return:	int											*/
	/* returning number between 1 - 2; important for main	*/
	/* 0: Game End; 1: Game Start; 2: Do nothing special	*/
	/* Autor: Dennis Klapper     							*/
	/********************************************************/

	void changeSoundSysState(int optSoundSysImgPosInArray, int pos_Or_negMove);
	/********************************************************/
	/* function: changeSoundSysState()						*/
	/* description: complicated function that handles the 	*/
	/* the logic by interacting with plus and minus			*/
	/* param: int, int										*/
	/* Autor: Dennis Klapper     							*/
	/********************************************************/

	void handleDataFromFile();
	/********************************************************/
	/* function: handleDataFromFile()						*/
	/* description: this func look if a posible file is		*/
	/* already exisiting and change settings. If not		*/
	/* the file create a new file with standart settings	*/
	/* Autor: Dennis Klapper     							*/
	/********************************************************/

	void updateNews();
	/********************************************************/
	/* function: updateNews()								*/
	/* description:informing about the updates in the menue */
	/* Autor: Dennis Klapper     							*/
	/********************************************************/

	void ReadDataFromFile();
	void writeDataToFile();

	void changeDifficult(int val);
	
};
//MODES
enum
{
	MODE_MAIN		= 1,
	MODE_OPTION,
	MODE_CREDIT
};

//MAIN SPECIFIC ENUM
enum
{
	ID_FALSE		= -1,
	ID_PLAY,
	ID_OPTION,
	ID_CREDITS,
	ID_END
};

//OPTION SPECIFIC ENUM
enum
{
	ID_BACK			= 0,		//CREDIT USE IT TOO
	ID_PLUS_1,
	ID_MINUS_1,
	ID_PLUS_2,
	ID_MINUS_2,
	//ID_BLOOD,
	ID_ARROW_L,
	ID_ARROW_R
};

//SOUND AND MUSIC
enum
{
	MUSIC = 2,
	SOUND = 3,
};



