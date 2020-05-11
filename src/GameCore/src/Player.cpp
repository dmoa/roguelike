#include "../include/Player.hpp"

extern const int WINDOWS_WIDTH;
extern const int WINDOWS_HEIGHT;

Player::Player()
{
	m_ID = 2;
	m_playerLength = 100;
	m_drawable.setSize(sf::Vector2f(m_playerLength, m_playerLength));
	m_drawable.setFillColor(sf::Color::Green);
}

void Player::SetStartingPos(LevelManager* levelManager, sf::Shader* shader)
{
	m_levelManager = levelManager;
	m_pos = levelManager->GetTileLocations(m_ID, true)[0];
	ResetRenderPos(shader);
}

void Player::Draw(sf::RenderTexture* renderTexture)
{
	renderTexture->draw(m_drawable);
}

bool Player::Move(int directionX, int directionY, sf::Shader* shader)
{
	sf::Vector2f possiblePos(m_pos.x + directionX, m_pos.y + directionY);
	if (possiblePos.x > m_levelManager->GetLevelTileWidth() - 1 || possiblePos.y > m_levelManager->GetLevelTileHeight() - 1 || possiblePos.x < 0 || possiblePos.y < 0) { return false; }

	Tile* tile = m_levelManager->GetTile(possiblePos, false);

	if (tile->GetCanWalkOver())
	{
		m_pos = possiblePos;
		ResetRenderPos(shader);

		return true;
	}
	return false;
}

void Player::ResetRenderPos(sf::Shader* shader)
{
	int newPosX = m_pos.x * *m_levelManager->GetTileLength() + *m_levelManager->GetLineThickness();
	int newPosY = m_pos.y * *m_levelManager->GetTileLength() + *m_levelManager->GetLineThickness();

	m_drawable.setPosition(newPosX, newPosY);
	shader->setUniform("lights[0].position", sf::Glsl::Vec2(m_pos.x * m_playerLength + m_playerLength / 2, newPosY + m_playerLength / 2));
}

sf::Vector2f Player::GetPos()
{
	return m_pos;
}