#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "RoundedRectangleShape.h"

class Button
{


public:

	int x;
	int y;
	int width;
	int height;
	int shadingThickness;

	sf::RenderWindow* window;
	sf::RoundedRectangleShape rect;
	sf::RoundedRectangleShape shadingRect;
	sf::Color color;
	sf::Color highlightColor;


	Button();
	~Button();

	void Setup();
	void Resize();
	void Draw();
	bool Highlight();



};

