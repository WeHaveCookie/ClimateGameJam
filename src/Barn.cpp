#include "Barn.hpp"

Barn::Barn(sf::Vector2f pos, Controller* controller)
:Building(pos)
{
    m_name = "Barn";
    m_type = RessourcesType::GOLD;
    m_controller = controller;
    if(!m_buildTexture.loadFromFile(defaultBuildingPath+"barn1.png"))
    { // RAISE ERROR
    }
    std::cout << m_name << " build done" << std::endl;
    //increaseLevel();
}

Barn::~Barn()
{
    //dtor
}

void Barn::enter()
{
    produce(1);
    increaseLevel();
}

void Barn::produce(int i)
{
    m_counter += i;
    if(m_counter > m_necessaryClick)
    {
        m_controller->increaseRessource(RessourcesType::GOLD,1);
        m_counter -= m_necessaryClick;
    }
}
