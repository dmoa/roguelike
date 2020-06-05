#pragma once

#include <tuple>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

#include "LevelDataStruct.hpp"

class LevelSaver
{
public:
	static void Save(std::string path, bool is_new_file, LevelData levelData)
	{
		if (std::remove(path.c_str()) != 0) { perror("Error deleting file [LevelSaver.hpp]"); } else { printf("Deleted file\n"); }

		std::ofstream file(path);
		if (!is_new_file && !file.is_open()) { throw std::invalid_argument("Path to file not found. [LevelSaver.hpp]"); }

		file << std::to_string(levelData.width) << std::endl;
		file << std::to_string(levelData.height) << std::endl;
		printf("size: %i\n", levelData.all_tiles.size());
		for (unsigned int i = 0; i < levelData.all_tiles.size() - 1; i++)
		{
			file <<  std::to_string(levelData.all_tiles[i]) << std::endl;
		}
		file <<  std::to_string(levelData.all_tiles[levelData.all_tiles.size() - 1]);

		file.close();
	}
private:
};