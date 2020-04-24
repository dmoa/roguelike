#pragma once

#include "Map.hpp"
#include "Inventory.hpp"

class Player
{
public:
	Player();
	void setTextures(sf::Texture* texture);
	void Draw(sf::RenderTexture* renderTexture, sf::RenderTexture* renderTexture_noShader);
	void move(int directionX, int directionY, sf::Shader* shader, Map* map);
	void setStartingPos(Map* map, sf::Shader* shader);
private:
	sf::Texture* m_texture;
	sf::Sprite m_sprite;
	int m_playerLength;
	int m_tileX;
	int m_tileY;
	Inventory m_inventory;
};