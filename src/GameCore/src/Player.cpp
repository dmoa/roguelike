#include "../include/Player.hpp"

extern const int GAME_WIDTH;
extern const int GAME_HEIGHT;
extern const int SCALE;

Player::Player()
{
	m_playerLength = 8;
	m_tileX = 12;
	m_tileY = 12;
	m_sprite.setPosition(m_tileX * m_playerLength, m_tileY * m_playerLength);
	m_sprite.setTextureRect(sf::Rect(32, 8, m_playerLength, m_playerLength));
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

void Player::move(int directionX, int directionY, sf::Shader* shader, Map* map)
{
	int possiblePosX = m_tileX + directionX;
	int posibblePosY = m_tileY + directionY;

	if (map->getTileID(possiblePosX, possiblePosX) == 0)
	{
		m_tileX = possiblePosX;
		m_tileY = posibblePosY;

		int newPosX = m_tileX * m_playerLength;
		int newPosY = m_tileY * m_playerLength;

		m_sprite.setPosition(newPosX, newPosY);
		// + half the player length to align the shader with the middle of the sprite
		shader->setUniform("lights[0].position", sf::Glsl::Vec2((newPosX + m_playerLength / 2) * SCALE, (newPosY + m_playerLength / 2) * SCALE));
	}
}