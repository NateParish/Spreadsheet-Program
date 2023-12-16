#pragma once
#include "SFML/Graphics.hpp"

class MenuBar

{

public:

	int x;
	int y;

	sf::RectangleShape bgRect;
	sf::Color bgRectColor;


	MenuBar();
	~MenuBar();	

	void Draw(sf::RenderWindow* window);


};

