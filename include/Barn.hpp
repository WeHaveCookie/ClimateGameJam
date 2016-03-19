#ifndef Barn_HPP
#define Barn_HPP

#include "Building.hpp"
#include "Controller.hpp"
class Controller;

class Barn : public Building
{
    public:
        Barn(sf::Vector2f pos, Controller* controller);
        virtual ~Barn();
        void enter();
        void produce(int i);
    protected:
    private:
        Controller* m_controller;


};

#endif // Barn_HPP
