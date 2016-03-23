#include "Cow.hpp"

Cow::Cow(std::string path, sf::Vector2f pos)
:Animal(path,pos)
{

    m_sprite.setTextureRect(sf::IntRect(0,0,COW_WIDTH,COW_HEIGHT));

    // Position init player
    m_position = sf::Vector2f(pos.x,GROUND_Y-m_sprite.getGlobalBounds().height);
    m_originPosition = m_position;
    m_sprite.setPosition(m_position);
    build();
    std::cout << "Cow build " << std::endl;
}

Cow::~Cow()
{
    //dtor
}

void Cow::build()
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

}
