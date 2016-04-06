#include "Building.hpp"

Building::Building(sf::Vector2f pos)
{
    m_level = 0;
    m_counter = 0;
    m_displayButton = false;
    m_necessaryClick = INIT_NECESSARY_CLICK;
    m_badEvent = false;
    m_goodEvent = false;
    m_highlighted = false;
    m_displayGauge = true;
    m_costToUpgrade = DEFAULT_COST_TO_UPGRADE;
    m_type = RessourcesType::NONE;

    if(!m_soundWorkDone.openFromFile(defaultFXPath+"workDone.ogg"))
    { // RAISE ERROR
    }
    m_soundWorkDone.setVolume(DEFAUT_VOLUME_FEEDBACK);

    if(!m_soundUpgrade.openFromFile(defaultFXPath+"upgrade.ogg"))
    { // RAISE ERROR
    }
    m_soundUpgrade.setVolume(DEFAUT_VOLUME_FEEDBACK);

    if(!m_texture.loadFromFile(defaultBuildingPath+"sign.png"))
    { // RAISE ERROR
    }
    m_texture.setSmooth(true);
    m_sprite.setTexture(m_texture);

    m_position = sf::Vector2f(pos.x,GROUND_Y-m_sprite.getGlobalBounds().height);
    m_posSign = m_position;
    if(!m_textureBar.loadFromFile(defaultBuildingPath+"Fond_Jauge.png"))
    { // RAISE ERROR
    }
    m_textureBar.setSmooth(true);
    m_spriteBar.setTexture(m_textureBar);


    if(!m_textureGauge.loadFromFile(defaultBuildingPath+"Jauge.png"))
    { // RAISE ERROR
    }
    m_textureGauge.setSmooth(true);
    m_spriteGauge.setTexture(m_textureGauge);


    if(!m_textureButtonA.loadFromFile(defaultHUDPath+"buttonA.png"))
    { // RAISE ERROR
    }
    m_textureButtonA.setSmooth(true);
    m_spriteButtonA.setTexture(m_textureButtonA);

    if(!m_textureIconGauge.loadFromFile(defaultBuildingPath+"rouage.png"))
    { // RAISE ERROR
    }
    m_textureIconGauge.setSmooth(true);
    m_spriteIconGauge.setTexture(m_textureIconGauge);

    // X BUTTON
    if(!m_textureButtonX.loadFromFile(defaultHUDPath+"buttonX.png"))
    { // RAISE ERROR
    }
    m_textureButtonX.setSmooth(true);
    m_spriteButtonX.setTexture(m_textureButtonX);


    if(!m_textureWorker.loadFromFile(defaultBuildingPath+"workerIcon.png"))
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
    if(!m_textureGoodEvent.loadFromFile(defaultShopPath+"bonus.png"))
    { // RAISE ERROR
    }
    m_textureGoodEvent.setSmooth(true);
    m_spriteGoodEvent.setTexture(m_textureGoodEvent);

    if(!m_textureStar.loadFromFile(defaultBuildingPath+"stars.png"))
    { // RAISE ERROR
    }

    for(int i = 0; i < MAX_BUILDING_LEVEL; i++)
    {
        sf::Sprite spr;
        spr.setTexture(m_textureStar);
        spr.setTextureRect(sf::IntRect(0,0,14,13));
        m_stars.push_back(spr);
    }


    if(!m_font.loadFromFile(defaultFontPath + "wonder.TTF"))
    { // RAISE ERROR
    }

    m_text.setFont(m_font);
    m_text.setCharacterSize(12);
    m_text.setColor(sf::Color::White);
    //m_spriteGauge.setColor(sf::Color::Blue);

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
    if(m_highlighted)
    {
        if(m_level == 0)
        {
            if(!m_textureHighlighted.loadFromFile(defaultBuildingPath+"signhi.png"))
            { // RAISE ERROR
            }
            m_textureHighlighted.setSmooth(true);
            m_spriteHighlighted.setTexture(m_textureHighlighted);
            m_spriteHighlighted.setTextureRect(sf::IntRect(0,0,SIGN_HEIGHT,SIGN_WIDTH));
        }
        window->draw(m_spriteHighlighted);
    } else
    {
        window->draw(m_sprite);
    }
    if(m_level > 0)
    {
        if(m_displayGauge)
        {
            window->draw(m_spriteBar);
            window->draw(m_spriteGauge);
            window->draw(m_spriteIconGauge);
        }
        //window->draw(m_text);
            // DRAW STAR
        for(int i = 0; i < (int)m_stars.size(); i++)
        {
            window->draw(m_stars[i]);
        }
    }
    if(m_displayButton)
    {
        if(m_level == 0)
        {
            window->draw(m_spriteButtonX);
        } else
        {
            if(m_displayGauge)
            {
                window->draw(m_spriteButtonA);
            }
        }
    }

    // DRAW WORKER ICON
    for(int i = 0; i < (int)m_workers.size(); i++)
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
    m_spriteHighlighted.setPosition(m_position);
    m_sprite.setPosition(m_position);
    if(m_level > 0)
    {
        m_positionBar = sf::Vector2f(m_position.x + m_sprite.getGlobalBounds().width/2.0 - m_spriteBar.getGlobalBounds().width/2.0,m_position.y-PADDING_BAR_BUILDING*3);
        m_positionButtonA = sf::Vector2f(m_positionBar.x-m_spriteButtonA.getGlobalBounds().width-PADDING_A_BUILDING,m_positionBar.y-(m_spriteButtonA.getGlobalBounds().width/2.0)+PADDING_A_BUILDING*1.5);
    } else
    {
        m_positionButtonA = sf::Vector2f(m_position.x+(SIGN_WIDTH/2.0)-(m_spriteButtonA.getGlobalBounds().width/2.0),m_position.y - m_spriteButtonA.getGlobalBounds().height - PADDING_A_BUILDING);
    }
    m_spriteButtonA.setPosition(m_positionButtonA);
    m_spriteButtonX.setPosition(m_positionButtonA);
    m_spriteBar.setPosition(m_positionBar);
    m_spriteGauge.setPosition(m_positionBar);
    m_spriteIconGauge.setPosition(m_positionBar);
    for(int i = 0; i < (int)m_stars.size(); i++)
    {
        m_stars[i].setPosition(sf::Vector2f(m_positionBar.x + m_spriteBar.getGlobalBounds().width + 10 + i*(PADDING_X_WORKER_BUILDING+m_stars[i].getGlobalBounds().width),m_positionBar.y));
    }


    m_text.setPosition(sf::Vector2f(m_positionBar.x+m_spriteBar.getGlobalBounds().width - (m_text.getGlobalBounds().width+TEXT_RESSOURCES_PADDING),m_positionBar.y+m_text.getCharacterSize()));
    m_text.setString(std::to_string(m_counter) + "/"+ std::to_string(m_necessaryClick));

    m_spriteGauge.setScale(sf::Vector2f((float)m_counter/(float)m_necessaryClick,1));
    m_spriteGauge.setPosition(m_positionBar);

    if(m_timeSinceLastUpdate > m_duration + m_TimePerFrame)
    {
        // INCREMENT WITH WORKER
        produce((int)m_workers.size());
        m_timeSinceLastUpdate = sf::Time::Zero;
    } else
    {
        m_timeSinceLastUpdate += m_TimePerFrame;
    }

    std::vector<int> deleteWorker;
    for(int i = 0; i < (int)m_workers.size(); i++)
    {
        if(m_workers[i]->isFinished())
        {
            m_soundWorkDone.play();
            deleteWorker.push_back(i);
            std::cout << "Building : Worker " << m_workers[i]->getUID() << " as finished " << std::endl;
        }
    }
    int eraseCount = 0;
    for(int i = 0; i < (int)deleteWorker.size(); i++)
    {
        std::vector<Pnj*>::iterator it = m_workers.begin()+deleteWorker[i]-eraseCount++;
        std::cout << "Erase worker " << m_workers[i]->getUID() << std::endl;
        m_workers.erase(it);
    }
    if((int)deleteWorker.size() > 0)
    {
        m_workers.shrink_to_fit();
        std::cout << "Shrink to fit done" << std::endl;
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
        m_position = sf::Vector2f(m_position.x - ((BUILDING_WIDTH/2.0)-(SIGN_WIDTH/2.0)),GROUND_Y-BUILDING_HEIGHT);
    }
    if(++m_level > MAX_BUILDING_LEVEL)
    {
        m_level--;
    }
    m_sprite.setTextureRect(sf::IntRect((/*m_level*/1-1)*BUILDING_WIDTH,0,BUILDING_WIDTH,BUILDING_HEIGHT));
    m_stars[m_level-1].setTextureRect(sf::IntRect(14,0,14,13));
    m_necessaryClick -= 2;
    m_costToUpgrade += 50*pow(2,m_level);
    m_soundUpgrade.play();
    this->trigger();
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
        m_sprite.setTextureRect(sf::IntRect((/*m_level*/1-1)*BUILDING_WIDTH,0,BUILDING_WIDTH,BUILDING_HEIGHT));
    }
    m_stars[m_level].setTextureRect(sf::IntRect(0,0,14,13));
    m_necessaryClick += 2;
    m_costToUpgrade -= 50;
}

void Building::addWorker(Pnj* worker)
{
    if(m_workers.size()<=3)
    {
        worker->setOriginPosition(sf::Vector2f(m_position.x + BUILDING_WIDTH/2+rand()%80-40,0.0f));
        worker->startWork();
        m_workers.push_back(worker);
    }
}

void Building::removeWorker()
{
    if(m_workers.size() > 0)
    {
        Pnj* worker = m_workers[m_workers.size()-1];
        worker->finishWork();
        m_workers.pop_back();
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

bool Building::isWorkable()
{
    return !(m_type == RessourcesType::MONEY || m_type == RessourcesType::NONE || m_type == RessourcesType::STORAGE);
}
