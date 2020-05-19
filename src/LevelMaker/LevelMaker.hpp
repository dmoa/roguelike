#pragma once

#include <StateMachine/State>

#include "../Assets.hpp"
#include "../../GameCore/include/LevelManager.hpp"
#include "../../GameCore/include/EnemyProperties.hpp"
#include "../../GameCore/include/Enemies.hpp"
#include "../../GameCore/include/Player.hpp"

class LevelMaker : public sm::State
{
public:
private:
	Game(float* windowWidth, float* windowHeight);
	sm::ReturnCode Update(sf::Int32* dt, std::vector<sf::Event>* events);
	void Draw(sf::RenderWindow* window);
	sf::Vector2f m_playerPos;
	std::vector<Enemy> m_enemies;
};