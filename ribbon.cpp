#include "ribbon.h"
#include "SFML/Graphics.hpp"


Ribbon::Ribbon()
{
	window;
	x = 15;
	y = 50;
	width = 0;
	height = 90;
	shadingThickness = 4;
	bgRectColor = sf::Color(255, 255, 255);
	bgRect.setFillColor(bgRectColor);
	bgRect.setOutlineColor(sf::Color(230, 230, 230));
	shadingRect;
	shadingRect.setFillColor(sf::Color(230, 230, 230,150));
}

Ribbon::~Ribbon()
{

}

void Ribbon::Setup()
{
	width = window->getSize().x - 30;

	bgRect.setSize(sf::Vector2f(width, height));
	bgRect.setCornersRadius(5);
	bgRect.setCornerPointCount(10);
	bgRect.setOutlineThickness(1);
	bgRect.setPosition(x, y);
	bgRect.setFillColor(bgRectColor);

	shadingRect.setSize(sf::Vector2f(width, height));
	shadingRect.setCornersRadius(5);
	shadingRect.setCornerPointCount(10);
	shadingRect.setOutlineThickness(0);
	shadingRect.setPosition(x, y + shadingThickness);
	//bgRect.setFillColor(sf::Color(bgRectColor.r, bgRectColor.g, bgRectColor.b));

}

void Ribbon::Resize()
{
	width = window->getSize().x - 30;
	bgRect.setSize(sf::Vector2f(width, height));
	shadingRect.setSize(sf::Vector2f(width, height));
}


void Ribbon::Draw()
{
	
	window->draw(shadingRect);
	window->draw(bgRect);
}