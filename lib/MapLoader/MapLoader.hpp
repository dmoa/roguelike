#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>


class MapLoader
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
			throw std::invalid_argument("Path to file not found. [MapLoader.hpp]");
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
private:
	static inline std::string m_seperator = ",";
};