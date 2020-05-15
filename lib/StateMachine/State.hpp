namespace
{
	class State
	{
		private:
			Draw(sf::RenderWindow* window);
			Update(sf::Int32* dt, sf::Event* event);
			// we don't need to pass the window (into update), because we already polled the window for events and filled "event" up
			// with things such as keys pressed, so there's no need to poll again.
			// now we can just cycle through the keypressed events contained inside event.
	};
}