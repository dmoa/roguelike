#include "../include/Shader.hpp"

Shader::Shader() {}

void Shader::Init(float* windowWidth, float* windowHeight)
{
	m_windowWidth = windowWidth;
	m_windowHeight = windowHeight;

	if (!m_shader.loadFromFile("content/shader.frag", sf::Shader::Fragment))
	{
		throw "Shader not available!";
	}
	m_shader.setUniform("screen", sf::Glsl::Vec2(*m_windowWidth, *m_windowHeight));
	m_shader.setUniform("num_lights", 1);
	m_shader.setUniform("lights[0].diffuse", sf::Glsl::Vec3(0.9, 1.0, 0.9));
	m_shader.setUniform("lights[0].power", 40.0f);
}

sf::Shader* Shader::GetShader()
{
	return &m_shader;
}