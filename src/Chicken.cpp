#include "Chicken.hpp"

Chicken::Chicken(std::string path,  sf::Vector2f pos)
{
    m_speed = DEFAULT_SPEED;

    // Load texture
    if(!m_texture.loadFromFile(defaultCharPath+path))
    { //RAISE A LOAD TEXTURE EXCEPTION
    }

    m_texture.setSmooth(false);
    m_sprite.setTexture(m_texture);
    m_sprite.setTextureRect(sf::IntRect(0,0,CHICKEN_WIDTH,CHICKEN_HEIGHT));

    // Position init player
    m_position = sf::Vector2f(pos.x,GROUND_Y-m_sprite.getGlobalBounds().height);
    m_sprite.setPosition(m_position);
    m_speed = 0.8f;
    m_onMove = false;
    m_movingState = MovingState::IDLERIGHT;
    build();
    std::cout << "Chicken build " << std::endl;
}

Chicken::~Chicken()
{
    //dtor
}


void Chicken::draw(sf::RenderWindow* window)
{
    update(window);
    window->draw(m_sprite);
    if(m_animationCounter == 0)
    {
        if(m_movingState == MovingState::RIGHT)
        {
            m_movingState = MovingState::IDLERIGHT;
        } else if (m_movingState == MovingState::LEFT)
        {
            m_movingState = MovingState::IDLELEFT;
        }

    }
}

void Chicken::update(sf::RenderWindow* window)
{
    if(m_onMove){
        updatePosition();
        m_sprite.setPosition(m_position);
    }
    if(m_timeSinceLastUpdate > m_duration + m_TimePerFrame)
    {
        updateAnimation();
    } else
    {
        m_timeSinceLastUpdate += m_TimePerFrame;
    }
}

void Chicken::move(sf::Vector2f motion)
{
    m_onMove = true;
    m_motion.x += motion.x;
}

void Chicken::updatePosition()
{
      if(m_motion.x > 0)
    { // Go to RIGHT
        m_position.x += 2*m_speed;
        m_motion.x -= 2*m_speed;
        m_movingState = MovingState::RIGHT;
        if(m_motion.x < 0)
        {
            m_position.x += m_motion.x;
            m_motion.x = 0;
        }
    } else if (m_motion.x < 0)
    { // Go to LEFT
        m_position.x -= 2*m_speed;
        m_motion.x += 2*m_speed;
        m_movingState = MovingState::LEFT;
        if(m_motion.x > 0)
        {
            m_position.x -= m_motion.x;
            m_motion.x = 0;
        }
    } else
    { // End of mouvment
        m_animationCounter = 0;
        m_onMove = false;
        if(m_movingState == MovingState::RIGHT)
        {
            m_movingState = MovingState::IDLERIGHT;
        } else if (m_movingState == MovingState::LEFT)
        {
            m_movingState = MovingState::IDLELEFT;
        }
    }
}

