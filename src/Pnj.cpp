#include "Pnj.hpp"

Pnj::Pnj(std::string path,  sf::Vector2f pos)
:m_uid(newUID++)
{
    m_speed = DEFAULT_SPEED;

    // Load texture
    if(!m_texture.loadFromFile(defaultCharPath+path))
    { //RAISE A LOAD TEXTURE EXCEPTION
    }

    m_texture.setSmooth(false);
    m_sprite.setTexture(m_texture);
    m_sprite.setTextureRect(sf::IntRect(0,0,CHARACTER_WIDTH,CHARACTER_HEIGHT));

    // Position init player
    m_position = sf::Vector2f(pos.x,GROUND_Y-m_sprite.getGlobalBounds().height);
    m_originPosition = m_position;
    m_sprite.setPosition(m_position);
    m_speed = 0.8f;
    m_onMove = false;
    m_movingState = MovingState::IDLERIGHT;
    m_timer = DEFAULT_TIME_WORKER;
    m_state = WorkerState::UNWORK;
    m_count = 0;
    build();
    std::cout << "PNJ build " << getUID() << std::endl;
}

Pnj::~Pnj()
{
    //dtor
}


void Pnj::draw(sf::RenderWindow* window)
{
    update(window);
    if(m_state == WorkerState::UNWORK)
    {
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
}

void Pnj::update(sf::RenderWindow* window)
{
    if(m_onMove){
        updatePosition();
        m_sprite.setPosition(m_position);
    }
    if(m_timeSinceLastUpdate > m_duration + m_TimePerFrame)
    {
        if (m_state == WorkerState::UNWORK)
        {
            updateAnimation();
        }
    } else
    {
        m_timeSinceLastUpdate += m_TimePerFrame;
    }

    if(m_timeSinceLastUpdateWork > m_durationWork + m_TimePerFrame)
    {
        m_timeSinceLastUpdateWork = sf::Time::Zero;
        if(m_count >= m_timer)
        {
            finishWork();
        }
        if (m_state == WorkerState::WORK)
        {
            m_count++;
            std::cout << "Worker " << getUID() << " for " << m_timer-m_count << std::endl;
        }
    } else
    {
        m_timeSinceLastUpdateWork += m_TimePerFrame;
    }
}

void Pnj::move(sf::Vector2f motion)
{
    m_onMove = true;
    m_motion.x += motion.x;
}

void Pnj::updatePosition()
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

void Pnj::build()
{
    sf::Sprite sprite;
    sprite.setTexture(m_texture);

    // Set animation RIGHT
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*0,0,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationRIGHT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*1,0,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationRIGHT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*2,0,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationRIGHT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*3,0,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationRIGHT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*4,0,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationRIGHT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*4,0,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationRIGHT.push_back(sprite);


    // set animation LEFT
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*0,CHARACTER_HEIGHT*1,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationLEFT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*1,CHARACTER_HEIGHT*1,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationLEFT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*2,CHARACTER_HEIGHT*1,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationLEFT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*3,CHARACTER_HEIGHT*1,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationLEFT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*3,CHARACTER_HEIGHT*1,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationLEFT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*3,CHARACTER_HEIGHT*1,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationLEFT.push_back(sprite);

    // set animation IDLERIGHT
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*3,0,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationIDLERIGHT = sprite;

    // set animation IDLELEFT
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*2,CHARACTER_HEIGHT*1,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationIDLELEFT = sprite;


    m_animationCounter = 0;

	m_timeSinceLastUpdate = sf::Time::Zero;
	m_TimePerFrame = sf::seconds(1.f / 60.f);
	m_duration = sf::seconds(0.1*(1/m_speed));

	m_timeSinceLastUpdateWork = sf::Time::Zero;
	m_durationWork = sf::seconds(1);
}

void Pnj::updateAnimation()
{
    m_timeSinceLastUpdate = sf::Time::Zero;
    switch(m_movingState)
    {
        case MovingState::IDLERIGHT:
            m_sprite.setTextureRect(m_animationIDLERIGHT.getTextureRect());
            break;
        case MovingState::IDLELEFT:
            m_sprite.setTextureRect(m_animationIDLELEFT.getTextureRect());
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

void Pnj::finishWork()
{
    m_state = WorkerState::UNWORK;
    m_count = 0;
    m_motion = sf::Vector2f(0.0,0.0);
    m_position = m_originPosition;
    m_sprite.setPosition(m_position);
    std::cout << "Worker " << m_uid << " " << "I finish the job ! "<< std::endl;
}

void Pnj::startWork()
{
    m_count = 0;
    m_state = WorkerState::WORK;
    std::cout << "Worker " << m_uid << " " << "Time to work" << std::endl;
}
