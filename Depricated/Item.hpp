#pragma once

class Item
{
	public:
		Item(std::string name, sf::IntRect quad, sf::Texture* tilesetTexture, int itemPos);
		void Draw(sf::RenderTexture* renderTexture);
		void SetItemPos(int itemPos);
		std::string GetName();
	private:
		std::string m_name;
		sf::Texture* m_texture;
		sf::Sprite m_sprite;
};