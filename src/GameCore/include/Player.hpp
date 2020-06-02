#pragma once

#include "../../LevelCore/LevelManager.hpp"
#include "Shader.hpp"

class Player
{
public:
	Player(LevelManager* levelManager);
	void GiveShader(sf::Shader* shader);
	void SetStartingPos(sf::Vector2f pos);
	void Draw(sf::RenderTexture* renderTexture);
	bool Move(int directionX, int directionY);
	void ResetRenderPos();
	int GetID();
	sf::RectangleShape GetDrawable();
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