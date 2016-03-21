#include "ShopHUD.hpp"

ShopHUD::ShopHUD()
{
    if(!m_textureFrame.loadFromFile(defaultShopPath+"frame.png"))
    { // RAISE ERROR
    }
    m_spriteFrame.setTexture(m_textureFrame);
    m_positionFrame = sf::Vector2f(66,80);
    m_selectItem = 0;

    if(!m_textureShop.loadFromFile(defaultShopPath+"shop.png"))
    { // RAISE ERROR
    }
    m_spriteShop.setTexture(m_textureShop);
    build();
}

ShopHUD::~ShopHUD()
{
    //dtor
}


void ShopHUD::draw(sf::RenderWindow* window)
{
    update(window);
    window->draw(m_spriteShop);
    window->draw(m_spriteFrame);
}

void ShopHUD::update(sf::RenderWindow* window)
{
  // MAJ RESSOURCES
  m_spriteFrame.setPosition(m_positionFrame);
}

void ShopHUD::updateAnimation()
{
    m_timeSinceLastUpdate = sf::Time::Zero;
    /*m_spriteBAR.setTextureRect(m_animationBAR[m_animationCounter].getTextureRect());
    if(++m_animationCounter >= (int)m_animationBAR.size())
    {
        m_animationCounter = 0;
    }*/
}

void ShopHUD::build()
{

    m_price.push_back(100);
    m_price.push_back(25);
    m_price.push_back(40);
    m_price.push_back(25);
    m_animationCounter = 0;

    sf::Clock tickClock;
    m_timeSinceLastUpdate = sf::Time::Zero;
	m_TimePerFrame = sf::seconds(1.f / 60.f);
	m_duration = sf::seconds(0.1);
}

void ShopHUD::select(sf::Vector2f motion)
{
    float x, y;
    x = m_positionFrame.x;
    y = m_positionFrame.y;
    if (motion.x == 1)
    { // RIGT
        x = m_positionFrame.x + m_spriteFrame.getGlobalBounds().width + 85;
        m_selectItem++;
        if(x > 600.0)
        {
            if(m_positionFrame.y < 350 )
            {
                y = m_positionFrame.y + m_spriteFrame.getGlobalBounds().height + 104.0;
                x = 66;
            } else
            {
                x = m_positionFrame.x;
                m_selectItem--;
            }
        }
        //selectItem++;
    } else if (motion.x == -1)
    { // LEFT
        x = m_positionFrame.x - m_spriteFrame.getGlobalBounds().width - 85;
        m_selectItem--;
        if(x < 30)
        {
            if(m_positionFrame.y >= 350)
            {
                x = 66 + m_spriteFrame.getGlobalBounds().width*1 + 1*85;
                y = m_positionFrame.y - m_spriteFrame.getGlobalBounds().height - 104.0;
            }
            else
            {
                x = 66;
                m_selectItem++;
            }
        }

    }
    std::cout << "Selected " << m_selectItem << std::endl;
    m_positionFrame = sf::Vector2f(x,y);
}
