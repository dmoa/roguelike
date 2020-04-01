#pragma once

#include <StateMachine/State.hpp>
#include "../../Map.hpp"

class Game final: public sm::State {
public:
	Game(sf::Shader* _shader);
private:
	void Update(sf::Time deltaTime);
	void Draw(const std::shared_ptr<sf::RenderWindow>& window);
	sf::Shader* m_shader;
	Map m_map;
	sf::View m_view;
	sf::RenderTexture m_renderTexture;
	sf::Sprite m_sprite;
};
