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
        m_ressourcesHUD[i]->draw(window);
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
    m_ressourcesHUD.push_back(new Wood());
    m_ressourcesHUD.push_back(new Iron());
    m_ressourcesHUD.push_back(new Gold());



    m_animationCounter = 0;

    sf::Clock tickClock;
    m_timeSinceLastUpdate = sf::Time::Zero;
	m_TimePerFrame = sf::seconds(1.f / 60.f);
	m_duration = sf::seconds(0.1);
}

void Hud::increase(RessourcesType rt)
{
    switch(rt)
    {
        case RessourcesType::WOOD:
            m_ressourcesHUD[0]->addRessources(1);
            break;
        case RessourcesType::IRON:
            m_ressourcesHUD[1]->addRessources(1);
            break;
        case RessourcesType::GOLD:
            m_ressourcesHUD[2]->addRessources(1);
            break;
        default:
            break;
    }
}
