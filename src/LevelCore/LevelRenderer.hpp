#pragma once

#include "../Render.hpp"

#include "LevelManager.hpp"
#include "../GameCore/include/Player.hpp"
#include "../GameCore/include/Enemies.hpp"

class LevelRenderer
{
public:
	LevelRenderer(Player* player, Enemies* enemies, LevelManager* levelManager);
	void Draw(sf::RenderWindow* window);
private:
	Render m_levelRender;
	Shader m_shader;
	Player* m_player;
	Enemies* m_enemies;
	LevelManager* m_levelManager;
};