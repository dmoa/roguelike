#pragma once

#include "PathChecker.hpp"

#include "EnemyProperties.hpp"
#include "ViewType.hpp"
#include "LevelManager.hpp"
#include "Tile.hpp"

class Enemy
{
public:
	Enemy(EnemyProperties* properties, sf::Vector2f pos, LevelManager* levelManager);
	void Draw(sf::RenderTexture* renderTexture);
	void InformAboutPlayerPos(sf::Vector2f playerPos);
	void Move();
	void SetRenderPos();
	bool CanSeePlayer(sf::Vector2f playerPos);
	void Reset();
private:
	EnemyProperties* m_properties;
	sf::Vector2f m_pos;
	sf::Vector2f m_startingPos;
	sf::Vector2f m_destinationPos;
	LevelManager* m_levelManager;
};