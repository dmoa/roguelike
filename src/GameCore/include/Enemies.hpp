#pragma once

#include <MapUtil/MapUtil.hpp>

#include "../../LevelCore/LevelManager.hpp"
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
	void Reset();
	std::vector<EnemyProperties>* GetEnemyTypes();
	int GetID(int index);
	bool IsEnemyThere(sf::Vector2f pos);
	void AddEnemy(int enemyType, sf::Vector2f pos, sf::Vector2f* playerPos);
	void RemoveEnemyIf(sf::Vector2f pos);
	void ChangeEnemy(sf::Vector2f pos, int type); // for level editor only
private:
	std::vector<Enemy> m_enemies;
	std::vector<EnemyProperties> m_enemyTypes;
	LevelManager* m_levelManager;
};