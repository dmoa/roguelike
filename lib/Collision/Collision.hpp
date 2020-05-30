#pragma once

class Collision
{
public:
	static bool PointInRect(sf::Vector2f point, sf::RectangleShape rect)
	{
		return point.x > rect.getPosition().x && point.x < rect.getPosition().x + rect.getLocalBounds().width && point.y > rect.getPosition().y && point.y < rect.getPosition().y + rect.getLocalBounds().height;
	}
};