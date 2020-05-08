#pragma once

#include <vector>

class MapUtil
{
public:
	static int GetTileLocation(std::vector<int> data, int tileID)
	{
		for (unsigned int i = 0; i < data.size(); i++)
		{
			if (data[i] == tileID)
        	{
            	return i;
        	}
		}
		return -1;
	}
	static sf::Vector2f GetIntToVector(int index, int mapTileWidth)
	{
		return sf::Vector2f(index % mapTileWidth, floor(index / mapTileWidth));
	}
	static int GetVectorToInt(sf::Vector2f pos, int mapTileWidth)
	{
		return pos.y * mapTileWidth + pos.x;
	}
};