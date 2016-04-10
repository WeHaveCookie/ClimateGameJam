#ifndef PNJ_HPP
#define PNJ_HPP
#include "DrawableObject.hpp"

class Pnj : public DrawableObject
{


    public:

        Pnj(std::string path, sf::Vector2f pos);
        virtual ~Pnj();

        // Function
        void draw(sf::RenderWindow* window);
        void update(sf::RenderWindow* window);
        void move(sf::Vector2f motion);
        void updateAnimation();

        // Inline
        inline sf::Sprite getSprite() {return m_sprite;}
        inline void setSpeed(float f) {m_speed = f; m_duration = sf::seconds(0.1/m_speed);}
        inline float getSpeed() {return m_speed;}
        inline int getUID() {return m_uid;}
        inline bool isFinished() {return m_state == WorkerState::UNWORK;}
        void finishWork();
        void startWork();

    protected:
    private:
        // Function
        void updatePosition();
        void build();

        // Attribut
        sf::Vector2f m_motion;
        bool m_onMove;

        const int m_uid;
        // Animate
        std::vector<sf::Sprite> m_animationLEFT;
        std::vector<sf::Sprite> m_animationRIGHT;
        sf::Sprite m_animationIDLERIGHT;
        sf::Sprite m_animationIDLELEFT;

        int m_animationCounter;
        sf::Time m_timeSinceLastUpdate;
        sf::Time m_TimePerFrame;
        sf::Time m_duration;

        sf::Time m_timeSinceLastUpdateWork;
        sf::Time m_durationWork;

        WorkerState m_state;
        int m_timer;
        int m_count;

        static int newUID;

};

#endif // PNJ_HPP
