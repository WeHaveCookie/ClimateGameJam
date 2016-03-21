#ifndef MENU_HPP
#define MENU_HPP
#include <string>
#include "Structure.hpp"
#include "Constante.hpp"

class Menu
{
    public:
        Menu();
        virtual ~Menu();

        // Function
        void draw(sf::RenderWindow* window);
        void update(sf::RenderWindow* window);
        void updateAnimation();

        // Inline
        inline bool isEnable() {return m_enable;}
        inline void setEnable(bool b) {m_enable = b;}
        inline void setState(MenuState st) {m_menuState = st;}
        inline void onAnimation() {m_onAnimation = true;}
        inline bool isAnimated() {return m_onAnimation;}
        inline MenuState getState() {return m_menuState;}

    protected:
    private:
        // Function
        void build();

        // Attribut
        sf::Texture m_texture;
        sf::Sprite m_sprite;

        int m_animationCounter;
        sf::Time m_timeSinceLastUpdate;
        sf::Time m_TimePerFrame;
        sf::Time m_duration;
        bool m_onAnimation;
        MenuState m_menuState;
        bool m_enable;

        sf::Texture m_textureBack;
        sf::Texture m_textureMenu;
        sf::Texture m_textureCredit;
        sf::Texture m_textureOption;
        sf::Sprite m_spriteBack;
        sf::Sprite m_spriteCredit;
        sf::Sprite m_spriteMenu;
        sf::Sprite m_spriteOption;
};
#endif // MENU_HPP
