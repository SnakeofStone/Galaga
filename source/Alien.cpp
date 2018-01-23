#include "../headers/Alien.hpp"
#include <time.h>

Alien::Alien(std::string path)
{
    if(!texture.loadFromFile(path))
    {
        exit(0);
    }
    sprite.setTexture(texture);
    posX = 25;
    posY = 30;
    sprite.setPosition(posX, posY);
}

Alien::Alien(std::string path, int x, int y)
{
    if(!texture.loadFromFile(path))
    {
        exit(0);
    }
    sprite.setTexture(texture);
    posX = x;
    posY = y;
    sprite.setPosition(posX, posY);
}

void Alien::setPos()
{
    sprite.setPosition(posX, posY);
}

void Alien::setPos(int x, int y)
{
    posX = x;
    posY = y;
    Alien::sprite.setPosition(posX, posY);
}

void Alien::Move(int x)
{
    posX += x;
    setPos();
}

sf::Sprite Alien::returnAlien()
{
    return Alien::sprite;
}

void Alien::checkBounds(sf::Vector2u windowSize)
{
    if(posX < 25)
        setPos(25, posY);

    if(posX > windowSize.x - sprite.getGlobalBounds().width - 25)
        setPos(windowSize.x - sprite.getGlobalBounds().width - 25, posY);
}
