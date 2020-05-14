#pragma once

#include <StateMachine/State.hpp>

#include "Shader.hpp"
#include "LevelManager.hpp"
#include "Player.hpp"
#include "Enemies.hpp"

struct Render
{
	sf::RenderTexture texture;
	sf::Color bg;
	float scale;
	sf::Sprite sprite;
};

class Game
{
public:
	Game();
	void Update(sf::Int32* dt, sf::RenderWindow* window);
	void Draw(sf::RenderWindow* window);
private:
	void PlayerMoveAttempt(bool playerDidMove);
	Render m_levelRender;
	// sf::RenderTexture m_renderTexture_noShader;
	sf::Color m_backgroundColor;
	Shader m_shader;
	sf::Sprite m_sprite;
	sf::Sprite m_sprite_noShader;
	sf::Texture m_tileSetTexture;
	LevelManager m_levelManager;
	Player m_player;
	Enemies m_enemies;
};
