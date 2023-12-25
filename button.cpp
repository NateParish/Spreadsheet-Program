#include "button.h"

Button::Button()
{
	window;
	x = 15;
	y = 350;
	width = 0;
	height = 90;
	shadingThickness = 2;
	color = sf::Color(240, 240, 240);
	highlightColor = sf::Color(255, 255, 255);
	rect.setFillColor(color);
	rect.setOutlineColor(sf::Color(220, 220, 220));
	shadingRect;
	shadingRect.setFillColor(sf::Color(230, 230, 230, 150));
}

Button::~Button()
{

}

void Button::Setup()
{
	width = 25;
	height = 25;

	font.loadFromFile("C:/Windows/Fonts/calibri.ttf");
	//width = window->getSize().x - 30;
	if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf"))
	{
		std::cout << "ERROR LOADING FONT";
	}

	text.setFont(font);
	text.setString("B");
	text.setCharacterSize(15);
	text.setPosition(x + 3, y + height / 2 - 6.67);
	text.setFillColor(sf::Color::Black);
	//text.setStyle(sf::Text::Bold);


	rect.setSize(sf::Vector2f(width, height));
	rect.setCornersRadius(5);
	rect.setCornerPointCount(10);
	rect.setOutlineThickness(1);
	rect.setPosition(x, y);
	rect.setFillColor(color);

	shadingRect.setSize(sf::Vector2f(width, height));
	shadingRect.setCornersRadius(5);
	shadingRect.setCornerPointCount(10);
	shadingRect.setOutlineThickness(0);
	shadingRect.setPosition(x, y + shadingThickness);
	//bgRect.setFillColor(sf::Color(bgRectColor.r, bgRectColor.g, bgRectColor.b));

}

void Button::Resize()
{
	width = window->getSize().x - 30;
	rect.setSize(sf::Vector2f(width, height));
	shadingRect.setSize(sf::Vector2f(width, height));
}

void Button::SetPosition(float inputX, float inputY)
{
	x = inputX;
	y = inputY;

	rect.setPosition(x, y);
	shadingRect.setPosition(x, y + shadingThickness);
	text.setPosition(x + 5, y + 1);

}
void Button::SetSize(float newWidth, float newHeight)
{
	width = newWidth;
	height = newHeight;
	rect.setSize(sf::Vector2f(width, height));
	shadingRect.setSize(sf::Vector2f(width, height));
}

void Button::SetColor(sf::Color newColor)
{
	color = newColor;
	rect.setFillColor(color);
}

void Button::SetText(std::string newText)
{
	text.setString(newText);
}

void Button::MakeTextBold()
{
	text.setStyle(sf::Text::Bold);
}

void Button::UnderlineText()
{
	text.setStyle(sf::Text::Underlined);
}

void Button::MakeTextItalic()
{
	text.setStyle(sf::Text::Italic);
}


void Button::Draw()
{

	window->draw(shadingRect);
	window->draw(rect);
	window->draw(text);
}

bool Button::Highlight()
{

	//std::count << mousePosition;
	sf::Cursor handCursor;
	handCursor.loadFromSystem(sf::Cursor::Hand);
	bool highlight(false);

	sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);

	rect.setFillColor(color);

	if(mousePosition.x > x)
	{
		if(mousePosition.x < x + width)
		{
			if(mousePosition.y > y)
			{
				if (mousePosition.y < y + height)
				{
					rect.setFillColor(highlightColor);
					//std::cout << mousePosition.x << " " << mousePosition.y << std::endl;
					highlight = true;
					
				}
			}
		}
	}

	return highlight;

}
