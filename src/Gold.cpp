#include "Gold.hpp"

Gold::Gold()
{
    m_spriteIcon.setTextureRect(sf::IntRect(128,0,64,64));
    m_positionIcon = sf::Vector2f(600,18);
    m_positionBar = sf::Vector2f(700,25);
}

Gold::~Gold()
{
    //dtor
}
