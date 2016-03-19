#include "../include/Level.hpp"

Level::Level(const std::string& path, Controller* controller)
: Reader(path)
{
    m_path = path;
    m_controller = controller;
    read();
    std::cout << "Level load ! " << std::endl;
}

Level::~Level()
{
}

void Level::read()
{


    float width, height;
    width = (float)std::stoi(nextWord());
    height = (float)std::stoi(nextWord());
    m_sizeLevel = sf::Vector2f(width,height);
    if(!m_tileset.loadFromFile(defaultLevelPath+nextWord()))
    { //RAISE A LOAD TEXTURE EXCEPTION
    }
    m_backGround.setTexture(m_tileset);


    buildLevel();
}

void Level::buildLevel()
{
    m_buildings.push_back(new Barn(sf::Vector2f(700.0,756.0-SIGN_HEIGHT),m_controller));
    m_buildings.push_back(new House(sf::Vector2f(2200,756.0-SIGN_HEIGHT),m_controller));
    m_buildings.push_back(new ChickenCoop(sf::Vector2f(3500,756.0-SIGN_HEIGHT),m_controller));
    m_buildings.push_back(new SellStore(sf::Vector2f(5000,756.0-SIGN_HEIGHT),m_controller));
    m_buildings.push_back(new Piggery(sf::Vector2f(7000,756.0-SIGN_HEIGHT),m_controller));
}

void Level::draw(sf::RenderWindow* window)
{
    window->draw(m_backGround);
    for(int i = 0; i < (int)m_buildings.size(); i++)
    {
        m_buildings[i]->draw(window);
    }
}
