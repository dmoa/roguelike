#pragma once

#include "LevelManager.hpp"
#include "EnemyProperties.hpp"
#include "Tile.hpp"

class PathChecker
{
public:
	static bool IsPathClear(sf::Vector2f pos1, sf::Vector2f pos2, LevelManager* levelManager, std::string viewType)
	{
		if (viewType == "vertical")
		{
			return vertical(pos1, pos2, levelManager);
		}
		else if (viewType == "horizontal")
		{
			return horizontal(pos1, pos2, levelManager);
		}
		else if (viewType == "rook")
		{
			return horizontal(pos1, pos2, levelManager) || vertical(pos1, pos2, levelManager);
		}
		else
		{
			throw std::invalid_argument("View Type not valid");
		}
	}
private:
	static bool vertical(sf::Vector2f pos1, sf::Vector2f pos2, LevelManager* levelManager)
	{
		if (pos1.x != pos2.x) { return false; }

		for (int i = std::min(pos1.y, pos2.y); i < std::max(pos1.y, pos2.y); i++)
		{
			Tile* checkingTile = levelManager->GetTile(sf::Vector2f(pos1.x, i), false);
			if (!checkingTile->GetCanWalkOver())
			{
				return false;
			}
		}
		return true;
	}
	static bool horizontal(sf::Vector2f pos1, sf::Vector2f pos2, LevelManager* levelManager)
	{
		if (pos1.y != pos2.y) { return false; }

		for (int i = std::min(pos1.x, pos2.x); i < std::max(pos1.x, pos2.x); i++)
		{
			Tile* checkingTile = levelManager->GetTile(sf::Vector2f(i, pos1.y), false);
			if (!checkingTile->GetCanWalkOver())
			{
				return false;
			}
		}
		return true;
	}
};