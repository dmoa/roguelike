#include "B_Enemies.hpp"

B_Enemies::B_Enemies()
{
	m_enemyTypes[3].viewType = Up;
	m_enemyTypes[3].shapes.push_back(sf::ConvexShape(3));
	m_enemyTypes[3].width = 80;
	m_enemyTypes[3].height = 80;
	m_enemyTypes[3].shapes[0].setPoint(0, sf::Vector2f(40, 0));
	m_enemyTypes[3].shapes[0].setPoint(1, sf::Vector2f(80, 80));
	m_enemyTypes[3].shapes[0].setPoint(2, sf::Vector2f(0, 80));
	m_enemyTypes[3].shapes[0].setFillColor(sf::Color(191,97,106));

	m_enemyTypes[4].viewType = Down;
	m_enemyTypes[4].shapes.push_back(sf::ConvexShape(3));
	m_enemyTypes[4].width = 80;
	m_enemyTypes[4].height = 80;
	m_enemyTypes[4].shapes[0].setPoint(0, sf::Vector2f(0, 0));
	m_enemyTypes[4].shapes[0].setPoint(1, sf::Vector2f(80, 0));
	m_enemyTypes[4].shapes[0].setPoint(2, sf::Vector2f(40, 80));
	m_enemyTypes[4].shapes[0].setFillColor(sf::Color(191,97,106));

	m_enemyTypes[5].viewType = Left;
	m_enemyTypes[5].shapes.push_back(sf::ConvexShape(3));
	m_enemyTypes[5].shapes[0].setPoint(0, sf::Vector2f(0, 40));
	m_enemyTypes[5].shapes[0].setPoint(1, sf::Vector2f(80, 0));
	m_enemyTypes[5].shapes[0].setPoint(2, sf::Vector2f(80, 80));
	m_enemyTypes[5].shapes[0].setFillColor(sf::Color(191,97,106));
	m_enemyTypes[5].width = 80;
	m_enemyTypes[5].height = 80;

	m_enemyTypes[6].viewType = Right;
	m_enemyTypes[6].shapes.push_back(sf::ConvexShape(3));
	m_enemyTypes[6].shapes[0].setPoint(0, sf::Vector2f(0, 0));
	m_enemyTypes[6].shapes[0].setPoint(1, sf::Vector2f(0, 80));
	m_enemyTypes[6].shapes[0].setPoint(2, sf::Vector2f(80, 40));
	m_enemyTypes[6].shapes[0].setFillColor(sf::Color(191,97,106));
	m_enemyTypes[6].width = 80;
	m_enemyTypes[6].height = 80;

	m_enemyTypes[7].viewType = Vertical;
	m_enemyTypes[7].shapes.push_back(sf::ConvexShape(3));
	m_enemyTypes[7].shapes[0].setPoint(0, sf::Vector2f(40, 0));
	m_enemyTypes[7].shapes[0].setPoint(1, sf::Vector2f(80, 30));
	m_enemyTypes[7].shapes[0].setPoint(2, sf::Vector2f(0, 30));
	m_enemyTypes[7].shapes[0].setFillColor(sf::Color(191,97,106));
	m_enemyTypes[7].shapes.push_back(sf::ConvexShape(3));
	m_enemyTypes[7].shapes[1].setPoint(0, sf::Vector2f(0, 50));
	m_enemyTypes[7].shapes[1].setPoint(1, sf::Vector2f(80, 50));
	m_enemyTypes[7].shapes[1].setPoint(2, sf::Vector2f(40, 80));
	m_enemyTypes[7].shapes[1].setFillColor(sf::Color(191,97,106));
	m_enemyTypes[7].width = 80;
	m_enemyTypes[7].height = 80;

	m_enemyTypes[8].viewType = Horizontal;
	m_enemyTypes[8].shapes.push_back(sf::ConvexShape(3));
	m_enemyTypes[8].shapes[0].setPoint(0, sf::Vector2f(0, 40));
	m_enemyTypes[8].shapes[0].setPoint(1, sf::Vector2f(30, 0));
	m_enemyTypes[8].shapes[0].setPoint(2, sf::Vector2f(30, 80));
	m_enemyTypes[8].shapes[0].setFillColor(sf::Color(191,97,106));
	m_enemyTypes[8].shapes.push_back(sf::ConvexShape(3));
	m_enemyTypes[8].shapes[1].setPoint(0, sf::Vector2f(50, 0));
	m_enemyTypes[8].shapes[1].setPoint(1, sf::Vector2f(80, 40));
	m_enemyTypes[8].shapes[1].setPoint(2, sf::Vector2f(50, 80));
	m_enemyTypes[8].shapes[1].setFillColor(sf::Color(191,97,106));
	m_enemyTypes[8].width = 80;
	m_enemyTypes[8].height = 80;

	m_enemyTypes[9].viewType = Rook;
	m_enemyTypes[9].shapes.push_back(sf::ConvexShape(4));
	m_enemyTypes[9].shapes[0].setPoint(0, sf::Vector2f(40, 0));
	m_enemyTypes[9].shapes[0].setPoint(1, sf::Vector2f(80, 40));
	m_enemyTypes[9].shapes[0].setPoint(2, sf::Vector2f(40, 80));
	m_enemyTypes[9].shapes[0].setPoint(3, sf::Vector2f(0, 40));
	m_enemyTypes[9].shapes[0].setFillColor(sf::Color(191,97,106));
	m_enemyTypes[9].width = 80;
	m_enemyTypes[9].height = 80;
}

void B_Enemies::Draw(sf::RenderTexture* renderTexture)
{
	for (unsigned int i = 0; i < m_enemies.size(); i++)
	{
		m_enemies[i].Draw(renderTexture);
	}
}

void Enemies::AddEnemy(EnemyProperties* enemyType, sf::Vector2f pos, sf::Vector2f playerPos)
{
	Enemy enemy(enemyType, pos, m_levelManager);
    enemy.InformAboutPlayerPos(playerPos);
	m_enemies.insert(m_enemies.begin(), enemy);
}