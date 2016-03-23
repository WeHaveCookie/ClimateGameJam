#ifndef PIG_HPP
#define PIG_HPP

#include "Animal.hpp"


class Pig : public Animal
{
    public:
        Pig(std::string path, sf::Vector2f pos);
        virtual ~Pig();


    protected:
    private:
        // Function
        void build();

};

#endif // PIG_HPP
