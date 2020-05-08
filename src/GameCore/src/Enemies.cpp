// #include "../include/Enemies.hpp"

// Enemies::Enemies()
// {
//     // indexes are accoding to tileID on map
//     m_enemyVersions[24] = "vertical";
//     m_enemyVersions[1] = "horizontal";
//     m_enemyVersions[2] = "rook";
// }

// void Enemies::Setup(sf::Texture* texture, Map* map, int playerX, int playerY)
// {
//     for (unsigned int i = 0; i < map->GetGridData().size(); i++)
//     {
//         int tileID = map->GetGridData()[i];
//         // if the tileID is a enemy tile, make the enemy
//         if (m_enemyVersions.count(tileID) > 0)
//         {
//             map->RemoveTileByIndex(i, false);

//             sf::IntRect quad = MapUtil::GetQuadFromTileID(tileID, map->GetTilesetWidth(), map->GetTileLength());
//             std::vector<int> pos = MapUtil::GetIntToVector(i, map->GetMapTileLength(), map->GetMapTileLength());
//             AddEnemy(m_enemyVersions[tileID], texture, quad, pos[0], pos[1], map, playerX, playerY);
//         }
//     }
//     map->ReloadMapRenderer();
// }

// void Enemies::Draw(sf::RenderTexture* renderTexture)
// {
// 	for (unsigned int i = 0; i < m_enemies.size(); i++)
// 	{
// 		m_enemies[i].Draw(renderTexture);
// 	}
// }

// void Enemies::Update(int playerX, int playerY, Map* map)
// {
// 	for (unsigned int i = 0; i < m_enemies.size(); i++)
// 	{
// 		m_enemies[i].InformAboutPlayerPos(playerX, playerY, map);
//         m_enemies[i].Move(map->GetTileLength());
//         m_enemies[i].InformAboutPlayerPos(playerX, playerY, map);
// 	}
// }

// void Enemies::AddEnemy(std::string type, sf::Texture* texture, sf::IntRect quad, int tileX, int tileY, Map* map, int playerX, int playerY)
// {
// 	Enemy enemy(type, texture, quad, tileX, tileY, map->GetTileLength());
//     enemy.InformAboutPlayerPos(playerX, playerY, map);
// 	m_enemies.insert(m_enemies.begin(), enemy);
// }