#ifndef STORAGE_HPP
#define STORAGE_HPP

#include "Building.hpp"
#include "Controller.hpp"
class Controller;

class Storage : public Building
{
    public:
        Storage(sf::Vector2f pos, Controller* controller);
        virtual ~Storage();
        void enter();
        void produce(int i);
    protected:
    private:
    Controller* m_controller;


};

#endif // STORAGE_HPP
