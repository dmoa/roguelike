#pragma once

#include "PathChecker.hpp"

#include "EnemyProperties.hpp"
#include "ViewType.hpp"
#include "LevelManager.hpp"
#include "Tile.hpp"

class Enemy
{
public:
	Enemy(EnemyProperties* properties, sf::Vector2f pos, LevelManager* levelManager, sf::Vector2f* playerPos);
	void Draw(sf::RenderTexture* renderTexture);
	void ReactToPlayerPos();
	void Move();
	bool CanSeePlayer();
	void Reset();
	sf::Vector2f GetPos();
	EnemyProperties* m_properties;
private:
	sf::Vector2f m_pos;
	sf::Vector2f m_startingPos;
	sf::Vector2f m_destinationPos;
	LevelManager* m_levelManager;
	sf::Vector2f* m_playerPos;
};