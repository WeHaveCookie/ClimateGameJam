#ifndef EVENTRESSOURCES_HPP
#define EVENTRESSOURCES_HPP

#include "Event.hpp"
#include "Controller.hpp"

class Controller;

class EventRessources : public Event
{
    public:
        EventRessources(Building* building, bool event, std::string desc, Controller* controller, int id,std::string name = "EventRessource");
        virtual ~EventRessources();
        void proceed();
    protected:
    private:
        Controller* m_controller;


};

#endif // EVENTRESSOURCES_HPP
