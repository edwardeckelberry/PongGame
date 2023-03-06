//
// Created by Edward Eckelberry on 1/11/23.
//

#include "Game.h"


void Game::run()
{
    sf::RenderWindow window({1420, 1080, 32}, "Pong");

    Mechanics m;

    while(window.isOpen())
    {
        sf::Event event;

        //if the red button or escape key is hit,
        //close the program window
        while (window.pollEvent(event)) {
            if (sf::Event::Closed == event.type)
                window.close();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }

        window.clear();
//        window.draw(m);

        window.display();
    }
}

