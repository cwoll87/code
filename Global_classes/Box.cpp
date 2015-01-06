#include "Box.h"

Box::Box()
{
	this->box_window = new sf::RenderWindow();
	buttonContainerSize	= 0;
	text = az::Textline("", 15, 15, 10, sf::Color::White);
}

Box::~Box()
{
}

int Box::create(int typ, std::string windowName, std::string handleMessage)
{
	int	returnval;

	//create new window
	box_window->create(sf::VideoMode(350, 150, 32), windowName, sf::Style::Titlebar);
	//set mouse in the middle of box
	sf::Vector2i posMouse = box_window->getPosition();
	posMouse.x = posMouse.x + 165;
	posMouse.y = posMouse.y + 75;

	sf::Mouse::setPosition(posMouse);
	box_window->setVisible(true);

	//detect line breaks

	//set handleMessageText in Box
	text.setString(handleMessage);

	switch(typ)
	{
	case INFOBOX:
		{
			buttonContainer.clear();
			newButton = new az::Button(90, 115, 155, 30, "Ok", 20, sf::Color::White, "/Ressources/Graphic/Button1v2unclicked.png");
			this->buttonContainer.push_back(newButton);
			buttonContainerSize = this->buttonContainer.size();
			returnval = eventloopInfoBox();
			break;
		}
	case MESSAGEBOX:
		
		{
			buttonContainer.clear();
			newButton = new az::Button(10, 105, 155, 30, "Ja", 20, sf::Color::White, "Ressources/Graphic/Button1v2unclicked.png");
			this->buttonContainer.push_back(newButton);
			newButton = new az::Button(180, 105, 155, 30, "Nein", 20, sf::Color::White, "Ressources/Graphic/Button1v2unclicked.png");
			this->buttonContainer.push_back(newButton);
			buttonContainerSize = this->buttonContainer.size();
			returnval = eventloopMessageBox();	 
			break;
		}
	case EDITBOX:
		{

		}
	};

	
	return returnval;
}

int Box::eventloopInfoBox()
{
	//logic
	while(box_window->isOpen())
		{
			while(box_window->pollEvent(eventvar))
			{
				switch (eventvar.type)		//switch events
				{
					act_pos_mouse = sf::Mouse::getPosition(*box_window);

					case sf::Event::MouseMoved:
					{
						newButton->changeTextColor(sf::Color::White);
						act_pos_mouse = sf::Mouse::getPosition(*box_window);
						if(getInteractButton(act_pos_mouse)== 0)
							newButton->changeTextColor(sf::Color::Green);
						break;
					}

					case sf::Event::MouseButtonPressed:
					{
						if(getInteractButton(act_pos_mouse)== 0)
							newButton->changeTexturePath("Ressources/Graphic/Button1v2clicked.png");

						break;
					}
					case sf::Event::MouseButtonReleased:
					{
						newButton->changeTexturePath("Ressources/Graphic/Button1v2unclicked.png");

						if(getInteractButton(act_pos_mouse)== 0)
						{
							box_window->close();
							return 0;
						}
						break;
					}
					case sf::Event::MouseLeft:
					{
						newButton->changeTexturePath("Ressources/Graphic/Button1v2unclicked.png");
						newButton->changeTextColor(sf::Color::White);

						break;
					}
					default:
					{
						break;
					}
				}
			}
			box_window->clear();
			box_window->draw(text);
				
			
			box_window->draw(*newButton);
			
			box_window->display();
		}

	return 1;
}
int Box::eventloopMessageBox()
{
	int buttonResult = -1;

	//logic
	while(box_window->isOpen())
		{
			while(box_window->pollEvent(eventvar))
			{
				switch (eventvar.type)		//switch events
				{
					act_pos_mouse = sf::Mouse::getPosition(*box_window);

					case sf::Event::MouseMoved:
					{
						for(unsigned int i = 0; i < buttonContainer.size(); i++)
							buttonContainer.at(i)->changeTextColor(sf::Color::White);

						act_pos_mouse = sf::Mouse::getPosition(*box_window);

						button_interact_move = getInteractButton(act_pos_mouse);
						if(button_interact_move== 0 || button_interact_move== 1)
							buttonContainer.at(button_interact_move)->changeTextColor(sf::Color::Green);
						break;
					}

					case sf::Event::MouseButtonPressed:
					{
						button_interact_pressed = getInteractButton(act_pos_mouse);
						if(button_interact_pressed== 0 || button_interact_pressed== 1)
							buttonContainer.at(button_interact_pressed)->changeTexturePath("Ressources/Graphic/Button1v2clicked.png");

						break;
					}
					case sf::Event::MouseButtonReleased:
					{
						for(unsigned int i = 0; i < buttonContainer.size(); i++)
							buttonContainer.at(i)->changeTexturePath("Ressources/Graphic/Button1v2unclicked.png");

						button_interact_released = getInteractButton(act_pos_mouse);

						if(button_interact_pressed == button_interact_released)
							if(button_interact_released == 0 || button_interact_released== 1)
							{
								box_window->close();
								return (button_interact_released)? 0 : 1;
							}
						break;
					}
					case sf::Event::MouseLeft:
					{
						for(unsigned int i = 0; i < buttonContainer.size(); i++)
						{
							buttonContainer.at(i)->changeTexturePath("Ressources/Graphic/Button1v2unclicked.png");
							buttonContainer.at(i)->changeTextColor(sf::Color::White);
						}

						break;
					}
					default:
					{
						break;
					}
				}
			}
			box_window->clear();
			box_window->draw(text);

			for(int i = 0; i < buttonContainerSize; i++)
				box_window->draw(*buttonContainer.at(i));

			box_window->display();
		}

	return 0;
}

int Box::getInteractButton(sf::Vector2i act_pos_mouse)
{
	for (unsigned int i = 0; i < buttonContainer.size(); i++)
		if((act_pos_mouse.x < (buttonContainer[i]->getPos().x + buttonContainer[i]->getSize().x) && act_pos_mouse.x > buttonContainer[i]->getPos().x) && (act_pos_mouse.y < (buttonContainer[i]->getPos().y + buttonContainer[i]->getSize().y) && act_pos_mouse.y > buttonContainer[i]->getPos().y))
			return i;

	return -1;		//else
}