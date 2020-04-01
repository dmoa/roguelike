class Player
{
public:
	Player();
	void setTexture(sf::Texture* texture);
	void Draw(sf::RenderTexture* renderTexture);
private:
	sf::Texture* m_texture;
	sf::Sprite m_sprite;
};