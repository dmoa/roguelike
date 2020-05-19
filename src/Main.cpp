#include "Platform/PlatformHelper.hpp"

#include <StateMachine/StateStack.hpp>
#include <StateMachine/State.hpp>

#include "Assets.hpp"
#include "GameCore/include/Game.hpp"
#include "Example.hpp"

// Init, only for window for now.
void Init(sf::RenderWindow* window, float* window_width, float* window_height)
{
	PlatformHelper platform;
	float screenScalingFactor = platform.getScreenScalingFactor(window->getSystemHandle());
	window->setFramerateLimit(60);
	window->create(sf::VideoMode(*window_width * screenScalingFactor, *window_height * screenScalingFactor), "");
	platform.setIcon(window->getSystemHandle());
}

// main loop
void Update(sf::RenderWindow* window, float* window_width, float* window_height, sf::Clock* deltaClock, bool* QUIT, sm::StateStack* stateStack)
{
	sf::Int32 dt = deltaClock->restart().asMilliseconds();

	// input
	sf::Event event;
	std::vector<sf::Event> otherEvents; // non core related events passed to state stack
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
			{
				*QUIT = true;
				break;
			}
			case sf::Event::Resized:
			{
				*window_width = event.size.width;
				*window_height = event.size.height;
        		sf::FloatRect visibleArea(0, 0, *window_width, *window_height);
        		window->setView(sf::View(visibleArea));
				break;
			}
			default:
			{
				otherEvents.push_back(event);
				break;
			}
		}
	}
	// here the event is still filled with keys that were pressed and other game event stuff,
	// so we can just pass it to the StateStack

	// draw & update
	window->clear(sf::Color(46,52,64));

	stateStack->Update(&dt, &otherEvents);

	window->display();
}

int main()
{
	// program
	bool QUIT = false;
	sf::Clock deltaClock;

	// window
	sf::RenderWindow window;
	float window_width = 1000.0;
	float window_height = 1000.0;

	// Assets (only enemy and player for now)
	Assets assets;

	// stack
	sm::StateStack stateStack(&window);
	stateStack.Push(std::make_unique<Game>(&window_width, &window_height, &assets));
	stateStack.Push(std::make_unique<Example>());

	// where shit gets real
	Init(&window, &window_width, &window_height);
	while (!QUIT)
	{
		Update(&window, &window_width, &window_height, &deltaClock, &QUIT, &stateStack);
	}

	return 0;
}






// the scenarios for storing things in the stack

// 1 menu -> return false -> pop menu, 0 game
// game

// loadingScreen (we don't have to add any keybindings), game (press escape -> open menu)

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