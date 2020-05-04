#include "../include/Enemy.hpp"

Enemy::Enemy(sf::Texture* texture, sf::IntRect quad, int tileX, int tileY, int tileLength)
{
	m_texture = texture;
	m_tileX = tileX;
	m_tileY = tileY;

	m_sprite.setTextureRect(quad);
	m_sprite.setTexture(*m_texture);
	m_sprite.setPosition(tileX * tileLength, tileY * tileLength);
}

void Enemy::Draw(sf::RenderTexture* renderTexture)
{
	renderTexture->draw(m_sprite);
}

void Enemy::UpdatePos(int playerX, int playerY, Map* map)
{
	int changeInX = std::clamp(playerX - m_tileX, -1, 1);
	int changeInY = std::clamp(playerY - m_tileY, -1, 1);


	Tile* newTile = map->GetTile(m_tileX + changeInX, m_tileY + changeInY);
	if (newTile->GetCanWalkOver())
	{
		m_tileX += changeInX;
		m_tileY += changeInY;
		m_sprite.setPosition(m_tileX * map->GetTileLength(), m_tileY * map->GetTileLength());
	}
}