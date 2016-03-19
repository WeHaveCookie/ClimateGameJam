#include "House.hpp"

House::House(sf::Vector2f pos, Controller* controller)
:Building(pos)
{
    m_name = "House";
    m_controller = controller;
    m_type = RessourcesType::WOOD;
    if(!m_buildTexture.loadFromFile(defaultBuildingPath+"house.png"))
    { // RAISE ERROR
    }

    // HIGHLIGHTED
    if(!m_textureHighlighted.loadFromFile(defaultBuildingPath+"househi.png"))
    { // RAISE ERROR
    }
    m_textureHighlighted.setSmooth(true);
    m_spriteHighlighted.setTexture(m_textureHighlighted);

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
