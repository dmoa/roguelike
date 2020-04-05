#pragma once

#include <TileMapRenderer/TileMapRenderer.hpp>

class Map {
public:
	Map();
	void Update();
	void Draw(sf::RenderTexture* renderTexture);
	// std::vector<int> getGridData();
	// int getMapTileLength();
	int getTileID(int tileX, int tileY);
private:
	int m_tileLength;
	std::vector<int> m_gridData;
	int m_mapTileLength;
	TileMapRenderer m_mapRenderer;
};