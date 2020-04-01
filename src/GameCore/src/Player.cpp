#include "../include/Player.hpp"

extern const int GAME_WIDTH;
extern const int GAME_HEIGHT;

Player::Player()
{
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