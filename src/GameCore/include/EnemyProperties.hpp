#pragma once

#include "ViewType.hpp"

struct EnemyProperties
{
	sf::ConvexShape shape;
	VIEW_TYPE viewType;
	int width;
	int height;
};