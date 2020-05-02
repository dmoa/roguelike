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
		std::string m_seperator = ",";
		std::string valid_data;

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
						// std::string string_line = std::to_string(line.c_str());
						valid_data += line;
						// std::vector<std::string> line_data = split(line.c_str(), ",");
					}
			}
			file.close();
		} else
		{
			throw std::invalid_argument("Path to file not found. [MapLoader.hpp]");
		}

		std::vector<int> results;

		size_t pos = 0;
		std::string token;
		while ((pos = valid_data.find(m_seperator)) != std::string::npos) {
			token = valid_data.substr(0, pos);
			std::cout << token << std::endl;
			results.push_back(atoi(token.c_str()));
			valid_data.erase(0, pos + m_seperator.length());
		}

		return results;

	}
private:
};

int main()
{
	MapLoader::LoadMap("../../content/roguelike.tmx");
	return 0;
}