#pragma once

#include "GameCore/include/LevelManager.hpp"
#include "GameCore/include/EnemyProperties.hpp"
#include "GameCore/include/Enemies.hpp"
#include "GameCore/include/Player.hpp"

#include "../Render.hpp"

class LevelMaker
{
public:
	LevelMaker(float* windowWidth, float* windowHeight, LevelManager* levelManager, Player* player, Enemies* enemies);
	void Draw(sf::RenderWindow* window);
	// void Update(sf::Time deltaTime, const std::shared_ptr<sf::RenderWindow>& window);
private:
	Render m_levelRender;
	float* m_windowWidth;
	float* m_windowHeight;
	LevelManager* m_levelManager;
	Player* m_player;
	Enemies* m_enemies;
};