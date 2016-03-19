#include "Building.hpp"

Building::Building(sf::Vector2f pos)
{
    m_level = 0;
    m_worker = 0;
    m_counter = 0;
    m_displayAButton = false;
    m_necessaryClick = INIT_NECESSARY_CLICK;
    m_badEvent = false;
    m_goodEvent = false;
    int m_costToUpgrade = DEFAULT_COST_TO_UPGRADE;
    m_position = pos;
    m_posSign = m_position;
    if(!m_texture.loadFromFile(defaultBuildingPath+"sign.png"))
    { // RAISE ERROR
    }
    m_texture.setSmooth(true);
    m_sprite.setTexture(m_texture);

    if(!m_textureBar.loadFromFile(defaultHUDPath+"ressourcesBAR.png"))
    { // RAISE ERROR
    }
    m_textureBar.setSmooth(true);
    m_spriteBar.setTexture(m_textureBar);


    if(!m_textureGauge.loadFromFile(defaultHUDPath+"gauge.png"))
    { // RAISE ERROR
    }
    m_textureGauge.setSmooth(true);
    m_spriteGauge.setTexture(m_textureGauge);


    if(!m_textureButtonA.loadFromFile(defaultHUDPath+"buttonA.png"))
    { // RAISE ERROR
    }
    m_textureButtonA.setSmooth(true);
    m_spriteButtonA.setTexture(m_textureButtonA);


    if(!m_textureWorker.loadFromFile(defaultBuildingPath+"worker.png"))
    { // RAISE ERROR
    }
    m_textureWorker.setSmooth(true);
    m_spriteWorker.setTexture(m_textureWorker);


    // ICON BAD MORAL
    if(!m_textureBadEvent.loadFromFile(defaultBuildingPath+"bad.png"))
    { // RAISE ERROR
    }
    m_textureBadEvent.setSmooth(true);
    m_spriteBadEvent.setTexture(m_textureBadEvent);

    // ICON GOOD MORAL
    if(!m_textureGoodEvent.loadFromFile(defaultBuildingPath+"good.png"))
    { // RAISE ERROR
    }
    m_textureGoodEvent.setSmooth(true);
    m_spriteGoodEvent.setTexture(m_textureGoodEvent);



    if(!m_font.loadFromFile(defaultFontPath + "wonder.TTF"))
    { // RAISE ERROR
    }

    m_text.setFont(m_font);
    m_text.setCharacterSize(12);
    m_text.setColor(sf::Color::White);
    m_spriteGauge.setColor(sf::Color::Blue);

    m_timeSinceLastUpdate = sf::Time::Zero;
	m_TimePerFrame = sf::seconds(1.f / 60.f);
	m_duration = sf::seconds(1);

}

Building::~Building()
{
    //dtor
}

void Building::draw(sf::RenderWindow* window)
{
    update(window);
    window->draw(m_sprite);
    if(m_level > 0)
    {
        window->draw(m_spriteBar);
        window->draw(m_spriteGauge);
        window->draw(m_text);
    }
    if(m_displayAButton)
    {
        window->draw(m_spriteButtonA);
    }

    // DRAW WORKER ICON
    for(int i = 0; i < m_worker; i++)
    {
        m_positionWorker = sf::Vector2f(m_positionBar.x+i*(m_spriteWorker.getGlobalBounds().width+PADDING_X_WORKER_BUILDING),m_positionBar.y-m_spriteWorker.getGlobalBounds().height-(i%2)*PADDING_Y_WORKER_BUILDING-PADDING_Y_WORKER_BUILDING);
        m_spriteWorker.setPosition(m_positionWorker);
        window->draw(m_spriteWorker);
    }

    // DRAW EVENT ICON
    if(m_goodEvent)
    {
        window->draw(m_spriteGoodEvent);
    } else if (m_badEvent)
    {
        window->draw(m_spriteBadEvent);
    }
}

