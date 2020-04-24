#include "Platform/PlatformHelper.hpp"
#include <StateMachine/StateMachine.hpp>

#include "GameCore/include/Game.hpp"

extern bool QUIT;
bool QUIT = false;

extern const int WINDOW_WIDTH = 1000;
extern const int WINDOW_HEIGHT = 1000;
extern const int GAME_WIDTH = 200;
extern const int GAME_HEIGHT = 200;
extern const int SCALE = WINDOW_WIDTH / GAME_WIDTH;

int main()
{
	PlatformHelper platform;

#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif

	std::shared_ptr<sf::RenderWindow> window = std::make_shared<sf::RenderWindow>();
	float screenScalingFactor = platform.getScreenScalingFactor(window->getSystemHandle());
	window->create(sf::VideoMode(WINDOW_WIDTH * screenScalingFactor, WINDOW_HEIGHT * screenScalingFactor), "");
	platform.setIcon(window->getSystemHandle());

	sm::StateMachine stateMachine(std::make_shared<Game>());

	sf::Clock deltaClock;

	while (!QUIT)
	{

		stateMachine.UpdateStates(deltaClock.restart(), window);

		window->clear();
		stateMachine.DrawStates(window);
		window->display();
	}

	return 0;
}
