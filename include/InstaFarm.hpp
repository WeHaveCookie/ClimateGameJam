#ifndef INSTAHouse_HPP
#define INSTAHouse_HPP
#include <math.h>
#include "DrawableObject.hpp"
#include "Post.hpp"
#include "Constante.hpp"
#include "Controller.hpp"

class Controller;

class InstaFarm : public DrawableObject
{
    public:
        InstaFarm(Controller* controller);
        virtual ~InstaFarm();
        void draw(sf::RenderWindow* window);
        void drawPost(sf::RenderWindow* window);
        void update(sf::RenderWindow* window);
        void addPost(Post* post);
        void updateNotoriety(int notoriety);
        int expo(int value, int notoriety);
        inline int getNbrPost() {return m_posts.size();}


    protected:
    private:
        std::vector<Post*> m_posts;
        std::vector<sf::Sprite*> m_separators;
        Controller* m_controller;
        // SEP ICON
        sf::Texture m_textureSep;
        sf::Sprite m_spriteSep;
        sf::Vector2f m_positionSep;

        // CURSOR ICON
        sf::Texture m_textureCursor;
        sf::Sprite m_spriteCursor;
        sf::Vector2f m_positionCursor;

        sf::Time m_timeSinceLastUpdate;
        sf::Time m_TimePerFrame;
        sf::Time m_duration;
};

#endif // INSTAHouse_HPP
