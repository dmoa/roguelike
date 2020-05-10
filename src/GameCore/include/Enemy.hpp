#pragma once

#include "PathChecker.hpp"

#include "EnemyProperties.hpp"
#include "LevelManager.hpp"
#include "Tile.hpp"

class Enemy
{
public:
	Enemy(EnemyProperties properties, sf::Vector2f pos, int* tileLength);
	void Draw(sf::RenderTexture* renderTexture);
	void InformAboutPlayerPos(sf::Vector2f playerPos, LevelManager* levelManager);
	void Move(int* tileLength);
	bool CanSeePlayer(sf::Vector2f playerPos, LevelManager* levelManager);
private:
	EnemyProperties m_properties;
	sf::Vector2f m_pos;
	sf::Vector2f m_destinationPos;
};