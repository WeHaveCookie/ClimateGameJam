#include "../include/Level.hpp"

Level::Level(const std::string& path, Controller* controller)
: Reader(path)
{
    m_path = path;
    m_controller = controller;
    read();


    if(!m_textureBackGround.loadFromFile(defaultClimatPath+"Ciel.png"))
    {  // RAISE ERROR
    }
    m_textureBackGround.setSmooth(true);
    m_textureBackGround.setRepeated(true);

    m_backGround.setTexture(m_textureBackGround);
    m_backGround.setPosition(sf::Vector2f(0,0));

    if(!m_textureMontain.loadFromFile(defaultClimatPath+"Montagne.png"))
    {  // RAISE ERROR
    }
    //m_textureMontain.setSmooth(true);

    if(!m_textureSecondGround.loadFromFile(defaultClimatPath+"colline2.png"))
    {  // RAISE ERROR
    }
    m_textureSecondGround.setSmooth(true);
    m_textureSecondGround.setRepeated(true);
    m_secondGround.setTexture(m_textureSecondGround);

    if(!m_textureThirdGround.loadFromFile(defaultClimatPath+"colline1.png"))
    {  // RAISE ERROR
    }
    m_textureThirdGround.setSmooth(true);
    m_textureThirdGround.setRepeated(true);
    m_thirdGround.setTexture(m_textureThirdGround);

    if(!m_textureGround.loadFromFile(defaultClimatPath+"Sol.png"))
    {  // RAISE ERROR
    }
    m_textureGround.setSmooth(true);
    m_textureGround.setRepeated(true);
    m_ground.setTexture(m_textureGround);
    m_ground.setPosition(sf::Vector2f(0,SIZE_MAP_Y - m_ground.getGlobalBounds().height));

    if(!m_textureElements.loadFromFile(defaultClimatPath+"decors.png"))
    { // RAISE ERROR
    }

    if(!m_textureCloud.loadFromFile(defaultClimatPath+"cloud.png"))
    { // RAISE ERROR
    }


    m_thirdGround.setPosition(sf::Vector2f(0,m_ground.getPosition().y - m_thirdGround.getGlobalBounds().height + 1));
    m_secondGround.setPosition(m_thirdGround.getPosition().x-300.0,m_thirdGround.getPosition().y);
    //m_firstGround.setPosition(m_thirdGround.getPosition().x+50,SIZE_MAP_Y-m_firstGround.getGlobalBounds().height);

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

    buildLevel();
}

void Level::buildLevel()
{
    m_buildings.push_back(new Building(sf::Vector2f(700.0f,760.0f-SIGN_HEIGHT)));
    m_buildings.push_back(new Building(sf::Vector2f(2400.0f,760.0f-SIGN_HEIGHT)));
    m_buildings.push_back(new Building(sf::Vector2f(3700.0f,760.0f-SIGN_HEIGHT)));
    m_buildings.push_back(new Building(sf::Vector2f(5200.0f,760.0f-SIGN_HEIGHT)));
    m_buildings.push_back(new Building(sf::Vector2f(7200.0f,760.0f-SIGN_HEIGHT)));
    m_buildings.push_back(new Building(sf::Vector2f(8500.0f,760.0f-SIGN_HEIGHT)));
    int lastRand = 0;
    for(int i = 0; i < SIZE_MAP_X; i+10)
    {
        if(rand()%1000 < 50)
        {
            int select = rand()%3;
            if(select == lastRand)
            {
                select = rand()%3;
            }
            lastRand = select;
            sf::Sprite spr;
            spr.setTexture(m_textureElements);
            switch(select)
            {
                case 0:
                    spr.setTextureRect(sf::IntRect(0,0,103,157));
                    //std::cout << "On ajoute un Arbre_01" << std::endl;
                    break;
                case 1:
                    spr.setTextureRect(sf::IntRect(103,60,60,97));
                    //std::cout << "On ajoute un Arbre_03" << std::endl;
                    break;
                case 2:
                    spr.setTextureRect(sf::IntRect(163,102,66,55));
                    //std::cout << "On ajoute un Roche" << std::endl;
                    break;
                default:
                    spr.setTextureRect(sf::IntRect(163,102,66,55));
                    //std::cout << "On ajoute un Roche default" << std::endl;
                    break;
            }
            m_textureElements.setSmooth(true);
            spr.setTexture(m_textureElements);
            spr.setPosition(sf::Vector2f(i,GROUND_Y-spr.getGlobalBounds().height+5));
            m_elements.push_back(spr);

        }
        i += rand()%20+20;
    }
     generateMontain();
     generateCloud();
}

