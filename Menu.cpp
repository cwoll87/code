#include "Menu.h"

#include <iostream>
#include <sstream>

//enable console, if we are in Debug-mode
#ifndef _DEBUG
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

template<class T> std::string toString(const T& t)
{
     std::ostringstream stream;
     stream << t;
     return stream.str();
}

Menu::Menu(void)
{
	//Initializations
	updateNews();

	win_gameMenu	= new sf::RenderWindow();									//Window created

	button_interact_pressed		= 0;
	button_interact_released	= 0;
	button_interact_move		= 0;

	mode						= 1;											//Standardmode by openning is the starting screen
	min							= 0;											//Standard																	
	max							= 4;											//Standard

	changedSettings				= false;										//Standard

	movementpoint = 14;

	//Read Option data from file & set val
	handleDataFromFile();

	headlineText	= az::Textline("", 23, 97, 19, sf::Color::Transparent);
	version			= az::Textline("version 0.2", 9, 233, 582, sf::Color::White);

	//Main Init
	mainBackground	= az::Image(300, 600, 0, 0,		"Ressources/Graphic/menu.jpg");
	mainLogo		= az::Image(180, 30, 25, 5,		"Ressources/Graphic/WorldOfAzuara.png");
	chain[0]		= az::Image(180, 30, 75, 110,	"Ressources/Graphic/chain_2.png");
	chain[1]		= az::Image(280, 30, 203, 110,	"Ressources/Graphic/chain_2.png");

	//Options Init
	optionDifficultState[0]		=	"Easy";
	optionDifficultState[1]		=	"Norm";
	optionDifficultState[2]		=	"Hard";

	optionDifficultColor[0]		= sf::Color::Green;
	optionDifficultColor[1]		= sf::Color::Blue;
	optionDifficultColor[2]		= sf::Color::Red;

	textlineVector.push_back(az::Textline("Musik:", 15, 78, 70, sf::Color::Black));
	textlineVector.push_back(az::Textline("Sound:", 15, 78, 139, sf::Color::Black));	
	textlineVector.push_back(az::Textline(toString<float>(optionSoundSysTlVal[0]).append("%"), 11, 127, 115, sf::Color::White));	
	textlineVector.push_back(az::Textline(toString<float>(optionSoundSysTlVal[1]).append("%"), 11, 127, 184, sf::Color::White));

	textlineVector.push_back(az::Textline("General:", 15, 78, 215, sf::Color::Black));
	textlineVector.push_back(az::Textline("Difficult", 16, 78, 238, sf::Color::Black));	
	textlineVector.push_back(az::Textline(optionDifficultState[DifficultState], 18, 164, 236, optionDifficultColor[DifficultState]));

	optionSoundSysImg[0]= az::Image(180, 30, 73, 70, "Ressources/Graphic/SoundSystemv3.png"); 
	optionSoundSysImg[1]= az::Image(180, 30, 73, 139, "Ressources/Graphic/SoundSystemv3.png");

	/****************************************INIT BUTTONS IN VECTOR***************************************/ 
	//fill all Buttons in the ButtonContainer
	//0 - 3 MAIN BUTTON OBJECTS
	//init Main Buttons//
	createButton("Play Game",	20, 75, 240, 0, "Ressources/Graphic/Button1v2unclicked.png");
	createButton("Options",		20, 75, 320, 0, "Ressources/Graphic/Button1v2unclicked.png");
	createButton("Credits",		20, 75, 400, 0, "Ressources/Graphic/Button1v2unclicked.png");
	createButton("End Game",	20, 75, 480, 0, "Ressources/Graphic/Button1v2unclicked.png");

	//4 - 8 OPTION BUTTON OBJECTS //4. Button for CREDITS too
	//init Option Buttons//
	createButton("Back to main",	20, 75, 525, 0, "Ressources/Graphic/Button1v2unclicked.png");									//Options and Credits

	createButton("+",		28, 196, 72, 1); 
	createButton("-",		29, 196, 113, 1);
	createButton("+",		28, 196, 141, 1);
	createButton("-",		29, 196, 183, 1);

	//Option arrows
	createButton("",	0, 145, 241, 3, "Ressources/Graphic/Difficult_Arrow_Left_unpressed.png");										//Arrow for Difficult Settings
	createButton("",	0, 217, 241, 3, "Ressources/Graphic/Difficult_Arrow_Right_unpressed.png");										//Arrow for Difficult Settings
	
	/*******************************INIT POS AND SIZE FOR SEPCIFIC ARRAY**********************************/
	//Init the Pos and Size
	for(unsigned int i = 0; i < 4; i++)
	{
		position_main[i]		= buttonContainer.at(i)->getPos();
		size_main[i]			= buttonContainer.at(i)->getSize();
	}

	for(unsigned int i = 0; i < 7; i++)
	{
		position_opt[i]		= buttonContainer.at(i+4)->getPos();
		size_opt[i]			= buttonContainer.at(i+4)->getSize();
	}
	
	//set standart color to Buttonelements 
	for(unsigned int i = 0; i < 5; i++)
	{
		buttonContainer.at(i)->changeTextColor(sf::Color(186, 171, 171, 255));	
	}

	for(unsigned int i = 0; i < textlineVector.size(); i++)
		if(textlineVector.at(i).getString() == "Musik:" || textlineVector.at(i).getString() == "Sound:" || textlineVector.at(i).getString() == "General:")
		{
			textlineVector.at(i).text.setStyle(sf::Text::Underlined|sf::Text::Italic);
		}

	//sf::Color(220, 65, 65, 255)	//COOL RED
	//sf::Color(186, 171, 171, 255) //COOL GRAY

	//ONLY BUTTON 4 for Credits needed
	position_cre[0]		= buttonContainer.at(4)->getPos();
	size_cre[0]			= buttonContainer.at(4)->getSize();

	//set sound test

	
	if (!MenueSoundTest.loadFromFile("Ressources/SoundSamples/button_test.wav"))
	{
		Log::write2("Can't load sound_test", 0);
	}
	else
	{
		sound_test.setBuffer(MenueSoundTest);
		sound_test.setVolume(optionSoundSysTlVal[1]);
	}

#ifndef _DEBUG
	//MenueMusic go
	if (!MusicMeue.openFromFile("MenueMusic.wav"))
	{
    // Error...
		Log::write2("Can't load menue music!", 0); 
	}
	else
	{
		MusicMeue.play();
		MusicMeue.setVolume(optionSoundSysTlVal[0]);
	}
#endif
}


