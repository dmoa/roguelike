#pragma once

#include "GameCore/include/EnemyProperties.hpp"
#include "GameCore/include/ViewType.hpp"

class Assets
{
public:
	Assets();
	std::map<int, EnemyProperties>* GetEnemyAssets();
	sf::RectangleShape* GetPlayerAssets();
private:
	std::map<int, EnemyProperties> m_enemyTypes;
	sf::RectangleShape m_playerShape;
};