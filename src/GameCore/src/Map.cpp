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
        3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
        3,3,0,3,3,0,0,3,3,3,3,3,0,0,0,25,28,0,0,25,0,0,0,3,3,
        3,0,0,0,0,0,0,0,0,0,3,0,0,0,3,3,3,3,3,3,3,3,0,3,3,
        3,0,0,0,3,3,0,3,3,0,0,0,25,3,2,2,2,2,2,2,2,3,0,0,3,
        3,0,0,0,0,3,28,0,0,0,3,3,3,3,2,0,0,0,0,0,2,3,0,3,3,
        3,0,3,0,0,0,0,0,3,0,3,3,3,3,2,0,0,0,0,0,2,3,0,68,3,
        3,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,3,3,0,3,
        3,0,0,3,0,0,0,3,3,3,3,0,0,0,0,0,2,2,2,1,86,0,0,3,3,
        12,12,14,3,3,3,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,100,86,3,
        0,0,24,3,0,3,0,0,0,0,0,0,0,0,2,2,0,0,89,0,0,0,0,0,3,
        88,0,24,0,0,57,0,0,0,0,0,0,0,2,0,0,0,0,86,0,88,0,0,0,0,
        0,0,24,0,0,0,0,0,0,0,0,0,0,101,0,0,87,0,0,0,0,0,0,0,3,
        0,0,24,82,82,82,82,82,82,82,84,0,15,105,18,0,0,0,100,0,87,0,0,84,0,
        86,0,24,3,0,0,0,0,0,0,0,0,0,107,102,102,109,102,104,0,0,0,0,0,3,
        0,0,24,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,107,104,3,3,3,3,3,
        54,12,34,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,107,102,104,2,3,3,
        3,0,3,50,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,3,3,107,102,104,2,
        3,3,3,0,3,0,0,3,3,0,0,0,0,0,0,0,0,0,3,3,3,3,2,105,3,
        3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,3,0,3,105,3,
        3,3,3,0,0,0,0,0,0,0,3,0,0,0,0,0,0,3,0,3,3,3,3,105,3,
        3,0,3,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,3,3,3,3,105,3,
        3,0,0,0,0,0,20,0,0,0,0,0,0,0,0,0,0,0,0,3,0,3,3,105,3,
        3,3,0,0,0,0,0,0,0,0,0,0,20,0,0,3,3,3,3,3,3,3,3,105,3,
        3,3,3,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,3,0,3,105,3,
        3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,105,3
    };
    for (int i = 0; i < m_mapTileLength * m_mapTileLength; i++)
    {
        // reshifting grid data due to tiled data being offset, blame tile editor
        m_gridData[i] = m_gridData[i] > 0 ? m_gridData[i] - 1: 0;
        if (m_gridData[i] == 14)
        {
            m_playerStartingPos = i;
            m_gridData[i] = 0;
        }
    }

    m_tileNames = {"empty", "wall", "tree", "tree", "tree"};
    m_tileData[0] =  Tile("empty", true, false);
    m_tileData[1] =  Tile("wall", false, false);
    m_tileData[2] =  Tile("tree", true, false);
    m_tileData[3] = m_tileData[2];
    m_tileData[4] = m_tileData[2];

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

// std::vector<int> Map::getGridData()
// {
//     return m_gridData;
// }

// int Map::getMapTileLength()
// {
//     return m_mapTileLength;
// }

int Map::getTileID(int tileX, int tileY)
{
    return m_gridData[tileY * m_mapTileLength + tileX];
}

bool Map::tileIsType(int tileX, int tileY, std::string type)
{
    return m_tileNames[getTileID(tileX, tileY)] == type;
}

std::vector<int> Map::getPlayerStartingPos()
{
    return {m_mapTileLength % m_playerStartingPos, (m_playerStartingPos - m_mapTileLength % m_playerStartingPos) / m_mapTileLength};
}