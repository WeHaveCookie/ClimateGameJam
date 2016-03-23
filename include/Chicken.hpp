#ifndef CHICKEN_HPP
#define CHICKEN_HPP
#include "Animal.hpp"

class Chicken : public Animal
{
    public:
        Chicken(std::string path, sf::Vector2f pos);
        virtual ~Chicken();

    protected:
    private:
        // Function
        void build();
};

#endif // CHICKEN_HPP
