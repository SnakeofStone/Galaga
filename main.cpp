#include <SFML/Graphics.hpp>
#include <iostream>
#include "headers/Nave.hpp"
#include "headers/Alien.hpp"

using namespace std;

int main()
{
    // Initiate simple properties for later use on the creation of the main window
    int windowDimensions[2] = {720, 720};
    int moveX = 5;

    // Set the configuration on the main window
    sf::RenderWindow window(sf::VideoMode(windowDimensions[0], windowDimensions[1])
                            , "Galaga"); //, sf::Style::Fullscreen
    window.setFramerateLimit(60);

    // Create a rectangle shape the size of the background and set the background
    sf::Texture background;
    sf::Texture* backgroundPointer = &background;
    background.loadFromFile("assets/images/fondo1.png");

    sf::RectangleShape rectangleBackground(sf::Vector2f(window.getSize()));
    rectangleBackground.setTexture(backgroundPointer);

    // Call the constructor of the Nave class and pass the image path
//  Nave ship("assets/images/nave.png");
//  Nave ship("assets/images/nave.png", windowDimensions);
    Nave ship("assets/images/nave.png", window.getSize());

    // Create the aliens
    // Create the first type of alien
    Alien alien("assets/images/alien1.png", 25, 30);
    Alien alien1("assets/images/alien2.png", 25, 125);

    ///////// Main game loop /////////
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();

            //if(event.type == sf::Event::Resized)

            //if(event.type == sf::Event::LostFocus)
            //if(event.type == sf::Event::GainedFocus)
        }

        //////////////////// Get keyboard input /////////////////////
        ///// Moving the spaceship i the x axis ///////

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            ship.MovePosX(moveX);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            ship.MovePosX(-moveX);

//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//            alien.Move(-moveX);
//
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//            alien.Move(moveX);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            ship.Fire();

        ///////// Ship //////////
        // Check bounds to avoid the ship getting off screen
        ship.checkXBounds(window.getSize());

//        if(ship.posX < 25)
//        {
//            ship.posX = 25;
//        }
//        ship.PrintDetails();

        ////// Set the position of the spacecraft ////////
        ship.setSNavePosition();

        //////// Aliens ///////////
        alien.checkBounds(window.getSize());
        alien1.checkBounds(window.getSize());

        ////// Clear the window and draw and display everything /////////
        window.clear(sf::Color::Black);

        // Draw the background
        //window.draw(sBackground);
        window.draw(rectangleBackground);

        // Draw the sprites
        window.draw(ship.returnSNave());
        window.draw(alien.returnAlien());
        window.draw(alien1.returnAlien());

        // Display the window
        window.display();
    }

    return 0;
}