void Level::draw(sf::RenderWindow* window)
{
    window->draw(m_backGround);
    for(int i = 0; i < (int)m_montains.size(); i++)
    {
        window->draw(m_montains[i]);
    }
    window->draw(m_secondGround);
    window->draw(m_thirdGround);
    for(int i = 0 ; i < (int)m_elements.size(); i++)
    {
        window->draw(m_elements[i]);
    }
    window->draw(m_ground);

    for(int i = 0; i < (int)m_clouds.size(); i++)
    {
        window->draw(m_clouds[i]);
    }

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

void Level::MoveCloud(sf::Vector2f motion)
{
    for(int i = 0; i < (int)m_clouds.size(); i++)
    {
        m_clouds[i].move(sf::Vector2f(motion.x,0.0));
        if (m_clouds[i].getPosition().x+m_clouds[i].getLocalBounds().width < 0)
        {
            int select = rand()%4;
            sf::Sprite spr;
            spr.setTexture(m_textureCloud);
            switch(select)
            {
                case 0:
                    spr.setTextureRect(sf::IntRect(0,0,256,91));
                    //std::cout << "On ajoute un cloud 1" << std::endl;
                    break;
                case 1:
                    spr.setTextureRect(sf::IntRect(256,0,256,91));
                    //std::cout << "On ajoute un cloud 2" << std::endl;
                    break;
                case 2:
                    spr.setTextureRect(sf::IntRect(256*2,0,256,91));
                    //std::cout << "On ajoute un cloud 3 " << std::endl;
                    break;
                case 3:
                    spr.setTextureRect(sf::IntRect(256*3,0,256,91));
                    //std::cout << "On ajoute un cloud 4 " << std::endl;
                    break;
                default:
                    spr.setTextureRect(sf::IntRect(0,0,256,91));
                    //std::cout << "On ajoute un cloud default" << std::endl;
                    break;
            }
            m_textureCloud.setSmooth(true);
            spr.setTexture(m_textureCloud);
            spr.setPosition(sf::Vector2f(SIZE_MAP_X,rand()%600));
            m_clouds[i] = spr;
        }
    }
}

void Level::moveBackGround(sf::Vector2f motion)
{
    m_backGround.move(motion);
    m_ground.move(sf::Vector2f(motion.x*1,0.0));
    m_thirdGround.move(sf::Vector2f(motion.x-motion.x*0.3,0.0));
    m_secondGround.move(sf::Vector2f(motion.x-motion.x*0.2,0.0));
    for(int i = 0; i < (int)m_montains.size(); i++)
    {
        m_montains[i].move(sf::Vector2f(motion.x-motion.x*0.1,0.0));;
    }
    for(int i = 0; i < (int)m_clouds.size(); i++)
    {
        m_clouds[i].move(sf::Vector2f(motion.x-motion.x*0.1,0.0));
    }
}


void Level::generateMontain()
{
    for(int i = 0; i < 2200; i+10)
    {
        if(rand()%1000 < 60)
        {
            sf::Sprite spr;
            spr.setTexture(m_textureMontain);
            spr.setTextureRect(sf::IntRect(0,0,566,760));
            float scale = (rand()%40+70.0)/100.0;
            spr.setScale(sf::Vector2f(scale,scale));
            spr.setPosition(sf::Vector2f(i,SIZE_MAP_Y-spr.getGlobalBounds().height+5));
            m_montains.push_back(spr);
        }
        i += rand()%10+20;
    }
}

void Level::generateCloud()
{
    int lastRand = 0;
    for(int i = 0; i < 1.5*SIZE_MAP_X; i+10)
    {
        if(rand()%1000 < 40)
        {
            int select = rand()%4;
            if(select == lastRand)
            {
                select = rand()%4;
            }
            lastRand = select;
            sf::Sprite spr;
            spr.setTexture(m_textureCloud);
            switch(select)
            {
                case 0:
                    spr.setTextureRect(sf::IntRect(0,0,256,91));
                    //std::cout << "On ajoute un cloud 1" << std::endl;
                    break;
                case 1:
                    spr.setTextureRect(sf::IntRect(256,0,256,91));
                    //std::cout << "On ajoute un cloud 2" << std::endl;
                    break;
                case 2:
                    spr.setTextureRect(sf::IntRect(256*2,0,256,91));
                    //std::cout << "On ajoute un cloud 3 " << std::endl;
                    break;
                case 3:
                    spr.setTextureRect(sf::IntRect(256*3,0,256,91));
                    //std::cout << "On ajoute un cloud 4 " << std::endl;
                    break;
                default:
                    spr.setTextureRect(sf::IntRect(0,0,256,91));
                    //std::cout << "On ajoute un cloud default" << std::endl;
                    break;
            }
            m_textureCloud.setSmooth(true);
            spr.setTexture(m_textureCloud);
            spr.setPosition(sf::Vector2f(i,rand()%600));
            m_clouds.push_back(spr);
        }
        i += rand()%20+20;
    }
}