Menu::~Menu(void)
{
}

void Menu::init(int width, int high, int bit_col, std::string name)
{
	win_gameMenu->create(sf::VideoMode(width, high, bit_col), name, NULL);
	//win_gameMenu->create(sf::WindowHandle(GetDlgItem(IDD_TEST_MENUE));

	initMainElements();
	Log::write2("Menu window created", (win_gameMenu)? true : false);
}

void Menu::show()
{
	if(mode == MODE_MAIN)
	{
		win_gameMenu->draw(mainBackground);
		win_gameMenu->draw(this->chain[0]);
		win_gameMenu->draw(this->chain[1]);	
		win_gameMenu->draw(mainLogo);
		win_gameMenu->draw(version);

		win_gameMenu->draw(headlineText);	
	}
				
	if(mode == MODE_OPTION)
	{
		win_gameMenu->draw(optionBackground);
		win_gameMenu->draw(headlineText);
		win_gameMenu->draw(optionSoundSysImg[0]);
		win_gameMenu->draw(optionSoundSysImg[1]);

		for(unsigned int y = 0; y < textlineVector.size(); y++)
		{
			win_gameMenu->draw(textlineVector.at(y));
		}

		win_gameMenu->draw(optionSoundSysImg[2]);
		win_gameMenu->draw(optionSoundSysImg[3]);
	}

	if(mode == MODE_CREDIT)
	{
		win_gameMenu->draw(headlineText);
	}
	
	//Draw Buttons depending on Mode
	for(unsigned int i = min; i < max; i++)
		win_gameMenu->draw(*buttonContainer.at(i));

	win_gameMenu->display();
}

