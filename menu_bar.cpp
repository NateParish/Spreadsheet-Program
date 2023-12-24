#include "menu_bar.h"

MenuBar::MenuBar()
{

	window;
	x = 0;
	y = 0;
	width=0;
	height = 25;
	bgRect;
	bgRectColor.r = 240;
	bgRectColor.g = 240;
	bgRectColor.b = 240;

	//bgRect.setFillColor(bgRectColor);
	//bgRect.setSize(sf::Vector2f(250, 250));
	//bgRect.setPosition(sf::Vector2f(x, y));

}


MenuBar::~MenuBar()
{

}

void MenuBar::Setup()
{
	width = window->getSize().x;
	//std::cout << width << std::endl;
	bgRect.setFillColor(bgRectColor);
	bgRect.setSize(sf::Vector2f(width, height));
	bgRect.setPosition(sf::Vector2f(x, y));
}

void MenuBar::Resize()
{
	width = window->getSize().x;
	bgRect.setSize(sf::Vector2f(width, height));
}


void MenuBar::Draw()
{
	window->draw(bgRect);
}

