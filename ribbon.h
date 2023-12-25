#pragma once
#include "SFML/Graphics.hpp"
#include "RoundedRectangleShape.h"
#include "button.h"

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

	std::vector <Button*> buttonList;


	Ribbon();
	~Ribbon();

	void Setup();
	void Resize();
	void Draw();


};