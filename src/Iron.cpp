#include "Iron.hpp"

Iron::Iron()
{
    m_spriteIcon.setTextureRect(sf::IntRect(64,0,64,64));
    m_positionIcon = sf::Vector2f(300,18);
    m_positionBar = sf::Vector2f(400,25);
}

Iron::~Iron()
{
    //dtor
}
