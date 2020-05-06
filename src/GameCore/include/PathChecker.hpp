#pragma once

#include "Map.hpp"
#include "Tile.hpp"

class PathChecker
{
public:
	static bool IsPathClear(int x1, int y1, int x2, int y2, Map* map, std::string viewType)
	{
		if (viewType == "vertical")
		{
			return vertical(x1, y1, x2, y2, map);
		}
		else if (viewType == "horizontal")
		{
			return horizontal(x1, y1, x2, y2, map);
		}
		else
		{
			throw std::invalid_argument("View Type not valid");
		}
	}
private:
	static bool vertical(int x1, int y1, int x2, int y2, Map* map)
	{
		if (x1 != x2) { return false; }

		for (int i = std::min(y1, y2); i < std::max(y1, y2); i++)
		{
			Tile* checkingTile = map->GetTile(x1, i);
			if (!checkingTile->GetCanWalkOver())
			{
				return false;
			}
		}
		return true;
	}
	static bool horizontal(int x1, int y1, int x2, int y2, Map* map)
	{
		if (y1 != y2) { return false; }

		for (int i = std::min(x1, x2); i < std::max(x1, x2); i++)
		{
			Tile* checkingTile = map->GetTile(i, y1);
			if (!checkingTile->GetCanWalkOver())
			{
				return false;
			}
		}
		return true;
	}
};