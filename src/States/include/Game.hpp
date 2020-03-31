#pragma once

#include <StateMachine/State.hpp>
#include "../../Map.hpp"

class Game final: public sm::State {
public:
	Game(sf::Shader* _shader);
private:
	void Update(sf::Time deltaTime);
	void Draw(const std::shared_ptr<sf::RenderWindow>& window);
	sf::Shader* shader;
	Map map;
	sf::View view;
};
