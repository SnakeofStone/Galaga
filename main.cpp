#include <SFML/Graphics.hpp>
#include <iostream>
#include "Nave.h"

using namespace std;

int main()
{
    // Initiate simple properties for later use on the creation of the main window
    int windowDimensions[2] = {720, 720};
    int moveX = 5;

    // Set the configuration on the main window
    sf::RenderWindow window(sf::VideoMode(windowDimensions[0], windowDimensions[1]), "Galaga");
    window.setFramerateLimit(60);

    //////// Define and declare textures and sprites////////////
//<<<<<<< HEAD
    sf::Texture nave, alien1, alien2, alien3, alien4;
    if (!nave.loadFromFile("assets/images/nave.png"))
    {
        // error...

    }

    sf::Sprite sNave(nave), sAlien1(alien1), sAlien2(alien2),
        sAlien3(alien3), sAlien4(alien4);
//=======
//    sf::Texture alien1, alien2, alien3, alien4;
//>>>>>>> intoClasses*/

    // Call the constructor of the Nave
    // class and pass the image path
    Nave ship("assets/images/nave.png");

//    sf::Sprite sAlien1(alien1), sAlien2(alien2),
//        sAlien3(alien3), sAlien4(alien4);

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
        ///// Moving the spaceship i the x axis ///////

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            ship.MovePosX(moveX);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            ship.MoveNegX(moveX);

        // Check bounds to avoid the ship getting off screen
        ship.checkXBounds(window.getSize());

        ////// Set the position of the spacecraft ////////
        ship.setSNavePosition();

        ////// Clear the window and draw and display everything /////////
        window.clear(sf::Color::Black);

        // Draw the Nave sprite
        window.draw(ship.returnSNave());
        //window.draw(shape);

        // Display the window
        window.display();
    }

    return 0;
}