void Building::update(sf::RenderWindow* window)
{
    m_sprite.setPosition(m_position);
    if(m_level > 0)
    {
        m_positionBar = sf::Vector2f(m_position.x,m_position.y-PADDING_BAR_BUILDING);
        m_positionButtonA = sf::Vector2f(m_positionBar.x-m_spriteButtonA.getGlobalBounds().width-PADDING_A_BUILDING,m_positionBar.y-(m_spriteButtonA.getGlobalBounds().width/2.0));
    } else
    {
        m_positionButtonA = sf::Vector2f(m_position.x+(SIGN_WIDTH/2.0)-(m_spriteButtonA.getGlobalBounds().width/2.0),m_position.y - m_spriteButtonA.getGlobalBounds().height - PADDING_A_BUILDING);
    }
    m_spriteButtonA.setPosition(m_positionButtonA);
    m_spriteBar.setPosition(m_positionBar);
    m_spriteGauge.setPosition(m_positionBar);



    m_text.setPosition(sf::Vector2f(m_positionBar.x+m_spriteBar.getGlobalBounds().width - (m_text.getGlobalBounds().width+TEXT_RESSOURCES_PADDING),m_positionBar.y+m_text.getCharacterSize()));
    m_text.setString(std::to_string(m_counter) + "/"+ std::to_string(m_necessaryClick));

    m_spriteGauge.setScale(sf::Vector2f((float)m_counter/(float)m_necessaryClick,1));
    m_spriteGauge.setPosition(m_positionBar);

    if(m_timeSinceLastUpdate > m_duration + m_TimePerFrame)
    {
        // INCREMENT WITH WORKER
        produce(m_worker);
        m_timeSinceLastUpdate = sf::Time::Zero;
    } else
    {
        m_timeSinceLastUpdate += m_TimePerFrame;
    }

    m_positionGoodEvent = sf::Vector2f(m_positionBar.x,m_positionBar.y - m_spriteWorker.getGlobalBounds().height - 2*PADDING_Y_WORKER_BUILDING - PADDING_Y_EVENT_BUILDING - m_spriteGoodEvent.getGlobalBounds().height);
    m_positionBadEvent = sf::Vector2f(m_positionBar.x+2*m_spriteGoodEvent.getGlobalBounds().width,m_positionBar.y - m_spriteWorker.getGlobalBounds().height - 2*PADDING_Y_WORKER_BUILDING - PADDING_Y_EVENT_BUILDING - m_spriteBadEvent.getGlobalBounds().height);
    m_spriteGoodEvent.setPosition(m_positionGoodEvent);
    m_spriteBadEvent.setPosition(m_positionBadEvent);
}

void Building::increaseLevel()
{
    if(m_level == 0)
    {
        m_sprite.setTexture(m_buildTexture);
        m_position = sf::Vector2f(m_position.x - ((BUILDING_WIDTH/2.0)-(SIGN_WIDTH/2.0)),756.0-BUILDING_HEIGHT);
    }
    if(++m_level > MAX_BUILDING_LEVEL)
    {
        m_level--;
    }
    m_sprite.setTextureRect(sf::IntRect((m_level-1)*BUILDING_WIDTH,0,BUILDING_WIDTH,BUILDING_HEIGHT));

}

void Building::decreaseLevel()
{
    if(--m_level < 0)
    {
        m_level = 0;
    }
    if(m_level == 0)
    {
        m_sprite.setTexture(m_texture);
        m_sprite.setTextureRect(sf::IntRect(0,0,SIGN_WIDTH,SIGN_HEIGHT));
        m_position = m_posSign;
    } else
    {
         m_sprite.setTextureRect(sf::IntRect((m_level-1)*BUILDING_WIDTH,0,BUILDING_WIDTH,BUILDING_HEIGHT));
    }
}

void Building::addWorker(int i)
{
    m_worker += i;
    if(m_worker > 3)
    {
        m_worker = 3;
    } else if (m_worker < 0)
    {
        m_worker = 0;
    }
}

void Building::triggerEvent(EventType et, bool b)
{
    switch(et)
    {
        case EventType::GOOD:
            if(m_goodEvent && !b)
            {
                m_necessaryClick++;
                m_goodEvent = false;
            } else if (!m_goodEvent && b)
            {
                m_goodEvent = true;
                m_necessaryClick--;
            }
            break;
        case EventType::BAD:
            if(m_badEvent && !b)
            {
                m_badEvent = false;
                m_necessaryClick-- ;
            } else if (!m_badEvent && b)
            {
                m_badEvent = true;
                m_necessaryClick++;
            }
            break;
        default:
            break;
    }
}
