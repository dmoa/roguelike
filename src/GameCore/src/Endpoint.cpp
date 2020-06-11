#include "../include/Endpoint.hpp"

Endpoint::Endpoint(LevelManager* levelManager)
{
	m_levelManager = levelManager;
	m_shape.setRadius(m_levelManager->GetTileLength() / 2 - m_levelManager->GetLineThickness() * 2);
	m_shape.setPointCount(10);
	m_shape.setFillColor(sf::Color::Green);
	m_ID = 3;
}

void Endpoint::Draw(sf::RenderTexture* renderTexture)
{
	renderTexture->draw(m_shape);
}

void Endpoint::Update()
{
	m_shape.setPosition(m_pos.x * m_levelManager->GetTileLength() + m_levelManager->GetLineThickness(), m_pos.y * m_levelManager->GetTileLength() + m_levelManager->GetLineThickness());
}