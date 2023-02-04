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
    // Method declaration
    Nave(std::string texturePath);
    void MovePosX(int x);
    void MoveNegX(int x);
    sf::Sprite returnSNave();
    void setSNavePosition();
    void setPosX(int x);
    void checkXBounds(sf::Vector2u windowSize);
};
