#include "../include/Game.hpp"

extern bool QUIT;

extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;

Game::Game()
{
	m_levelRender.texture.create(WINDOW_WIDTH, WINDOW_HEIGHT);
	m_levelRender.bg = sf::Color(34, 35, 35);
	m_levelRender.scale = 2;
	m_levelRender.sprite.setScale(m_levelRender.scale, m_levelRender.scale);

	m_player.SetStartingPos(&m_levelManager, m_shader.GetShader());
	m_enemies.Setup(&m_levelManager, m_player.GetPos());
	m_levelManager.ReloadRenderer();
}

void Game::Update(sf::Time deltaTime, const std::shared_ptr<sf::RenderWindow>& window)
{
	// we aren't doing anything with dt right now but we will need it later
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

			// sometimes there's input lag, not sure why
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
					default: break;
					// case sf::Keyboard::Space:
					// 	m_levelManager = Map();
					// 	m_enemies = Enemies();
					// 	m_player = Player();
					// 	m_player.SetTextures(&m_tileSetTexture);
					// 	m_player.SetStartingPos(&m_levelManager, m_shader.GetShader());
					// 	m_enemies.Setup(&m_tileSetTexture, &m_levelManager, m_player.GetX(), m_player.GetY());
					// 	break;

					case sf::Keyboard::Left:
					case sf::Keyboard::A:
						PlayerMoveAttempt(m_player.Move(-1, 0, m_shader.GetShader(), &m_levelManager));
						break;
					case sf::Keyboard::Right:
					case sf::Keyboard::D:
						PlayerMoveAttempt(m_player.Move(1, 0, m_shader.GetShader(), &m_levelManager));
						break;
					case sf::Keyboard::Up:
					case sf::Keyboard::W:
						PlayerMoveAttempt(m_player.Move(0, -1, m_shader.GetShader(), &m_levelManager));
						break;
					case sf::Keyboard::Down:
					case sf::Keyboard::S:
						PlayerMoveAttempt(m_player.Move(0, 1, m_shader.GetShader(), &m_levelManager));
						break;
				}
		}
	}
}

void Game::Draw(const std::shared_ptr<sf::RenderWindow>& window)
{
	m_levelRender.texture.clear(m_levelRender.bg);

	m_levelManager.Draw(&m_levelRender.texture);
	m_enemies.Draw(&m_levelRender.texture);
	m_player.Draw(&m_levelRender.texture);

	m_levelRender.texture.display();

	m_levelRender.sprite.setTexture(m_levelRender.texture.getTexture());
	m_levelRender.sprite.setTextureRect(sf::IntRect(0, 0, m_levelManager.GetLevelWidth(), m_levelManager.GetLevelHeight()));
	m_levelRender.sprite.setPosition((WINDOW_WIDTH - m_levelManager.GetLevelWidth() * m_levelRender.scale) / 2, (WINDOW_HEIGHT - m_levelManager.GetLevelHeight() * m_levelRender.scale) / 2);

	window->draw(m_levelRender.sprite, m_shader.GetShader());
}

void Game::PlayerMoveAttempt(bool playerDidMove)
{
	if (playerDidMove)
	{
		m_enemies.Update(m_player.GetPos(), &m_levelManager);
	}
}