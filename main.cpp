#include <SFML/Graphics.hpp>
#include <iostream>
#include "Nave.h"

int main()
{
    // Initiate simple properties for later use on the creation of the main window
    sf::Vector2u windowDimensions = {720, 720};
    int moveX = 10;

    // Set the configuration on the main window
    sf::RenderWindow window(sf::VideoMode(
                                windowDimensions.x,
                                windowDimensions.y
                            ), "Galaga");
    window.setFramerateLimit(60);

    sf::Texture texturemap;
    if (!texturemap.loadFromFile("assets/images/texturemap.png"))
    {
        // TO-DO: Add logging system
        exit(0);
    }

    // Call the constructor of the Nave
    // class and pass the texture map image and
    // a rectangle with the sprite coordenates
    Nave ship(
            texturemap,
            sf::IntRect(
                sf::Vector2i(0, 0),
                sf::Vector2i(70, 76)
            ),
            window.getSize()
    );

    ///////// Main game loop /////////
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::Resized)
                continue;
            //if(event.type == sf::Event::LostFocus)
            //if(event.type == sf::Event::GainedFocus)
        }

        //////////////////// Get keyboard input /////////////////////
        // Moving the spaceship in the x axis
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            ship.Move(sf::Vector2i(moveX, 0), window.getSize());

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            ship.Move(sf::Vector2i(-moveX, 0), window.getSize());

        // Clear the window and draw and display everything
        window.clear(sf::Color::Black);

        // Draw the Nave sprite
        window.draw(ship.getSNave());

        // Display the window
        window.display();
    }

    return 0;
}
