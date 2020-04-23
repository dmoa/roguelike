#pragma once

#include <TileMapRenderer/TileMapRenderer.hpp>
#include "Tile.hpp"

class Map {
public:
	Map();
	void Update();
	void Draw(sf::RenderTexture* renderTexture);
	Tile* getTile(int tileX, int tileY);
	int getTileID(int tileX, int tileY);
	// ADD GET TILE QUAD -> should be inside Tile.cpp/.hpp
	std::vector<int> getPlayerStartingPos();
private:
	int m_tileLength;
	std::vector<int> m_gridData;
	int m_mapTileLength;
	TileMapRenderer m_mapRenderer;
	int m_playerStartingPos;
	std::map<int, Tile> m_tileData;
};