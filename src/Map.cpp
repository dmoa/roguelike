#include "Map.hpp"

extern const int SCALE;

Map::Map()
{
	m_texture.loadFromFile("content/tileset.png");
	m_sprite.setTexture(m_texture);
}

// Update function contains state-specific logic
void Map::Update()
{
}

// Draw function contains SFML draw calls
void Map::Draw(sf::RenderTexture* renderTexture)
{
	renderTexture->draw(m_sprite);
}

sf::Sprite Map::getSprite()
{
	return m_sprite;
}