void Menu::createButton(std::string name, int size, int xpos, int ypos, int typ, char* texturepath)
{
	az::Button *neuerButton = new az::Button;

	if(typ == 0)	//with texturepath
		neuerButton	=  new az::Button(xpos, ypos, 155, 30, name, size, sf::Color::White,texturepath);

	if(typ == 1)	//without texturepath; little rect 20/30 for + / -
		neuerButton	=  new az::Button(xpos, ypos, 29, 25, name, size, sf::Color::Black, NULL);

	if(typ == 2)	//without texturepath 75/30
		neuerButton	=  new az::Button(xpos, ypos, 75, 30, name, size, sf::Color::Black, NULL);

	if(typ == 3)
		neuerButton	=  new az::Button(xpos, ypos, 20, 30, name, size, sf::Color::Black, texturepath);

	buttonContainer.push_back(neuerButton);
}

void Menu::initMainElements()
{
	headlineText.text.setString("");
	this->pos	 =	this->position_main;
	this->size	 =  this->size_main;
	Log::write2("Main elements loaded", true);
}

void Menu::initOptionElements()
{
	optionBackground	= az::Image(220, 550, 43, 15, "Ressources/Graphic/Options_Backgroundv1.png");
	headlineText.text.setString("OPTIONS");
	headlineText.text.setColor(sf::Color::Cyan);
	this->pos	 =	this->position_opt;
	this->size	 =  this->size_opt;
	Log::write2("Option elements loaded", true);
}

void Menu::initCreditElements()
{
	headlineText.text.setString("CREDITS");
	headlineText.text.setColor(sf::Color::Cyan);
	this->pos	 =	this->position_cre;
	this->size	 =  this->size_cre;
	Log::write2("Credit elements loaded", true);
}

void Menu::changeToMain()
{
	Log::write2("Change ui: mainmenu", true);
	mode = 1;
	min = 0;
	max = 4;
	initMainElements();
}

void Menu::changeToOptions()
{
	Log::write2("Change ui: optionmenu", true);
	mode = 2;
	min = 4;
	max = 11;
	initOptionElements();
}

void Menu::changeToCredits()
{
	Log::write2("Change ui: creditmenu", true);
	mode = 3;
	min = 4;
	max = 5;
	initCreditElements();
}

