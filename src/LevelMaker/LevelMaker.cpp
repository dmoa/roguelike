#include "LevelMaker.hpp"

LevelMaker::LevelMaker(sf::RenderWindow* renderWindow, LevelManager* levelManager, Player* player, Enemies* enemies)
{
	m_window = renderWindow;
	m_levelManager = levelManager;
	m_player = player;
	m_enemies = enemies;
	m_enemyTypes = enemies->GetEnemyTypes();

	m_levelRender.texture.create(levelManager->GetLevelWidth(), levelManager->GetLevelHeight());
	m_levelRender.bg = sf::Color(34, 35, 35);
	m_levelRender.scale = 1;
	m_levelRender.sprite.setScale(m_levelRender.scale, m_levelRender.scale);

	m_cursorMode = Drawing;
	m_selectedItemIndex = 0;

	m_commonBorder = 30;
	m_enemySelectorWidth = (*m_enemyTypes)[3].width + m_commonBorder;

	m_modeSelectorShape.setSize(sf::Vector2f(100, 50));
	m_modeSelectorShape.setPosition(m_commonBorder, 180);
	m_modeSelectorShape.setFillColor(sf::Color::Yellow);

	m_selectedShapeOutline.setSize(sf::Vector2f(m_commonBorder / 2, m_commonBorder / 2));
	m_selectedShapeOutline.setFillColor(sf::Color::White);
	m_selectedShapeOutline.setPosition((m_selectedItemIndex + 0.5) * m_enemySelectorWidth + m_commonBorder - m_selectedShapeOutline.getSize().x / 2, m_commonBorder / 2 - m_selectedShapeOutline.getSize().y / 2);

	m_font.loadFromFile("content/fonts/stats.ttf");
	m_details.setFont(m_font);
	m_details.setCharacterSize(18);
	m_details.setPosition(m_commonBorder, 130);
	m_details.setString("mode: draw\nselected: " + std::to_string(m_selectedItemIndex));
	m_details.setFillColor(sf::Color::White);
}

void LevelMaker::Draw()
{
	m_levelRender.texture.clear(m_levelRender.bg);

	m_levelManager->Draw(&m_levelRender.texture);
	m_enemies->Draw(&m_levelRender.texture);
	m_player->Draw(&m_levelRender.texture);

	// drawing enemy options to choose from
	for (unsigned int i = 0; i < m_enemyTypes->size(); i++)
	{
		EnemyProperties tempEnemy = (*m_enemyTypes)[i];
		for (unsigned int j = 0; j < tempEnemy.shapes.size(); j ++)
		{
			// meh fix
			// i - 3 because the map actually starts indexing at 9
			// might be good to add k variable if we get lots of enemies
			tempEnemy.shapes[j].setPosition((i - 3) * m_enemySelectorWidth + m_commonBorder * 1.5, m_commonBorder);
			m_window->draw(tempEnemy.shapes[j]);
		}

	}

	m_levelRender.texture.display();

	m_levelRender.sprite.setTexture(m_levelRender.texture.getTexture());
	m_levelRender.sprite.setPosition((m_window->getSize().x - m_levelManager->GetLevelWidth() * m_levelRender.scale) / 2, (m_window->getSize().y - m_levelManager->GetLevelHeight() * m_levelRender.scale) / 2);

	m_window->draw(m_levelRender.sprite);
	m_window->draw(m_modeSelectorShape);
	m_window->draw(m_details);
	m_window->draw(m_selectedShapeOutline);
}

void LevelMaker::Update(std::vector<sf::Event>* events)
{
	for (unsigned int i = 0; i < events->size(); i++)
	{
		if ((*events)[i].type == sf::Event::MouseButtonPressed)
		{
			sf::Vector2f mouse_pos = sf::Vector2f(sf::Mouse::getPosition(*m_window));
			if (Collision::PointInRect(mouse_pos, m_modeSelectorShape.getGlobalBounds()))
			{
				m_cursorMode = (m_cursorMode == Drawing) ? Erase : Drawing;
				UpdateToolsRender();
			}
			// all enemies have a height of 80, this is temp fix, because enemy heights could change.
			// ideally, we would figure out the max enemy height earlier and use that.
			if (mouse_pos.y > m_commonBorder && mouse_pos.y < m_commonBorder + 80)
			{
				int j;
				for (unsigned int i = 0; i < m_enemyTypes->size(); i++)
				{
					j = i - 3; // for everything but indexing (becaue map starts at 2, will have to fix this at some point)
					EnemyProperties ep = (*m_enemyTypes)[i];
					if (Collision::PointInRect(mouse_pos, sf::FloatRect(m_commonBorder + m_enemySelectorWidth * j, m_commonBorder, m_enemySelectorWidth, (*m_enemyTypes)[i].height)))
					{
						m_selectedItemIndex = j;
						UpdateToolsRender();
					}
				}
			}
		}
	}
}

void LevelMaker::UpdateToolsRender()
{
	m_modeSelectorShape.setFillColor(m_cursorMode == Drawing ? sf::Color::Yellow : sf::Color::White);
	m_selectedShapeOutline.setPosition((m_selectedItemIndex + 0.5) * m_enemySelectorWidth + m_commonBorder - m_selectedShapeOutline.getSize().x / 2, m_commonBorder / 2 - m_selectedShapeOutline.getSize().y / 2);

	std::string new_string = "mode: ";
	new_string += (m_cursorMode == Drawing) ? "draw" : "erase";
	new_string += "\n";
	new_string += "selected: " + std::to_string(m_selectedItemIndex);
	m_details.setString(new_string);
}


// I needed this, then turns out I didn't, but I'm still not sure yet
std::vector<std::string> LevelMaker::Split(std::string str, char delim)
{
    std::stringstream ss(str);
    std::string token;
	std::vector<std::string> stats;
    while (std::getline(ss, token, delim)) {
        stats.push_back(token);
    }
	return stats;
}