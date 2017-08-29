#include <SFML/Graphics.hpp>
#include <iostream>
#include "headers/Nave.hpp"

using namespace std;

int main()
{
    int windowDimensions[2] = {720, 720};
    int moveX = 5;

    sf::RenderWindow window(sf::VideoMode(windowDimensions[0], windowDimensions[1]), "Galaga");
    window.setFramerateLimit(60);
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);

    //////// Define and declare textures and sprites////////////
    sf::Texture alien1, alien2, alien3, alien4;

    // Call the constructor of the Nave
    // class and pass the image path
    Nave ship("assets/images/nave.png");

    sf::Sprite sAlien1(alien1), sAlien2(alien2),
        sAlien3(alien3), sAlien4(alien4);

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

        ship.checkXBounds(window.getSize());

        ////// Set the position of the spacecraft ////////
        ship.setSNavePosition();

        ////// Clear the window and draw and display everything /////////
        window.clear(sf::Color::Black);

        window.draw(ship.returnSNave());
        //window.draw(shape);

        window.display();
    }

    return 0;
}
