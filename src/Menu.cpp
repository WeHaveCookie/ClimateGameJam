#include "../include/Menu.hpp"

Menu::Menu()
{
    m_onAnimation = false;
    m_enable = false;
    m_animationCounter = 0;
    m_menuState = MenuState::NOTHING;
    build();
}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow* window)
{
    update(window);
    window->draw(m_spriteBack);
    window->draw(m_sprite);
}

void Menu::update(sf::RenderWindow* window)
{
    if(m_timeSinceLastUpdate > m_duration + m_TimePerFrame)
    {
        updateAnimation();
    } else
    {
        m_timeSinceLastUpdate += m_TimePerFrame;
    }
}

void Menu::build()
{

    // Load menuBack
    m_textureBack.loadFromFile(defaultMenuPath+"backmenu.png");
    m_spriteBack.setTexture(m_textureBack);

    // Load Credit
    m_textureCredit.loadFromFile(defaultMenuPath+"credit.png");
    m_spriteCredit.setTexture(m_textureCredit);

    // Load Menu
    m_textureMenu.loadFromFile(defaultMenuPath+"Menu.png");
    m_spriteMenu.setTexture(m_textureMenu);

    // Load Option
    m_textureOption.loadFromFile(defaultMenuPath+"Options.png");
    m_spriteOption.setTexture(m_textureOption);


    sf::Clock tickClock;
	m_timeSinceLastUpdate = sf::Time::Zero;
	m_TimePerFrame = sf::seconds(1.f / 60.f);
	m_duration = sf::seconds(0.05);
}

void Menu::updateAnimation()
{
    m_timeSinceLastUpdate = sf::Time::Zero;
    switch(m_menuState)
    {
        case MenuState::TITLE :
            m_sprite = m_spriteMenu;
            break;
        case MenuState::CREDIT :
            m_sprite = m_spriteCredit;
            break;
        case MenuState::OPTION :
            m_sprite = m_spriteOption;
            break;
        case MenuState::NOTHING :
        default:
            m_sprite = m_spriteMenu;
            break;
    }
}
