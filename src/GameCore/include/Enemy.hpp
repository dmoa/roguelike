#pragma once

#include "PathChecker.hpp"

#include "Map.hpp"
#include "Tile.hpp"

class Enemy
{
public:
	Enemy(sf::Texture* texture, sf::IntRect quad, int tileX, int tileY, int mapLength);
	void Draw(sf::RenderTexture* renderTexture);
	void InformAboutPlayerPos(int playerX, int playerY, Map* map);
	void Move(int tileLength);
	bool CanSeePlayer(int playerX, int playerY, Map* map);
private:
	sf::Texture* m_texture;
	sf::Sprite m_sprite;
	int m_tileX;
	int m_tileY;
	int m_destinationX;
	int m_destinationY;
};