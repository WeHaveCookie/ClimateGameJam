#include "Wood.hpp"

Wood::Wood()
{
    m_spriteIcon.setTextureRect(sf::IntRect(0,0,64,64));
    m_positionIcon = sf::Vector2f(0,18);
    m_positionBar = sf::Vector2f(100,25);
}

Wood::~Wood()
{
    //dtor
}
