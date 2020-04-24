#include "../include/Item.hpp"

Item::Item(std::string name, sf::IntRect quad, sf::Texture* texture, int itemPos)
{
	m_name = name;
	m_texture = texture;
	m_sprite.setTextureRect(quad);
	m_sprite.setTexture(*m_texture, false);
	m_sprite.setPosition(quad.width * itemPos, 0);
}

void Item::Draw(sf::RenderTexture* renderTexture_noShader)
{
	renderTexture_noShader->draw(m_sprite);
}

std::string Item::getName()
{
	return m_name;
}

void Item::setItemPos(int itemPos)
{
	m_sprite.setPosition(m_sprite.getLocalBounds().width * itemPos, 0);
}