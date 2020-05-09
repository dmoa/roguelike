#pragma once

#include <map>

#include <MapUtil/MapUtil.hpp>

#include "LevelLoader.hpp"
#include "Tile.hpp"

struct LevelData {
	int width;
	int height;
	std::vector<int> tileData;
};

class LevelManager
{
public:
	LevelManager();
	// Draws everything except the player and enemies
	void Draw(sf::RenderTexture* renderTexture);
	void ReloadRenderer();
	std::vector<sf::Vector2f> GetTileLocations(int ID, bool remove);
	Tile* GetTile(sf::Vector2f pos);
	int* GetTileLength();
	int* GetLineThickness();
private:
	int m_currentLevelIndex;
	LevelData m_currentLevel;
	int m_tileLength;
	std::map<int, Tile> m_tileData;
	std::vector<sf::RectangleShape> m_tiles;
	int m_lineThickness;
	std::vector<sf::RectangleShape> m_gridLines;
	sf::Color m_gridLineColor;
	sf::Color m_emptyTileColor;
	sf::Color m_wallTileColor;
};