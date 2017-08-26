#include <SFML/Graphics.hpp>
#include <iostream>

struct dimensions
{
    int x, y;
} windowDimensions;

int main()
{
    windowDimensions.x = 720;
    windowDimensions.y = 720;

    sf::RenderWindow window(sf::VideoMode(windowDimensions.x, windowDimensions.y), "Galaga");
    window.setFramerateLimit(60);
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);

    //////// Define and declare textures and sprites////////////
    sf::Texture nave, alien1, alien2, alien3, alien4;
    nave.loadFromFile("images/nave.png");

    sf::Sprite sNave(nave), sAlien1(alien1), sAlien2(alien2),
        sAlien3(alien3), sAlien4(alien4);

    //////// Define the spacecraft initial position /////////

    sf::Vector2u windowSize = window.getSize();

    int xPos = windowSize.x/2 - sNave.getLocalBounds().width,
        yPos = windowSize.y - sNave.getLocalBounds().height;

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
            xPos += 5;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            xPos -= 5;

        /////// Check if it is in bounds ////////
        if(xPos < 0)
            xPos = 0;

        if(xPos > windowSize.x - sNave.getGlobalBounds().width)
            xPos = windowSize.x - sNave.getGlobalBounds().width;

        ////// Set the position of the spacecraft ////////
        sNave.setPosition(xPos, yPos);

        ////// Clear the window and draw and display everything /////////
        window.clear(sf::Color::Black);

        window.draw(sNave);
        //window.draw(shape);

        window.display();
    }

    return 0;
}
