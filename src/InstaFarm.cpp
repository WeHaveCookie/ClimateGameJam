#include "InstaFarm.hpp"

InstaFarm::InstaFarm(Controller* controller)
{
    m_controller = controller;
    if(!m_texture.loadFromFile(defaultInstaFarmPath+"back.png"))
    { // RAISE ERROR
    }
    m_texture.setSmooth(true);
    m_sprite.setTexture(m_texture);

    if(!m_textureBar.loadFromFile(defaultInstaFarmPath+"bar.png"))
    { // RAISE ERROR
    }
    m_textureBar.setSmooth(true);
    m_spriteBar.setTexture(m_textureBar);


    sf::Vector2f m_positionBar = sf::Vector2f(671.0f,136.0f);

    m_timeSinceLastUpdate = sf::Time::Zero;
    m_TimePerFrame = sf::seconds(1.f / 60.f);
    m_duration = sf::seconds(5);
}

InstaFarm::~InstaFarm()
{
    //dtor
}

void InstaFarm::draw(sf::RenderWindow* window)
{
    update(window);
    window->draw(m_sprite);
    window->draw(m_spriteBar);
}

void InstaFarm::drawPost(sf::RenderWindow* window)
{
    std::reverse(m_posts.begin(),m_posts.end());
    for(int i = 0; i < (int)m_posts.size(); i++)
    {
        m_posts[i]->updateOrder(i);
        m_posts[i]->draw(window);
    }
    std::reverse(m_posts.begin(),m_posts.end());
    for(int i = 0; i < (int)m_posts.size(); i++)
    {
        m_posts[i]->updateOrder(i);
    }
}

void InstaFarm::update(sf::RenderWindow* window)
{
    m_spriteBar.setPosition(m_positionBar);
}


void InstaFarm::addPost(Post* post)
{
    m_posts.push_back(post);
    for(int i = 0; i < (int)m_posts.size(); i++)
    {
        m_posts[i]->update();
    }
    if(m_posts.size()%2 != 0)
    {
        sf::Sprite sprite;
        sprite.setTexture(m_texture);
        sprite.setPosition(sf::Vector2f(post->getGlobalBounds().top,post->getGlobalBounds().left + post->getGlobalBounds().height + PADDING_Y_WORKER_BUILDING));
        m_separators.push_back(&sprite);
    }
}

void InstaFarm::updateNotoriety(int notoriety)
{
    if(m_timeSinceLastUpdate > m_duration + m_TimePerFrame)
    {

        if(m_posts.size() > 0)
        {
            int like, dislike;
            like = expo(m_posts[m_posts.size()-1]->getTypeValue(PostType::LIKE),notoriety) + m_posts[m_posts.size()-1]->getTypeValue(PostType::LIKE) ;
            dislike = expo(m_posts[m_posts.size()-1]->getTypeValue(PostType::DISLIKE),200-notoriety) + m_posts[m_posts.size()-1]->getTypeValue(PostType::DISLIKE);
            if(dislike>like)
            {
                m_controller->addNotoriety(-1);
            } else
            {
                m_controller->addNotoriety(1);
            }
            m_posts[m_posts.size()-1]->setTypeValye(PostType::LIKE,like);
            m_posts[m_posts.size()-1]->setTypeValye(PostType::DISLIKE,dislike);
        }
        m_timeSinceLastUpdate = sf::Time::Zero;
    } else
    {
        m_timeSinceLastUpdate += m_TimePerFrame;
    }

}

int InstaFarm::expo(int value, int notoriety)
{
    return round(log2(value+(notoriety/100)*pow(2,getNbrPost())+2));
}
