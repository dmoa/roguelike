#pragma once

#include "LevelManager.hpp"

class Player
{
public:
	Player();
	void SetStartingPos(LevelManager* levelManager, sf::Shader* shader);
	void Draw(sf::RenderTexture* renderTexture);
	bool Move(int directionX, int directionY, sf::Shader* shader);
	void ResetRenderPos(sf::Shader* shader);
	sf::Vector2f GetPos();
private:
	int m_ID;
	sf::RectangleShape m_drawable;
	int m_playerLength;
	sf::Vector2f m_pos;
	LevelManager* m_levelManager;
};