#include "../include/Enemy.hpp"

Enemy::Enemy(EnemyProperties* properties, sf::Vector2f pos, LevelManager* levelManager, sf::Vector2f* playerPos)
{
	m_properties = properties;
	m_pos = pos;
	m_startingPos = pos;
	m_destinationPos = pos;
	m_levelManager = levelManager;
	m_playerPos = playerPos;
}

void Enemy::Draw(sf::RenderTexture* renderTexture)
{
	sf::ConvexShape iter_shape;
	for (unsigned int i = 0; i < (*m_properties).shapes.size(); i++)
	{
		iter_shape = (*m_properties).shapes[i];
		iter_shape.setPosition(m_pos.x * *m_levelManager->GetTileLength() + (*m_levelManager->GetTileLength() - (*m_properties).width) / 2 + *m_levelManager->GetLineThickness() / 2,
								   	   m_pos.y * *m_levelManager->GetTileLength() + (*m_levelManager->GetTileLength() - (*m_properties).height) / 2 + *m_levelManager->GetLineThickness() / 2);
		renderTexture->draw(iter_shape);
	}
}

void Enemy::InformAboutPlayerPos()
{
	// destination X and Y are where the enemy is going -> this can be over several turns
	// if the enemy seees the player in view, it sets the player position to the destination
	// this gets overrided if it sees the player in a different position
	if (CanSeePlayer())
	{
		m_destinationPos.x = m_playerPos->x;
		m_destinationPos.y = m_playerPos->y;
	}
}

void Enemy::Move()
{
	int changeInX = std::clamp(int(m_destinationPos.x - m_pos.x), -1, 1);
	int changeInY = std::clamp(int(m_destinationPos.y - m_pos.y), -1, 1);

	m_pos.x += changeInX;
	m_pos.y += changeInY;
}

bool Enemy::CanSeePlayer()
{
	printf("path check\n");
	return PathChecker::IsPathClear(m_pos, *m_playerPos, m_levelManager, (*m_properties).viewType);
	printf("path check done\n");
}

void Enemy::Reset()
{
	m_pos = m_startingPos;
	m_destinationPos = m_pos;
	InformAboutPlayerPos();
}

sf::Vector2f Enemy::GetPos()
{
	return m_pos;
}