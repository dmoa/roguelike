#include "../include/Shader.hpp"

Shader::Shader()
{
	if (!m_shader.loadFromFile("content/shader.frag", sf::Shader::Fragment))
	{
		throw "Shader not available!";
	}
	m_shader.setUniform("screen", sf::Glsl::Vec2(1000, 1000));
	m_shader.setUniform("num_lights", 1);
	m_shader.setUniform("lights[0].diffuse", sf::Glsl::Vec3(0.9, 1.0, 0.9));
	m_shader.setUniform("lights[0].power", 10.0f);
}

sf::Shader* Shader::GetShader()
{
	return &m_shader;
}