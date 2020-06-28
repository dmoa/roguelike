#pragma once

#include "../Render.hpp"

#include "LevelManager.hpp"
#include "../GameCore/include/Player.hpp"
#include "../GameCore/include/Enemies.hpp"
#include "../GameCore/include/Shader.hpp"

class LevelRenderer
{
public:
	LevelRenderer(sf::RenderWindow* window, Player* player, Enemies* enemies, LevelManager* levelManager);
	void Draw();
	void Update();
	void ReloadShader();
	sf::FloatRect GetBounds();
	void UpdateRenderBounds();
private:
	Render m_levelRender;
	Shader m_shader;
	sf::RenderWindow* m_window;
	Player* m_player;
	Enemies* m_enemies;
	LevelManager* m_levelManager;
};