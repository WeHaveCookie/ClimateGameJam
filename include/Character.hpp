#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <SFML/Graphics.hpp>
#include "Constante.hpp"
#include "DrawableObject.hpp"
#include "Controller.hpp"
#include "Structure.hpp"

class Controller;

class Character : public DrawableObject
{
public:
    Character(std::string path, Controller* controller);
    virtual ~Character();

    // Function
    void draw(sf::RenderWindow* window);
    void update(sf::RenderWindow* window);
    void move(sf::Vector2f motion);
    void updateAnimation();
    void addNotoriety(int value);

    // Inline
    inline sf::Sprite getSprite() {return m_sprite;}
    inline void setSpeed(float f) {m_speed = f; m_duration = sf::seconds(0.1/m_speed);}
    inline float getSpeed() {return m_speed;}
    inline int getNotoriety() {return m_notoriety;}

protected:
private:
    // Function
    void updatePosition();
    void build();

    // Attribut
    sf::Vector2f m_motion;
    bool m_onMove;

    // Animate

    std::vector<sf::Sprite> m_animationLEFT;
    std::vector<sf::Sprite> m_animationRIGHT;
    std::vector<sf::Sprite> m_animationIDLERIGHT;
    std::vector<sf::Sprite> m_animationIDLELEFT;

    int m_animationCounter;
    sf::Time m_timeSinceLastUpdate;
	sf::Time m_TimePerFrame;
	sf::Time m_duration;

	int m_notoriety;

	Controller* m_controller;
};

#endif // CHARACTER_HPP
