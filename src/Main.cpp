#include "Platform/PlatformHelper.hpp"
#include <StateMachine/StateMachine.hpp>

#include "States/include/Game.hpp"

extern const float WINDOW_WIDTH = 1000.0;
extern const float WINDOW_HEIGHT = 1000.0;

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
	mainShader.setUniform("lights[0].power", 10.0f);

	sm::StateMachine stateMachine(std::make_shared<Game>(&mainShader));

	sf::Clock deltaClock;

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				stateMachine.ClearAll();
				window->close();
			}
		}

		stateMachine.UpdateStates(deltaClock.restart());
		// Draw states
		window->clear();
		stateMachine.DrawStates(window);
		window->display();
	}

	return 0;
}
