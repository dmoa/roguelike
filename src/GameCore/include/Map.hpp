#pragma once

#include <TileMapRenderer/TileMapRenderer.hpp>
#include <MapUtil/MapUtil.hpp>

#include "Tile.hpp"

class Map {
public:
	Map();
	void Draw(sf::RenderTexture* renderTexture);
	void ReloadMapRenderer();
	Tile* GetTile(int tileX, int tileY);
	int GetTileID(int tileX, int tileY);
	sf::IntRect GetTileQuad(int tileX, int tileY);
	void RemoveTile(int tileX, int tileY, bool reload);
	void RemoveTileByIndex(int index, bool reload);
	std::vector<int> GetPlayerStartingPos();
	void PlayerMoved(int playerX, int playerY);
	std::vector<int> GetGridData();
	int GetTileLength();
	int GetTilesetWidth();
	int GetMapTileLength();
private:
	std::map<int, Tile> m_tileData;
	std::vector<int> m_gridData;
	TileMapRenderer m_mapRenderer;
	int m_mapTileLength;
	int m_tileLength;
	int m_tilesetWidth;
	int m_playerStartingPos;
};