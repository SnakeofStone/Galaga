#include "Nave.hpp"

Nave::Nave()
{
    sf::Texture nave;
    nave.loadFromFile("assets/");
}

Nave::MovePosX(int x)
{
    posX += x;
}
