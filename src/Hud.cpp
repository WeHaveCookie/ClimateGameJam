#include "Hud.hpp"

Hud::Hud()
{
    build();
    std::cout << "HUD Build done " << std::endl;
}

Hud::~Hud()
{

}


void Hud::draw(sf::RenderWindow* window)
{
    update(window);
    for(int i = 0; i < (int)m_ressourcesHUD.size(); i++)
    {
        if(m_displayRessource[i])
        {
            m_ressourcesHUD[i]->draw(window);
        }
    }
}

void Hud::update(sf::RenderWindow* window)
{
  // MAJ RESSOURCES
}

void Hud::updateAnimation()
{
    m_timeSinceLastUpdate = sf::Time::Zero;
    /*m_spriteBAR.setTextureRect(m_animationBAR[m_animationCounter].getTextureRect());
    if(++m_animationCounter >= (int)m_animationBAR.size())
    {
        m_animationCounter = 0;
    }*/
}

void Hud::build()
{

    // Set animation BAR
    m_ressourcesHUD.push_back(new Money());
    m_displayRessource.push_back(true);
    m_ressourcesHUD.push_back(new Meat());
    m_displayRessource.push_back(false);
    m_ressourcesHUD.push_back(new Corn());
    m_displayRessource.push_back(false);
    m_ressourcesHUD.push_back(new Milk());
    m_displayRessource.push_back(false);
    m_ressourcesHUD.push_back(new Egg());
    m_displayRessource.push_back(false);



    m_animationCounter = 0;

    sf::Clock tickClock;
    m_timeSinceLastUpdate = sf::Time::Zero;
	m_TimePerFrame = sf::seconds(1.f / 60.f);
	m_duration = sf::seconds(0.1);
}

void Hud::increase(RessourcesType rt, int value)
{
    switch(rt)
    {
        case RessourcesType::MONEY:
            m_ressourcesHUD[0]->addRessources(value);
            break;
        case RessourcesType::MEAT:
            m_ressourcesHUD[1]->addRessources(value);
            break;
        case RessourcesType::CORN:
            m_ressourcesHUD[2]->addRessources(value);
            break;
        case RessourcesType::MILK:
            m_ressourcesHUD[3]->addRessources(value);
            break;
        case RessourcesType::EGG:
            m_ressourcesHUD[4]->addRessources(value);
            break;
        default:
            break;
    }
}

int Hud::getRessourcesValue(RessourcesType rt)
{
    switch(rt)
    {
        case RessourcesType::MONEY:
            return m_ressourcesHUD[0]->getValue();
            break;
        case RessourcesType::MEAT:
            return m_ressourcesHUD[1]->getValue();
            break;
        case RessourcesType::CORN:
            return m_ressourcesHUD[2]->getValue();
            break;
        case RessourcesType::MILK:
            return m_ressourcesHUD[3]->getValue();
            break;
        case RessourcesType::EGG:
            return m_ressourcesHUD[4]->getValue();
            break;
        default:
            break;
    }
}
void Hud::displayRessources(RessourcesType rt, bool b)
{
        switch(rt)
    {
        case RessourcesType::MONEY:
            m_displayRessource[0] = b;
            break;
        case RessourcesType::MEAT:
            m_displayRessource[1] = b;
            break;
        case RessourcesType::CORN:
            m_displayRessource[2] = b;
            break;
        case RessourcesType::MILK:
            m_displayRessource[3] = b;
            break;
        case RessourcesType::EGG:
            m_displayRessource[4] = b;
            break;
        default:
            break;
    }
}
