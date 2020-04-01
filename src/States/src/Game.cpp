#include "../include/Game.hpp"

extern const int SCALE;
extern const int GAME_WIDTH;
extern const int GAME_HEIGHT;

Game::Game(sf::Shader* _shader)
{
	m_shader = _shader;
	m_renderTexture.create(GAME_WIDTH, GAME_HEIGHT);
	m_sprite.setScale(SCALE, SCALE);
}

// Update function contains state-specific logic
void Game::Update(sf::Time deltaTime)
{
	deltaTime.asMilliseconds();
}

// Draw function contains SFML draw calls
void Game::Draw(const std::shared_ptr<sf::RenderWindow>& window)
{
	m_renderTexture.clear();
	m_map.Draw(&m_renderTexture);
	m_renderTexture.display();
	m_sprite.setTexture(m_renderTexture.getTexture());
	window->draw(m_sprite);
}