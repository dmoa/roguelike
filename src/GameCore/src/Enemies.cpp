#include "../include/Enemies.hpp"

Enemies::Enemies(LevelManager* levelManager)
{
    m_levelManager = levelManager;

	m_enemyTypes.push_back(EnemyProperties());
	m_enemyTypes.back().viewType = Up;
	m_enemyTypes.back().shapes.push_back(sf::ConvexShape(3));
	m_enemyTypes.back().width = 80;
	m_enemyTypes.back().height = 80;
	m_enemyTypes.back().shapes[0].setPoint(0, sf::Vector2f(40, 0));
	m_enemyTypes.back().shapes[0].setPoint(1, sf::Vector2f(80, 80));
	m_enemyTypes.back().shapes[0].setPoint(2, sf::Vector2f(0, 80));
	m_enemyTypes.back().shapes[0].setFillColor(sf::Color(255,0,0));

	m_enemyTypes.push_back(EnemyProperties());
	m_enemyTypes.back().viewType = Down;
	m_enemyTypes.back().shapes.push_back(sf::ConvexShape(3));
	m_enemyTypes.back().width = 80;
	m_enemyTypes.back().height = 80;
	m_enemyTypes.back().shapes[0].setPoint(0, sf::Vector2f(0, 0));
	m_enemyTypes.back().shapes[0].setPoint(1, sf::Vector2f(80, 0));
	m_enemyTypes.back().shapes[0].setPoint(2, sf::Vector2f(40, 80));
	m_enemyTypes.back().shapes[0].setFillColor(sf::Color(255,0,0));

	m_enemyTypes.push_back(EnemyProperties());
	m_enemyTypes.back().viewType = Left;
	m_enemyTypes.back().shapes.push_back(sf::ConvexShape(3));
	m_enemyTypes.back().shapes[0].setPoint(0, sf::Vector2f(0, 40));
	m_enemyTypes.back().shapes[0].setPoint(1, sf::Vector2f(80, 0));
	m_enemyTypes.back().shapes[0].setPoint(2, sf::Vector2f(80, 80));
	m_enemyTypes.back().shapes[0].setFillColor(sf::Color(255,0,0));
	m_enemyTypes.back().width = 80;
	m_enemyTypes.back().height = 80;

	m_enemyTypes.push_back(EnemyProperties());
	m_enemyTypes.back().viewType = Right;
	m_enemyTypes.back().shapes.push_back(sf::ConvexShape(3));
	m_enemyTypes.back().shapes[0].setPoint(0, sf::Vector2f(0, 0));
	m_enemyTypes.back().shapes[0].setPoint(1, sf::Vector2f(0, 80));
	m_enemyTypes.back().shapes[0].setPoint(2, sf::Vector2f(80, 40));
	m_enemyTypes.back().shapes[0].setFillColor(sf::Color(255,0,0));
	m_enemyTypes.back().width = 80;
	m_enemyTypes.back().height = 80;

	m_enemyTypes.push_back(EnemyProperties());
	m_enemyTypes.back().viewType = Vertical;
	m_enemyTypes.back().shapes.push_back(sf::ConvexShape(3));
	m_enemyTypes.back().shapes[0].setPoint(0, sf::Vector2f(40, 0));
	m_enemyTypes.back().shapes[0].setPoint(1, sf::Vector2f(80, 30));
	m_enemyTypes.back().shapes[0].setPoint(2, sf::Vector2f(0, 30));
	m_enemyTypes.back().shapes[0].setFillColor(sf::Color(255,0,0));
	m_enemyTypes.back().shapes.push_back(sf::ConvexShape(3));
	m_enemyTypes.back().shapes[1].setPoint(0, sf::Vector2f(0, 50));
	m_enemyTypes.back().shapes[1].setPoint(1, sf::Vector2f(80, 50));
	m_enemyTypes.back().shapes[1].setPoint(2, sf::Vector2f(40, 80));
	m_enemyTypes.back().shapes[1].setFillColor(sf::Color(255,0,0));
	m_enemyTypes.back().width = 80;
	m_enemyTypes.back().height = 80;

	m_enemyTypes.push_back(EnemyProperties());
	m_enemyTypes.back().viewType = Horizontal;
	m_enemyTypes.back().shapes.push_back(sf::ConvexShape(3));
	m_enemyTypes.back().shapes[0].setPoint(0, sf::Vector2f(0, 40));
	m_enemyTypes.back().shapes[0].setPoint(1, sf::Vector2f(30, 0));
	m_enemyTypes.back().shapes[0].setPoint(2, sf::Vector2f(30, 80));
	m_enemyTypes.back().shapes[0].setFillColor(sf::Color(255,0,0));
	m_enemyTypes.back().shapes.push_back(sf::ConvexShape(3));
	m_enemyTypes.back().shapes[1].setPoint(0, sf::Vector2f(50, 0));
	m_enemyTypes.back().shapes[1].setPoint(1, sf::Vector2f(80, 40));
	m_enemyTypes.back().shapes[1].setPoint(2, sf::Vector2f(50, 80));
	m_enemyTypes.back().shapes[1].setFillColor(sf::Color(255,0,0));
	m_enemyTypes.back().width = 80;
	m_enemyTypes.back().height = 80;

	m_enemyTypes.push_back(EnemyProperties());
	m_enemyTypes.back().viewType = Rook;
	m_enemyTypes.back().shapes.push_back(sf::ConvexShape(4));
	m_enemyTypes.back().shapes[0].setPoint(0, sf::Vector2f(40, 0));
	m_enemyTypes.back().shapes[0].setPoint(1, sf::Vector2f(80, 40));
	m_enemyTypes.back().shapes[0].setPoint(2, sf::Vector2f(40, 80));
	m_enemyTypes.back().shapes[0].setPoint(3, sf::Vector2f(0, 40));
	m_enemyTypes.back().shapes[0].setFillColor(sf::Color(255,0,0));
	m_enemyTypes.back().width = 80;
	m_enemyTypes.back().height = 80;
}

