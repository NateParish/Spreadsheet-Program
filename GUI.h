#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "SFML/Graphics.hpp"
#include "menu_bar.h"
#include "ribbon.h"
#include "button.h"
#include "cell.h"
#include "RoundedRectangleShape.h"

class GUI
{


	public:

		//sf::RenderWindow* window;
		sf::RenderWindow* window;
		int initialWidth;
		int initialHeight;
		std::string windowTitle;

		MenuBar topMenuBar;
		Ribbon topRibbon;
		Button boldButton;
		Button italicButton;
		Button underlineButton;


		GUI(sf::RenderWindow* windowPtr);
		~GUI();

		void LaunchGUI();
		void MainLoop();

		//MenuBar topMenuBar;
		//Ribbon topRibbon;


	private:
		bool updateCursor;


		
};

