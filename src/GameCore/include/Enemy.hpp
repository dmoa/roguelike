#pragma once

#include "PathChecker.hpp"

#include "Map.hpp"
#include "Tile.hpp"

class Enemy
{
public:
	Enemy(std::string type, sf::Texture* texture, sf::IntRect quad, int tileX, int tileY, int tileLength);
	void Draw(sf::RenderTexture* renderTexture);
	void InformAboutPlayerPos(int playerX, int playerY, Map* map);
	void Move(int tileLength);
	bool CanSeePlayer(int playerX, int playerY, Map* map);
private:
	std::string m_type;
	sf::Texture* m_texture;
	sf::Sprite m_sprite;
	int m_tileX;
	int m_tileY;
	int m_destinationX;
	int m_destinationY;
};