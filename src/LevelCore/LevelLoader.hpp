#pragma once

#include <tuple>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

class LevelLoader
{
public:
	static std::tuple<int, int, std::vector<int> > GetLevel(std::string path)
	{
		std::vector<int> gridData;

		int levelWidth = -1;
		int levelHeight = -1;

		std::ifstream file;
		file.open(path);
		if (file.is_open())
		{
			std::string line;
			while (std::getline(file, line))
			{
				int lineAsInt = atoi(line.c_str());

				if (levelWidth == -1)
				{
					levelWidth = lineAsInt;
				}
				else if (levelHeight == -1)
				{
					levelHeight = lineAsInt;
				}
				else
				{
					gridData.push_back(lineAsInt);
				}
			}
			file.close();
		}
		else
		{
			throw std::invalid_argument("Path to file not found. [LevelLoader.hpp]");
		}

		return {levelWidth, levelHeight, gridData};
	}
private:
};