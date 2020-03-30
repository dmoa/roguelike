#pragma once

class Game final: public sm::State {
public:
	// Constructor initialises the state
	Game(sf::Shader* shader);
private:
	void Update(sf::Time deltaTime);
	void Draw(const std::shared_ptr<sf::RenderWindow>& window);
	sf::RectangleShape _rectangle;
	sf::Texture shapeTexture;
	sf::Shader* shader;
};