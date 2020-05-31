#pragma once

#include "LevelManager.hpp"
#include "Shader.hpp"

class Player
{
public:
	Player();
	void GiveShader(sf::Shader* shader);
	void SetStartingPos(LevelManager* levelManager);
	void Draw(sf::RenderTexture* renderTexture);
	bool Move(int directionX, int directionY);
	void ResetRenderPos();
	sf::Vector2f* GetPos();
	void Reset();
private:
	int m_ID;
	sf::RectangleShape m_drawable;
	int m_playerLength;
	sf::Vector2f m_pos;
	sf::Vector2f m_startingPos;
	LevelManager* m_levelManager;
	sf::Shader* m_shader;
};