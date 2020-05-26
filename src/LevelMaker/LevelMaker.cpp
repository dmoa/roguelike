#include "LevelMaker.hpp"

LevelMaker::LevelMaker(float* windowWidth, float* windowHeight, LevelManager* levelManager, Player* player, Enemies* enemies)
{
	m_windowWidth = windowWidth;
	m_windowHeight = windowHeight;
	m_levelManager = levelManager;
	m_player = player;
	m_enemies = enemies;

	m_levelRender.texture.create(levelManager->GetLevelWidth(), levelManager->GetLevelHeight());
	m_levelRender.bg = sf::Color(34, 35, 35);
	m_levelRender.scale = 1;
	m_levelRender.sprite.setScale(m_levelRender.scale, m_levelRender.scale);
}

void LevelMaker::Draw(sf::RenderWindow* window)
{
	m_levelRender.texture.clear(m_levelRender.bg);

	m_levelManager->Draw(&m_levelRender.texture);
	// m_enemies->Draw(&m_levelRender.texture);
	m_player->Draw(&m_levelRender.texture);

	m_levelRender.texture.display();

	m_levelRender.sprite.setTexture(m_levelRender.texture.getTexture());
	m_levelRender.sprite.setPosition((*m_windowWidth - m_levelManager->GetLevelWidth() * m_levelRender.scale) / 2, (*m_windowHeight - m_levelManager->GetLevelHeight() * m_levelRender.scale) / 2);

	window->draw(m_levelRender.sprite);
}

// void LevelMaker::Update(sf::Time deltaTime, std::vector<sf::Event>*)
// {
// //	deltaTime += 0;

// 	// for (unsigned int i = 0; i < events->size(); i++)
// 	// {
// 	// 	if ((*events)[i].type == sf::Event::KeyPressed)
// 	// 	{
// 	// 		switch ((*events)[i].key.code)
// 	// 		{
// 	// 			case sf::Keyboard::R:
// 	// 			{
// 	// 				m_enemies->Setup()
// 	// 				break;
// 	// 			}

// 	// 			default: break;
// 	// 		}
// 	// 	}
// }