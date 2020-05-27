#include "../include/Game.hpp"

Game::Game(sf::RenderWindow* window, LevelManager* levelManager, Player* player, Enemies* enemies)
{
	m_window = window;
	m_levelRender.texture.create(m_window->getSize().x, m_window->getSize().y);
	m_levelRender.bg = sf::Color(34, 35, 35);
	m_levelRender.scale = 1;
	m_levelRender.sprite.setScale(m_levelRender.scale, m_levelRender.scale);

	// m_shader.Init(m_windowWidth, m_windowHeight);


	m_levelManager = levelManager;
	m_player = player;
	m_enemies = enemies;

	m_player->GiveShader(m_shader.GetShader());
	m_player->SetStartingPos(m_levelManager);
	m_enemies->Setup(m_levelManager, m_player->GetPos());
	m_levelManager->ReloadRenderer();
}


void Game::Update(sf::Int32* dt, std::vector<sf::Event>* events)
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
					PlayerMoveAttempt(m_player->Move(-1, 0));
					break;
				case sf::Keyboard::Right:
				case sf::Keyboard::D:
					PlayerMoveAttempt(m_player->Move(1, 0));
					break;
				case sf::Keyboard::Up:
				case sf::Keyboard::W:
					PlayerMoveAttempt(m_player->Move(0, -1));
					break;
				case sf::Keyboard::Down:
				case sf::Keyboard::S:
					PlayerMoveAttempt(m_player->Move(0, 1));
					break;

				case sf::Keyboard::R:
					ResetLevel();
					break;

				default: break;
			}
		}
	}
}

void Game::Draw()
{
	m_levelRender.texture.clear(m_levelRender.bg);

	m_levelManager->Draw(&m_levelRender.texture);
	m_enemies->Draw(&m_levelRender.texture);
	m_player->Draw(&m_levelRender.texture);

	m_levelRender.texture.display();

	m_levelRender.sprite.setTexture(m_levelRender.texture.getTexture());
	m_levelRender.sprite.setTextureRect(sf::IntRect(0, 0, m_levelManager->GetLevelWidth(), m_levelManager->GetLevelHeight()));
	m_levelRender.sprite.setPosition((m_window->getSize().x - m_levelManager->GetLevelWidth() * m_levelRender.scale) / 2, (m_window->getSize().y - m_levelManager->GetLevelHeight() * m_levelRender.scale) / 2);

	m_window->draw(m_levelRender.sprite, m_shader.GetShader());
}

void Game::PlayerMoveAttempt(bool playerDidMove)
{
	if (playerDidMove)
	{
		m_enemies->Update(m_player->GetPos());
	}
}

void Game::ResetLevel()
{
	m_player->Reset();
	m_enemies->Reset();
}