#include "Money.hpp"

Money::Money()
{
    m_spriteIcon.setTextureRect(sf::IntRect(263*3,0,263,103));
    m_positionIcon = sf::Vector2f(25,0);
    m_positionBar = sf::Vector2f(25+100,55);
}

Money::~Money()
{
    //dtor
}
