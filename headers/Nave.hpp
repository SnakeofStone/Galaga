#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Nave
{
private:
    // Private properties declaration
    sf::Texture nave;
    sf::Sprite sNave;
    int posX, posY;
    int delayFire;

public:
    //////// Method declaration ///////////
    // Constructor declaration

    Nave(std::string texturePath);
    Nave(std::string texturePath, int windowSize[]);
    Nave(std::string texturePath, sf::Vector2u windowSize);

    // Other method declaration
    // Move X units the ship
    void MovePosX(int x);

    // Return the Nave object
    sf::Sprite returnSNave();

    // Set the initial Nave position
    void setSNavePosition();

    // Set the Nave position in X
    void setPosX(int x);

    // Check for local bounds
    void checkXBounds(sf::Vector2u windowSize);

    // Print the ship details
    void PrintDetails();

    // Fire!
    sf::Sprite Fire();

    // Set the shot initial position
    void setShot(sf::Texture& proyectile, sf::Sprite& sProyectile);
};
