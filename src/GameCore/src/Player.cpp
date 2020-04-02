#include "../include/Player.hpp"

extern const int GAME_WIDTH;
extern const int GAME_HEIGHT;
extern const int SCALE;

Player::Player()
{
	tileX = 12;
	tileY = 12;
	m_sprite.setPosition(tileX * 8, tileY * 8);
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

void Player::move(int directionX, int directionY, sf::Shader* shader)
{
	tileX += directionX;
	tileY += directionY;

	int newPosX = tileX * 8;
	int newPosY = tileY * 8;

	m_sprite.setPosition(newPosX, newPosY);
	// +4 to align the shader with the middle of the sprite
	shader->setUniform("lights[0].position", sf::Glsl::Vec2((newPosX + 4) * SCALE, (newPosY + 4) * SCALE));
}