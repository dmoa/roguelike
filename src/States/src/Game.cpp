#include "../include/Game.hpp"

extern const float WINDOW_WIDTH;
extern const float WINDOW_HEIGHT;

Game::Game(sf::Shader* _shader)
{
	shader = _shader;

	_rectangle.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
	_rectangle.setFillColor(sf::Color::White);
	shapeTexture.loadFromFile("content/tileset.png");
	_rectangle.setTexture(&shapeTexture);

	ty::Settings::TileSize = 16;
	ty::Settings::ChunkWidth = 16;
	ty::Settings::ChunkHeight = 16;

	map.Create(320, 160, 1);
}

// Update function contains state-specific logic
void Game::Update(sf::Time deltaTime)
{
	deltaTime.asMilliseconds();
}

// Draw function contains SFML draw calls
void Game::Draw(const std::shared_ptr<sf::RenderWindow>& window)
{
	map.DrawLayer(0, window, sf::RenderStates(&shapeTexture));

	// shader->setUniform("texture", shapeTexture);
	// window->draw(_rectangle);
}