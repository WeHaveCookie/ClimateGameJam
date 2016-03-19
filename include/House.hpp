#ifndef House_HPP
#define House_HPP

#include "Building.hpp"
#include "Controller.hpp"

class Controller;

class House : public Building
{
    public:
        House(sf::Vector2f pos, Controller* controller);
        virtual ~House();
        void enter();
        void produce(int i);
    protected:
    private:
        Controller* m_controller;
};

#endif // House_HPP
