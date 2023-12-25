#include "cell.h"

Cell::Cell()
{
	window;
	x = 15;
	y = 250;
	width = 100;
	height = 25;
	color = sf::Color(255, 255, 255);
	highlightColor = sf::Color(0, 255, 255);
	rect.setFillColor(color);
	rect.setOutlineColor(sf::Color(230, 230, 230));
	displayText = "test";
	text;



};

Cell::~Cell()
{

}

void Cell::Setup()
{
	font.loadFromFile("C:/Windows/Fonts/calibri.ttf");
	//width = window->getSize().x - 30;
	if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf"))
	{
		std::cout << "ERROR LOADING FONT";
	}

	text.setFont(font);
	text.setString("Hello world");
	text.setCharacterSize(13.33);
	text.setPosition(x + 3, y + height / 2 - 6.67);
	text.setFillColor(sf::Color::Black);
	//text.setStyle(sf::Text::Bold | sf::Text::Underlined);


	rect.setSize(sf::Vector2f(width, height));
	rect.setCornersRadius(5);
	rect.setCornerPointCount(10);
	rect.setOutlineThickness(1);
	rect.setPosition(x, y);
	rect.setFillColor(color);

	//bgRect.setFillColor(sf::Color(bgRectColor.r, bgRectColor.g, bgRectColor.b));

}

void Cell::Resize()
{
	width = window->getSize().x - 30;
	rect.setSize(sf::Vector2f(width, height));
}

void Cell::Draw()
{

	window->draw(rect);
	window->draw(text);
}

bool Cell::Highlight()
{

	//std::count << mousePosition;
	sf::Cursor handCursor;
	handCursor.loadFromSystem(sf::Cursor::Hand);
	bool highlight(false);

	sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);

	rect.setFillColor(color);

	if (mousePosition.x > x)
	{
		if (mousePosition.x < x + width)
		{
			if (mousePosition.y > y)
			{
				if (mousePosition.y < y + height)
				{
					rect.setFillColor(highlightColor);
					//std::cout << mousePosition.x << " " << mousePosition.y << std::endl;
					highlight = true;

				}
			}
		}
	}

	return highlight;

}