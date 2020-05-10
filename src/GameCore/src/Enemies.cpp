#include "../include/Enemies.hpp"

Enemies::Enemies()
{
    m_enemyTypes[3].viewType = "vertical";
    m_enemyTypes[3].shape = sf::ConvexShape(3);
    m_enemyTypes[3].shape.setPoint(0, sf::Vector2f(21, 0));
    m_enemyTypes[3].shape.setPoint(1, sf::Vector2f(41, 41));
    m_enemyTypes[3].shape.setPoint(2, sf::Vector2f(0, 41));
    m_enemyTypes[3].shape.setFillColor(sf::Color(191,97,106));

    m_enemyTypes[4].viewType = "horizontal";
    m_enemyTypes[4].shape = sf::ConvexShape(3);
    m_enemyTypes[4].shape.setPoint(0, sf::Vector2f(0, 0));
    m_enemyTypes[4].shape.setPoint(1, sf::Vector2f(0, 41));
    m_enemyTypes[4].shape.setPoint(2, sf::Vector2f(41, 21));
    m_enemyTypes[4].shape.setFillColor(sf::Color(191,97,106));
}

void Enemies::Setup(LevelManager* levelManager, sf::Vector2f playerPos)
{
    for (auto i = m_enemyTypes.begin(); i != m_enemyTypes.end(); i++)
    {
        int tileID = i->first;
        for (sf::Vector2f const& pos: levelManager->GetTileLocations(tileID, true))
        {
            AddEnemy(m_enemyTypes[tileID], pos, levelManager, playerPos);
        }
    }
}

void Enemies::Draw(sf::RenderTexture* renderTexture)
{
	for (unsigned int i = 0; i < m_enemies.size(); i++)
	{
		m_enemies[i].Draw(renderTexture);
	}
}

void Enemies::Update(sf::Vector2f playerPos, LevelManager* levelManager)
{
	for (unsigned int i = 0; i < m_enemies.size(); i++)
	{
		m_enemies[i].InformAboutPlayerPos(playerPos, levelManager);
        m_enemies[i].Move(levelManager->GetTileLength());
        m_enemies[i].InformAboutPlayerPos(playerPos, levelManager);
	}
}

void Enemies::AddEnemy(EnemyProperties enemyType, sf::Vector2f pos, LevelManager* levelManager, sf::Vector2f playerPos)
{
	Enemy enemy(enemyType, pos, levelManager->GetTileLength());
    enemy.InformAboutPlayerPos(playerPos, levelManager);
	m_enemies.insert(m_enemies.begin(), enemy);
}