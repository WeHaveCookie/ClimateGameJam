#include "Storage.hpp"

Storage::Storage(sf::Vector2f pos, Controller* controller)
:Building(pos)
{
    m_name = "Storage";
    m_controller = controller;
    if(!m_buildTexture.loadFromFile(defaultBuildingPath+"storage.png"))
    { // RAISE ERROR
    }
    std::cout << m_name << " build done" << std::endl;
    increaseLevel();
}

Storage::~Storage()
{
    //dtor
}

void Storage::enter()
{
    produce(1);
}

void Storage::produce(int i)
{
    m_counter += i;
    if(m_counter > m_necessaryClick)
    {
        m_controller->increaseRessource(RessourcesType::GOLD);
        m_counter -= m_necessaryClick;
    }
}
