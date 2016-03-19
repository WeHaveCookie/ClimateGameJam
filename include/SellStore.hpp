#ifndef SELLSTORE_HPP
#define SELLSTORE_HPP

#include "Building.hpp"
#include "Controller.hpp"
class Controller;

class SellStore : public Building
{
    public:
        SellStore(sf::Vector2f pos, Controller* controller);
        virtual ~SellStore();
        void enter();
        void produce(int i);
    protected:
    private:
        Controller* m_controller;
};

#endif // SELLSTORE_HPP
