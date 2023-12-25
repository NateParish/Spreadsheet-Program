#pragma once
#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "RoundedRectangleShape.h"



class Cell
{

public:

	float x;
	float y;
	float width;
	float height;
	std::string displayText;


	sf::RenderWindow* window;
	sf::RoundedRectangleShape rect;
	sf::Color color;
	sf::Color highlightColor;

	sf::Font font;
	sf::Text text;
	


	Cell();
	~Cell();

	void Setup();
	void Resize();
	void Draw();
	bool Highlight();


};

