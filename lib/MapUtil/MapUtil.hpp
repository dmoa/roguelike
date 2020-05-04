#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>


class MapUtil
{
public:
	static std::vector<int> LoadMap(std::string path)
	{
		std::string valid_data;

		// Reading the file and adding valid data -> anything without tags

		std::ifstream file;
		file.open(path);
		if (file.is_open()) {
			std::string line;
			while (std::getline(file, line)) {
				bool isMapData = true;
				std::size_t found = line.find_first_of("<");
				while (found!=std::string::npos)
				{
					found=line.find_first_of("<",found+1);
					isMapData = false;
					}
					if (isMapData)
					{
						valid_data += line;
					}
			}
			file.close();
		} else
		{
			throw std::invalid_argument("Path to file not found. [MapUtil.hpp]");
		}

		// filtering out commas and converting the string vector into an int vector

		std::vector<int> results;

		size_t pos = 0;
		std::string token;
		while ((pos = valid_data.find(m_seperator)) != std::string::npos) {
			token = valid_data.substr(0, pos);
			results.push_back(atoi(token.c_str()));
			valid_data.erase(0, pos + m_seperator.length());
		}

		return results;

	}
	static std::vector<int> GetShiftedData(std::vector<int> data, int shift)
	{
		for (unsigned int i = 0; i < data.size(); i++)
    	{
			data[i] = data[i] > 0 ? data[i] + shift: 0;
		}
		return data;
	}
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
	static std::vector<int> GetIntToVector(int index, int mapTileWidth, int mapTileHeight)
	{
		return {index % mapTileWidth, int(index / mapTileHeight)};
	}
private:
	static inline std::string m_seperator = ",";
};