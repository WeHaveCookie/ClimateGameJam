#include "Event.hpp"

Event::Event(Building* building, bool event, std::string desc, int id, std::string name)
{

    m_building = building;
    m_id = id;
    m_name = name;
    m_counter = 0;
    (event)?m_type = EventType::GOOD: m_type = EventType::BAD;
    m_descriptor = desc;
    m_onFocus = false;
    m_state = EventState::WAITED;
    m_timer = rand()%25+5;
    if(!m_font.loadFromFile(defaultFontPath + "wonder.TTF"))
    { // RAISE ERROR
    }

    if(!m_texture.loadFromFile(defaultEventdingPath + "back.png"))
    { // RAISE ERROR
    }
    m_texture.setSmooth(true);
    m_sprite.setTexture(m_texture);


    // A Button
    if(!m_textureButtonA.loadFromFile(defaultHUDPath + "ButtonA.png"))
    { // RAISE ERROR
    }
    m_textureButtonA.setSmooth(true);
    m_spriteButtonA.setTexture(m_textureButtonA);


    // X Button
    if(!m_textureButtonX.loadFromFile(defaultHUDPath + "ButtonX.png"))
    { // RAISE ERROR
    }
    m_textureButtonX.setSmooth(true);
    m_spriteButtonX.setTexture(m_textureButtonX);

    m_text.setFont(m_font);
    m_text.setCharacterSize(12);
    m_text.setColor(sf::Color::Black);
    m_text.setString(desc);

    m_textAccept.setFont(m_font);
    m_textAccept.setCharacterSize(12);
    m_textAccept.setColor(sf::Color::Green);
    m_textAccept.setString("Accept");

    m_textDecline.setFont(m_font);
    m_textDecline.setCharacterSize(12);
    m_textDecline.setColor(sf::Color::Red);
    m_textDecline.setString("Decline");

    m_timeSinceLastUpdate = sf::Time::Zero;
    m_TimePerFrame = sf::seconds(1.f / 60.f);
    m_duration = sf::seconds(1);
}

Event::~Event()
{
    //dtor
}

void Event::draw(sf::RenderWindow* window)
{
    m_position = sf::Vector2f(window->getSize().x/2.0 - m_sprite.getGlobalBounds().width/2.0,window->getSize().y /2 - m_sprite.getGlobalBounds().height/2.0);
    m_sprite.setPosition(m_position);
    m_position = sf::Vector2f(m_position.x +  3*TEXT_RESSOURCES_PADDING,m_position.y + m_text.getCharacterSize());
    m_text.setPosition(m_position);
    m_positionButtonA = sf::Vector2f(m_position.x+PADDING_A_BUILDING,m_position.y + m_sprite.getGlobalBounds().height*(3/4));
    m_spriteButtonA.setPosition(m_positionButtonA);
    m_positionTextAccept = sf::Vector2f(m_positionButtonA.x +  TEXT_RESSOURCES_PADDING,m_positionButtonA.y+m_spriteButtonA.getGlobalBounds().height);
    m_textAccept.setPosition(m_positionTextAccept);
    m_positionButtonX = sf::Vector2f(m_positionTextAccept.x + m_textAccept.getGlobalBounds().width + PADDING_A_BUILDING,m_position.y + m_sprite.getGlobalBounds().height*(3/4));
    m_spriteButtonX.setPosition(m_positionButtonX);
    m_positionTextDecline = sf::Vector2f(m_positionButtonX.x+ TEXT_RESSOURCES_PADDING,m_positionButtonX.y+m_spriteButtonX.getGlobalBounds().height);
    m_textDecline.setPosition(m_positionTextDecline);

   update(window);
    if(m_onFocus)
    {
        window->draw(m_sprite);
        window->draw(m_text);
        window->draw(m_spriteButtonA);
        window->draw(m_textAccept);
        window->draw(m_spriteButtonX);
        window->draw(m_textDecline);

    }
}

void Event::update(sf::RenderWindow* window)
{
    if(m_timeSinceLastUpdate > m_duration + m_TimePerFrame)
    {
        if(m_state == EventState::ACCEPTED)
        {
            if(m_counter > m_timer)
            {
                m_state == EventState::FINISHED;
                stop();
            } else
            {
                std::cout << "Proceed on event "<< m_id << " time left " << m_timer-m_counter << std::endl;
                proceed();
            }
        }
        m_timeSinceLastUpdate = sf::Time::Zero;
    } else
    {
        m_timeSinceLastUpdate += m_TimePerFrame;
    }
}

void Event::stop()
{

}

void Event::launch()
{
    m_state = EventState::ACCEPTED;
    m_onFocus = false;
}
