#include "../include/Game.hpp"

extern bool QUIT;

extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;

Game::Game()
{
	if (!m_shader.loadFromFile("content/shader.frag", sf::Shader::Fragment))
	{
		throw "Shaders not available!";
	}
	m_shader.setUniform("screen", sf::Glsl::Vec2(WINDOW_WIDTH, WINDOW_HEIGHT));
	m_shader.setUniform("num_lights", 1);
	m_shader.setUniform("lights[0].diffuse", sf::Glsl::Vec3(1.0, 1.0, 1.0));
	m_shader.setUniform("lights[0].power", 20.0f);

	// m_renderTexture_noShader.create(WINDOW_WIDTH, WINDOW_HEIGHT);
	m_renderTexture.create(WINDOW_WIDTH, WINDOW_HEIGHT);
	m_backgroundColor = sf::Color(34, 35, 35);

	m_player.SetStartingPos(&m_levelManager, &m_shader);
	m_levelManager.ReloadRenderer();
	// m_enemies.Setup(&m_levelManager, m_player.GetX(), m_player.GetY());
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
					// 	m_player.SetStartingPos(&m_levelManager, &m_shader);
					// 	m_enemies.Setup(&m_tileSetTexture, &m_levelManager, m_player.GetX(), m_player.GetY());
					// 	break;

					case sf::Keyboard::Left:
					case sf::Keyboard::A:
						PlayerMoveAttempt(m_player.Move(-1, 0, &m_shader, &m_levelManager));
						break;
					case sf::Keyboard::Right:
					case sf::Keyboard::D:
						PlayerMoveAttempt(m_player.Move(1, 0, &m_shader, &m_levelManager));
						break;
					case sf::Keyboard::Up:
					case sf::Keyboard::W:
						PlayerMoveAttempt(m_player.Move(0, -1, &m_shader, &m_levelManager));
						break;
					case sf::Keyboard::Down:
					case sf::Keyboard::S:
						PlayerMoveAttempt(m_player.Move(0, 1, &m_shader, &m_levelManager));
						break;
				}
		}
	}
}

void Game::Draw(const std::shared_ptr<sf::RenderWindow>& window)
{
	m_renderTexture.clear(m_backgroundColor);
	// m_renderTexture_noShader.clear(sf::Color(0, 0, 0, 0));

	m_levelManager.Draw(&m_renderTexture);
	// m_enemies.Draw(&m_renderTexture);
	m_player.Draw(&m_renderTexture);

	m_renderTexture.display();
	// m_renderTexture_noShader.display();

	m_sprite.setTexture(m_renderTexture.getTexture());
	// m_sprite_noShader.setTexture(m_renderTexture_noShader.getTexture());

	window->draw(m_sprite, &m_shader);
	// window->draw(m_sprite_noShader);
}

void Game::PlayerMoveAttempt(bool playerDidMove)
{
	if (playerDidMove)
	{
		// m_enemies.Update(m_player.GetX(), m_player.GetY(), &m_levelManager);
	}
}