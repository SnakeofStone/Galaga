#include "Nave.h"

Nave::Nave(
        const sf::Texture &texturemap,
        const sf::IntRect &rect,
        const sf::Vector2u &windowSize)
{
   sNave = sf::Sprite(texturemap, rect);
   sNave.setPosition(
        windowSize.x/2 - sNave.getGlobalBounds().width,
        windowSize.y - sNave.getGlobalBounds().height
   );
}

void Nave::Move(
    const sf::Vector2i &move,
    const sf::Vector2u &windowDimensions)
{
    if (sNave.getPosition().x + move.x < 0)
    {
        sNave.setPosition(sf::Vector2f(
            0,
            sNave.getPosition().y
        ));
    }
    else if (sNave.getPosition().x + sNave.getGlobalBounds().width > windowDimensions.x)
    {
        sNave.setPosition(sf::Vector2f(
            windowDimensions.x - sNave.getGlobalBounds().width,
            sNave.getPosition().y
        ));
    }
    else
    {
        sNave.setPosition(sf::Vector2f(
            sNave.getPosition().x + move.x,
            sNave.getPosition().y
        ));
    }
}

sf::Sprite Nave::getSNave()
{
    return sNave;
}
