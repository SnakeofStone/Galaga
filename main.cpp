#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <list>
#include "Nave.h"

int averageFPS(const std::list<int>& pastValues);

int main()
{
    // Initiate simple properties for later use on the creation of the main window
    sf::Vector2u windowDimensions = {720, 720};

    // Set the configuration on the main window
    sf::RenderWindow window(sf::VideoMode(
                                windowDimensions.x,
                                windowDimensions.y
                            ), "Galaga");
    //window.setFramerateLimit(60);
    constexpr int N = 25;

    sf::Texture texturemap;
    if (!texturemap.loadFromFile("assets/images/texturemap.png"))
    {
        // TO-DO: Add logging system
        return EXIT_FAILURE;
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

    sf::Font font;
    if (!font.loadFromFile("assets/fonts/RobotoCondensed-Regular.ttf"))
    {
        // TO-DO: Add logging system
        return EXIT_FAILURE;
    }
    sf::Clock clock;
    sf::Text fps_counter;
    fps_counter.setFont(font);
    fps_counter.setCharacterSize(50);
    fps_counter.setFillColor(sf::Color::White);
    fps_counter.setPosition(sf::Vector2f(10, 10));

    std::list<int> pastFPS(N, 0);

    ///////// Main game loop /////////
    while (window.isOpen())
    {
        float delta_t = clock.restart().asSeconds();
        // FPS counter
        pastFPS.push_back((sf::Int32)std::round(1.0f / delta_t));
        pastFPS.pop_front();
        sf::Int32 fps = averageFPS(pastFPS);
        fps_counter.setString(std::to_string(fps));

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

        // Reset Ship velocity vector
        ship.resetVelocity(sf::Vector2f(0, 0));

        // Get keyboard input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            ship.setVelocity(sf::Vector2f(1, 0));

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            ship.setVelocity(sf::Vector2f(-1, 0));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            ship.setVelocity(sf::Vector2f(0, -1));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            ship.setVelocity(sf::Vector2f(0, 1));

        // Update ship position
        ship.Move(delta_t, window.getSize());

        // Clear the window and draw and display everything
        window.clear(sf::Color::Black);

        // Draw the sprites
        window.draw(fps_counter);
        window.draw(ship.getSprite());

        // Display the window
        window.display();
    }

    return EXIT_SUCCESS;
}

int averageFPS(const std::list<int>& pastValues)
{
    int avg = 0;
    for (int value : pastValues)
    {
        avg += value;
    }
    avg /= pastValues.size();

    return avg;
}
