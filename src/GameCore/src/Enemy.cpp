#include "../include/Enemy.hpp"

Enemy::Enemy(EnemyProperties properties, sf::Vector2f pos, LevelManager* levelManager)
{
	m_properties = properties;
	m_pos = pos;
	m_destinationPos = pos;
	m_levelManager = levelManager;
	m_properties.shape.setPosition(m_pos.x * *m_levelManager->GetTileLength() + (*m_levelManager->GetTileLength() - m_properties.width) / 2 + *m_levelManager->GetLineThickness() / 2,
								   m_pos.y * *m_levelManager->GetTileLength() + (*m_levelManager->GetTileLength() - m_properties.height) / 2 + *m_levelManager->GetLineThickness() / 2);
}

void Enemy::Draw(sf::RenderTexture* renderTexture)
{
	renderTexture->draw(m_properties.shape);
}

void Enemy::InformAboutPlayerPos(sf::Vector2f playerPos)
{
	// destination X and Y are where the enemy is going -> this can be over several turns
	// if the enemy seees the player in view, it sets the player position to the destination
	// this gets overrided if it sees the player in a different position
	if (CanSeePlayer(playerPos))
	{
		m_destinationPos.x = playerPos.x;
		m_destinationPos.y = playerPos.y;
	}
}

void Enemy::Move()
{
	int changeInX = std::clamp(int(m_destinationPos.x - m_pos.x), -1, 1);
	int changeInY = std::clamp(int(m_destinationPos.y - m_pos.y), -1, 1);

	m_pos.x += changeInX;
	m_pos.y += changeInY;

	m_properties.shape.setPosition(m_pos.x * *m_levelManager->GetTileLength() + (*m_levelManager->GetTileLength() - m_properties.width) / 2 + *m_levelManager->GetLineThickness() / 2,
								   m_pos.y * *m_levelManager->GetTileLength() + (*m_levelManager->GetTileLength() - m_properties.height) / 2 + *m_levelManager->GetLineThickness() / 2);
}

bool Enemy::CanSeePlayer(sf::Vector2f playerPos)
{
	return PathChecker::IsPathClear(m_pos, playerPos, m_levelManager, m_properties.viewType);
}