#pragma once

class Shader
{
public:
	Shader();
	sf::Shader* GetShader();
private:
	sf::Shader m_shader;
};