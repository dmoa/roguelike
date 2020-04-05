#include "Map.hpp"

class Player
{
public:
	Player();
	void setTexture(sf::Texture* texture);
	void Draw(sf::RenderTexture* renderTexture);
	void move(int directionX, int directionY, sf::Shader* shader, Map* map);
private:
	sf::Texture* m_texture;
	sf::Sprite m_sprite;
	int m_playerLength;
	int m_tileX;
	int m_tileY;
};