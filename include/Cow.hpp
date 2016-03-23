#ifndef COW_HPP
#define COW_HPP
#include "Animal.hpp"

class Cow : public Animal
{
    public:
        Cow(std::string path, sf::Vector2f pos);
        virtual ~Cow();

    protected:
    private:
        // Function
        void build();
};

#endif // COW_HPP
