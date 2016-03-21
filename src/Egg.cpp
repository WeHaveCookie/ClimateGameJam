#include "Egg.hpp"

Egg::Egg()
{
    m_spriteIcon.setTextureRect(sf::IntRect(263*4,0,263,103));
    m_positionIcon = sf::Vector2f(1165,0);
    m_positionBar = sf::Vector2f(1165+100,55);
}

Egg::~Egg()
{
    //dtor
}
