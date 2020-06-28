#include "../include/Game.hpp"

Game::Game(sf::RenderWindow* window, LevelRenderer* levelRenderer, LevelManager* levelManager, Player* player, Enemies* enemies)
{
	m_window = window;

	m_levelRenderer = levelRenderer;
	m_levelManager = levelManager;
	m_player = player;
	m_enemies = enemies;

	m_player->SetStartingPos(m_levelManager->GetTileLocations(m_player->GetID(), true)[0]);
	m_enemies->Setup(m_player->GetPos());
}


void Game::Update(std::vector<sf::Event>* events, float dt)
{
	for (unsigned int i = 0; i < events->size(); i++)
	{
		if ((*events)[i].type == sf::Event::KeyPressed)
		{
			switch ((*events)[i].key.code)
			{
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
					// ResetLevel();
					m_levelRenderer->ReloadShader();
					break;

				default: break;
			}
		}
	}

	m_levelRenderer->Update(dt);
}

void Game::Draw()
{
	m_levelRenderer->Draw();
}

void Game::PlayerMoveAttempt(bool playerDidMove)
{
	if (playerDidMove)
	{
		m_enemies->Update();
	}
}

void Game::ResetLevel()
{
	m_player->Reset();
	m_enemies->Reset();
}