#include "Corn.hpp"

Corn::Corn()
{
    m_spriteIcon.setTextureRect(sf::IntRect(263*2,0,263,103));
    m_positionIcon = sf::Vector2f(595,0);
    m_positionBar = sf::Vector2f(595+100,55);
}

Corn::~Corn()
{
    //dtor
}
