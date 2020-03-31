#include "../include/Game.hpp"

extern const int SCALE;

Game::Game(sf::Shader* _shader)
{
	shader = _shader;

	// _rectangle.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
	// _rectangle.setFillColor(sf::Color::White);
	// shapeTexture.loadFromFile("content/placeholder.png");
	// _rectangle.setTexture(&shapeTexture);

	const int level[] =
    {
        0, 0, 0, 0, 0,
		1, 1, 1, 1, 1,
		2, 1, 1, 2, 1,
		1, 2, 3, 4, 5,
		3, 1, 3, 2, 1
    };

	tilemap.load("content/tileset.png", sf::Vector2u(16, 16), level, 5, 5);
	tilemap.setScale(SCALE, SCALE);
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
	window->setView(view);
	window->draw(tilemap);
}