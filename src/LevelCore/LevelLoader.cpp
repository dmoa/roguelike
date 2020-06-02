#include "LevelLoader.hpp"

std::tuple<int, int, std::vector<int> > LevelLoader::GetLevel(std::string path)
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