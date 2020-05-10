#include "../include/Enemy.hpp"

Enemy::Enemy(EnemyProperties properties, sf::Vector2f pos, int* tileLength)
{
	m_properties = properties;
	m_pos = pos;
	m_destinationPos = pos;
	m_properties.shape.setPosition(m_pos.x * *tileLength, m_pos.y * *tileLength);
}

void Enemy::Draw(sf::RenderTexture* renderTexture)
{
	renderTexture->draw(m_properties.shape);
}

void Enemy::InformAboutPlayerPos(sf::Vector2f playerPos, LevelManager* levelManager)
{
	// destination X and Y are where the enemy is going -> this can be over several turns
	// if the enemy seees the player in view, it sets the player position to the destination
	// this gets overrided if it sees the player in a different position
	if (CanSeePlayer(playerPos, levelManager))
	{
		m_destinationPos.x = playerPos.x;
		m_destinationPos.y = playerPos.y;
	}
}

void Enemy::Move(int* tileLength)
{
	int changeInX = std::clamp(int(m_destinationPos.x - m_pos.x), -1, 1);
	int changeInY = std::clamp(int(m_destinationPos.y - m_pos.y), -1, 1);

	m_pos.x += changeInX;
	m_pos.y += changeInY;

	m_properties.shape.setPosition(m_pos.x * *tileLength, m_pos.y * *tileLength);
}

bool Enemy::CanSeePlayer(sf::Vector2f playerPos, LevelManager* levelManager)
{
	return PathChecker::IsPathClear(m_pos, playerPos, levelManager, m_properties.viewType);
}