#include "Milk.hpp"

Milk::Milk()
{
    m_spriteIcon.setTextureRect(sf::IntRect(0,0,263,103));
    m_positionIcon = sf::Vector2f(880,0);
    m_positionBar = sf::Vector2f(880+100,55);
}

Milk::~Milk()
{
    //dtor
}
