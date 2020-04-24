#include <time.h>
#include <math.h>

#include "../include/Map.hpp"

extern const int SCALE;

// get Value at gridData[x][y]
// in player.move pass a pointer to Map Class

Map::Map()
{
	m_tileLength = 8;
    m_mapTileLength = 25;
    m_tilesetWidth = 80;
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
        0,0,24,0,0,0,0,0,0,0,0,0,0,105,0,0,87,0,0,0,0,0,0,0,3,
        0,0,24,82,82,82,82,82,82,82,84,0,15,105,18,0,0,0,100,0,87,0,0,84,0,
        86,0,24,3,0,0,0,0,0,0,0,0,0,107,102,102,109,102,104,0,0,0,0,0,3,
        0,0,24,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,107,104,3,3,3,3,3,
        54,12,34,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,107,102,104,2,3,3,
        3,0,3,50,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,3,3,107,102,104,2,
        3,3,3,0,3,0,0,3,3,0,0,0,0,0,0,0,0,0,3,3,3,3,2,105,3,
        3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,3,0,3,105,3,
        3,3,3,0,0,0,0,0,0,0,3,0,0,0,0,0,0,3,0,3,3,3,3,105,3,
        3,0,3,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,3,5,3,3,105,3,
        3,0,0,0,0,0,20,0,0,0,0,0,0,0,0,0,0,0,0,3,0,3,3,105,3,
        3,3,0,0,0,0,0,0,0,0,0,0,20,0,0,3,3,3,5,3,3,3,3,105,3,
        3,3,3,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,3,0,3,105,3,
        3,3,3,3,3,3,3,3,3,3,3,3,5,5,5,5,3,3,3,3,3,3,3,105,3
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

    // indexes are one less than the map data
    m_tileData[0] =  Tile("empty", "empty", 0, m_tileLength, m_mapTileLength, m_tilesetWidth, true, false);
    m_tileData[1] =  Tile("temp-wall", "wall", 1, m_tileLength, m_mapTileLength, m_tilesetWidth, false, false);
    m_tileData[2] =  Tile("tree-1", "tree", 2, m_tileLength, m_mapTileLength, m_tilesetWidth, false, false);
    m_tileData[3] =  Tile("tree-2", "tree", 3, m_tileLength, m_mapTileLength, m_tilesetWidth, false, false);
    m_tileData[4] =  Tile("tree-3", "tree", 4, m_tileLength, m_mapTileLength, m_tilesetWidth, false, false);


    m_tileData[10] =  Tile("top-left-wall", "wall", 10, m_tileLength, m_mapTileLength, m_tilesetWidth, false, false);
    m_tileData[11] =  Tile("top-wall", "wall", 11, m_tileLength, m_mapTileLength, m_tilesetWidth, false, false);
    m_tileData[13] =  Tile("top-right-wall", "wall", 13, m_tileLength, m_mapTileLength, m_tilesetWidth, false, false);
    m_tileData[20] =  Tile("left-wall", "wall", 4, m_tileLength, m_mapTileLength, m_tilesetWidth, false, false);
    m_tileData[30] =  Tile("bottom-left-wall", "wall", 4, m_tileLength, m_mapTileLength, m_tilesetWidth, false, false);
    m_tileData[33] =  Tile("bottom-right-wall", "wall", 4, m_tileLength, m_mapTileLength, m_tilesetWidth, false, false);
    m_tileData[100] =  Tile("top-left-wall-2", "wall", 4, m_tileLength, m_mapTileLength, m_tilesetWidth, false, false);
    m_tileData[101] =  Tile("top-wall-2", "wall", 4, m_tileLength, m_mapTileLength, m_tilesetWidth, false, false);
    m_tileData[102] =  Tile("tunnel", "passage", 4, m_tileLength, m_mapTileLength, m_tilesetWidth, true, false);
    m_tileData[103] =  Tile("top-right-wall-2", "wall", 4, m_tileLength, m_mapTileLength, m_tilesetWidth, false, false);
    m_tileData[104] =  Tile("side-wall", "wall", 4, m_tileLength, m_mapTileLength, m_tilesetWidth, false, false);
    m_tileData[105] =  Tile("side-open-wall", "wall", 4, m_tileLength, m_mapTileLength, m_tilesetWidth, false, false);
    m_tileData[106] =  Tile("bottom-left-wall-2", "wall", 4, m_tileLength, m_mapTileLength, m_tilesetWidth, false, false);
    m_tileData[107] =  Tile("locked-door", "door", 4, m_tileLength, m_mapTileLength, m_tilesetWidth, false, false);
    m_tileData[108] =  Tile("tunnel-2", "passage", 4, m_tileLength, m_mapTileLength, m_tilesetWidth, false, false);
    m_tileData[109] =  Tile("bottom-right-wall-2", "wall", 4, m_tileLength, m_mapTileLength, m_tilesetWidth, false, false);

    m_tileData[81] =  Tile("arrow-h", "arrow", 81, m_tileLength, m_mapTileLength, m_tilesetWidth, true, false);
    m_tileData[83] =  Tile("arrow-right", "arrow", 83, m_tileLength, m_mapTileLength, m_tilesetWidth, true, false);
    m_tileData[56] =  Tile("sword", "weapon", 56, m_tileLength, m_mapTileLength, m_tilesetWidth, true, true);

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
        throw "Map Renderer could not loaded!";
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

Tile* Map::getTile(int tileX, int tileY)
{
    return &m_tileData[getTileID(tileX, tileY)];
}

int Map::getTileID(int tileX, int tileY)
{
    return m_gridData[tileY * m_mapTileLength + tileX];
}

sf::IntRect Map::getTileQuad(int tileX, int tileY)
{
    return getTile(tileX, tileY)->getQuad();
}

void Map::removeTile(int tileX, int tileY)
{
    m_gridData[tileY * m_mapTileLength + tileX] = 0;
    // reloading map renderer after changing grid data
    if (!m_mapRenderer.load("content/tileset.png", sf::Vector2u(m_tileLength, m_tileLength), m_gridData, m_mapTileLength, m_mapTileLength))
        throw "Map Renderer could not loaded!";
}

std::vector<int> Map::getPlayerStartingPos()
{
    return {m_playerStartingPos % m_mapTileLength, int(m_playerStartingPos / m_mapTileLength)};
}