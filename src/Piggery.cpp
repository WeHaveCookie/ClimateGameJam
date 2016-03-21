#include "Piggery.hpp"

Piggery::Piggery(sf::Vector2f pos, Controller* controller)
:Building(pos)
{
    m_name = "Piggery";
    m_type = RessourcesType::MEAT;
    m_controller = controller;
    if(!m_buildTexture.loadFromFile(defaultBuildingPath+"piggery.png"))
    { // RAISE ERROR
    }

    // HIGHLIGHTED
    if(!m_textureHighlighted.loadFromFile(defaultBuildingPath+"piggeryhi.png"))
    { // RAISE ERROR
    }
    m_textureHighlighted.setSmooth(true);
    m_spriteHighlighted.setTexture(m_textureHighlighted);

    std::cout << m_name << " build done" << std::endl;
}

Piggery::~Piggery()
{
    //dtor
}


void Piggery::enter()
{
    produce(1);
    //increaseLevel();
}

void Piggery::produce(int i)
{
    m_counter += i;
    if(m_counter > m_necessaryClick)
    {
        m_controller->increaseRessource(m_type,1);
        m_counter -= m_necessaryClick;
    }
}
