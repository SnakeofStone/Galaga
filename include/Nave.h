#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Nave
{
private:
    // Private properties declaration
    sf::Sprite sNave;

public:
    // Method declaration
    Nave(const sf::Texture &, const sf::IntRect &, const sf::Vector2u &);
    void Move(const sf::Vector2f &, const sf::Vector2u &);
    sf::Sprite getSprite();
};
