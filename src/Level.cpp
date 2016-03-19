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
    m_buildings.push_back(new Building(sf::Vector2f(700.0f,760.0f-SIGN_HEIGHT)));
    m_buildings.push_back(new Building(sf::Vector2f(2400.0f,760.0f-SIGN_HEIGHT)));
    m_buildings.push_back(new Building(sf::Vector2f(3700.0f,760.0f-SIGN_HEIGHT)));
    m_buildings.push_back(new Building(sf::Vector2f(5200.0f,760.0f-SIGN_HEIGHT)));
    m_buildings.push_back(new Building(sf::Vector2f(7200.0f,760.0f-SIGN_HEIGHT)));
}

void Level::draw(sf::RenderWindow* window)
{
    window->draw(m_backGround);
    for(int i = 0; i < (int)m_buildings.size(); i++)
    {
        m_buildings[i]->draw(window);
    }
}

void Level::remplaceBuild(Building* build)
{
    for(int i = 0; i < (int)m_buildings.size(); i++)
    {
        if(m_buildings[i]->getPosition() == build->getPosition())
        {
            m_buildings[i] = build;
            m_buildings[i]->increaseLevel();
        }
    }
}
