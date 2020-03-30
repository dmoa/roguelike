#pragma once

class Game : public sm::State {
public:
	// Constructor initialises the state
	Game();
private:
	void Update(sf::Time deltaTime);
	void Draw(const std::shared_ptr<sf::RenderWindow>& window);
	sf::RectangleShape _rectangle;
};