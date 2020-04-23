#pragma once

class Inventory
{
public:
	Inventory();
	void setTileset(sf::Texture* texture);
	void Draw(sf::RenderTexture* renderTexture);
	void addItem(std::string name, sf::Rect quad);
	void removeItem(std::string name, sf::Rect quad);
private:
	sf::texture tilesetTexture;
	std::vector<std::string> m_items;
}