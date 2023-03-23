#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Nave
{
private:
    // Private properties declaration
    sf::Sprite sNave;
    float maxSpeed;
    sf::Vector2f velocity;

public:
    // Method declaration
    Nave(const sf::Texture&, const sf::IntRect&, const sf::Vector2u&);
    void Move(float delta_t, const sf::Vector2u& windowDimensions);
    //void Move(const sf::Vector2f& move, const sf::Vector2u& windowDimensions);
    sf::Sprite getSprite();
    void setVelocity(const sf::Vector2f& direction);
    void resetVelocity(const sf::Vector2f& direction);
};