bool Menu::handle()
{
	int mainResult = 2;

	//reposed mouse on the middle of the screen
	sf::Mouse::setPosition(sf::Vector2i(win_gameMenu->getPosition().x + 150 , win_gameMenu->getPosition().y + 300));
	
	if(!win_gameMenu)
	{
		Log::write2("Menu window has an NULL Pointer\n", 1);
		return false;
	}
	else
	{
		while(win_gameMenu->isOpen())
		{
			show();

			while(win_gameMenu->pollEvent(my_event))
			{
				switch (my_event.type)		//switch events
				{
					act_pos_mouse = sf::Mouse::getPosition(*win_gameMenu);
					//mouse move
				case sf::Event::MouseMoved:
					{
						act_pos_mouse = sf::Mouse::getPosition(*win_gameMenu);
						button_interact_move = getInteractButton(act_pos_mouse);
						interact_MouseMoved_event();
						win_gameMenu->clear();
						show();
						break;
					}
					//mouse left screen
				case sf::Event::MouseLeft:
					{
						act_pos_mouse = sf::Mouse::getPosition(*win_gameMenu);
						interact_MouseButtonLeft_event();
						win_gameMenu->clear();
						show();
						break;
					}
					//mouse key pressed
				case sf::Event::MouseButtonPressed:
					{
						act_pos_mouse = sf::Mouse::getPosition(*win_gameMenu);
						button_interact_pressed = getInteractButton(act_pos_mouse);					
						interact_MouseButtonPressed_event();
						//get mouse coords and set
						sf::Vector2i test(win_gameMenu->getPosition().x + sf::Mouse::getPosition(*win_gameMenu).x, win_gameMenu->getPosition().y + sf::Mouse::getPosition(*win_gameMenu).y);
						sf::Mouse::setPosition(test);
						win_gameMenu->clear();
						show();
						break;
					}
					//mouse key released
				case sf::Event::MouseButtonReleased:
					{	
						act_pos_mouse = sf::Mouse::getPosition(*win_gameMenu);
						button_interact_released = getInteractButton(act_pos_mouse);
						mainResult = interact_MouseButtonReleased_event();
						win_gameMenu->clear();
						show();
						
						if(mainResult == 0)
						{
							break;
						}
						if(mainResult == 1)
						{
							win_gameMenu->close();
							return true;
						}
					}
				case sf::Event::LostFocus:
					{
						//system("PAUSE");
					}


					button_interact_move		= ID_FALSE;		//else case
				default:
					{
						win_gameMenu->clear();
						show();
						break;
					}
				}
			}
		}

	}
	
	return false;		//normally not possible
}
int Menu::getInteractButton(sf::Vector2i act_pos_mouse)
{

	if(mode == 1)
	{
	for (unsigned int i = min; i < max; i++)
		if((act_pos_mouse.x < ((pos[i]).x + (size[i]).x) && act_pos_mouse.x > (pos[i]).x) && (act_pos_mouse.y < ((pos[i]).y + (size[i]).y) && act_pos_mouse.y > (pos[i]).y))
			return i;
	}

	if(mode == 2)
	{
	for (unsigned int i = i = min; i < max; i++)
		if((act_pos_mouse.x < (pos[i-4].x + size[i-4].x) && act_pos_mouse.x > pos[i-4].x) && (act_pos_mouse.y < (pos[i-4].y + size[i-4].y) && act_pos_mouse.y > pos[i-4].y))
			return i-4;
	}

	if(mode == 3)
	{
	for (unsigned int i = i = min; i < max; i++)
		if((act_pos_mouse.x < (pos[i-4].x + size[i-4].x) && act_pos_mouse.x > pos[i-4].x) && (act_pos_mouse.y < (pos[i-4].y + size[i-4].y) && act_pos_mouse.y > pos[i-4].y))
			return i-4;
	}

	return -1;		//else
}

void Menu::interact_MouseMoved_event()
{
	for(unsigned int i = 0; i < 5; i++)
	{
		buttonContainer.at(i)->changeTextColor(sf::Color(186, 171, 171, 255));	
	}

	if(this->mode == MODE_MAIN)
	{
		if(button_interact_move > -1 && button_interact_move <static_cast<int>(buttonContainer.size()))
			buttonContainer[button_interact_move]->changeTextColor(sf::Color(220, 65, 65, 255));
	}
	if(this->mode == MODE_OPTION)
	{
		for(unsigned int y = 4; y < 11; y++)
		{
			buttonContainer.at(y)->changeTextColor(sf::Color::Black);
		}
		buttonContainer.at(4)->changeTextColor(sf::Color(186, 171, 171, 255));
		if(button_interact_move > ID_FALSE && button_interact_move < static_cast<int>(buttonContainer.size()))
			buttonContainer[button_interact_move+4]->changeTextColor(sf::Color(220, 65, 65, 255));

		if(button_interact_move > ID_FALSE && button_interact_move == 5)
			buttonContainer[button_interact_move+4]->changeTextColor(sf::Color(220, 65, 65, 255));
	}
	if(this->mode == MODE_CREDIT)
	{
		for(unsigned int y = 4; y < 5; y++)
		{
			buttonContainer.at(y)->changeTextColor(sf::Color(186, 171, 171, 255));	
		}
		if(button_interact_move > ID_FALSE && button_interact_move < static_cast<int>(buttonContainer.size()))
			buttonContainer[button_interact_move+4]->changeTextColor(sf::Color(208, 40, 40, 255));  
	}
}

