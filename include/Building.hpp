#ifndef BUILDING_HPP
#define BUILDING_HPP
#include <SFML/Audio.hpp>

#include "DrawableObject.hpp"
#include "Pnj.hpp"


class Building : public DrawableObject
{
    public:
        Building(sf::Vector2f pos);
        virtual ~Building();
        void draw(sf::RenderWindow* window);
        void update(sf::RenderWindow* window);
        void increaseLevel();
        void decreaseLevel();
        virtual void enter() {};
        virtual void produce(int i) {};
        inline std::string getName() {return m_name;}
        void addWorker(Pnj* worker);
        void removeWorker();
        void triggerEvent(EventType et, bool b);
        inline void displayButton(bool b) {m_displayButton = b;}
        inline RessourcesType getType() {return m_type;}
        inline int getLevel() {return m_level;}
        inline void highlighted(bool b) {m_highlighted = b;}
        inline int getCostToUpgrade() {return m_costToUpgrade;}
        inline sf::Vector2f getBuildPos() {return m_position;}
        virtual void trigger(){}
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

        // ICON GAUGE
        sf::Texture m_textureIconGauge;
        sf::Sprite m_spriteIconGauge;

        // A BUTTON
        sf::Texture m_textureButtonA;
        sf::Sprite m_spriteButtonA;
        sf::Vector2f m_positionButtonA;

        // X BUTTON
        sf::Texture m_textureButtonX;
        sf::Sprite m_spriteButtonX;

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

        // HIGHLIGHTED
        sf::Texture m_textureHighlighted;
        sf::Sprite m_spriteHighlighted;

        // STAR
        sf::Texture m_textureStar;
        std::vector<sf::Sprite> m_stars;

        // FONT
        sf::Font m_font;
        sf::Text m_text;
        sf::Vector2f m_positionText;

        int m_counter;
        int m_necessaryClick;
        std::vector<Pnj*> m_workers;
        bool m_badEvent;
        bool m_goodEvent;
        bool m_displayButton;
        bool m_highlighted;
        bool m_displayGauge;

        sf::Time m_timeSinceLastUpdate;
        sf::Time m_TimePerFrame;
        sf::Time m_duration;

        RessourcesType m_type;

        sf::Music m_soundWorkDone;
        sf::Music m_soundUpgrade;

    private:

};

#endif // BUILDING_HPP
