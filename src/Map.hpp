#pragma once

#include <TileMapRenderer/TileMapRenderer.hpp>

class Map {
public:
	Map();
	void Update();
	void Draw(sf::RenderTexture* renderTexture);
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	int tileLength;
	TileMapRenderer mapRenderer;
};