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

class Game : public sm::State
{
public:
	Game(float* windowWidth, float* windowHeight);
	void Update(sf::Int32* dt, std::vector<sf::Event>* events);
	void Draw(sf::RenderWindow* window);
private:
	void PlayerMoveAttempt(bool playerDidMove);
	Render m_levelRender;
	float* m_windowWidth;
	float* m_windowHeight;
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