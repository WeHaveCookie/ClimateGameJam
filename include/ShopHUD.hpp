#ifndef SHOPHUD_HPP
#define SHOPHUD_HPP

#include "DrawableObject.hpp"

class ShopHUD : public DrawableObject
{
    public:
        ShopHUD();
        virtual ~ShopHUD();
        void draw(sf::RenderWindow* window);
        void update(sf::RenderWindow* window);
        void updateAnimation();
        void select(sf::Vector2f motion);
        int getPrice() {std::cout << "REturn "<< m_price[m_selectItem] << std::endl; return m_price[m_selectItem];}
    protected:
    private:
        // Function
        void build();

        // Attribut

        // Ressources HUD
        std::vector<int> m_price;

        // SHOP VIEW
        sf::Texture m_textureShop;
        sf::Sprite m_spriteShop;

        // SELECT FRAME
        sf::Texture m_textureFrame;
        sf::Sprite m_spriteFrame;
        sf::Vector2f m_positionFrame;

        int m_animationCounter;
        sf::Time m_timeSinceLastUpdate;
        sf::Time m_TimePerFrame;
        sf::Time m_duration;
        int m_selectItem;

};

#endif // SHOPHUD_HPP
