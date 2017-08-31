#include "../headers/Nave.hpp"


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

Nave::Nave(std::string texturePath, int windowSize[])
{
    if(!nave.loadFromFile(texturePath))
    {
            exit(0);
    }
    sNave.setTexture(nave);
    posX = windowSize[0]/2 - sNave.getLocalBounds().width;
    posY = windowSize[1] - sNave.getLocalBounds().height;
}

Nave::Nave(std::string texturePath, sf::Vector2u windowSize)
{
    if(!nave.loadFromFile(texturePath))
    {
            exit(0);
    }
    sNave.setTexture(nave);
    posX = windowSize.x/2 - sNave.getLocalBounds().width;
    posY = windowSize.y - sNave.getLocalBounds().height;
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
    Nave::sNave.setPosition(Nave::posX, Nave::posY - 80);
}

void Nave::setPosX(int x)
{
    Nave::posX = x;
}

void Nave::checkXBounds(sf::Vector2u windowSize)
{
    /////// Check if it is in bounds ////////
    if(Nave::posX < 0 + 25)
        Nave::setPosX(0+25);

    if(Nave::posX > windowSize.x - Nave::returnSNave().getGlobalBounds().width - 25)
        Nave::setPosX(windowSize.x - Nave::returnSNave().getGlobalBounds().width - 25);
}
