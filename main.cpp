#include <iostream>
#include "SFML/Graphics.hpp"
#include "GUI.h"

int main()
{


	sf::RenderWindow window;
	sf::RenderWindow* windowPtr(&window);

	GUI GUI(windowPtr);
	GUI.LaunchGUI();

	return 0;

}