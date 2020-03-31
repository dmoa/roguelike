#pragma once

#include <TileMap/TileMap.hpp>

class Map {
public:
	Map();
	void Update();
	void Draw(const std::shared_ptr<sf::RenderWindow>& window, sf::Shader* shader);
	TileMap tilemap;
private:
};