//MapRende//main.cpp

#pragma once
#include <SFML/Graphics.hpp>
#include "MapRenderer.h"
using namespace sf;

///we will simply autogenerate tiles
///you can read them from your tilemap class, etc.
void provider(int x, int y, int layer, Color& color, IntRect &src)
{
    //color = Color::Yellow;
    color = Color((x*5)%255, (y*5)%255,50);
    src = IntRect(0,0,1,1);
}

void main()
{
    RenderWindow window(VideoMode(800,600), "Game");
    Clock clock;
    View view = window.getDefaultView();
    Texture texture;
    texture.create(1,1);
    MapRenderer map(&texture, provider);
    Vector2f prev;
    while(window.isOpen())
    {
        float dT = clock.getElapsedTime().asSeconds();
        clock.restart();

        window.clear();
        window.setView(view);

        map.update(window);
        window.draw(map);

        window.display();

        Event event;
        while(window.pollEvent(event))
        {
            Vector2f ms, delta;
            switch(event.type)
            {
            case Event::Closed:
                window.close();
                break;
            case Event::Resized:
                view.setSize(event.size.width, event.size.height);
                view.setCenter(view.getSize() * 0.5f );
                break;
            case Event::MouseMoved:
                ms = Vector2f(event.mouseMove.x, event.mouseMove.y);
                delta = ms - prev;
                if(Mouse::isButtonPressed(Mouse::Button::Left))
                    view.setCenter(view.getCenter() - delta);
                prev = ms;
                break;
            case Event::KeyPressed:
                map.refresh();
                break;
            }
        }
    }
}