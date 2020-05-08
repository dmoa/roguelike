#include "../include/Player.hpp"

extern const int WINDOWS_WIDTH;
extern const int WINDOWS_HEIGHT;

Player::Player()
{
	m_ID = 2;
	m_playerLength = 40;
	m_drawable.setSize(sf::Vector2f(m_playerLength, m_playerLength));
	m_drawable.setFillColor(sf::Color::Green);
}

void Player::Draw(sf::RenderTexture* renderTexture)
{
	renderTexture->draw(m_drawable);
}

bool Player::Move(int directionX, int directionY, sf::Shader* shader, LevelManager* levelManager)
{
	sf::Vector2f possiblePos(m_pos.x + directionX, m_pos.y + directionY);

	Tile* tile = levelManager->GetTile(possiblePos);

	if (tile->GetCanWalkOver())
	{
		m_pos = possiblePos;

		ResetRenderPos(shader);

		return true;
	}
	return false;
}

void Player::SetStartingPos(LevelManager* levelManager, sf::Shader* shader)
{
	m_pos = levelManager->GetTileLocations(m_ID)[0];
	ResetRenderPos(shader);
}

void Player::ResetRenderPos(sf::Shader* shader)
{
	int newPosX = m_pos.x * m_playerLength;
	int newPosY = m_pos.y * m_playerLength;

	m_drawable.setPosition(newPosX, newPosY);
	shader->setUniform("lights[0].position", sf::Glsl::Vec2(m_pos.x * m_playerLength + m_playerLength / 2, newPosY + m_playerLength / 2));
}

int Player::GetX()
{
	return m_pos.x;
}

int Player::GetY()
{
	return m_pos.y;
}