#pragma once

class Shader
{
public:
	Shader();
	void Init(float* windowWidth, float* windowHeight);
	sf::Shader* GetShader();
private:
	sf::Shader m_shader;
	float* m_windowWidth;
	float* m_windowHeight;
};