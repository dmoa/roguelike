class Enemy
{
public:
	Enemy(sf::Texture* texture, sf::IntRect quad, int tileX, int tileY, int mapLength);
	void Draw(sf::RenderTexture* renderTexture);
private:
	sf::Texture* m_texture;
	sf::Sprite m_sprite;
	int m_tileX;
	int m_tileY;
};