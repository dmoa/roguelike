#include "../include/Game.hpp"

extern const float WINDOW_WIDTH;
extern const float WINDOW_HEIGHT;

Game::Game(sf::Shader* _shader)
{
	_rectangle.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
	_rectangle.setFillColor(sf::Color::White);
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
	shader->setUniform("texture", shapeTexture);
	window->draw(_rectangle, shader);
}