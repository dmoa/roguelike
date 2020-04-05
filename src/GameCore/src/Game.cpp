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
	m_shader.setUniform("lights[0].position", sf::Glsl::Vec2(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));
	m_shader.setUniform("lights[0].diffuse", sf::Glsl::Vec3(1.0, 1.0, 1.0));
	m_shader.setUniform("lights[0].power", 5.0f);

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

			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
					default: break;

					case sf::Keyboard::Left:
						m_player.move(-1, 0, &m_shader, &m_map);
						break;
					case sf::Keyboard::Right:
						m_player.move(1, 0, &m_shader, &m_map);
						break;
					case sf::Keyboard::Up:
						m_player.move(0, -1, &m_shader, &m_map);
						break;
					case sf::Keyboard::Down:
						m_player.move(0, 1, &m_shader, &m_map);
						break;
				}
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
	window->draw(m_sprite, &m_shader);
}