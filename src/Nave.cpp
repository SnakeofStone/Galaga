#include "Nave.h"

Nave::Nave(std::string texturePath)
{
    if(!nave.loadFromFile(texturePath))
    {
            exit(0);
    }
    sNave.setTexture(nave);
    posX = 720/2 - sNave.getLocalBounds().width;
    posY = 720 - sNave.getLocalBounds().height;
}

void Nave::MovePosX(int x)
{
    posX += x;
//    cout << posX << endl;
}

void Nave::MoveNegX(int x)
{
    posX -= x;
//    cout << posX << endl;
}

sf::Sprite Nave::returnSNave()
{
    return Nave::sNave;
}

void Nave::setSNavePosition()
{
    Nave::sNave.setPosition(Nave::posX, Nave::posY);
}

void Nave::setPosX(int x)
{
    Nave::posX = x;
}

void Nave::checkXBounds(sf::Vector2u windowSize)
{
    /////// Check if it is in bounds ////////
    if(Nave::posX < 0)
        Nave::setPosX(0);

    if(Nave::posX > windowSize.x - Nave::returnSNave().getGlobalBounds().width)
        Nave::setPosX(windowSize.x - Nave::returnSNave().getGlobalBounds().width);
}
