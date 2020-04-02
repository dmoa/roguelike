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
	// in Windows at least, this must be called before creating the window
	float screenScalingFactor = platform.getScreenScalingFactor(window->getSystemHandle());
	// Use the screenScalingFactor
	window->create(sf::VideoMode(WINDOW_WIDTH * screenScalingFactor, WINDOW_HEIGHT * screenScalingFactor), "SFML works!");
	platform.setIcon(window->getSystemHandle());

	sf::Shader mainShader;
	if (!mainShader.loadFromFile("content/shader.frag", sf::Shader::Fragment))
	{
		throw "Shaders not available!";
	}
	mainShader.setUniform("screen", sf::Glsl::Vec2(WINDOW_WIDTH, WINDOW_HEIGHT));
	mainShader.setUniform("num_lights", 1);
	mainShader.setUniform("lights[0].position", sf::Glsl::Vec2(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));
	mainShader.setUniform("lights[0].diffuse", sf::Glsl::Vec3(1.0, 1.0, 1.0));
	mainShader.setUniform("lights[0].power", 2.0f);

	sm::StateMachine stateMachine(std::make_shared<Game>(&mainShader));

	sf::Clock deltaClock;

	while (!QUIT)
	{

		stateMachine.UpdateStates(deltaClock.restart(), window);
		// Draw states
		window->clear();
		stateMachine.DrawStates(window);
		window->display();
	}

	return 0;
}
