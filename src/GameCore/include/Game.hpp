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

class Game final: public sm::State
{
public:
	Game();
private:
	void Update(sf::Time deltaTime, const std::shared_ptr<sf::RenderWindow>& window);
	void Draw(const std::shared_ptr<sf::RenderWindow>& window);
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
