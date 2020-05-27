#pragma once

#include <Collision/Collision.hpp>

#include "GameCore/include/LevelManager.hpp"
#include "GameCore/include/EnemyProperties.hpp"
#include "GameCore/include/Enemies.hpp"
#include "GameCore/include/Player.hpp"

#include "../Render.hpp"

enum CursorModes
{
	Pencil, Eraser
};

class LevelMaker
{
public:
	LevelMaker(sf::RenderWindow* renderWindow, LevelManager* levelManager, Player* player, Enemies* enemies);
	void Draw();
	void Update(std::vector<sf::Event>* events);
private:
	sf::RenderWindow* m_window;
	Render m_levelRender;
	CursorModes m_cursorMode;
	LevelManager* m_levelManager;
	Player* m_player;
	Enemies* m_enemies;
	sf::RectangleShape temp_shape;
};