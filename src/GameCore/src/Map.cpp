#include <time.h>

#include "../include/Map.hpp"

extern const int SCALE;

// get Value at gridData[x][y]
// in player.move pass a pointer to Map Class

Map::Map()
{
	m_tileLength = 8;
    m_mapTileLength = 25;
    m_gridData =
    {
        0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 2, 2, 2,
        1, 1, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2,
        0, 1, 0, 0, 2, 0, 2, 2, 2, 0, 1, 1, 1, 0, 0, 0, 1, 2, 2, 2, 2, 2, 2, 2, 2,
        0, 1, 1, 0, 2, 2, 2, 0, 0, 0, 1, 1, 1, 2, 0, 0, 1, 2, 2, 2, 2, 2, 2, 2, 2,
        0, 0, 1, 0, 2, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0, 1, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 0, 1, 0, 2, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
        0, 0, 1, 0, 2, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
		0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 2, 2, 2,
        1, 1, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2,
        0, 1, 0, 0, 2, 0, 2, 2, 2, 0, 1, 0, 1, 0, 0, 0, 1, 2, 2, 2, 2, 2, 2, 2, 2,
        0, 1, 1, 0, 2, 2, 2, 0, 0, 0, 1, 0, /*center tile */0, 2, 0, 0, 1, 2, 2, 2, 2, 2, 2, 2, 2,
        0, 0, 1, 0, 2, 0, 2, 2, 0, 0, 1, 0, 1, 1, 2, 0, 1, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 0, 1, 0, 2, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
        0, 0, 1, 0, 2, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
		0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 2, 2, 2,
        1, 1, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2,
        0, 1, 0, 0, 2, 0, 2, 2, 2, 0, 1, 1, 1, 0, 0, 0, 1, 2, 2, 2, 2, 2, 2, 2, 2,
        0, 1, 1, 0, 2, 2, 2, 0, 0, 0, 1, 1, 1, 2, 0, 0, 1, 2, 2, 2, 2, 2, 2, 2, 2,
        0, 0, 1, 0, 2, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0, 1, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 0, 1, 0, 2, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
        0, 0, 1, 0, 2, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
		0, 0, 1, 0, 2, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2
    };

    srand((unsigned)time(NULL));
    for (auto &tile : m_gridData)
    {
        if (tile == 2)
        {
            int random = rand() % 3 + 2;
            tile = random;
        }
    }

	if (!m_mapRenderer.load("content/tileset.png", sf::Vector2u(m_tileLength, m_tileLength), m_gridData, m_mapTileLength, m_mapTileLength))
        throw "Map Renderer not loaded!";
}

// Update function contains state-specific logic
void Map::Update()
{
}

// Draw function contains SFML draw calls
void Map::Draw(sf::RenderTexture* renderTexture)
{
	m_mapRenderer.Draw(renderTexture);
}

std::vector<int> Map::getGridData()
{
    return m_gridData;
}

int Map::getMapTileLength()
{
    return m_mapTileLength;
}

int Map::getTileID(int tileX, int tileY)
{
    return m_gridData[m_tileY * mapTileLength + m_tileX];
}