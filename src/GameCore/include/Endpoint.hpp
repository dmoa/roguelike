#pragma once

#include "../../LevelCore/LevelManager.hpp"

class Endpoint
{
public:
	Endpoint(LevelManager* levelManager);
	void Draw(sf::RenderTexture* renderTexture);
	void Update(float* dt);
	sf::Vector2f m_pos;
	int m_ID; // @TODO make const
	float m_angle;
private:
	sf::CircleShape m_shape;
	LevelManager* m_levelManager;
};