void Menu::interact_MouseButtonLeft_event()
{
	for(unsigned int i = 0; i < 5; i++)
	{
		if(mode == MODE_MAIN)
			buttonContainer.at(i)->changeTexturePath("Ressources/Graphic/Button1v2unclicked.png");

		if((mode == MODE_OPTION || mode == MODE_CREDIT) && i == 0)
				buttonContainer.at(i)->changeTexturePath("Ressources/Graphic/Button1v2unclicked.png");
	}
}

void Menu::interact_MouseButtonPressed_event()
{
	if(button_interact_pressed > ID_FALSE && button_interact_pressed < static_cast<int>(buttonContainer.size()))
	{
		if(this->mode == MODE_MAIN)
		{
			buttonContainer.at(button_interact_pressed)->changeTexturePath("Ressources/Graphic/Button1v2clicked.png");		
		}
		if(this->mode == MODE_OPTION)
		{
			if(button_interact_pressed==ID_BACK)
				buttonContainer.at(4)->changeTexturePath("Ressources/Graphic/Button1v2clicked.png");
			if(button_interact_pressed==ID_ARROW_L)
				buttonContainer.at(9)->changeTexturePath("Ressources/Graphic/Difficult_Arrow_Left_pressed.png");
			if(button_interact_pressed==ID_ARROW_R)
				buttonContainer.at(10)->changeTexturePath("Ressources/Graphic/Difficult_Arrow_Right_pressed.png");
		}
		if(this->mode == MODE_CREDIT)
		{
			if(button_interact_pressed==ID_BACK)
				buttonContainer.at(4)->changeTexturePath("Ressources/Graphic/Button1v2clicked.png");
		}
	}
}

int Menu::interact_MouseButtonReleased_event()
{
	if(this->mode == MODE_MAIN) 
	{
		for(unsigned int i = 0; i < 5; i++)
			buttonContainer.at(i)->changeTexturePath("Ressources/Graphic/Button1v2unclicked.png");

		if(button_interact_pressed == ID_PLAY && button_interact_released == ID_PLAY)
		{
			MusicMeue.stop();
			return 1;
		}
		if(button_interact_pressed == ID_OPTION && button_interact_released == ID_OPTION)
		{
			changeToOptions();
			return 2;
		}	
		if(button_interact_pressed == ID_CREDITS && button_interact_released == ID_CREDITS)
		{
			changeToCredits();
			return 2;
		}
		if(button_interact_pressed == ID_END && button_interact_released == ID_END)
		{	
			this->win_gameMenu->close();
			Log::write2("Menu Window closed", true);
			return 0;
		}
	}
	if(this->mode == MODE_OPTION) 
	{
			buttonContainer.at(4)->changeTexturePath("Ressources/Graphic/Button1v2unclicked.png");
			buttonContainer.at(9)->changeTexturePath("Ressources/Graphic/Difficult_Arrow_Left_unpressed.png");
			buttonContainer.at(10)->changeTexturePath("Ressources/Graphic/Difficult_Arrow_Right_unpressed.png");

		if(button_interact_pressed == ID_BACK && button_interact_released == ID_BACK)
		{
			this->win_gameMenu->setVisible(false);
			//CREATEMESSAGEBOX
			if(changedSettings)			//something was changed
				if(box.create(MESSAGEBOX, "MessageBox", "Wollen Sie die Einstellungen beim nächsten \nneustart übernehmen ?"))
				{
					box.create(INFOBOX, "Infobox", "Die Einstellungen wurden gespeichert. \nBeim nächsten Programmstart werden diese \nEinstellungen wieder übernommen.");
					writeDataToFile();
					changedSettings = false;
				}
				else//
				{
					handleDataFromFile();
					changedSettings = false;

				}
				changeToMain();
				this->win_gameMenu->setVisible(true);
				return 2;
		}
		if(button_interact_pressed == ID_PLUS_1 && button_interact_released == ID_PLUS_1)
		{
			if(	optionSoundSysTlVal[0] < 90 )
			{
				changeSoundSysState(MUSIC, 1);
				return 2;
			}
		}
		if(button_interact_pressed == ID_MINUS_1 && button_interact_released == ID_MINUS_1)
		{
			if(	optionSoundSysTlVal[0] > 10 )
			{
				changeSoundSysState(MUSIC, 0);
				return 2;
			}
		} 
		if(button_interact_pressed == ID_PLUS_2 && button_interact_released == ID_PLUS_2)
		{
			if(	optionSoundSysTlVal[1] < 90 )
			{
				changeSoundSysState(SOUND, 1);
				return 2;
			}
		}
		if(button_interact_pressed == ID_MINUS_2 && button_interact_released == ID_MINUS_2)
		{	
			if(	optionSoundSysTlVal[1] > 10 )
			{
				changeSoundSysState(SOUND, 0);
				return 2;
			}
		}
		if(button_interact_pressed == ID_ARROW_L && button_interact_released == ID_ARROW_L)
		{	
			changeDifficult(-1);
			return 2;
		}
		if(button_interact_pressed == ID_ARROW_R && button_interact_released == ID_ARROW_R)
		{	
			changeDifficult(1);
			return 2;
		}
	}
	if(this->mode == MODE_CREDIT)
	{
		buttonContainer.at(4)->changeTexturePath("Ressources/Graphic/Button1v2unclicked.png");
		if(button_interact_pressed == ID_BACK && button_interact_released == ID_BACK)
		{
			changeToMain();
			return 2;
		}
	}
	return 2;
}

