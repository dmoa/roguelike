#pragma once

#include "LevelManager.hpp"

class Player
{
public:
	Player();
	void SetTextures(sf::Texture* texture);
	void Draw(sf::RenderTexture* renderTexture);
	bool Move(int directionX, int directionY, sf::Shader* shader, LevelManager* levelManager);
	void SetStartingPos(LevelManager* levelManager, sf::Shader* shader);
	void ResetRenderPos(sf::Shader* shader);
	int GetX();
	int GetY();
private:
	int m_ID;
	sf::RectangleShape m_drawable;
	int m_playerLength;
	sf::Vector2f m_pos;
};