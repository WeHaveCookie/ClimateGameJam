#include "Farm.hpp"

Farm::Farm(sf::Vector2f pos, Controller* controller)
:Building(pos)
{
    m_name = "Farm";
    m_controller = controller;

    if(!m_buildTexture.loadFromFile(defaultBuildingPath+"farm.png"))
    { // RAISE ERROR
    }
    std::cout << m_name << " build Done " << std::endl;
}

Farm::~Farm()
{
    //dtor
}

void Farm::enter()
{
    if(m_level == 0)
    {
        increaseLevel();
    }
    produce(1);
}

void Farm::produce(int i)
{
    m_counter += i;
    if(m_counter > m_necessaryClick)
    {
        m_controller->increaseRessource(RessourcesType::WOOD);
        m_counter -= m_necessaryClick;
    }
}
