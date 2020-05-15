#include "Platform/PlatformHelper.hpp"
#include "GameCore/include/Game.hpp"

// Init, only for window for now.
void Init(sf::RenderWindow* window, int* window_width, int* window_height)
{
	float screenScalingFactor = platform.getScreenScalingFactor(window->getSystemHandle());
	window->setFramerateLimit(60);
	window->create(sf::VideoMode(*window_width * screenScalingFactor, *window_height * screenScalingFactor), "");
	platform.setIcon(window->getSystemHandle());
}

// main loop
void Update(sf::RenderWindow* window, int* window_width, int* window_height, Game* game)
{
	// input
	sf::Event event;
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
			{
				QUIT = true;
				break;
			}
			case sf::Event::Resized:
			{
				window_width = event.size.width;
				window_height = event.size.height;
        		sf::FloatRect visibleArea(0, 0, event.size.width, window_height);
        		window->setView(sf::View(visibleArea));
				game->resize(window_width, window_height);
				break;
			}
		}
	}
	// here the event is still filled with keys that were pressed

	// draw & update
	window->clear(sf::Color(46,52,64));
	sf::Int32 dt = deltaClock.restart().asMilliseconds();

	switch (currentState)
	{
		case InGame:
			game->HandleInput(&event);
			game->Update(&dt, window);
			game->Draw(window);
			break;
		case LevelEditor:
			game->Draw(window);

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
	PlatformHelper platform;
	sf::RenderWindow window;
	float window_width = 1000.0;
	float window_height = 1000.0;

	// game related
	Game game;
	sf::Clock deltaClock;

	// "game" states
	enum States
	{
		InGame, LevelEditor, StartingScreen
	};
	States currentState = InGame;

	// where shit gets real
	Init(&window, &window_width, &window_height);
	while (!QUIT)
	{
		Update(&window, &window_width, &window_height, &game);
	}

	return 0;
}






// the scenarios for storing things in the stack

// menu, game
// game
// victory animation, game
// paused menu, victory animation, game
// level editor, game

// stateMachine->push(game(&window_width, &window_height));
// stateMachine->push(startingMenu());
// presses play
// stateMachine->pop();

// stateMachine->draw() -> gets the top item in the stack -> game->draw(window);
// stateMachine->updateResolution() -> ONLY update the top item
// when you pop another item, then you could update all the resolutions