#pragma once

#include "State.hpp"

namespace sm
{
	class StateStack
	{
	public:
		StateStack(sf::RenderWindow* window)
		{
			m_window = window;
		}
		void Update(sf::Int32* dt, sf::Event* event)
		{
			m_stateStack[0]->Update(dt, event);
			for (unsigned int i = 0; i < m_stateStack.size(); i++)
			{
				m_stateStack[i]->Draw(m_window);
			}
		}
		void Push(State newState)
		{
			// m_stateStack.push_back(newState);
			newState.Draw(m_window);
		}
		void Pop()
		{
			m_stateStack.erase(m_stateStack.end());
		}
	private:
		std::vector<std::unique_ptr<State> > m_stateStack; // yes it's a vector not a stack. It's so that we can index all values.
		sf::RenderWindow* m_window;
	};
}