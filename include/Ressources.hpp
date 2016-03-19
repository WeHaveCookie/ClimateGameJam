#ifndef RESSOURCES_HPP
#define RESSOURCES_HPP
#include <time.h>
#include <stdio.h>
#include <iostream>
#include "DrawableObject.hpp"
#include "Constante.hpp"


class Ressources : public DrawableObject
{
    public:
        Ressources();
        virtual ~Ressources();
        void draw(sf::RenderWindow* window);
        void update(sf::RenderWindow* window);
        bool addRessources(int i);
    protected:
        // ICON RESSOURCES
        sf::Texture m_textureIcon;
        sf::Sprite m_spriteIcon;
        sf::Vector2f m_positionIcon;

        // BAR RESSOURCES
        sf::Texture m_textureBar;
        sf::Sprite m_spriteBar;
        sf::Vector2f m_positionBar;

        // GAUGE RESSOURCES
        sf::Texture m_textureGauge;
        sf::Sprite m_spriteGauge;


        // FONT
        sf::Font m_font;
        sf::Text m_text;
        sf::Vector2f m_positionText;

        int m_quantity;
        int m_storeCapacity;
    private:
};

#endif // RESSOURCES_HPP
