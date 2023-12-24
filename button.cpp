#include "button.h"

Button::Button()
{
	window;
	x = 15;
	y = 250;
	width = 0;
	height = 90;
	shadingThickness = 4;
	color = sf::Color(255, 255, 255);
	highlightColor = sf::Color(0, 255, 255);
	rect.setFillColor(color);
	rect.setOutlineColor(sf::Color(230, 230, 230));
	shadingRect;
	shadingRect.setFillColor(sf::Color(230, 230, 230, 150));
}

Button::~Button()
{

}

void Button::Setup()
{
	width = window->getSize().x - 30;

	rect.setSize(sf::Vector2f(width, height));
	rect.setCornersRadius(5);
	rect.setCornerPointCount(10);
	rect.setOutlineThickness(1);
	rect.setPosition(x, y);
	rect.setFillColor(color);

	shadingRect.setSize(sf::Vector2f(width, height));
	shadingRect.setCornersRadius(5);
	shadingRect.setCornerPointCount(10);
	shadingRect.setOutlineThickness(0);
	shadingRect.setPosition(x, y + shadingThickness);
	//bgRect.setFillColor(sf::Color(bgRectColor.r, bgRectColor.g, bgRectColor.b));

}

void Button::Resize()
{
	width = window->getSize().x - 30;
	rect.setSize(sf::Vector2f(width, height));
	shadingRect.setSize(sf::Vector2f(width, height));
}


void Button::Draw()
{

	window->draw(shadingRect);
	window->draw(rect);
}

bool Button::Highlight()
{

	//std::count << mousePosition;
	sf::Cursor handCursor;
	handCursor.loadFromSystem(sf::Cursor::Hand);
	bool highlight(false);

	sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);

	rect.setFillColor(color);

	if(mousePosition.x > x)
	{
		if(mousePosition.x < x + width)
		{
			if(mousePosition.y > y)
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
