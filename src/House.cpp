#include "House.hpp"

House::House(sf::Vector2f pos, Controller* controller)
:Building(pos)
{
    m_name = "House";
    m_controller = controller;
    m_type = RessourcesType::WOOD;
    if(!m_buildTexture.loadFromFile(defaultBuildingPath+"house1.png"))
    { // RAISE ERROR
    }
    std::cout << m_name << " build Done " << std::endl;
}

House::~House()
{
    //dtor
}

void House::enter()
{
    /*if(m_level == 0)
    {
        increaseLevel();
    }*/
    increaseLevel();
    produce(1);
}

void House::produce(int i)
{
    m_counter += i;
    if(m_counter > m_necessaryClick)
    {
        m_controller->increaseRessource(RessourcesType::WOOD,1);
        m_counter -= m_necessaryClick;
    }
}
