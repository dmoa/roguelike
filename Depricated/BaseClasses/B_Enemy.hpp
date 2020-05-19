#pragma once

#include "PathChecker.hpp"

#include "EnemyProperties.hpp"
#include "ViewType.hpp"

class B_Enemy
{
public:
	B_Enemy(EnemyProperties* properties, sf::Vector2f pos, LevelManager* levelManager);
	void Draw(sf::RenderTexture* renderTexture);
	void SetRenderPos();
private:
	EnemyProperties* m_properties;
	sf::Vector2f m_pos;
	LevelManager* m_levelManager;
};