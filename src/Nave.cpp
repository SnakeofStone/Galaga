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
   this->maxSpeed = 25.0f;
   this->velocity = sf::Vector2f(0, 0);
}

void Nave::Move(
    float delta_t,
    const sf::Vector2u& windowDimensions)
{
    const sf::Vector2f newPos = sNave.getPosition() + delta_t * this->maxSpeed * this->velocity;
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
            newPos
        ));
    }
}

sf::Sprite Nave::getSprite()
{
    return this->sNave;
}

void Nave::setVelocity(const sf::Vector2f& direction)
{
    /*if (1 != std::sqrt(std::pow(direction.x, 2) + std::pow(direction.y, 2)))
        this->velocity = sf::Vector2f(0, 0);

    else*/
        this->velocity += direction * this->maxSpeed;
}

void Nave::resetVelocity(const sf::Vector2f& direction)
{
    this->velocity = sf::Vector2f(0, 0);
}
