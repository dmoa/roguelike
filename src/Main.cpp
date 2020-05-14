#include "Platform/PlatformHelper.hpp"

#include "GameCore/include/Game.hpp"

extern bool QUIT;
bool QUIT = false;

float WINDOW_WIDTH = 1000.0;
float WINDOW_HEIGHT = 1000.0;

int main()
{
	PlatformHelper platform;

	sf::RenderWindow window;
	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
	window.setFramerateLimit(60);
	window.create(sf::VideoMode(WINDOW_WIDTH * screenScalingFactor, WINDOW_HEIGHT * screenScalingFactor), "");
	platform.setIcon(window.getSystemHandle());

	Game game;
	sf::Clock deltaClock;

	enum States
	{
		InGame, LevelEditor, StartingScreen
	};
	States currentState = InGame;

	while (!QUIT)
	{
		window.clear(sf::Color(46,52,64));
		sf::Int32 dt = deltaClock.restart().asMilliseconds();

		switch (currentState)
		{
			case InGame:
				game.Draw(&window);
				game.Update(&dt, &window);
				break;

			default:
				break;
		}

		window.display();
	}

	return 0;
}
