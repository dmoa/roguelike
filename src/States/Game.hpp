#include "Game.h"

Game::Game(sf::Shader* _shader)
{
	_rectangle.setSize(sf::Vector2f(500, 500));
	_rectangle.setFillColor(sf::Color::White);
	sf::Texture shapeTexture;
	shapeTexture.loadFromFile("content/bg.png");
	_rectangle.setTexture(&shapeTexture);
	shader = _shader;
}

// Update function contains state-specific logic
void Game::Update(sf::Time deltaTime)
{
	deltaTime.asMilliseconds();
}

// Draw function contains SFML draw calls
void Game::Draw(const std::shared_ptr<sf::RenderWindow>& window)
{
	// shader->setUniform("texture", shapeTexture);
	window->draw(_rectangle);
}

	// sf::RectangleShape shape;
	// shape.setSize(sf::Vector2f(500, 500));
	//