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
	bool tileIsType(int tileX, int tileY, std::string type);
	std::vector<int> getPlayerStartingPos();
private:
	int m_tileLength;
	std::vector<int> m_gridData;
	std::vector<std::string> m_tileNames;
	int m_mapTileLength;
	TileMapRenderer m_mapRenderer;
	int m_playerStartingPos;
};