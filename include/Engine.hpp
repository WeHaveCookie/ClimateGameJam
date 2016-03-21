#ifndef ENGINE_HPP
#define ENGINE_HPP
#include <math.h>
#include "Structure.hpp"
#include "Level.hpp"
#include "DrawableObject.hpp"
#include "Building.hpp"

class Level;

class Engine
{
    public:
        Engine(Level* level, sf::View* viewGame);
        Engine();
        virtual ~Engine();

        // Function
        bool collisionCircle(sf::FloatRect box1, sf::CircleShape circle);
        bool collisionAABB(sf::FloatRect box1, sf::FloatRect box2);
        bool move(DrawableObject* obj, const sf::Vector2f& motion, bool collision = true);
        Building* enterOnBuilding(const sf::FloatRect bounds);
        std::vector<float> getSoundAmbiance(DrawableObject* obj);

        // Inline
    protected:
    private:
        sf::Vector2f m_sizeLevel;
        Level* m_level;
        sf::View* m_viewGame;

};

#endif // ENGINE_HPP
