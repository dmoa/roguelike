#pragma once

#include "../GameCore/include/EnemyProperties.hpp"
#include "B_Enemies.hpp"

class B_Enemies
{
public:
	B_Enemies();
	~B_Enemies() = default;
	void Draw(sf::RenderTexture* renderTexture);
private:
	std::vector<Enemy> m_enemies;
	std::map<int, EnemyProperties> m_enemyTypes;
};