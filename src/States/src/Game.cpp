#include "../include/Game.hpp"

extern const int SCALE;

Game::Game(sf::Shader* _shader)
{
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
	window->setView(view);
	map.Draw(window, shader);
}