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
	button1.window = window;
	updateCursor = false;

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
	//bool updateCursor(false);
	

	sf::Cursor arrowCursor;
	arrowCursor.loadFromSystem(sf::Cursor::Arrow);
	bool setCursorToArrow(true);
	
	sf::Cursor arrowWaitCursor;
	arrowWaitCursor.loadFromSystem(sf::Cursor::ArrowWait);
	bool setCursorToArrowWait(false);

	sf::Cursor handCursor;
	handCursor.loadFromSystem(sf::Cursor::Hand);
	bool setCursorToHand(false);


	window->setFramerateLimit(FPS);
	topMenuBar.Setup();
	topRibbon.Setup();
	button1.Setup();


	std::vector<Button*> listOfButtons;
	listOfButtons.push_back(&button1);



	sf::Event e;

	while (window->isOpen())
	{
		
		setCursorToArrow = true;
		setCursorToHand = false;
		setCursorToArrowWait = false;

		//window->setMouseCursor(arrowCursor);
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

		for (Button* button : listOfButtons)
		{
			setCursorToHand = button->Highlight();
			if(setCursorToHand == true)
			{
				updateCursor = true;
				//std::cout << "updateCursor 1 : " << updateCursor << std::endl;
			}
			button->Draw();
		}

		if (updateCursor == true)
		{
			if (setCursorToHand == true)
			{
				window->setMouseCursor(handCursor);
				setCursorToArrow = false;
			}
			if (setCursorToArrowWait == true)
			{
				window->setMouseCursor(arrowWaitCursor);
				setCursorToArrow = false;
			}
			if (setCursorToArrow == true)
			{
				window->setMouseCursor(arrowCursor);
			}

			std::cout << "updateCursor 1 : " << updateCursor << std::endl;
			updateCursor = false;
			std::cout << "updateCursor 1 : " << updateCursor << std::endl;

		}

		topMenuBar.Draw();
		topRibbon.Draw();
		window->display();

	}


}