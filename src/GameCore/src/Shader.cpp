#include "../include/Shader.hpp"

extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;

Shader::Shader()
{
	if (!m_shader.loadFromFile("content/shader.frag", sf::Shader::Fragment))
	{
		throw "Shader not available!";
	}
	m_shader.setUniform("screen", sf::Glsl::Vec2(WINDOW_WIDTH, WINDOW_HEIGHT));
	m_shader.setUniform("num_lights", 1);
	m_shader.setUniform("lights[0].diffuse", sf::Glsl::Vec3(1.0, 1.0, 1.0));
	m_shader.setUniform("lights[0].power", 20.0f);
}

sf::Shader* Shader::GetShader()
{
	return &m_shader;
}