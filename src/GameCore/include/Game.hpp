#pragma once

#include "Shader.hpp"
#include "../../LevelCore/LevelManager.hpp"
#include "../../LevelCore/LevelRenderer.hpp"
#include "Player.hpp"
#include "Enemies.hpp"
#include "Endpoint.hpp"

class Game
{
public:
	Game(sf::RenderWindow* window, LevelRenderer* levelRenderer, LevelManager* levelManager, Player* player, Enemies* enemies, Endpoint* endpoint);
	void Update(std::vector<sf::Event>* events, float* dt);
	void Draw();
	void ResetLevel();
private:
	void PlayerMoveAttempt(bool playerDidMove);
	sf::RenderWindow* m_window;
	LevelRenderer* m_levelRenderer;
	sf::Color m_backgroundColor;
	sf::Sprite m_sprite;
	sf::Sprite m_sprite_noShader;
	sf::Texture m_tileSetTexture;
	LevelManager* m_levelManager;
	Player* m_player;
	Enemies* m_enemies;
	Endpoint* m_endpoint;
};