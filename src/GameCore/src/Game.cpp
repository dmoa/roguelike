#include "../include/Game.hpp"

extern bool QUIT;

extern const int SCALE;
extern const int GAME_WIDTH;
extern const int GAME_HEIGHT;

Game::Game(sf::Shader* _shader)
{
	m_shader = _shader;
	m_renderTexture.create(GAME_WIDTH, GAME_HEIGHT);
	m_sprite.setScale(SCALE, SCALE);
	m_backgroundColor = sf::Color(34, 35, 35);

	m_tileSetTexture.loadFromFile("content/tileset.png");
	m_player.setTexture(&m_tileSetTexture);
}

void Game::Update(sf::Time deltaTime, const std::shared_ptr<sf::RenderWindow>& window)
{
	deltaTime.asMilliseconds();
	sf::Event event;
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
			default: break;

			case sf::Event::Closed:
				QUIT = true;
				break;
		}
	}
}

void Game::Draw(const std::shared_ptr<sf::RenderWindow>& window)
{
	m_renderTexture.clear(m_backgroundColor);

	m_map.Draw(&m_renderTexture);
	m_player.Draw(&m_renderTexture);

	m_renderTexture.display();
	m_sprite.setTexture(m_renderTexture.getTexture());
	window->draw(m_sprite, m_shader);
}