#include "../include/Game.hpp"

extern const int SCALE;

Game::Game(sf::Shader* _shader)
{
	m_shader = _shader;
	// m_renderTexture.create(500, 500);

	m_sprite.setColor(sf::Color::White);
	m_sprite.scale(SCALE, SCALE);


	m_texture.loadFromFile("content/tileset.png");
	tempSprite.setPosition(250, 250);
	tempSprite.setColor(sf::Color::White);
	tempSprite.setTexture(m_texture);
	tempSprite.setPosition(0, 0);
	tempSprite.setScale(2, 2);

	m_renderTexture.draw(tempSprite);
	m_renderTexture.display();
	m_renderTexture_texture = m_renderTexture.getTexture();
	m_sprite.setTexture(m_renderTexture_texture);
}

void Game::Update(sf::Time deltaTime)
{
	deltaTime.asMilliseconds();
}

// Draw function contains SFML draw calls
void Game::Draw(const std::shared_ptr<sf::RenderWindow>& window)
{
	// m_map.Draw(&m_renderTexture);
	//m_sprite.setTexture(m_renderTexture.getTexture());
	// window->setView(m_view);
	//m_sprite.setTexture(m_renderTexture.getTexture());
	window->draw(tempSprite);
}