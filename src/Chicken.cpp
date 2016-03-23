#include "Chicken.hpp"

Chicken::Chicken(std::string path,  sf::Vector2f pos)
:Animal(path,pos)
{
    m_sprite.setTextureRect(sf::IntRect(0,0,CHICKEN_WIDTH,CHICKEN_HEIGHT));

    // Position init player
    m_position = sf::Vector2f(pos.x,GROUND_Y-m_sprite.getGlobalBounds().height);
    m_originPosition = m_position;
    m_sprite.setPosition(m_position);
    build();
    std::cout << "Chicken build " << std::endl;
}

Chicken::~Chicken()
{
    //dtor
}

void Chicken::build()
{
    sf::Sprite sprite;
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

}
