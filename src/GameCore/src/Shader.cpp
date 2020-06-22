#include "../include/Shader.hpp"

Shader::Shader()
{
	if (!shader.loadFromFile("content/shader.frag", sf::Shader::Fragment))
	{
		throw "Shader not available!";
	}
	shader.setUniform("screen", sf::Glsl::Vec2(1200, 1000));
	shader.setUniform("num_lights", 1);
	shader.setUniform("lights[0].diffuse", sf::Glsl::Vec3(0.9, 1.0, 0.9));
	shader.setUniform("lights[0].power", 25.0f);
}