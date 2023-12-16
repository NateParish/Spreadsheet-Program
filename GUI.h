#pragma once
#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "menu_bar.h"
#include "ribbon.h"

class GUI
{


	public:

		//sf::RenderWindow* window;
		sf::RenderWindow* window;
		int initialWidth;
		int initialHeight;
		std::string windowTitle;

		MenuBar topMenuBar;

		GUI(sf::RenderWindow* windowPtr);
		~GUI();

		void LaunchGUI();
		void MainLoop();

		//MenuBar topMenuBar;
		//Ribbon topRibbon;


	private:


		
};
