#include "../include/Enemies.hpp"

Enemies::Enemies() {}

void Enemies::Setup(Assets* assets, LevelManager* levelManager, sf::Vector2f playerPos)
{
	m_enemyTypes = assets->GetEnemyAssets();
    m_levelManager = levelManager;
    for (auto i = m_enemyTypes->begin(); i != m_enemyTypes->end(); i++)
    {
        int tileID = i->first;
        for (sf::Vector2f const& pos: m_levelManager->GetTileLocations(tileID, true))
        {
            AddEnemy(&((*m_enemyTypes)[tileID]), pos, playerPos);
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

void Enemies::Update(sf::Vector2f playerPos)
{
	for (unsigned int i = 0; i < m_enemies.size(); i++)
	{
		m_enemies[i].InformAboutPlayerPos(playerPos);
        m_enemies[i].Move();
        m_enemies[i].InformAboutPlayerPos(playerPos);
	}
}

void Enemies::AddEnemy(EnemyProperties* enemyType, sf::Vector2f pos, sf::Vector2f playerPos)
{
	Enemy enemy(enemyType, pos, m_levelManager);
    enemy.InformAboutPlayerPos(playerPos);
	m_enemies.insert(m_enemies.begin(), enemy);
}