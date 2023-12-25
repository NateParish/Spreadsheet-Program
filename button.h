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
	sf::Font font;
	sf::Text text;


	Button();
	~Button();

	void Setup();
	void Resize();
	void SetColor(sf::Color color);
	void SetText(std::string newText);
	void MakeTextBold();
	void MakeTextItalic();
	void UnderlineText();
	void SetSize(float newWidth, float newHeight);
	void SetPosition(float x, float y);
	void Draw();
	bool Highlight();



};

