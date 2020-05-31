#pragma once

#include <map>

#include <MapUtil/MapUtil.hpp>

#include "LevelLoader.hpp"
#include "Tile.hpp"

struct LevelData {
	int width;
	int height;
	std::vector<int> all_tiles;
	std::vector<int> base_tiles;
};

class LevelManager
{
public:
	LevelManager();
	// Draws everything except the player and enemies
	void Draw(sf::RenderTexture* renderTexture);
	void LoadLevel();
	void ReloadRenderer();
	std::vector<sf::Vector2f> GetTileLocations(int ID);
	Tile* GetBaseTile(sf::Vector2f pos);
	bool IsBaseTile(int index);
	int GetTileIndex(sf::Vector2f pos);
	void SetTile(sf::Vector2f pos, int new_id);
	int* GetTileLength();
	int* GetLineThickness();
	int GetLevelWidth();
	int GetLevelHeight();
	int GetLevelTileWidth();
	int GetLevelTileHeight();
private:
	int m_currentLevelIndex;
	LevelData m_currentLevel;
	int m_tileLength;
	int m_lineThickness;
	std::map<int, Tile> m_tileData;
	std::vector<sf::RectangleShape> m_renderedTiles;
	// base_tiles + m_all_tiles?
	// have all the tiles (for loading and saving level files), then have just base tiles (being only for rendering)
	sf::Color m_gridLineColor;
};