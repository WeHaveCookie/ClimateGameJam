#ifndef HUD_H
#define HUD_H

#include <time.h>
#include <stdio.h>
#include <iostream>
#include "DrawableObject.hpp"
#include "Constante.hpp"
#include "Corn.hpp"
#include "Milk.hpp"
#include "Meat.hpp"
#include "Money.hpp"
#include "Egg.hpp"

class Hud : public DrawableObject
{
    public:
        Hud();
        virtual ~Hud();
        // Function
        void draw(sf::RenderWindow* window);
        void update(sf::RenderWindow* window);
        void updateAnimation();
        void displayRessources(RessourcesType rt, bool b);
        inline std::vector<Ressources*> getRessources() {return m_ressourcesHUD;}
        void increase(RessourcesType rt, int value);
        int getRessourcesValue(RessourcesType rt);
        void increaseStorageCapacity(int value);
    protected:
    private:
        // Function
        void build();

        // Attribut

        // Ressources HUD
        std::vector<Ressources*> m_ressourcesHUD;
        std::vector<bool> m_displayRessource;
        int m_animationCounter;
        sf::Time m_timeSinceLastUpdate;
        sf::Time m_TimePerFrame;
        sf::Time m_duration;
};

#endif // HUD_H
