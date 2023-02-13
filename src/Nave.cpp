#include "Nave.h"

Nave::Nave(
        const sf::Texture &texturemap,
        const sf::IntRect &rect,
        const sf::Vector2u &windowSize)
{
   sNave = sf::Sprite(texturemap, rect);
   sNave.setPosition(
        (windowSize.x>>1) - sNave.getGlobalBounds().width,
        windowSize.y - sNave.getGlobalBounds().height
   );
}

void Nave::Move(
    const sf::Vector2f &move,
    const sf::Vector2u &windowDimensions)
{
    const sf::Vector2f newPos = sNave.getPosition() + move;
    if (newPos.x < 0)
    {
        sNave.setPosition(sf::Vector2f(
            0,
            sNave.getPosition().y
        )); 
    }
    else if (newPos.x + sNave.getGlobalBounds().width > windowDimensions.x)
    {
        sNave.setPosition(sf::Vector2f(
            windowDimensions.x - sNave.getGlobalBounds().width,
            sNave.getPosition().y
        ));
    }
    else if (newPos.y + sNave.getGlobalBounds().height > windowDimensions.y)
    {
        sNave.setPosition(sf::Vector2f(
            sNave.getPosition().x,
            windowDimensions.y - sNave.getGlobalBounds().height
        ));
    }
    else if (newPos.y < 0)
    {
        sNave.setPosition(sf::Vector2f(
            sNave.getPosition().x,
            0
        ));
    }
    else
    {
        sNave.setPosition(sf::Vector2f(
            sNave.getPosition() + move
        ));
    }
}

sf::Sprite Nave::getSprite()
{
    return sNave;
}
