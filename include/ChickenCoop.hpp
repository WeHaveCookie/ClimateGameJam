#ifndef CHICKENCOOP_HPP
#define CHICKENCOOP_HPP
#include "Building.hpp"
#include "Controller.hpp"
class Controller;

class ChickenCoop : public Building
{
    public:
        ChickenCoop(sf::Vector2f pos, Controller* controller);
        virtual ~ChickenCoop();
        void enter();
        void produce(int i);
    protected:
    private:
        Controller* m_controller;
};

#endif // CHICKENCOOP_HPP
