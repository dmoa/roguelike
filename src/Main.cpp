#include "Platform/PlatformHelper.hpp"
#include "StateMachine/State.hpp"
#include "StateMachine/StateMachine.hpp"

#include "States/Game.hpp"

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
	window->create(sf::VideoMode(500.0f * screenScalingFactor, 500.0f * screenScalingFactor), "SFML works!");
	platform.setIcon(window->getSystemHandle());

	sf::Shader mainShader;
	if (!mainShader.loadFromFile("content/shader.frag", sf::Shader::Fragment))
	{
		throw "Shaders not available!";
	}
	mainShader.setUniform("screen", sf::Glsl::Vec2(500.0f, 500.0f));
	mainShader.setUniform("num_lights", 1);
	mainShader.setUniform("lights[0].position", sf::Glsl::Vec2(250.0f, 250.0f));
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
