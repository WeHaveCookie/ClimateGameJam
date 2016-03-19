#include "../include/Controller.hpp"

Controller::Controller(sf::RenderWindow* window)
{
    m_window = window;
    //m_menu = new Menu();

    init();
}

Controller::~Controller()
{
    delete m_window;
    delete m_player;
    //delete m_menu;
    delete m_engine;
    delete m_level;
}

int Controller::start()
{
	sf::Vector2f speed = sf::Vector2f(0.f,0.f);
    bool startPressed = false;
    bool aPressed = false;
    bool xPressed = false;
    bool yPressed = false;
    bool reload = false;
    int counter = 0;

	sf::Clock tickClock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

	sf::Time timeSinceLastUpdateEvent = sf::Time::Zero;
	sf::Time TimePerFrameEvent = sf::seconds(1.f / 60.f);
	sf::Time durationEvent = sf::seconds(1);

    // Setting Music


    // Setting Menu
    m_displayMenu = true;
    //m_menu->setEnable(true);
    while (m_window->isOpen())
    {
        // Catching event
        sf::Event event;
        while (m_window->pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed :
                    m_window->close();
                    break;
                case sf::Event::KeyPressed :
                    {
                        switch(event.key.code)
                        {
                            case sf::Keyboard::Escape :
                                m_window->close();
                                break;
                            default :
                                break;
                        }
                    }
                    break;
                case sf::Event::MouseButtonPressed :
                    {
                        switch(event.mouseButton.button)
                        {
                        case sf::Mouse::Left :
                            break;
                        case sf::Mouse::Right:
                            break;
                        default:
                            break;
                        }
                    }
                    break;
                default :
                    break;
            }
        }

        // Update Music
        updateMusic();
        // Victory


        if(!m_displayPause)
        {
            // Catch keyboard event
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                m_engine->move(m_player,sf::Vector2f(-1.0,0.0));
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                m_engine->move(m_player,sf::Vector2f(1.0,0.0));
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {

            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
            }

            // Catch gamepad event

            if (!sf::Joystick::isButtonPressed(0, 0) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            { // A RELEASE
                aPressed = false;
            }

            if(sf::Joystick::getAxisPosition(0, sf::Joystick::Z) < -50.0)
            { // GACHETTE
            }
            if(sf::Joystick::getAxisPosition(0, sf::Joystick::Z) > -10.0)
            {
            }
        }



         if(!sf::Joystick::isButtonPressed(0,7) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
         {
             startPressed = false;
         }

         if(! sf::Joystick::isButtonPressed(0,2) && !sf::Keyboard::isKeyPressed(sf::Keyboard::X))
         {
            xPressed = false;
         }

        if(! sf::Joystick::isButtonPressed(0,3) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
        {
            yPressed = false;
        }

        if(timeSinceLastUpdateEvent > durationEvent + TimePerFrameEvent)
        {
            sf::Time timeSinceLastUpdateEvent = sf::Time::Zero;
            if(sf::Joystick::isButtonPressed(0,7) || sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
            { // Start button
                if(!startPressed)
                {
                    startPressed = true;
                    std::vector<Building*> buildings = m_level->getBuilding();
                    m_events.push_back(new EventBonus(buildings[rand()%buildings.size()],true,"Bonus time",counter++));
                }
            }

            if(sf::Joystick::isButtonPressed(0,2) || sf::Keyboard::isKeyPressed(sf::Keyboard::X))
            { // X button
                if(!xPressed)
                {
                    if(m_focusEvent == NULL)
                    {
                        xPressed = true;
                        Building* build = m_engine->enterOnBuilding(m_player->getGlobalBounds());
                        if (build != NULL)
                        { // Enter on Building
                            //std::cout << "Decrease on : " << build->getName() << std::endl;
                            build->addWorker(1);
                            std::cout << "Add a new worker on " << build->getName() << std::endl;
                        }
                    } else
                    { // Refuse Event
                        m_focusEvent = NULL;
                    }

                }
            }

            if(sf::Joystick::isButtonPressed(0,3) || sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
            { // Y button
                if(!yPressed)
                {
                    yPressed = true;
                    Building* build = m_engine->enterOnBuilding(m_player->getGlobalBounds());
                    if (build != NULL)
                    { // Enter on Building
                        build->addWorker(-1);
                        std::cout << "Remove a worker on " << build->getName() << std::endl;
                    }
                }
            }



            if (sf::Joystick::isButtonPressed(0, 0) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {// A button
                // ENTER ON BUILDING
                if(!aPressed)
                {
                    if(m_focusEvent == NULL)
                    {
                        aPressed = true;
                        Building* build = m_engine->enterOnBuilding(m_player->getGlobalBounds());
                        if (build != NULL)
                        { // Enter on Building
                            //std::cout << "Enter on : " << build->getName() << std::endl;
                            build->enter();
                        }
                    } else
                    { // Accept event
                        m_focusEvent->launch();
                        m_triggeredEvent.push_back(m_focusEvent);
                        m_focusEvent = NULL;
                    }
                }

            }


        } else
        {
            timeSinceLastUpdateEvent += TimePerFrameEvent;
        }

        if(sf::Joystick::isButtonPressed(0,1))
        {// B button
            m_window->close();
            break;
        }

        // REMOVE FOR MENU
        m_displayMenu = false;

        m_window->clear();

        if(m_focusEvent != NULL)
        {
            drawViewGame();
            drawViewHUD();
            m_window->setView(m_viewGame);
            m_focusEvent->draw(m_window);
        } else if (reload)
        { // Reload Game
            init();
            speed = sf::Vector2f(0.f,0.f);

            timeSinceLastUpdate = sf::Time::Zero;
            TimePerFrame = sf::seconds(1.f / 60.f);


            // Setting Menu
            m_displayMenu = true;
            //m_menu->setEnable(true);
            m_victory = false;

            startPressed = false;
            aPressed = false;
            xPressed = false;
            yPressed = false;
            reload = false;
        } else if(m_displayMenu)
        { // Display Menu
            /*drawViewMenu();
            if(!m_menu->isEnable())
            {
                m_displayMenu = false;
            }*/
        } else if (m_victory)
        { // Display Victory
            /*if(m_menu->getState() == MenuState::END)
            {
                drawViewMenu();
            } else
            {
                reload = true;
            }*/

        } else if (m_displayPause)
        { // Display Pause
            drawViewGame();

            m_window->setView(m_viewMenu);
            m_window->draw(m_filterPause);
        } else
        { // Display game
            if(!m_victory)
            {
                speed = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                timeSinceLastUpdate += tickClock.restart();

                while (timeSinceLastUpdate > TimePerFrame)
                {
                    timeSinceLastUpdate -= TimePerFrame;

                    // Update the position of the square according to input from joystick
                    // 60% dead zone
                    if ((speed.x > 20.f || speed.x < -20.f || speed.y > 20.f || speed.y < -20.f) && !m_displayPause)
                    {
                        m_engine->move(m_player,sf::Vector2f(speed.x*TimePerFrame.asSeconds(), speed.y*TimePerFrame.asSeconds()));
                    }
                }

                // Setting view
                /*float decPlayer = m_player->getSprite().getGlobalBounds().left - m_viewGame.getCenter().x;
                if((m_viewGame.getSize().x/2) + decPlayer > (m_viewGame.getSize().x*0.66))
                {
                    m_viewGame.move(sf::Vector2f(m_player->getSpeed()*2.0,0));
                }*/
            }
            triggerEvent();
            updateEvent();
            drawViewGame();
            drawViewHUD();
        }
        m_window->display();
    }
    return 0;
}

void Controller::init()
{
    m_displayMenu = false;
    m_displayPause = false;
    m_victory = false;
    m_speedPlayer = DEFAULT_SPEED;

    // Load level
    m_level = new Level(defaultLevelPath+"level.lvl", this);
    m_player = new Character("tileset.png",this);
    m_hud = new Hud();

    // Setting view
    m_viewGame.reset(sf::FloatRect(0, 0, 1920, 1080));
    m_viewMenu.reset(sf::FloatRect(0,0,1920,1080));
    m_viewHUD.reset(sf::FloatRect(0,0,1920,100));

    m_viewHUD.setViewport(sf::FloatRect(0,0,1920.0f/1920.0f,100.0f/1080.0f));
    // Set engine
    m_engine = new Engine(m_level, &m_viewGame);

    std::cout << "Game init done" << std::endl;
}


void Controller::setLevel(std::string path)
{
    m_level = new Level(path, this);
}

void Controller::updateMusic()
{

}

void Controller::drawViewGame()
{
    m_window->setView(m_viewGame);
    m_level->draw(m_window);
    m_player->draw(m_window);
}


void Controller::drawViewMenu()
{
    /*m_window->setView(m_viewMenu);
    m_menu->draw(m_window);*/
}

void Controller::drawViewHUD()
{
    m_window->setView(m_viewHUD);
    m_hud->draw(m_window);
}

void Controller::increaseRessource(RessourcesType rt, int value)
{
    m_hud->increase(rt, value);
}

void Controller::triggerEvent()
{
    if(m_events.size() > 0)
    {
        if(rand()%1000 < 5)
        {
            int ev = rand()%m_events.size();
            m_focusEvent = m_events[ev];
            std::vector<Event*>::iterator it= m_events.begin()+ev;
            m_events.erase(it);
            m_focusEvent->trigger();
        }
    }
}

void Controller::updateEvent()
{
    m_window->setView(m_viewGame);
    int eventToDelete = -1;
    for(int i = 0; i < (int)m_triggeredEvent.size(); i++)
    {
        if(m_triggeredEvent[i]->getState() == EventState::FINISHED)
        {
            eventToDelete = i;
        } else
        {
            m_triggeredEvent[i]->draw(m_window);
        }
    }
    if(eventToDelete > -1)
    {
       std::vector<Event*>::iterator it = m_triggeredEvent.begin()+eventToDelete;
        m_triggeredEvent.erase(it);
        m_triggeredEvent.shrink_to_fit();
    }
}