void Enemies::Setup(sf::Vector2f* playerPos)
{
	m_enemies.clear();
    for (unsigned int i = 0; i < m_enemyTypes.size(); i++)
    {
        int tileID = GetID(i);
        for (sf::Vector2f const& pos: m_levelManager->GetTileLocations(tileID, false))
        {
            AddEnemy(i, pos, playerPos);
        }
    }
}

void Enemies::Draw(sf::RenderTexture* renderTexture)
{
	for (unsigned int i = 0; i < m_enemies.size(); i++)
	{
		m_enemies[i].Draw(renderTexture);
	}
}

void Enemies::Update()
{
	for (unsigned int i = 0; i < m_enemies.size(); i++)
	{
		m_enemies[i].ReactToPlayerPos();
        m_enemies[i].Move();
        m_enemies[i].ReactToPlayerPos();
	}
}

void Enemies::Reset()
{
	for (unsigned int i = 0; i < m_enemies.size(); i++)
	{
		m_enemies[i].Reset();
	}
}


std::vector<EnemyProperties>* Enemies::GetEnemyTypes()
{
    return &m_enemyTypes;
}

int Enemies::GetID(int index)
{
	return index + 4;
}

bool Enemies::IsEnemyThere(sf::Vector2f pos)
{
	for (unsigned int i = 0; i < m_enemies.size(); i++)
	{
		if (m_enemies[i].GetPos() == pos)
		{
			return true;
		}
	}
	return false;
}

void Enemies::AddEnemy(int enemyType, sf::Vector2f pos, sf::Vector2f* playerPos)
{
	Enemy enemy(&(m_enemyTypes[enemyType]), pos, m_levelManager, playerPos);
	m_enemies.insert(m_enemies.begin(), enemy);
}

void Enemies::RemoveEnemyIf(sf::Vector2f pos)
{
	for (unsigned int i = 0; i < m_enemies.size(); i++)
	{
		if (m_enemies[i].GetPos() == pos)
		{
			m_enemies.erase(m_enemies.begin() + i);
			return;
		}
	}
}

void Enemies::ChangeEnemy(sf::Vector2f pos, int type)
{
	for (unsigned int i = 0; i < m_enemies.size(); i++)
	{
		if (m_enemies[i].GetPos() == pos)
		{
			m_enemies[i].m_properties = &(m_enemyTypes[type]);
		}
	}
}