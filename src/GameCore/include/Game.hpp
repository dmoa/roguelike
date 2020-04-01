#pragma once

#include <StateMachine/State.hpp>
#include "Map.hpp"
#include "Player.hpp"

class Game final: public sm::State {
public:
	Game(sf::Shader* _shader);
private:
	void Update(sf::Time deltaTime);
	void Draw(const std::shared_ptr<sf::RenderWindow>& window);
	sf::RenderTexture m_renderTexture;
	sf::Color m_backgroundColor;
	sf::Shader* m_shader;
	sf::Sprite m_sprite;

	sf::Texture m_tileSetTexture;
	Map m_map;
	Player m_player;
};
