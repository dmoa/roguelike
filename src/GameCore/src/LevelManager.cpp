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
    m_tileLength = 40;

    m_tileData[0] = Tile("ground", true);
    m_tileData[1] = Tile("wall", false);
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
    m_tiles.clear();
    for (unsigned int i = 0; i < m_currentLevel.tileData.size(); i++)
    {
        int ID = m_currentLevel.tileData[i];
        if (ID < 2)
        {
            sf::RectangleShape shape(sf::Vector2f(m_tileLength, m_tileLength));
            sf::Vector2f pos = MapUtil::GetIntToVector(i, m_currentLevel.width);
            shape.setPosition(pos.x * m_tileLength, pos.y * m_tileLength);
            shape.setOutlineColor(sf::Color(250, 150, 100));
            shape.setOutlineThickness(2);
            if (ID == 0)
            {
                shape.setFillColor(sf::Color(216, 222, 233));
            }
            else if (ID == 1)
            {
                shape.setFillColor(sf::Color(129,161,193));
            }
            m_tiles.push_back(shape);
        }
    }
}

std::vector<sf::Vector2f> LevelManager::GetTileLocations(int ID, bool remove)
{
    bool found = false;
    std::vector<sf::Vector2f> results;
    for (unsigned int i = 0; i < m_currentLevel.tileData.size(); i++)
    {
        if (m_currentLevel.tileData[i] == ID)
        {
            found = true;
            results.push_back(MapUtil::GetIntToVector(i, m_currentLevel.width));
            if (remove)
            {
                m_currentLevel.tileData[i] = 0;
            }
        }
    }
    if (!found)
    {
        throw std::invalid_argument("Tile not found! [LevelManager.cpp]");
    }
    return results;
}

Tile* LevelManager::GetTile(sf::Vector2f pos)
{
    return &m_tileData[m_currentLevel.tileData[MapUtil::GetVectorToInt(pos, m_currentLevel.width)]];
}

// void LevelManager::RemoveTile(int tileX, int tileY, bool reload)
// {
//     m_currentLevel.tileData[tileY * m_currentLevel.width + tileX] = 0;
//     if (reload)
//     {
//         ReloadRenderer();
//     }
// }

// void LevelManager::RemoveTileByIndex(int index, bool reload)
// {
//     m_currentLevel.tileData[index] = 0;
//     if (reload)
//     {
//         ReloadRenderer();
//     }
// }