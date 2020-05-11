#include "../include/LevelManager.hpp"

extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;

LevelManager::LevelManager()
{
    m_currentLevelIndex = 1;
    std::string path = "content/levels/" + std::to_string(m_currentLevelIndex);
    std::tuple<int, int, std::vector<int> > loadedData = LevelLoader::GetLevel(path);
    m_currentLevel.width = std::get<0>(loadedData);
    m_currentLevel.height = std::get<1>(loadedData);
    m_currentLevel.tileData = std::get<2>(loadedData);
    m_tileLength = 42;
    m_lineThickness = 1;

    m_gridLineColor = sf::Color(46, 52, 64);

    m_tileData[0] = Tile("ground", sf::Color(216, 222, 233), true);
    m_tileData[1] = Tile("wall", sf::Color(129,161,193), false);
}

// Draws everything except the player and enemies
void LevelManager::Draw(sf::RenderTexture* renderTexture)
{
	for (unsigned int i = 0; i < m_tiles.size(); i++)
    {
        renderTexture->draw(m_tiles[i]);
    }
}

void LevelManager::ReloadRenderer()
{
    // grid lines
    m_gridLines.clear();
    // setting render of level objects other than enemy and player
    m_tiles.clear();
    for (unsigned int i = 0; i < m_currentLevel.tileData.size(); i++)
    {
        int ID = m_currentLevel.tileData[i];
        if (ID < 2)
        {
            sf::RectangleShape shape(sf::Vector2f(m_tileLength, m_tileLength));
            sf::Vector2f pos = MapUtil::GetIntToVector(i, m_currentLevel.width);
            shape.setPosition(pos.x * m_tileLength + m_lineThickness, pos.y * m_tileLength + m_lineThickness);
            shape.setFillColor(m_tileData[ID].GetColor());
            shape.setOutlineThickness(- m_lineThickness);
            shape.setOutlineColor(m_gridLineColor);
            m_tiles.push_back(shape);
        }
    }
}

std::vector<sf::Vector2f> LevelManager::GetTileLocations(int ID, bool remove)
{
    std::vector<sf::Vector2f> results;
    for (unsigned int i = 0; i < m_currentLevel.tileData.size(); i++)
    {
        if (m_currentLevel.tileData[i] == ID)
        {
            results.push_back(MapUtil::GetIntToVector(i, m_currentLevel.width));
            if (remove)
            {
                m_currentLevel.tileData[i] = 0;
            }
        }
    }
    return results;
}

Tile* LevelManager::GetTile(sf::Vector2f pos, bool remove)
{
    if (remove) { m_currentLevel.tileData[MapUtil::GetVectorToInt(pos, m_currentLevel.width)] = 0; }
    return &m_tileData[m_currentLevel.tileData[MapUtil::GetVectorToInt(pos, m_currentLevel.width)]];
}

int* LevelManager::GetTileLength()
{
    return &m_tileLength;
}

int* LevelManager::GetLineThickness()
{
    return &m_lineThickness;
}

int LevelManager::GetLevelWidth()
{
    return m_currentLevel.width * m_tileLength + m_lineThickness * 2;
}

int LevelManager::GetLevelHeight()
{
    return m_currentLevel.height * m_tileLength + m_lineThickness * 2;
}

int LevelManager::GetLevelTileWidth()
{
    return m_currentLevel.width;
}

int LevelManager::GetLevelTileHeight()
{
    return m_currentLevel.height;
}