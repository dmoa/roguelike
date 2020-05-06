#pragma once

#include <MapUtil/MapUtil.hpp>

#include "Map.hpp"
#include "Enemy.hpp"

class Enemies
{
public:
	Enemies();
	void Setup(sf::Texture* texture, Map* map);
	void Draw(sf::RenderTexture* renderTexture);
	// RemoveEnemy();
	void Update(int playerX, int playerY, Map* map);
private:
	void AddEnemy(sf::Texture* texture, sf::IntRect quad, int tileX, int tileY, int mapLength);
	std::vector<Enemy> m_enemies;
	//std::
};