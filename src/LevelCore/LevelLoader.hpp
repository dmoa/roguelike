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

		int levelWidth;
		int levelHeight;

		std::ifstream file;
		file.open(path);
		if (file.is_open())
		{
			std::string line;

			std::getline(file, line);
			levelWidth = atoi(line.c_str());
			std::getline(file, line);
			levelHeight = atoi(line.c_str());

			std::getline(file, line);
			std::string currentID = "";
			for (unsigned int i = 0; i < line.length(); i++)
			{
				if (line[i] != ',')
				{
					currentID += line[i];
				}
				else
				{
					gridData.push_back(atoi(currentID.c_str()));
					currentID = "";
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



// iterate over file or whatv

// 1st line is width
// 2nd line is height
// 3rd line is the juice stuff

// currentS = ""

// for (blah blah blah over each character in line 3)
// {
// 	if the character is not a ",", then += that character to currentS
// 	but if it is a comnman, then
// 		add currentS (as a int) to the tile data, and set currentS back to ""
// }