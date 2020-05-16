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
		void Update(sf::Int32* dt, std::vector<sf::Event>* events)
		{
			m_stateStack[0]->Update(dt, events);
			for (unsigned int i = 0; i < m_stateStack.size(); i++)
			{
				m_stateStack[i]->Draw(m_window);
			}
		}
		void Push(std::unique_ptr<State>&& newState)
		{
			// moving the newState into the vector from an r value reference
			m_stateStack.push_back(std::move(newState));
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