void Menu::changeSoundSysState(int optSoundSysImgPosInArray, int pos_Or_negMove)
{
	int soundSysObject = optSoundSysImgPosInArray - 2;			//because different poses in arrays

	changedSettings		= true;									//something was changed in settings

	if(pos_Or_negMove == 1)		//positiv move '->'
	{
		optionSoundSysImg[optSoundSysImgPosInArray].changePosition(+movementpoint, 0);
		optionSoundSysTlVal[soundSysObject] = optionSoundSysTlVal[soundSysObject] + (float)12.5; 
	}

	if(pos_Or_negMove == 0)		//negativ move '<-'
	{
		optionSoundSysImg[optSoundSysImgPosInArray].changePosition(-movementpoint, 0);
		optionSoundSysTlVal[soundSysObject] = optionSoundSysTlVal[soundSysObject] - (float)12.5;
	}

	textlineVector.at(optSoundSysImgPosInArray).text.setString(toString<float>(optionSoundSysTlVal[soundSysObject]).append("%"));

	if (optSoundSysImgPosInArray == SOUND)
	{
		sound_test.setVolume(optionSoundSysTlVal[1]);
		sound_test.play();
	}

#ifndef _DEBUG
	MusicMeue.setVolume(optionSoundSysTlVal[0]);
#endif
}

