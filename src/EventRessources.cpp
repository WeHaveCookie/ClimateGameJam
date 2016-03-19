#include "EventRessources.hpp"

EventRessources::EventRessources(Building* building, bool event, std::string desc, Controller* controller, int id, std::string name)
:Event(building,event,desc,id, name)
{
    m_controller = controller;

    std::cout << "Create event " << m_name << " num : " <<  m_id << " state : " << m_type << " with " << m_timer << " secondes" << std::endl;
}

EventRessources::~EventRessources()
{
    //dtor
}


void EventRessources::proceed()
{
    RessourcesType rt = m_building->getType();
    if(m_type == EventType::GOOD)
    { // Add ressources
        m_controller->increaseRessource(rt,1);
    } else
    { // Remove ressources
        m_controller->increaseRessource(rt,-1);
    }
    m_counter++;
}
