#pragma once

#include "Shader.hpp"
#include "../../LevelCore/LevelManager.hpp"
#include "Player.hpp"
#include "Enemies.hpp"
#include "Endpoint.hpp"

#include "../../Render.hpp"

class Game
{
public:
	Game(sf::RenderWindow* window, LevelManager* levelManager, Player* player, Enemies* enemies, Endpoint* endpoint);
	void Update(std::vector<sf::Event>* events, sf::Int32* dt);
	void Draw();
	void ResetLevel();
private:
	void PlayerMoveAttempt(bool playerDidMove);
	Render m_levelRender;
	sf::RenderWindow* m_window;
	// sf::RenderTexture m_renderTexture_noShader;
	sf::Color m_backgroundColor;
	Shader m_shader;
	sf::Sprite m_sprite;
	sf::Sprite m_sprite_noShader;
	sf::Texture m_tileSetTexture;
	LevelManager* m_levelManager;
	Player* m_player;
	Enemies* m_enemies;
	Endpoint* m_endpoint;
};