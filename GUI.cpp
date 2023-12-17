#include "GUI.h"




GUI::GUI(sf::RenderWindow* windowPtr)
{	
	window = windowPtr;
	initialWidth = 1024;
	initialHeight = 768;
	windowTitle = "Spreadsheet Program";
	window->create(sf::VideoMode(initialWidth, initialHeight), windowTitle);
	topMenuBar.window = window;
	topRibbon.window = window;

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
	topMenuBar.Setup();
	topRibbon.Setup();



	//sf::RoundedRectangleShape rectangle;
	// rectangle.setSize(sf::Vector2f(100, 50));
	// rectangle.setCornersRadius(5);
	// rectangle.setCornerPointCount(10);
	// rectangle.setOutlineThickness(5);
	// rectangle.setPosition(100, 200);
	// rectangle.setFillColor(sf::Color(255, 255, 255));
	// window->draw(rectangle);

	




	sf::Event e;

	while (window->isOpen())
	{

		window->clear(sf::Color(240,240,240));

		while (window->pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window->close();
			}
			if (e.type == sf::Event::Resized)
			{
				window->setView(sf::View(sf::FloatRect(0, 0, e.size.width, e.size.height)));
				topMenuBar.Resize();
				topRibbon.Resize();
			}

		}

		//window->draw(rectangle);

		topMenuBar.Draw();
		topRibbon.Draw();
		window->display();

	}


}