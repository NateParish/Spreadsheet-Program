#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class MenuBar

{

public:

	int x;
	int y;
	int width;
	int height;

	sf::RenderWindow* window;
	sf::RectangleShape bgRect;
	sf::Color bgRectColor;


	MenuBar();
	~MenuBar();	

	void Setup();
	void Resize();
	void Draw();


};

