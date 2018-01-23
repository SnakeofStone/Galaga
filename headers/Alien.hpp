#pragma once
#include <SFML/Graphics.hpp>

using namespace std;

class Alien
{
private:
    // Private properties declaration
    sf::Texture texture;
    sf::Sprite sprite;
    int posX, posY;

public:
    //////// Method declaration ///////////
    // Constructor declaration
    Alien(std::string path);
    Alien(std::string path, int x, int y);

    // General method declaration
    void setPos();
    void setPos(int x, int y);
    void Move(int x);
    sf::Sprite returnAlien();
    void checkBounds(sf::Vector2u windowSize);
};
