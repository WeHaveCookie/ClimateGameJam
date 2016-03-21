#include "Cow.hpp"

Cow::Cow(std::string path, sf::Vector2f pos)
{
    m_speed = DEFAULT_SPEED;

    // Load texture
    if(!m_texture.loadFromFile(defaultCharPath+path))
    { //RAISE A LOAD TEXTURE EXCEPTION
    }

    m_texture.setSmooth(false);
    m_sprite.setTexture(m_texture);
    m_sprite.setTextureRect(sf::IntRect(0,0,COW_WIDTH,COW_HEIGHT));

    // Position init player
    m_position = sf::Vector2f(pos.x,GROUND_Y-m_sprite.getGlobalBounds().height);
    m_sprite.setPosition(m_position);
    m_speed = 0.8f;
    m_onMove = false;
    m_movingState = MovingState::IDLERIGHT;
    build();
    std::cout << "Cow build " << std::endl;
}

Cow::~Cow()
{
    //dtor
}


void Cow::draw(sf::RenderWindow* window)
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

void Cow::update(sf::RenderWindow* window)
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

void Cow::move(sf::Vector2f motion)
{
    m_onMove = true;
    m_motion.x += motion.x;
}

void Cow::updatePosition()
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
        //m_position = sf::Vector2f((m_positionInWorld%(PATTERN_WIDTH*PATTERN_NBR))*SPRITE_WIDTH,(m_positionInWorld/(PATTERN_WIDTH*PATTERN_NBR))*SPRITE_HEIGHT);
    }
}

void Cow::build()
{
    sf::Sprite sprite;
    m_texture.setSmooth(true);
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
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*5,0,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationRIGHT.push_back(sprite);

    // set animation IDLERIGHT
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*0,CHARACTER_HEIGHT*1,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationIDLERIGHT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*1,CHARACTER_HEIGHT*1,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationIDLERIGHT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*2,CHARACTER_HEIGHT*1,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationIDLERIGHT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*3,CHARACTER_HEIGHT*1,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationIDLERIGHT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*4,CHARACTER_HEIGHT*1,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationIDLERIGHT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*5,CHARACTER_HEIGHT*1,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationIDLERIGHT.push_back(sprite);

    // set animation LEFT
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*0,CHARACTER_HEIGHT*2,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationLEFT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*1,CHARACTER_HEIGHT*2,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationLEFT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*2,CHARACTER_HEIGHT*2,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationLEFT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*3,CHARACTER_HEIGHT*2,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationLEFT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*4,CHARACTER_HEIGHT*2,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationLEFT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*5,CHARACTER_HEIGHT*2,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationLEFT.push_back(sprite);


     // set animation IDLELEFT
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*0,CHARACTER_HEIGHT*3,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationIDLELEFT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*1,CHARACTER_HEIGHT*3,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationIDLELEFT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*2,CHARACTER_HEIGHT*3,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationIDLELEFT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*3,CHARACTER_HEIGHT*3,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationIDLELEFT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*4,CHARACTER_HEIGHT*3,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationIDLELEFT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHARACTER_WIDTH*5,CHARACTER_HEIGHT*3,CHARACTER_WIDTH,CHARACTER_HEIGHT));
    m_animationIDLELEFT.push_back(sprite);

    m_animationCounter = 0;
    sf::Clock tickClock;
	m_timeSinceLastUpdate = sf::Time::Zero;
	m_TimePerFrame = sf::seconds(1.f / 60.f);
	m_duration = sf::seconds(0.1*(1/m_speed));
}

void Cow::updateAnimation()
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
