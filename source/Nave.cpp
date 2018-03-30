#include "../headers/Nave.hpp"

Nave::Nave(std::string texturePath)
{
    if(!nave.loadFromFile(texturePath))
    {
            exit(0);
    }
    sNave.setTexture(nave);
    posX = 720/2 - sNave.getLocalBounds().width/2;
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
    if(Nave::posX < 25)
        Nave::setPosX(25);
//        Nave::posX = 25;

    if(Nave::posX > windowSize.x - Nave::returnSNave().getGlobalBounds().width - 25)
        Nave::setPosX(windowSize.x - Nave::returnSNave().getGlobalBounds().width - 25);
}

void Nave::PrintDetails()
{
    cout << "Ship positions:" << endl;
    cout << "X position: " << posX << endl;
    cout << "Y position: " << posY << endl;
}

void Nave::Fire()
{
    sf::Texture proyectile;
    sf::Sprite sProyectile;

    if(!proyectile.loadFromFile("assets/images/proyectile.png"))
    {
        exit(0);
    }
    sProyectile.setTexture(proyectile);
    sProyectile.setPosition(50.0, 50.0);
}
