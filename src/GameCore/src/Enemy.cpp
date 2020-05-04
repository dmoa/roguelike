#include "../include/Enemy.hpp"

Enemy::Enemy(sf::Texture* texture, sf::IntRect quad, int tileX, int tileY, int mapLength)
{
	m_texture = texture;
	m_tileX = tileX;
	m_tileY = tileY;

	m_sprite.setTextureRect(quad);
	m_sprite.setTexture(*m_texture);
	m_sprite.setPosition(tileX * mapLength, tileY * mapLength);
}

void Enemy::Draw(sf::RenderTexture* renderTexture)
{
	renderTexture->draw(m_sprite);
}