#pragma once

#include <MapUtil/MapUtil.hpp>

#include "LevelManager.hpp"
#include "EnemyProperties.hpp"
#include "ViewType.hpp"
#include "Enemy.hpp"

class Enemies
{
public:
	Enemies(LevelManager* levelManager);
	void Setup(sf::Vector2f* playerPos);
	void Draw(sf::RenderTexture* renderTexture);
	void Update();
	std::vector<EnemyProperties>* GetEnemyTypes();
	void Reset();
	int GetID(int index);
	void ChangeEnemy(sf::Vector2f pos, int type); // for level editor only
private:
	void AddEnemy(int enemyType, sf::Vector2f pos, sf::Vector2f* playerPos);
	std::vector<Enemy> m_enemies;
	std::vector<EnemyProperties> m_enemyTypes;
	LevelManager* m_levelManager;
};