#include "LevelRenderer.hpp"

LevelRenderer::LevelRenderer(Player* player, Enemies* enemies, LevelManager* levelManager)
{
	m_player = player;
	m_enemies = enemies;
	m_levelManager = levelManager;

	m_levelRender.bg = sf::Color(34, 35, 35);
	m_levelRender.scale = 1;
	m_levelRender.sprite.setScale(m_levelRender.scale, m_levelRender.scale);
	m_levelRender.texture.create(m_levelManager->GetLevelWidth(), m_levelManager->GetLevelHeight()); // change to size of current level
	m_shader.shader.setUniform("screen", sf::Glsl::Vec2(m_levelManager->GetLevelWidth(), m_levelManager->GetLevelHeight()));
}

void LevelRenderer::Draw(sf::RenderWindow* window)
{
    m_levelRender.texture.clear(m_levelRender.bg);

	m_levelManager->DrawTiles(&(m_levelRender.texture));
    m_enemies->Draw(&(m_levelRender.texture));
	m_player->Draw(&(m_levelRender.texture));

	m_levelRender.texture.display();

	m_levelRender.sprite.setTexture(m_levelRender.texture.getTexture());
	m_levelRender.sprite.setPosition((window->getSize().x - m_levelManager->GetLevelWidth() * m_levelRender.scale) / 2, (window->getSize().y - m_levelManager->GetLevelHeight() * m_levelRender.scale) / 2);

	window->draw(m_levelRender.sprite, &m_shader.shader);
}

void LevelRenderer::Update()
{
	m_shader.shader.setUniform("lights[0].position", sf::Glsl::Vec2(((*m_player->GetPos()).x * m_levelManager->GetTileLength()) + 100 / 2, ((*m_player->GetPos()).y * m_levelManager->GetTileLength()) + 100 / 2));
}