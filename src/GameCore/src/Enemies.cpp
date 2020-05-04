#include "../include/Enemies.hpp"

Enemies::Enemies() {}

void Enemies::Setup(sf::Texture* texture, Map* map)
{
    for (unsigned int i = 0; i < map->GetGridData().size(); i++)
    {
        if (map->GetGridData()[i] == 24)
        {
            map->RemoveTileByIndex(i, false);

            sf::IntRect quad = MapUtil::GetQuadFromTileID(24, map->GetTilesetWidth(), map->GetTileLength());
            std::vector<int> pos = MapUtil::GetIntToVector(i, map->GetMapTileLength(), map->GetMapTileLength());
            AddEnemy(texture, quad, pos[0], pos[1], map->GetTileLength());
        }
    }
    map->ReloadMapRenderer();
}

void Enemies::Draw(sf::RenderTexture* renderTexture)
{
	for (unsigned int i = 0; i < m_enemies.size(); i++)
	{
		m_enemies[i].Draw(renderTexture);
	}
}

void Enemies::AddEnemy(sf::Texture* texture, sf::IntRect quad, int tileX, int tileY, int tileLength)
{
	Enemy enemy(texture, quad, tileX, tileY, tileLength);
	m_enemies.insert(m_enemies.begin(), enemy);
}

void Enemies::UpdatePos(int playerX, int playerY, Map* map)
{
	for (unsigned int i = 0; i < m_enemies.size(); i++)
	{
		m_enemies[i].UpdatePos(playerX, playerY, map);
	}
}