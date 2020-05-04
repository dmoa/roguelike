#pragma once

#include <StateMachine/State.hpp>
#include "Map.hpp"
#include "Player.hpp"
#include "Enemies.hpp"

class Game final: public sm::State {
public:
	Game();
private:
	void Update(sf::Time deltaTime, const std::shared_ptr<sf::RenderWindow>& window);
	void Draw(const std::shared_ptr<sf::RenderWindow>& window);
	sf::RenderTexture m_renderTexture;
	sf::RenderTexture m_renderTexture_noShader;
	sf::Color m_backgroundColor;
	sf::Shader m_shader;
	sf::Sprite m_sprite;
	sf::Sprite m_sprite_noShader;
	sf::Texture m_tileSetTexture;
	Map m_map;
	Player m_player;
	Enemies m_enemies;
};
