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
void Init(sf::RenderWindow* window, float* window_width, float* window_height)
{
	PlatformHelper platform;
	float screenScalingFactor = platform.getScreenScalingFactor(window->getSystemHandle());
	window->setFramerateLimit(60);
	window->create(sf::VideoMode(*window_width * screenScalingFactor, *window_height * screenScalingFactor), "");
	platform.setIcon(window->getSystemHandle());
}

// create game->ResizeGlobalDimensions()
// uses the reference giving earlier to resize the window
// means passing less stuff in Update.

// create program.cpp/.hpp

// main loop
void Update(sf::RenderWindow* window, float* window_width, float* window_height, bool* QUIT, sf::Clock* deltaClock, States* currentState, Game* game, LevelMaker* levelMaker)
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
				// sf::RenderWindow* window =
				*window_width = event.size.width;
				*window_height = event.size.height;
        		sf::FloatRect visibleArea(0, 0, *window_width, *window_height);
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
	sf::Int32 dt = deltaClock->restart().asMilliseconds();

	switch (*currentState)
	{
		case InGame:
			game->Update(&dt, &events);
			game->Draw(window);
			break;
		case LevelEditor:
			// levelMaker->Update(&dt, &events);
			levelMaker->Draw(window);

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
	float window_width = 1000.0;
	float window_height = 1000.0;
	sf::Clock deltaClock;

	// game related
	LevelManager levelManager;
	Player player;
	Enemies enemies;
	Game game(&window_width, &window_height, &levelManager, &player, &enemies);
	LevelMaker levelMaker(&window_width, &window_height, &levelManager, &player, &enemies);

	// "game" states
	States currentState = InGame;

	// where shit gets real
	Init(&window, &window_width, &window_height);
	while (!QUIT)
	{
		Update(&window, &window_width, &window_height, &QUIT, &deltaClock, &currentState, &game, &levelMaker);
	}

	return 0;
}