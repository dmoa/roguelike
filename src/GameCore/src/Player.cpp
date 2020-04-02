#include "../include/Player.hpp"

extern const int GAME_WIDTH;
extern const int GAME_HEIGHT;

Player::Player()
{
	tileX = 13;
	tileY = 13;
	m_sprite.setPosition(GAME_WIDTH / 2, GAME_HEIGHT / 2);
	m_sprite.setTextureRect(sf::Rect(32, 8, 8, 8));
}

void Player::setTexture(sf::Texture* texture)
{
	m_texture = texture;
	m_sprite.setTexture(*m_texture, false);
}

void Player::Draw(sf::RenderTexture* renderTexture)
{
	renderTexture->draw(m_sprite);
}

void Player::move(int directionX, int directionY)
{
	tileX += directionX;
	tileY += directionY;
	m_sprite.setPosition(tileX * 8, tileY * 8);
}