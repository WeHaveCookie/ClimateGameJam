#ifndef BUILDING_HPP
#define BUILDING_HPP

#include "DrawableObject.hpp"
#include "Constante.hpp"


class Building : public DrawableObject
{
    public:
        Building(sf::Vector2f pos);
        virtual ~Building();
        void draw(sf::RenderWindow* window);
        void update(sf::RenderWindow* window);
        void increaseLevel();
        void decreaseLevel();
        virtual void enter() = 0;
        virtual void produce(int i) = 0;
        inline std::string getName() {return m_name;}
        void addWorker(int i);
        void triggerEvent(EventType et, bool b);
        inline void displayAButton(bool b) {m_displayAButton = b;}

    protected:
        int m_level;
        int m_costToUpgrade;
        sf::Texture m_buildTexture;
        sf::Vector2f m_posSign;
        std::string m_name;


        // BAR BUILDING
        sf::Texture m_textureBar;
        sf::Sprite m_spriteBar;
        sf::Vector2f m_positionBar;

        // GAUGE BUILDING
        sf::Texture m_textureGauge;
        sf::Sprite m_spriteGauge;

        // A BUTTON
        sf::Texture m_textureButtonA;
        sf::Sprite m_spriteButtonA;
        sf::Vector2f m_positionButtonA;

        // ICON WORKER
        sf::Texture m_textureWorker;
        sf::Sprite m_spriteWorker;
        sf::Vector2f m_positionWorker;

        // ICON BAD EVENT
        sf::Texture m_textureBadEvent;
        sf::Sprite m_spriteBadEvent;
        sf::Vector2f m_positionBadEvent;

        // ICON GOOD EVENT
        sf::Texture m_textureGoodEvent;
        sf::Sprite m_spriteGoodEvent;
        sf::Vector2f m_positionGoodEvent;

        // FONT
        sf::Font m_font;
        sf::Text m_text;
        sf::Vector2f m_positionText;

        int m_counter;
        int m_necessaryClick;
        int m_worker;
        bool m_badEvent;
        bool m_goodEvent;
        bool m_displayAButton;

        sf::Time m_timeSinceLastUpdate;
        sf::Time m_TimePerFrame;
        sf::Time m_duration;

    private:

};

#endif // BUILDING_HPP
