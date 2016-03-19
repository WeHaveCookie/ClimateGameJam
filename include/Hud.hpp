#ifndef HUD_H
#define HUD_H

#include <time.h>
#include <stdio.h>
#include <iostream>
#include "DrawableObject.hpp"
#include "Constante.hpp"
#include "Iron.hpp"
#include "Gold.hpp"
#include "Wood.hpp"

class Hud : public DrawableObject
{
    public:
        Hud();
        virtual ~Hud();
        // Function
        void draw(sf::RenderWindow* window);
        void update(sf::RenderWindow* window);
        void updateAnimation();
        inline std::vector<Ressources*> getRessources() {return m_ressourcesHUD;}
        void increase(RessourcesType rt);
    protected:
    private:
        // Function
        void build();

        // Attribut

        // Ressources HUD
        std::vector<Ressources*> m_ressourcesHUD;

        int m_animationCounter;
        sf::Time m_timeSinceLastUpdate;
        sf::Time m_TimePerFrame;
        sf::Time m_duration;
};

#endif // HUD_H
