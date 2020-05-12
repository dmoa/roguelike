#pragma once

#include "ViewType.hpp"

struct EnemyProperties
{
	std::vector<sf::ConvexShape> shapes;
	VIEW_TYPE viewType;
	int width;
	int height;
};