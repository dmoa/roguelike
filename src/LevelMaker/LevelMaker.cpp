#include "LevelMaker.hpp"

LevelMaker::LevelMaker(sf::RenderWindow* renderWindow, LevelManager* levelManager, Player* player, Enemies* enemies)
{
	m_window = renderWindow;
	m_levelManager = levelManager;
	m_player = player;
	m_enemies = enemies;

	m_levelRender.texture.create(levelManager->GetLevelWidth(), levelManager->GetLevelHeight());
	m_levelRender.bg = sf::Color(34, 35, 35);
	m_levelRender.scale = 1;
	m_levelRender.sprite.setScale(m_levelRender.scale, m_levelRender.scale);

	m_cursorMode = Pencil;

	temp_shape.setSize(sf::Vector2f(100, 50));
	temp_shape.setPosition(50, 150);
	temp_shape.setFillColor(sf::Color::White);
}

void LevelMaker::Draw()
{
	m_levelRender.texture.clear(m_levelRender.bg);

	m_levelManager->Draw(&m_levelRender.texture);
	m_enemies->Draw(&m_levelRender.texture);
	m_player->Draw(&m_levelRender.texture);

	// drawing enemy options to choose from
	for (unsigned int i = 0; i < m_enemies->GetEnemyTypes()->size(); i++)
	{
		EnemyProperties tempEnemy = (*(m_enemies->GetEnemyTypes()))[i];
		for (unsigned int j = 0; j < tempEnemy.shapes.size(); j ++)
		{
			// meh fix
			// i - 3 because the map actually starts indexing at 9
			// might be good to add k variable if we get lots of enemies
			tempEnemy.shapes[j].setPosition((i - 3) * (tempEnemy.width + 15) + 15, 15);
			m_window->draw(tempEnemy.shapes[j]);
		}

	}

	m_levelRender.texture.display();

	m_levelRender.sprite.setTexture(m_levelRender.texture.getTexture());
	m_levelRender.sprite.setPosition((m_window->getSize().x - m_levelManager->GetLevelWidth() * m_levelRender.scale) / 2, (m_window->getSize().y - m_levelManager->GetLevelHeight() * m_levelRender.scale) / 2);

	m_window->draw(m_levelRender.sprite);
	m_window->draw(temp_shape);
}

void LevelMaker::Update(std::vector<sf::Event>* events)
{
	for (unsigned int i = 0; i < events->size(); i++)
	{
		if ((*events)[i].type == sf::Event::MouseButtonPressed)
		{
			printf("mouse pressed\n");
			if (Collision::PointInRect(sf::Vector2f(sf::Mouse::getPosition(*m_window)), sf::IntRect(50, 150, 100, 50)))
			{
				temp_shape.setFillColor(temp_shape.getFillColor() == sf::Color::Green ? sf::Color::White : sf::Color::Green);
				printf("collision!\n");
			}
		}
	}
}