#include "menu_bar.h"

MenuBar::MenuBar()
{
	x = 100;
	y = 100;
	bgRect;
	bgRectColor.r = 50;
	bgRectColor.g = 50;
	bgRectColor.b = 50;

	bgRect.setFillColor(bgRectColor);
	bgRect.setSize(sf::Vector2f(250, 250));
	bgRect.setPosition(sf::Vector2f(x, y));

}


MenuBar::~MenuBar()
{

}



void MenuBar::Draw(sf::RenderWindow* window)
{
	window->draw(bgRect);
}

