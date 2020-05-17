#pragma once

namespace sm
{
	class State
	{
		public:
			// add constructor here?????
			virtual ~State() = default;
			virtual void Draw(sf::RenderWindow* window) = 0;
			virtual bool Update(sf::Int32* dt, std::vector<sf::Event>* events) = 0;
			// we don't need to pass the window (into update), because we already polled the window for events and filled "event" up
			// with things such as keys pressed, so there's no need to poll again.
			// now we can just cycle through the keypressed events contained inside event.
		private:
	};
}