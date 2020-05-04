#include "../include/Enemy.hpp"

Enemy::Enemy(sf::Texture* texture, sf::IntRect quad, int tileX, int tileY, int length)
{
	m_texture = texture;
	m_tileX = tileX;
	m_tileY = tileY;
	m_length = length;

	m_sprite.setTextureRect(quad);
	m_sprite.setTexture(*m_texture);
}

void Enemy::Draw(sf::RenderTexture* renderTexture)
{
	renderTexture->draw(m_sprite);
}