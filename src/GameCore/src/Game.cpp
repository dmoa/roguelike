#include "../include/Game.hpp"

extern bool QUIT;

extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;

extern const int SCALE;
extern const int GAME_WIDTH;
extern const int GAME_HEIGHT;

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

	m_renderTexture_noShader.create(GAME_WIDTH, GAME_HEIGHT);
	m_renderTexture.create(GAME_WIDTH, GAME_HEIGHT);
	m_sprite.setScale(SCALE, SCALE);
	m_sprite_noShader.setScale(SCALE, SCALE);
	m_backgroundColor = sf::Color(34, 35, 35);

	m_tileSetTexture.loadFromFile("content/tileset.png");
	m_player.SetTextures(&m_tileSetTexture);
	m_player.SetStartingPos(&m_map, &m_shader);

	m_enemies.Setup(&m_tileSetTexture, &m_map, m_player.GetX(), m_player.GetY());
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

			// sometimes there's input lag, not sure why
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
					default: break;

					case sf::Keyboard::Left:
					case sf::Keyboard::A:
						m_player.Move(-1, 0, &m_shader, &m_map);
						m_enemies.Update(m_player.GetX(), m_player.GetY(), &m_map);
						break;
					case sf::Keyboard::Right:
					case sf::Keyboard::D:
						m_player.Move(1, 0, &m_shader, &m_map);
						m_enemies.Update(m_player.GetX(), m_player.GetY(), &m_map);
						break;
					case sf::Keyboard::Up:
					case sf::Keyboard::W:
						m_player.Move(0, -1, &m_shader, &m_map);
						m_enemies.Update(m_player.GetX(), m_player.GetY(), &m_map);
						break;
					case sf::Keyboard::Down:
					case sf::Keyboard::S:
						m_player.Move(0, 1, &m_shader, &m_map);
						m_enemies.Update(m_player.GetX(), m_player.GetY(), &m_map);
						break;
					case sf::Keyboard::Space:
						m_map = Map();
						m_enemies = Enemies();
						m_player = Player();
						m_player.SetTextures(&m_tileSetTexture);
						m_player.SetStartingPos(&m_map, &m_shader);
						m_enemies.Setup(&m_tileSetTexture, &m_map, m_player.GetX(), m_player.GetY());
						break;
				}
		}
	}
}

void Game::Draw(const std::shared_ptr<sf::RenderWindow>& window)
{
	m_renderTexture.clear(m_backgroundColor);
	m_renderTexture_noShader.clear(sf::Color(0, 0, 0, 0));

	m_map.Draw(&m_renderTexture);
	m_enemies.Draw(&m_renderTexture);
	m_player.Draw(&m_renderTexture, &m_renderTexture_noShader);

	m_renderTexture.display();
	m_renderTexture_noShader.display();

	m_sprite.setTexture(m_renderTexture.getTexture());
	m_sprite_noShader.setTexture(m_renderTexture_noShader.getTexture());

	window->draw(m_sprite, &m_shader);
	window->draw(m_sprite_noShader);
}