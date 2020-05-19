#include "../include/Game.hpp"

Game::Game(float* windowWidth, float* windowHeight, Assets* assets)
{
	m_windowWidth = windowWidth;
	m_windowHeight = windowHeight;
	m_levelRender.texture.create(*m_windowWidth, *m_windowHeight);
	m_levelRender.bg = sf::Color(34, 35, 35);
	m_levelRender.scale = 1;
	m_levelRender.sprite.setScale(m_levelRender.scale, m_levelRender.scale);

	m_shader.Init(m_windowWidth, m_windowHeight);

	m_assets = assets;

	m_player.SetStartingPos(&m_levelManager, m_shader.GetShader());
	m_enemies.Setup(assets, &m_levelManager, m_player.GetPos());
	m_levelManager.ReloadRenderer();
}


sm::ReturnCode Game::Update(sf::Int32* dt, std::vector<sf::Event>* events)
{
	// we aren't doing anything with dt right now but we will need it later
	dt = 0;
			// case sf::Event::Resized:
			// {
			// 	*window_width = event.size.width;
			// 	WINDOW_HEIGHT = event.size.height;
			// 	m_levelRender.scale = std::min(*window_width / 1000, WINDOW_HEIGHT / 1000);
			// 	m_levelRender.sprite.setScale(m_levelRender.scale, m_levelRender.scale);
			// // sometimes there's input lag, not sure why
	for (unsigned int i = 0; i < events->size(); i++)
	{
		if ((*events)[i].type == sf::Event::KeyPressed)
		{
			switch ((*events)[i].key.code)
			{
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
					PlayerMoveAttempt(m_player.Move(-1, 0, m_shader.GetShader()));
					break;
				case sf::Keyboard::Right:
				case sf::Keyboard::D:
					PlayerMoveAttempt(m_player.Move(1, 0, m_shader.GetShader()));
					break;
				case sf::Keyboard::Up:
				case sf::Keyboard::W:
					PlayerMoveAttempt(m_player.Move(0, -1, m_shader.GetShader()));
					break;
				case sf::Keyboard::Down:
				case sf::Keyboard::S:
					PlayerMoveAttempt(m_player.Move(0, 1, m_shader.GetShader()));
					break;

				default: break;
			}
		}
	}
	return sm::CONTINUE;
}

void Game::Draw(sf::RenderWindow* window)
{
	m_levelRender.texture.clear(m_levelRender.bg);

	m_levelManager.Draw(&m_levelRender.texture);
	m_enemies.Draw(&m_levelRender.texture);
	m_player.Draw(&m_levelRender.texture);

	m_levelRender.texture.display();

	m_levelRender.sprite.setTexture(m_levelRender.texture.getTexture());
	m_levelRender.sprite.setTextureRect(sf::IntRect(0, 0, m_levelManager.GetLevelWidth(), m_levelManager.GetLevelHeight()));
	m_levelRender.sprite.setPosition((*m_windowWidth - m_levelManager.GetLevelWidth() * m_levelRender.scale) / 2, (*m_windowHeight - m_levelManager.GetLevelHeight() * m_levelRender.scale) / 2);

	window->draw(m_levelRender.sprite, m_shader.GetShader());
}

LevelManager* GetLevelManager()
{
	return m_leve
}

void Game::PlayerMoveAttempt(bool playerDidMove)
{
	if (playerDidMove)
	{
		m_enemies.Update(m_player.GetPos());
	}
}