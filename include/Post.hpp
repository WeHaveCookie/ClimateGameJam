#ifndef POST_HPP
#define POST_HPP

#include "DrawableObject.hpp"

class Post : public DrawableObject
{
    public:
        Post(std::string textString, int order);
        virtual ~Post();
        void draw(sf::RenderWindow* window);
        void update();
        void increase(PostType tp, int value);
        void setTypeValye(PostType tp, int value);
        int getTypeValue(PostType tp);
        inline void setPosition(sf::Vector2f pos) {m_position = pos;}
        inline void updateOrder(int order) {m_order = order;}
    protected:
    private:
        int m_like;
        int m_dislike;
        int m_order;

        // FONT
        sf::Font m_font;
        sf::Text m_textLike;
        sf::Text m_textDislike;
        sf::Vector2f m_positionLike;
        sf::Vector2f m_positionDislike;

        sf::Text m_textPost;
        sf::Vector2f m_positionPost;

        std::string m_textString;

};

#endif // POST_HPP
