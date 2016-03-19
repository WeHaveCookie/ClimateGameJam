#ifndef EVENTBONUS_HPP
#define EVENTBONUS_HPP

#include "Event.hpp"


class EventBonus : public Event
{
    public:
        EventBonus(Building* building, bool event, std::string desc,int id,std::string name = "EventBonus");
        virtual ~EventBonus();
        void proceed();
        void stop();
    protected:
    private:
};

#endif // EVENTBONUS_HPP
