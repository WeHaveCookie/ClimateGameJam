#ifndef DRAWABLEOBJECT_HPP
#define DRAWABLEOBJECT_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <stdio.h>
#include <iostream>
#include "Structure.hpp"

class DrawableObject
{
    public:
        DrawableObject();
        virtual ~DrawableObject();
        virtual void move(sf::Vector2f motion);
        inline sf::Vector2f getPosition() {return m_position;}
        inline void setState(MovingState st) {m_movingState = st;}
        inline MovingState getState() {return m_movingState;}
        inline float getSpeed() {return m_speed;}
        inline sf::FloatRect getGlobalBounds() {return m_sprite.getGlobalBounds();}
    protected:
        virtual void draw(sf::RenderWindow* window);
        virtual void update(sf::RenderWindow* window);

        sf::Texture m_texture;
        sf::Sprite m_sprite;
        sf::Vector2f m_position;
        float m_speed;
        MovingState m_movingState;
    private:
};
#endif // DRAWABLEOBJECT_HPP
