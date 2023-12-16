#include "GUI.h"




GUI::GUI(sf::RenderWindow* windowPtr)
{	
	window = windowPtr;
	initialWidth = 1024;
	initialHeight = 768;
	windowTitle = "Spreadsheet Program";
	window->create(sf::VideoMode(initialWidth, initialHeight), windowTitle);

	topMenuBar;

}

GUI::~GUI()
{

}

void GUI::LaunchGUI()
{	
	MainLoop();	
}


void GUI::MainLoop()
{
	int FPS(60);
	window->setFramerateLimit(FPS);

	sf::Event e;

	while (window->isOpen())
	{

		window->clear();

		while (window->pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window->close();
			}
			if (e.type == sf::Event::Resized)
			{
				window->setView(sf::View(sf::FloatRect(0, 0, e.size.width, e.size.height)));
			}

		}

		topMenuBar.Draw(window);
		window->display();

	}


}