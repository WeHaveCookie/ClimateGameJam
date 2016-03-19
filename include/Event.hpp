#ifndef EVENT_HPP
#define EVENT_HPP

#include "DrawableObject.hpp"
#include "Building.hpp"

class Event : public DrawableObject
{
    public:
        Event(Building* building, bool event, std::string desc, int id, std::string name);
        virtual ~Event();

        void draw(sf::RenderWindow* window);
        void update(sf::RenderWindow* window);
        inline void trigger() {m_onFocus = true;}
        void launch();
        virtual void stop();
        virtual void proceed() = 0;
        inline bool isFocus() {return m_onFocus;}
        inline EventState getState() {return m_state;}
        inline int getId() {return m_id;}
    protected:
        Building* m_building;
        EventType m_type;
        EventState m_state;
        sf::Time m_timeSinceLastUpdate;
        sf::Time m_TimePerFrame;
        sf::Time m_duration;
        int m_id;
        bool m_onFocus;
        std::string m_name;
        int m_counter;
        int m_timer;



    private:



        std::string m_descriptor;

        // FONT
        sf::Font m_font;
        sf::Text m_text;
        sf::Vector2f m_positionText;

        // A Button
        sf::Texture m_textureButtonA;
        sf::Sprite m_spriteButtonA;
        sf::Vector2f m_positionButtonA;

        // FONT Accepte
        sf::Text m_textAccept;
        sf::Vector2f m_positionTextAccept;


        // X Button
        sf::Texture m_textureButtonX;
        sf::Sprite m_spriteButtonX;
        sf::Vector2f m_positionButtonX;

        // FONT
        sf::Text m_textDecline;
        sf::Vector2f m_positionTextDecline;

};

#endif // EVENT_HPP
