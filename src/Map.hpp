#pragma once

class Map {
public:
	Map();
	void Update();
	void Draw(sf::RenderTexture* renderTexture);
	sf::Sprite getSprite();
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
};