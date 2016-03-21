#include "Barn.hpp"

Barn::Barn(sf::Vector2f pos, Controller* controller)
:Building(pos)
{
    m_name = "Barn";
    m_type = RessourcesType::MILK;
    m_controller = controller;
    if(!m_buildTexture.loadFromFile(defaultBuildingPath+"barn.png"))
    { // RAISE ERROR
    }

    // HIGHLIGHTED
    if(!m_textureHighlighted.loadFromFile(defaultBuildingPath+"barnhi.png"))
    { // RAISE ERROR
    }
    m_textureHighlighted.setSmooth(true);
    m_spriteHighlighted.setTexture(m_textureHighlighted);

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
    /*if(m_level != 0)
    {
        increaseLevel();
    }*/
}

void Barn::produce(int i)
{
    m_counter += i;
    if(m_counter > m_necessaryClick)
    {
        m_controller->increaseRessource(m_type,1);
        m_counter -= m_necessaryClick;
    }
}
