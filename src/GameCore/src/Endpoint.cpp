#include "../include/Endpoint.hpp"

Endpoint::Endpoint(LevelManager* levelManager)
{
	m_levelManager = levelManager;

	m_shape.setRadius(40);
	m_shape.setPointCount(5);
	m_shape.setOrigin(40, 40);
	m_shape.setFillColor(sf::Color::Green);
	m_angle = 0;
	m_ID = 3;

	m_pos = m_levelManager->GetTileLocations(m_ID, true)[0];
}

void Endpoint::Draw(sf::RenderTexture* renderTexture)
{
	renderTexture->draw(m_shape);
}

void Endpoint::Update(float dt)
{
	m_shape.setPosition(m_levelManager->CenterTile(m_pos));

	m_angle += dt * 40;
	if (m_angle > 360) { m_angle = remainder(360, m_angle); }
	m_shape.setRotation(m_angle);
}