#include "Post.hpp"

Post::Post(std::string textString, int order)
{
    m_like = 0;
    m_dislike = 0;
    m_order = order;
    if(!m_texture.loadFromFile(defaultInstaFarmPath+textString))
    { // RAISE ERROR
    }
    m_texture.setSmooth(true);
    m_sprite.setTexture(m_texture);
    m_position = sf::Vector2f((663.0f/2.0f)-(373.0f/2.0f),100.0f);
    m_sprite.setPosition(m_position);
    if(!m_font.loadFromFile(defaultFontPath+"wonder.TTF"))
    { // RAISE ERROR
    }

    m_textLike.setFont(m_font);
    m_textLike.setCharacterSize(10);
    m_textLike.setColor(sf::Color::Black);

    m_textDislike.setFont(m_font);
    m_textDislike.setCharacterSize(10);
    m_textDislike.setColor(sf::Color::Black);


    m_textString = textString;

    /*m_textPost.setFont(m_font);
    m_textPost.setCharacterSize(8);
    m_textPost.setColor(sf::Color::Black);*/

    m_textLike.setPosition(m_positionLike);
    m_textDislike.setPosition(m_positionDislike);
    m_textPost.setPosition(m_positionPost);

    //m_textPost.setString(textString);

    std::cout << "Post " << m_order << " build Done" << std::endl;


}

Post::~Post()
{
    //dtor
}

void Post::draw(sf::RenderWindow* window)
{
    update();
    window->draw(m_sprite);
    window->draw(m_textLike);
    window->draw(m_textDislike);

}

void Post::update()
{
    //m_sprite.setPosition(m_position);
    m_position = sf::Vector2f((663.0f/2.0f)-(373.0f/2.0f),m_order*((m_sprite.getGlobalBounds().height)+100) + 100.0f);
    m_sprite.setPosition(m_position);
    m_positionLike = sf::Vector2f(m_sprite.getGlobalBounds().left + 286.0f, m_sprite.getGlobalBounds().top + 390.0f);
    m_textLike.setPosition(m_positionLike);
    m_positionDislike = sf::Vector2f(m_sprite.getGlobalBounds().left + 346.0f, m_sprite.getGlobalBounds().top + 390.0f);
    m_textDislike.setPosition(m_positionDislike);
    m_positionPost = sf::Vector2f(m_sprite.getGlobalBounds().left + 45.0f, m_sprite.getGlobalBounds().top + 45.0f);
    m_textPost.setPosition(m_positionPost);


    m_textLike.setString(std::to_string(m_like));
    m_textDislike.setString(std::to_string(m_dislike));
}

void Post::increase(PostType tp, int value)
{
    switch(tp)
    {
        case PostType::LIKE:
            if (m_like += value < 0)
            {
                m_like = 0;
            }
            break;
        case PostType::DISLIKE:
            if (m_dislike += value < 0)
            {
                m_dislike = 0;
            }
            break;
        default:
            break;
    }
}

void Post::setTypeValye(PostType tp, int value)
{
    switch(tp)
    {
        case PostType::LIKE:
            m_like = value;
            break;
        case PostType::DISLIKE:
            m_dislike = value;
            break;
        default:
            break;
    }
}

int Post::getTypeValue(PostType tp)
{
    switch(tp)
    {
        case PostType::LIKE:
            return m_like;
            break;
        case PostType::DISLIKE:
            return m_dislike;
            break;
        default:
            break;
    }
}
