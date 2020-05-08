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
	static std::tuple<int, int, std::vector<int> > GetLevel(std::string path);
private:
};