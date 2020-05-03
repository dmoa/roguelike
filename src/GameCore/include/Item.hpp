#pragma once

class Item
{
	public:
		Item(std::string name, sf::IntRect quad, sf::Texture* tilesetTexture, int itemPos);
		void Draw(sf::RenderTexture* renderTexture);
		std::string GetName();
		void SetItemPos(int itemPos);
	private:
		std::string m_name;
		sf::Texture* m_texture;
		sf::Sprite m_sprite;
};