#include "../include/Enemies.hpp"

Enemies::Enemies() {}

void Enemies::Draw(sf::RenderTexture* renderTexture)
{
	for (unsigned int i = 0; i < m_enemies.size(); i++)
	{
		m_enemies[i].Draw(renderTexture);
	}
}

void Enemies::AddEnemy(sf::Texture* texture, sf::IntRect quad, int tileX, int tileY, int length)
{
	Enemy enemy(texture, quad, tileX, tileY, length);
	m_enemies.insert(m_enemies.begin(), enemy);
}