void Menu::handleDataFromFile()
{
	readFile.open("AzuaraDataBaseV2.azd");

	if (readFile.is_open())
	{		//If Datafile already existing
			ReadDataFromFile();
    }
	else	//If no Datafile existing
	{
		Log::write2("Could not open file", 0);
		Log::write2("Creating a new file", 1);

		//Create a new
		//set standart settings: 5 5 0 0
		optionSoundSysTlVal[0]		= 50;
		optionSoundSysTlVal[1]		= 50;
		bloodState					= 0;
		DifficultState				= 0;

		writeDataToFile();
		handleDataFromFile();
	}
	optionSoundSysImg[2]= az::Image(30, 30, 132 +(movementpoint*(optionSoundSysTlVal[0]/(float)12.5-(float)5.0) + (float)12.5), 98, "Ressources/Graphic/SoundSystem_Object_Movable.png");
	optionSoundSysImg[3]= az::Image(30, 30, 132 +(movementpoint*(optionSoundSysTlVal[1]/(float)12.5-(float)5.0) + (float)12.5), 167, "Ressources/Graphic/SoundSystem_Object_Movable.png");

	std::string percent("%");
	int temp = 0;
	int retval = 0;

	for (unsigned int i = 0; i < textlineVector.size(); i++)
	{
		if (retval = textlineVector.at(i).getString().find_first_of(percent) != -1)
		{
			textlineVector.at(i).setString(toString<float>(optionSoundSysTlVal[temp]).append("%"));
			temp++;
		}
	}

#ifndef _DEBUG
	MusicMeue.setVolume(optionSoundSysTlVal[0]);
#endif
	
}

void Menu::ReadDataFromFile()
{
		char *tempWord2			= new char[6];

		Log::write2("File opened successfully", 1);

		for(int i = 0; i < 4; i++)
			readFile.read(tempWord2, 8);

		tempWord2[8] = '\0';

		optionSoundSysTlVal[0]		= (float)tempWord2[0] - '0';
		optionSoundSysTlVal[0]		= optionSoundSysTlVal[0] * (float)12.5;
		optionSoundSysTlVal[1]		= (float)tempWord2[2] - '0';
		optionSoundSysTlVal[1]		= optionSoundSysTlVal[1] * (float)12.5;
		bloodState					= tempWord2[4] - '0';
		DifficultState				= tempWord2[6] - '0';

		Log::write2("Settings changed", 1);

		readFile.close();
}

void Menu::writeDataToFile()
{
		std::string tempWord[4];

		writeFile.open("AzuaraDataBaseV2.azd");
		tempWord[0]		= toString<float>(optionSoundSysTlVal[0]/(float)12.5).append(" ");
		tempWord[1]		= toString<float>(optionSoundSysTlVal[1]/(float)12.5).append(" ");
		tempWord[2]		= toString<int>(bloodState).append(" ");
		tempWord[3]		= toString<int>(DifficultState).append(" ");


		for(int i = 0; i < 4; i++)
			writeFile.write(tempWord[i].c_str(), 2);

		writeFile.close();
}

void Menu::changeDifficult(int val)
{
	changedSettings = true;
	if(val == 1)
	{
		if(this->DifficultState == 2)
			this->DifficultState = 0;
		else
			this->DifficultState += 1;
	}


	if(val == -1)
	{
		if(this->DifficultState == 0)
			this->DifficultState = 2;
		else
			this->DifficultState -= 1;
	}

	for(unsigned int i = 0; i < textlineVector.size(); i++)
		if(textlineVector.at(i).getString() == optionDifficultState[0] || textlineVector.at(i).getString() == optionDifficultState[1] || textlineVector.at(i).getString() == optionDifficultState[2])
		{
			textlineVector.at(i).setString(optionDifficultState[DifficultState]);
			textlineVector.at(i).setColor(optionDifficultColor[DifficultState]);
		}

		return;
}

void Menu::updateNews()
{
//Update 0x0
//#ifndef UPDATEINFB0x0
//	box.create(INFOBOX, "UPDATEINFB0x0:", "Update:\n-InfoBox added\n");
//	box.create(INFOBOX, "Hilfe", "Damit du nicht immer wieder das letzte Update \nlesen musst, füge in deinem Präprozessor \ndirektiven in den Einstellungen den Namen der \nInfoBox hinzu. Dann wird das letzte Update nicht \nmehr angezeigt. Hier bspw. UPDATEINFB0x0."); 
//#else
//#endif
//
//#ifndef UPDATEINFB0x1
//	box.create(INFOBOX, "UPDATEINFB0x1:", "Update:\n-MessageBox added\n-Difficult added\n-Rebuild data save (AzuaraDataBaseV2.azd) ");
//#else
//#endif


}