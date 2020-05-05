#include "../include/Enemy.hpp"

Enemy::Enemy(sf::Texture* texture, sf::IntRect quad, int tileX, int tileY, int tileLength)
{
	m_texture = texture;
	m_tileX = tileX;
	m_tileY = tileY;
	m_destinationX = tileX;
	m_destinationY = tileY;

	m_sprite.setTextureRect(quad);
	m_sprite.setTexture(*m_texture);
	m_sprite.setPosition(tileX * tileLength, tileY * tileLength);
}

void Enemy::Draw(sf::RenderTexture* renderTexture)
{
	renderTexture->draw(m_sprite);
}

void Enemy::InformAboutPlayerPos(int playerX, int playerY, Map* map)
{
	// destination X and Y are where the enemy is going -> this can be over several turns
	// if the enemy seees the player in view, it sets the player position to the destination
	// this gets overrided if it sees the player in a different position
	if (CanSeePlayer(playerX, playerY, map))
	{
		printf("found player\n");
		m_destinationX = playerX;
		m_destinationY = playerY;
	}
}

void Enemy::Move(int tileLength)
{
	int changeInY = std::clamp(m_destinationY - m_tileY, -1, 1);
	m_tileY += changeInY;

	m_sprite.setPosition(m_tileX * tileLength, m_tileY * tileLength);
}

bool Enemy::CanSeePlayer(int playerX, int playerY, Map* map)
{
	if (playerX != m_tileX) { return false; }

	for (int i = m_tileY; i < playerY; i++)
	{
		Tile* checkingTile = map->GetTile(m_tileX, i);
		if (!checkingTile->GetCanWalkOver())
		{
			return false;
		}
	}
	return true;
}