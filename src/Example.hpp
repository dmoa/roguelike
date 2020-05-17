#pragma once

#include <StateMachine/State.hpp>

class Example : public sm::State
{
public:
	Example()
	{
		font.loadFromFile("content/font.ttf");
		text.setString("Now, as I was saying...");
		text.setFont(font);
		text.setCharacterSize(50);
		text.setFillColor(sf::Color(128, 128, 0));
		text.setPosition(100.f, 200.f);

		bg.setSize(sf::Vector2f(1000, 1000));
		bg.setFillColor(sf::Color(0, 0, 0, 200));
	}
	sm::ReturnCode Update(sf::Int32* dt, std::vector<sf::Event>* events)
	{
		dt += 0;
		for (unsigned int i = 0; i < events->size(); i++)
		{
			if ((*events)[i].type == sf::Event::KeyPressed)
			{
				if ((*events)[i].key.code == sf::Keyboard::Escape)
				{
					return sm::DELETE_SELF;
				}
			}
		}
		return sm::CONTINUE;
	}
	void Draw(sf::RenderWindow* window)
	{
		// window->draw(bg);
		window->draw(text);
	}
private:
	sf::Font font;
	sf::Text text;
	sf::RectangleShape bg;
};