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

public:
    //////// Method declaration ///////////
    // Constructor declaration
    Nave(std::string texturePath);
    Nave(std::string texturePath, int windowSize[]);
    Nave(std::string texturePath, sf::Vector2u windowSize);

    // Other method declaration
    void MovePosX(int x);
    void MoveNegX(int x);
    sf::Sprite returnSNave();
    void setSNavePosition();
    void setPosX(int x);
    void checkXBounds(sf::Vector2u windowSize);
};
