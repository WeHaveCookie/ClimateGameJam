#ifndef FARM_HPP
#define FARM_HPP

#include "Building.hpp"
#include "Controller.hpp"

class Controller;

class Farm : public Building
{
    public:
        Farm(sf::Vector2f pos, Controller* controller);
        virtual ~Farm();
        void enter();
        void produce(int i);
    protected:
    private:
        Controller* m_controller;
};

#endif // FARM_HPP
