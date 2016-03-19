#include "SellStore.hpp"

SellStore::SellStore(sf::Vector2f pos, Controller* controller)
:Building(pos)
{
    m_name = "SellStore";
    m_type = RessourcesType::GOLD;
    m_controller = controller;
    if(!m_buildTexture.loadFromFile(defaultBuildingPath+"sellstore1.png"))
    { // RAISE ERROR
    }
    std::cout << m_name << " build done" << std::endl;
}

SellStore::~SellStore()
{
    //dtor
}


void SellStore::enter()
{
    produce(1);
    increaseLevel();
}

void SellStore::produce(int i)
{
    m_counter += i;
    if(m_counter > m_necessaryClick)
    {
        m_controller->increaseRessource(RessourcesType::GOLD,1);
        m_counter -= m_necessaryClick;
    }
}
