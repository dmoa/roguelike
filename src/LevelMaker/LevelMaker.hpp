#pragma once

#include <Collision/Collision.hpp>

#include "GameCore/include/LevelManager.hpp"
#include "GameCore/include/EnemyProperties.hpp"
#include "GameCore/include/Enemies.hpp"
#include "GameCore/include/Player.hpp"

#include "../Render.hpp"

enum CursorModes
{
	Drawing, Erase
};

class LevelMaker
{
public:
	LevelMaker(sf::RenderWindow* renderWindow, LevelManager* levelManager, Player* player, Enemies* enemies);
	void Draw();
	void Update(std::vector<sf::Event>* events);
private:
	void UpdateToolsRender();
	std::vector<std::string> Split(std::string str, char delim = '\n');
	Render m_levelRender;
	sf::RenderWindow* m_window;
	LevelManager* m_levelManager;
	Player* m_player;
	Enemies* m_enemies;
	std::map<int, EnemyProperties>* m_enemyTypes;
	CursorModes m_cursorMode;
	int m_selectedItemIndex;
	int m_commonBorder;
	int m_enemySelectorWidth;
	sf::Font m_font;
	sf::Text m_details;
	sf::RectangleShape m_modeSelectorShape;
	sf::RectangleShape m_selectedShapeOutline;
};