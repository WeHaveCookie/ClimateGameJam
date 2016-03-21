#include "Meat.hpp"

Meat::Meat()
{
    m_spriteIcon.setTextureRect(sf::IntRect(263,0,263,103));
    m_positionIcon = sf::Vector2f(310,0);
    m_positionBar = sf::Vector2f(310+100,55);
}

Meat::~Meat()
{
    //dtor
}
