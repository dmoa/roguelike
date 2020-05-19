Enemy::Enemy(EnemyProperties* properties, sf::Vector2f pos, LevelManager* levelManager)
{
	m_properties = properties;
	m_pos = pos;
	m_destinationPos = pos;
	m_levelManager = levelManager;
	SetRenderPos();
}

void Enemy::Draw(sf::RenderTexture* renderTexture)
{
	for (auto &shape: (*m_properties).shapes)
	{
		renderTexture->draw(shape);
	}
}

void Enemy::SetRenderPos()
{
	for (unsigned int i = 0; i < (*m_properties).shapes.size(); i++)
	{
		(*m_properties).shapes[i].setPosition(m_pos.x * *m_levelManager->GetTileLength() + (*m_levelManager->GetTileLength() - (*m_properties).width) / 2 + *m_levelManager->GetLineThickness() / 2,
								   	   m_pos.y * *m_levelManager->GetTileLength() + (*m_levelManager->GetTileLength() - (*m_properties).height) / 2 + *m_levelManager->GetLineThickness() / 2);
	}
}