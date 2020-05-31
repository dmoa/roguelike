#include "Platform/PlatformHelper.hpp"
#include "GameCore/include/Game.hpp"
#include "LevelMaker/LevelMaker.hpp"


// temp
// I'm a bad dev
enum States
{
	InGame, LevelEditor, StartingScreen
};

// Init, only for window for now.
inline void InitWindow(sf::RenderWindow* window, float* initial_window_width, float* initial_window_height)
{
	PlatformHelper platform;
	float screenScalingFactor = platform.getScreenScalingFactor(window->getSystemHandle());
	window->setFramerateLimit(60);
	window->create(sf::VideoMode(*initial_window_width * screenScalingFactor, *initial_window_height * screenScalingFactor), "");
	platform.setIcon(window->getSystemHandle());
}
// main loop

inline void Update(sf::RenderWindow* window, bool* QUIT, sf::Clock* deltaClock, States* currentState, Game* game, LevelMaker* levelMaker)
{
	// input
	std::vector<sf::Event> events;
	sf::Event event;
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::KeyPressed:
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					*currentState = (*currentState == InGame) ? LevelEditor : InGame;
					game->ResetLevel();
				}
				else
				{
					events.push_back(event);
				}
				break;
			}
			case sf::Event::Closed:
			{
				*QUIT = true;
				break;
			}
			case sf::Event::Resized:
			{
        		sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
        		window->setView(sf::View(visibleArea)); // game->getRenderWindow()->setView(sf::vView(visibleArea))
				// game->resize(window_width, window_height);
				break;
			}
			default:
			{
				events.push_back(event);
				break;
			}
		}
	}
	// here the event is still filled with keys that were pressed

	// draw & update
	window->clear(sf::Color(46,52,64));
	// sf::Int32 dt =
	deltaClock->restart();

	switch (*currentState)
	{
		case InGame:
			game->Update(&events);
			game->Draw();
			break;
		case LevelEditor:
			levelMaker->Update(&events);
			levelMaker->Draw();

		default:
			break;
	}

	window->display();
}

int main()
{
	// program
	bool QUIT = false;

	// window
	sf::RenderWindow window;
	float initial_window_width = 1000.0;
	float initial_window_height = 1000.0;
	sf::Clock deltaClock;

	// where shit gets real
	InitWindow(&window, &initial_window_width, &initial_window_height);

	// game related
	printf("test1\n");
	LevelManager levelManager;
	printf("test2\n");
	Player player;
	printf("test3\n");
	Enemies enemies(&levelManager);
	printf("test4\n");
	Game game(&window, &levelManager, &player, &enemies);
	printf("test5\n");
	LevelMaker levelMaker(&window, &levelManager, &player, &enemies);
	printf("test6\n");

	// "game" states
	States currentState = InGame;

	while (!QUIT)
	{
		Update(&window, &QUIT, &deltaClock, &currentState, &game, &levelMaker);
	}

	return 0;
}