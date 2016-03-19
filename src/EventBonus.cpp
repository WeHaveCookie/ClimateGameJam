#include "EventBonus.hpp"

EventBonus::EventBonus(Building* building, bool event, std::string desc, int id, std::string name)
:Event(building,event,desc,id,name)
{
    std::cout << "Create event " << m_name << " num : " << m_id << " with good : " << m_type << std::endl;
    //ctor
}

EventBonus::~EventBonus()
{
    //dtor
}


void EventBonus::proceed()
{
    m_building->triggerEvent(m_type,true);
    m_counter++;
}

void EventBonus::stop()
{
    m_building->triggerEvent(m_type,false);
    m_state = EventState::FINISHED;
}
