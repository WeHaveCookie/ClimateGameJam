#ifndef PIGGERY_HPP
#define PIGGERY_HPP
#include "Building.hpp"
#include "Controller.hpp"
class Controller;

class Piggery : public Building
{
    public:
        Piggery(sf::Vector2f pos, Controller* controller);
        virtual ~Piggery();
        void enter();
        void produce(int i);
    protected:
    private:
        Controller* m_controller;
};

#endif // PIGGERY_HPP
#include "Building.hpp"
#include "Controller.hpp"
class Controller;
