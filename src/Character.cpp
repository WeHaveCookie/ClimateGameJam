#include "../include/Character.hpp"

Character::Character(std::string path, Controller* controller)
{
    m_speed = DEFAULT_SPEED;

    // Load texture
    if(!m_texture.loadFromFile(defaultCharPath+path))
    { //RAISE A LOAD TEXTURE EXCEPTION
    }

    m_texture.setSmooth(true);
    m_sprite.setTexture(m_texture);
    m_sprite.setTextureRect(sf::IntRect(0,0,64,64));

    // Position init player
    m_position = sf::Vector2f(100.0,692.0);
    m_sprite.setPosition(m_position);
    m_speed = 2.0f;
    m_onMove = false;
    m_movingState = MovingState::IDLE;
    m_controller = controller;
    build();
    std::cout << "Char build " << std::endl;
}

Character::~Character()
{
}

void Character::draw(sf::RenderWindow* window)
{
    update(window);
    window->draw(m_sprite);
    if(m_animationCounter == 0)
    {
        m_movingState = MovingState::IDLE;
    }
}

void Character::update(sf::RenderWindow* window)
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

void Character::move(sf::Vector2f motion)
{
    m_onMove = true;
    m_motion.x += motion.x;
}

void Character::updatePosition()
{
    if(m_motion.x < 0)
    {
        m_movingState = MovingState::LEFT;
    } else if (m_motion.x > 0)
    {
        m_movingState = MovingState::RIGHT;
    }
    m_position.x += m_motion.x*m_speed;
    m_motion.x -= m_motion.x;
    if (m_motion.x = 0.0)
    { // End of mouvment
        m_animationCounter = 0;
        m_onMove = false;
        m_movingState = MovingState::IDLE;
    }
}

void Character::build()
{
    sf::Sprite sprite;
    m_texture.setSmooth(true);
    sprite.setTexture(m_texture);

    // Set animation IDLE
    sprite.setTextureRect(sf::IntRect(SPRITE_WIDTH*0,0,SPRITE_WIDTH,SPRITE_HEIGHT));
    m_animationIDLE.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(SPRITE_WIDTH*1,0,SPRITE_WIDTH,SPRITE_HEIGHT));
    m_animationIDLE.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(SPRITE_WIDTH*2,0,SPRITE_WIDTH,SPRITE_HEIGHT));
    m_animationIDLE.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(SPRITE_WIDTH*3,0,SPRITE_WIDTH,SPRITE_HEIGHT));
    m_animationIDLE.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(SPRITE_WIDTH*4,0,SPRITE_WIDTH,SPRITE_HEIGHT));
    m_animationIDLE.push_back(sprite);


    // set animation RIGHT
    sprite.setTextureRect(sf::IntRect(SPRITE_WIDTH*0,SPRITE_HEIGHT*2,SPRITE_WIDTH,SPRITE_HEIGHT));
    m_animationRIGHT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(SPRITE_WIDTH*1,SPRITE_HEIGHT*2,SPRITE_WIDTH,SPRITE_HEIGHT));
    m_animationRIGHT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(SPRITE_WIDTH*2,SPRITE_HEIGHT*2,SPRITE_WIDTH,SPRITE_HEIGHT));
    m_animationRIGHT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(SPRITE_WIDTH*3,SPRITE_HEIGHT*2,SPRITE_WIDTH,SPRITE_HEIGHT));
    m_animationRIGHT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(SPRITE_WIDTH*4,SPRITE_HEIGHT*2,SPRITE_WIDTH,SPRITE_HEIGHT));
    m_animationRIGHT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(SPRITE_WIDTH*5,SPRITE_HEIGHT*2,SPRITE_WIDTH,SPRITE_HEIGHT));
    m_animationRIGHT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(SPRITE_WIDTH*6,SPRITE_HEIGHT*2,SPRITE_WIDTH,SPRITE_HEIGHT));
    m_animationRIGHT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(SPRITE_WIDTH*7,SPRITE_HEIGHT*2,SPRITE_WIDTH,SPRITE_HEIGHT));
    m_animationRIGHT.push_back(sprite);

    // set animation LEFT
    sprite.setTextureRect(sf::IntRect(SPRITE_WIDTH*0,SPRITE_HEIGHT*3,SPRITE_WIDTH,SPRITE_HEIGHT));
    m_animationLEFT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(SPRITE_WIDTH*1,SPRITE_HEIGHT*3,SPRITE_WIDTH,SPRITE_HEIGHT));
    m_animationLEFT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(SPRITE_WIDTH*2,SPRITE_HEIGHT*3,SPRITE_WIDTH,SPRITE_HEIGHT));
    m_animationLEFT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(SPRITE_WIDTH*3,SPRITE_HEIGHT*3,SPRITE_WIDTH,SPRITE_HEIGHT));
    m_animationLEFT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(SPRITE_WIDTH*4,SPRITE_HEIGHT*3,SPRITE_WIDTH,SPRITE_HEIGHT));
    m_animationLEFT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(SPRITE_WIDTH*5,SPRITE_HEIGHT*3,SPRITE_WIDTH,SPRITE_HEIGHT));
    m_animationLEFT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(SPRITE_WIDTH*6,SPRITE_HEIGHT*3,SPRITE_WIDTH,SPRITE_HEIGHT));
    m_animationLEFT.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(SPRITE_WIDTH*7,SPRITE_HEIGHT*3,SPRITE_WIDTH,SPRITE_HEIGHT));
    m_animationLEFT.push_back(sprite);

    m_animationCounter = 0;
    sf::Clock tickClock;
	m_timeSinceLastUpdate = sf::Time::Zero;
	m_TimePerFrame = sf::seconds(1.f / 60.f);
	m_duration = sf::seconds(0.1*(1/m_speed));
}

void Character::updateAnimation()
{
    m_timeSinceLastUpdate = sf::Time::Zero;
    switch(m_movingState)
    {
        case MovingState::IDLE:
            m_sprite.setTextureRect(m_animationIDLE[m_animationCounter].getTextureRect());
            if(++m_animationCounter >= (int)m_animationIDLE.size())
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