void Chicken::build()
{
    sf::Sprite sprite;
    m_texture.setSmooth(true);
    sprite.setTexture(m_texture);

    // Set animation RIGHT
    sprite.setTextureRect(sf::IntRect(CHICKEN_WIDTH*0,0,CHICKEN_WIDTH,CHICKEN_HEIGHT));
    m_animationRIGHT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHICKEN_WIDTH*1,0,CHICKEN_WIDTH,CHICKEN_HEIGHT));
    m_animationRIGHT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHICKEN_WIDTH*2,0,CHICKEN_WIDTH,CHICKEN_HEIGHT));
    m_animationRIGHT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHICKEN_WIDTH*3,0,CHICKEN_WIDTH,CHICKEN_HEIGHT));
    m_animationRIGHT.push_back(sprite);


    // set animation LEFT
    sprite.setTextureRect(sf::IntRect(CHICKEN_WIDTH*0,CHICKEN_HEIGHT*1,CHICKEN_WIDTH,CHICKEN_HEIGHT));
    m_animationLEFT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHICKEN_WIDTH*1,CHICKEN_HEIGHT*1,CHICKEN_WIDTH,CHICKEN_HEIGHT));
    m_animationLEFT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHICKEN_WIDTH*2,CHICKEN_HEIGHT*1,CHICKEN_WIDTH,CHICKEN_HEIGHT));
    m_animationLEFT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHICKEN_WIDTH*3,CHICKEN_HEIGHT*1,CHICKEN_WIDTH,CHICKEN_HEIGHT));
    m_animationLEFT.push_back(sprite);

    // set animation IDLERIGHT
    sprite.setTextureRect(sf::IntRect(CHICKEN_WIDTH*0,CHICKEN_HEIGHT*2,CHICKEN_WIDTH,CHICKEN_HEIGHT));
    m_animationIDLERIGHT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHICKEN_WIDTH*1,CHICKEN_HEIGHT*2,CHICKEN_WIDTH,CHICKEN_HEIGHT));
    m_animationIDLERIGHT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHICKEN_WIDTH*2,CHICKEN_HEIGHT*2,CHICKEN_WIDTH,CHICKEN_HEIGHT));
    m_animationIDLERIGHT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHICKEN_WIDTH*3,CHICKEN_HEIGHT*2,CHICKEN_WIDTH,CHICKEN_HEIGHT));
    m_animationIDLERIGHT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHICKEN_WIDTH*4,CHICKEN_HEIGHT*2,CHICKEN_WIDTH,CHICKEN_HEIGHT));
    m_animationIDLERIGHT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHICKEN_WIDTH*5,CHICKEN_HEIGHT*2,CHICKEN_WIDTH,CHICKEN_HEIGHT));
    m_animationIDLERIGHT.push_back(sprite);

    // set animation IDLELEFT
    sprite.setTextureRect(sf::IntRect(CHICKEN_WIDTH*0,CHICKEN_HEIGHT*3,CHICKEN_WIDTH,CHICKEN_HEIGHT));
    m_animationIDLELEFT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHICKEN_WIDTH*1,CHICKEN_HEIGHT*3,CHICKEN_WIDTH,CHICKEN_HEIGHT));
    m_animationIDLELEFT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHICKEN_WIDTH*2,CHICKEN_HEIGHT*3,CHICKEN_WIDTH,CHICKEN_HEIGHT));
    m_animationIDLELEFT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHICKEN_WIDTH*3,CHICKEN_HEIGHT*3,CHICKEN_WIDTH,CHICKEN_HEIGHT));
    m_animationIDLELEFT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHICKEN_WIDTH*4,CHICKEN_HEIGHT*3,CHICKEN_WIDTH,CHICKEN_HEIGHT));
    m_animationIDLELEFT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHICKEN_WIDTH*5,CHICKEN_HEIGHT*3,CHICKEN_WIDTH,CHICKEN_HEIGHT));
    m_animationIDLELEFT.push_back(sprite);



    m_animationCounter = 0;
    sf::Clock tickClock;
	m_timeSinceLastUpdate = sf::Time::Zero;
	m_TimePerFrame = sf::seconds(1.f / 60.f);
	m_duration = sf::seconds(0.1*(1/m_speed));
}

void Chicken::updateAnimation()
{
    m_timeSinceLastUpdate = sf::Time::Zero;
    switch(m_movingState)
    {
        case MovingState::IDLERIGHT:
            m_sprite.setTextureRect(m_animationIDLERIGHT[m_animationCounter].getTextureRect());
            if(++m_animationCounter >= (int)m_animationIDLERIGHT.size())
            {
                m_animationCounter = 0;
            }
            break;
        case MovingState::IDLELEFT:
            m_sprite.setTextureRect(m_animationIDLELEFT[m_animationCounter].getTextureRect());
            if(++m_animationCounter >= (int)m_animationIDLELEFT.size())
            {
                m_animationCounter = 0;
            }
            break;
        case MovingState::RIGHT:
            m_sprite.setTextureRect(m_animationRIGHT[m_animationCounter].getTextureRect());
            if(++m_animationCounter >= (int)m_animationRIGHT.size())
            {
                m_animationCounter = 0;
            }
            break;
        case MovingState::LEFT:
            m_sprite.setTextureRect(m_animationLEFT[m_animationCounter].getTextureRect());
            if(++m_animationCounter >= (int)m_animationLEFT.size())
            {
                m_animationCounter = 0;
            }
            break;
        default:
            break;
    }
}
