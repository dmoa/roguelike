#pragma once

#include <MapUtil/MapUtil.hpp>

#include "Map.hpp"
#include "Enemy.hpp"

class Enemies
{
public:
	Enemies();
	void Setup(sf::Texture* texture, Map* map, int playerX, int playerY);
	void Draw(sf::RenderTexture* renderTexture);
	// RemoveEnemy();
	void Update(int playerX, int playerY, Map* map);
private:
	void AddEnemy(std::string type, sf::Texture* texture, sf::IntRect quad, int tileX, int tileY, Map* map, int playerX, int playerY);
	std::vector<Enemy> m_enemies;
	std::map<int, std::string> m_enemyVersions;
};