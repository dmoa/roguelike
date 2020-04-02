class Player
{
public:
	Player();
	void setTexture(sf::Texture* texture);
	void Draw(sf::RenderTexture* renderTexture);
	void move(int directionX, int directionY, sf::Shader* shader);
private:
	sf::Texture* m_texture;
	sf::Sprite m_sprite;
	int tileX;
	int tileY;
};