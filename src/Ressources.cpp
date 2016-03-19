#include "Ressources.hpp"

Ressources::Ressources()
{
    m_storeCapacity = INIT_STORE_CAPACITY;
    m_quantity = 0;
    if(!m_textureIcon.loadFromFile(defaultHUDPath+"ressources.png"))
    { // RAISE ERROR
    }
    m_textureIcon.setSmooth(true);
    m_spriteIcon.setTexture(m_textureIcon);

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

    if(!m_font.loadFromFile(defaultFontPath + "wonder.TTF"))
    { // RAISE ERROR
    }

    m_text.setFont(m_font);
    m_text.setCharacterSize(12);
    m_text.setColor(sf::Color::White);
}

Ressources::~Ressources()
{
    //dtor
}

void Ressources::draw(sf::RenderWindow* window)
{
    update(window);
    window->draw(m_spriteIcon);
    window->draw(m_spriteBar);
    window->draw(m_spriteGauge);
    window->draw(m_text);
}

void Ressources::update(sf::RenderWindow* window)
{
    m_spriteIcon.setPosition(m_positionIcon);
    m_spriteBar.setPosition(m_positionBar);
    m_text.setPosition(sf::Vector2f(m_positionBar.x+m_spriteBar.getGlobalBounds().width - (m_text.getGlobalBounds().width+TEXT_RESSOURCES_PADDING),37));
    m_text.setString(std::to_string(m_quantity) + "/" + std::to_string(m_storeCapacity));

    if ((float)m_quantity / (float)m_storeCapacity > 0.80)
    {
        m_text.setColor(sf::Color::Red);
        m_text.setStyle(sf::Text::Bold);
        m_spriteGauge.setColor(sf::Color::Blue);
    } else
    {
        m_text.setColor(sf::Color::White);
        m_text.setStyle(sf::Text::Regular);
        m_spriteGauge.setColor(sf::Color::Blue);
    }
    m_spriteGauge.setScale(sf::Vector2f((float)m_quantity/(float)m_storeCapacity,1));
    m_spriteGauge.setPosition(m_positionBar);
}

bool Ressources::addRessources(int i)
{
    if(i >= 0)
    {
        if(m_quantity + i <= m_storeCapacity)
        {
            m_quantity += i;
        } else
        {
            m_quantity = m_storeCapacity;
        }
    } else
    {
        if(m_quantity + i < 0)
        {
            return false;
        } else
        {
            m_quantity += i;
        }
    }
    return true;
}
