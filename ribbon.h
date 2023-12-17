#pragma once
#include "SFML/Graphics.hpp"
#include "RoundedRectangleShape.h"

class Ribbon
{

public:

	int x;
	int y;
	int width;
	int height;
	int shadingThickness;

	sf::RenderWindow* window;
	sf::RoundedRectangleShape bgRect;
	sf::RoundedRectangleShape shadingRect;
	sf::Color bgRectColor;


	Ribbon();
	~Ribbon();

	void Setup();
	void Resize();
	void Draw();


};