#pragma once

#include <MapUtil/MapUtil.hpp>

#include "LevelManager.hpp"
#include "EnemyProperties.hpp"
#include "ViewType.hpp"
#include "Enemy.hpp"

class Enemies
{
public:
	Enemies();
	void Setup(LevelManager* levelManager, sf::Vector2f playerPos);
	void Draw(sf::RenderTexture* renderTexture);
	void Update(sf::Vector2f playerPos);
	std::map<int, EnemyProperties> GetEnemyTypes();
private:
	void AddEnemy(EnemyProperties enemyType, sf::Vector2f pos, sf::Vector2f playerPos);
	std::vector<Enemy> m_enemies;
	std::map<int, EnemyProperties> m_enemyTypes;
	LevelManager* m_levelManager;
};