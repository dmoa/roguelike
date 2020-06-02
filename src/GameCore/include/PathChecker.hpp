#pragma once

#include "../../LevelCore/LevelManager.hpp"
#include "../../LevelCore/Tile.hpp"
#include "EnemyProperties.hpp"
#include "ViewType.hpp"

// The logic is that pos1 is looking for pos2

class PathChecker
{
public:
	static bool IsPathClear(sf::Vector2f pos1, sf::Vector2f pos2, LevelManager* levelManager, VIEW_TYPE viewType)
	{
		switch (viewType)
		{
			case Up:
				return up(pos1, pos2, levelManager);
			case Down:
				return down(pos1, pos2, levelManager);
			case Left:
				return left(pos1, pos2, levelManager);
			case Right:
				return right(pos1, pos2, levelManager);
			case Vertical:
				return up(pos1, pos2, levelManager) || down(pos1, pos2, levelManager);
			case Horizontal:
				return left(pos1, pos2, levelManager) || right(pos1, pos2, levelManager);
			case Rook:
				return up(pos1, pos2, levelManager) || down(pos1, pos2, levelManager) || left(pos1, pos2, levelManager) || right(pos1, pos2, levelManager);
			default:
				throw std::invalid_argument("View Type not valid");
		}
	}
private:
	static bool up(sf::Vector2f pos1, sf::Vector2f pos2, LevelManager* levelManager)
	{
		if (pos1.x != pos2.x) { return false; }
		if (pos1.y < pos2.y) { return false; }

		for (int i = pos2.y; i < pos1.y; i++)
		{
			Tile* checkingTile = levelManager->GetBaseTile(sf::Vector2f(pos1.x, i));
			if (!checkingTile->GetCanWalkOver())
			{
				return false;
			}
		}
		return true;
	}
	static bool down(sf::Vector2f pos1, sf::Vector2f pos2, LevelManager* levelManager)
	{
		if (pos1.x != pos2.x) { return false; }
		if (pos1.y > pos2.y) { return false; }

		for (int i = pos1.y; i < pos2.y; i++)
		{
			Tile* checkingTile = levelManager->GetBaseTile(sf::Vector2f(pos1.x, i));
			if (!checkingTile->GetCanWalkOver())
			{
				return false;
			}
		}
		return true;
	}
	static bool left(sf::Vector2f pos1, sf::Vector2f pos2, LevelManager* levelManager)
	{
		if (pos1.y != pos2.y) { return false; }
		if (pos2.x > pos1.x) { return false; }

		for (int i = pos2.x; i < pos1.x; i++)
		{
			Tile* checkingTile = levelManager->GetBaseTile(sf::Vector2f(i, pos1.y));
			if (!checkingTile->GetCanWalkOver())
			{
				return false;
			}
		}
		return true;
	}
	static bool right(sf::Vector2f pos1, sf::Vector2f pos2, LevelManager* levelManager)
	{
		if (pos1.y != pos2.y) { return false; }
		if (pos2.x < pos1.x) { return false; }

		for (int i = pos1.x; i < pos2.x; i++)
		{
			Tile* checkingTile = levelManager->GetBaseTile(sf::Vector2f(i, pos1.y));
			if (!checkingTile->GetCanWalkOver())
			{
				return false;
			}
		}
		return true;
	}
};