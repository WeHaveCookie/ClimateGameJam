#include "SellStore.hpp"

SellStore::SellStore(sf::Vector2f pos, Controller* controller)
:Building(pos)
{
    m_name = "SellStore";
    m_type = RessourcesType::MONEY;
    m_controller = controller;
    if(!m_buildTexture.loadFromFile(defaultBuildingPath+"sellstore.png"))
    { // RAISE ERROR
    }

    // HIGHLIGHTED
    if(!m_textureHighlighted.loadFromFile(defaultBuildingPath+"sellstorehi.png"))
    { // RAISE ERROR
    }
    m_textureHighlighted.setSmooth(true);
    m_spriteHighlighted.setTexture(m_textureHighlighted);

    std::cout << m_name << " build done" << std::endl;
}

SellStore::~SellStore()
{
    //dtor
}


void SellStore::enter()
{
    m_controller->showShop(true);
    //increaseLevel();
}

void SellStore::produce(int i)
{
    m_counter += i;
    if(m_counter > m_necessaryClick)
    {
        m_controller->increaseRessource(m_type,1);
        m_counter -= m_necessaryClick;
    }
}
