#pragma once

class Collision
{
public:
	static bool PointInRect(sf::Vector2f point, sf::IntRect rect)
	{
		return point.x > rect.left && point.x < rect.left + rect.width && point.y > rect.top && point.y < rect.top + rect.height;
	}
};