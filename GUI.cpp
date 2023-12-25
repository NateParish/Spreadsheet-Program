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
	boldButton.window = window;
	italicButton.window = window;
	underlineButton.window = window;
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

	boldButton.Setup();
	boldButton.SetSize(20, 20);
	boldButton.SetText("B");
	boldButton.MakeTextBold();
	boldButton.SetPosition(100, 100);

	italicButton.Setup();
	italicButton.SetSize(20, 20);
	italicButton.SetText("I");
	italicButton.MakeTextItalic();
	italicButton.SetPosition(125, 100);

	underlineButton.Setup();
	underlineButton.SetSize(20, 20);
	underlineButton.SetText("U");
	underlineButton.UnderlineText();
	underlineButton.SetPosition(150, 100);


	std::vector<Button*> listOfButtons;
	listOfButtons.push_back(&boldButton);
	listOfButtons.push_back(&italicButton);
	listOfButtons.push_back(&underlineButton);

	Cell testCell;
	testCell.window = window;
	testCell.Setup();
	std::vector<Cell*> listOfCells;
	listOfCells.push_back(&testCell);




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
			if(setCursorToHand)
			{
				updateCursor = true;
			}
		}

		if (updateCursor)
		{
			if (setCursorToHand)
			{
				window->setMouseCursor(handCursor);
				setCursorToArrow = false;
			}
			if (setCursorToArrowWait)
			{
				window->setMouseCursor(arrowWaitCursor);
				setCursorToArrow = false;
			}
			if (setCursorToArrow)
			{
				window->setMouseCursor(arrowCursor);
			}

			//std::cout << "updateCursor 1 : " << updateCursor << std::endl;
			updateCursor = false;
			//std::cout << "updateCursor 1 : " << updateCursor << std::endl;

		}
		else
		{
			window->setMouseCursor(arrowCursor);
		}

		testCell.Draw();
		topMenuBar.Draw();
		topRibbon.Draw();

		for (Button* button : listOfButtons)
		{
			button->Draw();
		}

		window->display();

	}


}