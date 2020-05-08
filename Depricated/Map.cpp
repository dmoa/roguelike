#include <time.h>
#include <math.h>

#include "../include/Map.hpp"

extern const int SCALE;


Map::Map()
{
	m_tileLength = 8;
    m_mapTileLength = 25;
    m_tilesetWidth = 80;
    m_gridData = MapUtil::GetShiftedData(MapUtil::LoadMap("content/roguelike.tmx"), -1);

    m_playerStartingPos = MapUtil::GetTileLocation(m_gridData, 14);
    RemoveTileByIndex(m_playerStartingPos, false);

    // indexes are one less than the map data
    m_tileData[0] =  Tile("empty", "empty", 0, m_tileLength, m_tilesetWidth, true);
    m_tileData[64] =  Tile("tree-1", "tree", 64, m_tileLength, m_tilesetWidth, false);
    m_tileData[65] =  Tile("tree-2", "tree", 65, m_tileLength, m_tilesetWidth, false);
    m_tileData[66] =  Tile("tree-3", "tree", 66, m_tileLength, m_tilesetWidth, false);

    m_tileData[54] =  Tile("gravel", "ground", 54, m_tileLength, m_tilesetWidth, true);
    m_tileData[55] =  Tile("grass", "ground", 55, m_tileLength, m_tilesetWidth, true);

    m_tileData[10] =  Tile("top-left-wall", "wall", 10, m_tileLength, m_tilesetWidth, false);
    m_tileData[11] =  Tile("top-wall", "wall", 11, m_tileLength, m_tilesetWidth, false);
    m_tileData[13] =  Tile("top-right-wall", "wall", 13, m_tileLength, m_tilesetWidth, false);
    m_tileData[20] =  Tile("left-wall", "wall", 4, m_tileLength, m_tilesetWidth, false);
    m_tileData[30] =  Tile("bottom-left-wall", "wall", 4, m_tileLength, m_tilesetWidth, false);
    m_tileData[33] =  Tile("bottom-right-wall", "wall", 4, m_tileLength, m_tilesetWidth, false);
    m_tileData[100] =  Tile("top-left-wall-2", "wall", 4, m_tileLength, m_tilesetWidth, false);
    m_tileData[101] =  Tile("top-wall-2", "wall", 4, m_tileLength, m_tilesetWidth, false);
    m_tileData[102] =  Tile("tunnel", "passage", 4, m_tileLength, m_tilesetWidth, true);
    m_tileData[103] =  Tile("top-right-wall-2", "wall", 4, m_tileLength, m_tilesetWidth, false);
    m_tileData[104] =  Tile("side-wall", "wall", 4, m_tileLength, m_tilesetWidth, false);
    m_tileData[105] =  Tile("side-open-wall", "wall", 4, m_tileLength, m_tilesetWidth, false);
    m_tileData[106] =  Tile("bottom-left-wall-2", "wall", 4, m_tileLength, m_tilesetWidth, false);
    m_tileData[107] =  Tile("locked-door", "door", 4, m_tileLength, m_tilesetWidth, false);
    m_tileData[108] =  Tile("tunnel-2", "passage", 4, m_tileLength, m_tilesetWidth, false);
    m_tileData[109] =  Tile("bottom-right-wall-2", "wall", 4, m_tileLength, m_tilesetWidth, false);

    m_tileData[81] =  Tile("arrow-h", "arrow", 81, m_tileLength, m_tilesetWidth, true);
    m_tileData[73] =  Tile("small-arrow", "arrow", 73, m_tileLength, m_tilesetWidth, true);
    m_tileData[83] =  Tile("arrow-right", "arrow", 83, m_tileLength, m_tilesetWidth, true);
    m_tileData[56] =  Tile("sword", "weapon", 56, m_tileLength, m_tilesetWidth, tru);
    m_tileData[67] =  Tile("key", "key", 67, m_tileLength, m_tilesetWidth, tru);

    // random tree picker
    srand((unsigned)time(NULL));
    for (auto &tile : m_gridData)
    {
        if (tile == 64)
        {
            int random = rand() % 3;
            tile += random;
        }
    }

	if (!m_mapRenderer.load("content/tileset.png", sf::Vector2u(m_tileLength, m_tileLength), m_gridData, m_mapTileLength, m_mapTileLength))
        throw "Map Renderer could not loaded!";
}

void Map::Draw(sf::RenderTexture* renderTexture)
{
	m_mapRenderer.Draw(renderTexture);
}

void Map::ReloadMapRenderer()
{
    if (!m_mapRenderer.load("content/tileset.png", sf::Vector2u(m_tileLength, m_tileLength), m_gridData, m_mapTileLength, m_mapTileLength))
        throw "Map Renderer could not loaded!";
}

Tile* Map::GetTile(int tileX, int tileY)
{
    return &m_tileData[GetTileID(tileX, tileY)];
}

int Map::GetTileID(int tileX, int tileY)
{
    return m_gridData[tileY * m_mapTileLength + tileX];
}

void Map::RemoveTile(int tileX, int tileY, bool reload)
{
    m_gridData[tileY * m_mapTileLength + tileX] = 0;
    // reloading map renderer after changing grid data
    if (reload)
    {
        if (!m_mapRenderer.load("content/tileset.png", sf::Vector2u(m_tileLength, m_tileLength), m_gridData, m_mapTileLength, m_mapTileLength))
            throw "Map Renderer could not loaded!";
    }
}

void Map::RemoveTileByIndex(int index, bool reload)
{
    m_gridData[index] = 0;
    // reloading map renderer after changing grid data
    if (reload)
    {
        if (!m_mapRenderer.load("content/tileset.png", sf::Vector2u(m_tileLength, m_tileLength), m_gridData, m_mapTileLength, m_mapTileLength))
            throw "Map Renderer could not loaded!";
    }
}

std::vector<int> Map::GetPlayerStartingPos()
{
    return MapUtil::GetIntToVector(m_playerStartingPos, m_mapTileLength, m_mapTileLength);
}

std::vector<int> Map::GetGridData()
{
    return m_gridData;
}

int Map::GetTileLength()
{
    return m_tileLength;
}

int Map::GetTilesetWidth()
{
    return m_tilesetWidth;
}

int Map::GetMapTileLength()
{
    return m_mapTileLength;
}