#include "Enemy.hpp"

class Enemies
{
public:
	Enemies();
	void Draw(sf::RenderTexture* renderTexture);
	void AddEnemy(sf::Texture* texture, sf::IntRect quad, int tileX, int tileY, int length);
	// RemoveEnemy();
private:
	std::vector<Enemy> m_enemies;
};