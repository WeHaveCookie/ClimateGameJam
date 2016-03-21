#include "../include/Controller.hpp"

Controller::Controller(sf::RenderWindow* window)
{
    m_window = window;
    //m_menu = new Menu();



    if(!m_introMusic.openFromFile(defaultSoundPath+"intro.ogg"))
    { // RAISE ERROR
    }

    if(!m_mainThemeMusic.openFromFile(defaultSoundPath+"theme.ogg"))
    { // RAISE ERROR
    }

    if(!m_ambianceMusic.openFromFile(defaultSoundPath+"amb.ogg"))
    { // RAISE ERROR
    }
    m_volumeAmbianceMusique = 0;

    if(!m_soundError.openFromFile(defaultFXPath+"error.ogg"))
    {
    }
    m_soundError.setVolume(DEFAUT_VOLUME_FEEDBACK);

    if(!m_soundBuild.openFromFile(defaultFXPath+"build.ogg"))
    {
    }

    m_soundBuild.setVolume(DEFAUT_VOLUME_FEEDBACK);

    if(!m_soundCow.openFromFile(defaultFXPath+"cow0.ogg"))
    { // RAISE ERROR
    }


    if(!m_soundChicken.openFromFile(defaultFXPath+"chicken0.ogg"))
    { // RAISE ERROR
    }

    if(!m_soundPig.openFromFile(defaultFXPath+"pig0.ogg"))
    { // RAISE ERROR
    }

    m_soundChicken.setVolume(DEFAULT_VOLUME_ANIMAL);
    m_soundCow.setVolume(DEFAULT_VOLUME_ANIMAL);
    m_soundPig.setVolume(DEFAULT_VOLUME_ANIMAL);

    m_soundChicken.setLoop(true);
    m_soundCow.setLoop(true);
    m_soundPig.setLoop(true);

    if(!m_textureIconBuild.loadFromFile(defaultBuildingPath+"icon.png"))
    { // RAISE ERROR
    }
    m_textureIconBuild.setSmooth(true);
    m_spriteIconBuild.setTexture(m_textureIconBuild);

    if(!m_textureVictory.loadFromFile(defaultHUDPath+"victory.png"))
    { // RAISE ERROR
    }
    m_textureVictory.setSmooth(true);
    m_spriteVictory.setTexture(m_textureVictory);

    if(!m_textureLoose.loadFromFile(defaultHUDPath+"loose.png"))
    { // RAISE ERROR
    }
    m_textureLoose.setSmooth(true);
    m_spriteLoose.setTexture(m_textureLoose);




    if(!m_textureIconPad.loadFromFile(defaultHUDPath+"pad.png"))
    { // RAISE ERROR
    }
    m_textureIconPad.setSmooth(true);
    m_spriteIconPad.setTexture(m_textureIconPad);

    if(!m_textureAButton.loadFromFile(defaultHUDPath+"buttonA.png"))
    { // RAISE ERROR
    }
    m_textureAButton.setSmooth(true);
    m_spriteIconAButton.setTexture(m_textureAButton);


    init();
}

Controller::~Controller()
{
    delete m_window;
    delete m_player;
    delete m_menu;
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
    bool bPressed = false;
    bool tiltDetected = false;
    bool displayIconBuild = false;
    bool reload = false;
    bool displayPause = false;
    bool addWorker = false;
    bool buildSelected = false;
    bool rbPressed = false;
    bool lbPressed = false;
    int counter = 0;
    Building* build = NULL;

	sf::Clock tickClock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

	sf::Time timeSinceLastUpdateEvent = sf::Time::Zero;
	sf::Time TimePerFrameEvent = sf::seconds(1.f / 60.f);
	sf::Time durationEvent = sf::seconds(1);

    // Setting Music
    m_introMusic.setVolume(DEFAULT_VOLUME_MAINTHEME);
    m_mainThemeMusic.setVolume(DEFAULT_VOLUME_MAINTHEME);
    m_mainThemeMusic.setLoop(true);
    m_ambianceMusic.setVolume(m_volumeAmbianceMusique);
    m_ambianceMusic.setLoop(true);
    m_introMusic.play();
    m_ambianceMusic.play();
    m_soundChicken.play();
    m_soundCow.play();
    m_soundPig.play();
    // Setting Menu
    m_displayMenu = true;
    m_menu->setEnable(true);
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
            build = m_engine->enterOnBuilding(m_player->getGlobalBounds());
            buildSelected = false;
            if (build != NULL)
            {
                build->highlighted(false);
            }
            displayIconBuild = false;
         }

        if(! sf::Joystick::isButtonPressed(0,3) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
        {
            yPressed = false;
        }

        if(!sf::Joystick::isButtonPressed(0,1) && !sf::Keyboard::isKeyPressed(sf::Keyboard::B))
        {// B button
            bPressed = false;
        }

        if(!sf::Joystick::isButtonPressed(0,4))
        { // VICTORY
            lbPressed = false;
        }

        if(!sf::Joystick::isButtonPressed(0,5))
        { // DEFAITE
            rbPressed = false;
        }

        if(timeSinceLastUpdateEvent > durationEvent + TimePerFrameEvent)
        {
            sf::Time timeSinceLastUpdateEvent = sf::Time::Zero;

            if(sf::Joystick::isButtonPressed(0,4))
            { // VICTORY
                if(!lbPressed)
                {
                    lbPressed = true;
                }

            }

            if(sf::Joystick::isButtonPressed(0,5))
            { // DEFAITE
                if(!rbPressed)
                {
                    rbPressed = true;
                }
            }

            if(sf::Joystick::isButtonPressed(0,7) || sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
            { // Start button
                if(!startPressed)
                {
                    startPressed = true;
                    (displayPause)?displayPause=false:displayPause=true;
                    //m_instaFarm->addPost(new Post("J'adore trop ta ferme !",counter++));
                    /*std::vector<Building*> buildings = m_level->getBuilding();
                    m_events.push_back(new EventRessources(buildings[rand()%buildings.size()],true,"Bonus time",this,counter++));*/
                }
            }

            if(sf::Joystick::isButtonPressed(0,2) || sf::Keyboard::isKeyPressed(sf::Keyboard::X))
            { // X button
                    if(m_displayMenu)
                    {
                        m_menu->setState(MenuState::CREDIT);
                    } else
                    {
                        build = m_engine->enterOnBuilding(m_player->getGlobalBounds());
                        if (build != NULL)
                        { // Enter on Building
                            //std::cout << "Decrease on : " << build->getName() << std::endl;
                            buildSelected = true;
                            build->highlighted(true);

                            if(build->getLevel() == 0)
                            { // Construct
                                displayIconBuild = true;

                                // CATCH SELECT
                                if (sf::Joystick::getAxisPosition(0,sf::Joystick::PovY) < -50.0 || sf::Keyboard::isKeyPressed(sf::Keyboard::Down) )
                                { // down -> Barn
                                    m_level->remplaceBuild(new Barn(build->getPosition(),this));
                                    build->highlighted(false);
                                    m_animals.push_back(new Cow("cow.png",build->getPosition()));
                                    m_instaFarm->addPost(new Post("photo_vache.png",counter++));
                                    m_hud->displayRessources(RessourcesType::MILK,true);                                increaseRessource(RessourcesType::MONEY,50);
                                    displayIconBuild = false;
                                    m_soundBuild.play();
                                } else if (sf::Joystick::getAxisPosition(0,sf::Joystick::PovY) > 50.0 || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) )
                                { // UP -> Piggery
                                    m_level->remplaceBuild(new Piggery(build->getPosition(),this));
                                    build->highlighted(false);
                                    m_animals.push_back(new Pig("pig.png",build->getPosition()));
                                    m_instaFarm->addPost(new Post("photo_cochon.png",counter++));
                                    m_hud->displayRessources(RessourcesType::MEAT,true);
                                    displayIconBuild = false;
                                    m_soundBuild.play();
                                } else if (sf::Joystick::getAxisPosition(0,sf::Joystick::PovX) < -50.0 || sf::Keyboard::isKeyPressed(sf::Keyboard::Left) )
                                { // LEFT -> House
                                    m_level->remplaceBuild(new House(build->getPosition(),this));
                                    build->highlighted(false);
                                    m_instaFarm->addPost(new Post("photo_blé.png",counter++));
                                    displayIconBuild = false;
                                    m_soundBuild.play();
                                } else if (sf::Joystick::getAxisPosition(0,sf::Joystick::PovX) > 50.0 || sf::Keyboard::isKeyPressed(sf::Keyboard::Right) )
                                { // RIGHT -> ChickenCoop
                                    m_level->remplaceBuild(new ChickenCoop(build->getPosition(),this));
                                    m_hud->displayRessources(RessourcesType::EGG,true);
                                    m_animals.push_back(new Chicken("chicken.png",build->getPosition()));
                                    //m_animals.push_back(New Chicken("chicken.png",build->getPosition()));
                                    build->highlighted(false);
                                    displayIconBuild = false;
                                    m_soundBuild.play();
                                } else if(sf::Joystick::isButtonPressed(0,0) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                                { // Button A -> SellStore
                                    aPressed = true;
                                    m_level->remplaceBuild(new SellStore(build->getPosition(),this));
                                    m_hud->displayRessources(RessourcesType::MONEY,true);
                                    build->highlighted(false);
                                    displayIconBuild = false;
                                    m_soundBuild.play();
                                }

                            } else
                            {

                                if (sf::Joystick::getAxisPosition(0,sf::Joystick::PovY) < -50.0 || sf::Keyboard::isKeyPressed(sf::Keyboard::Down) )
                                { // down -> Barn
                                    if(!addWorker)
                                    {
                                        build->addWorker(-1);
                                        addWorker = true;
                                    }
                                } else if (sf::Joystick::getAxisPosition(0,sf::Joystick::PovY) > 50.0 || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) )
                                { // UP -> Piggery
                                    if(!addWorker)
                                    {
                                        build->addWorker(1);
                                        addWorker = true;
                                    }

                                } else if ((sf::Joystick::isButtonPressed(0, 0) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && buildSelected)
                                { // UPGRADE
                                    if(!aPressed)
                                    {
                                        aPressed = true;
                                        if(m_hud->getRessourcesValue(RessourcesType::MONEY) >= build->getCostToUpgrade())
                                        {
                                            increaseRessource(RessourcesType::MONEY,-build->getCostToUpgrade());
                                            build->increaseLevel();
                                            increaseSoundAnimal(build->getType(),build->getLevel());
                                        } else
                                        {
                                            std::cout << "Not enought Money man need "<< build->getCostToUpgrade() << std::endl;
                                        }

                                    }

                                } else if ((sf::Joystick::isButtonPressed(0,1) || sf::Keyboard::isKeyPressed(sf::Keyboard::B)) && buildSelected)
                                {
                                    if(!bPressed)
                                    {
                                        bPressed = true;
                                        build->decreaseLevel();
                                    }
                                } else
                                {
                                    addWorker = false;
                                }
                            }
                        }
                }
            }

            if((sf::Joystick::isButtonPressed(0,3) || sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) && !buildSelected)
            { // Y button
                if(!yPressed)
                {
                    if(m_displayMenu)
                    {
                        m_menu->setState(MenuState::OPTION);
                    }
                    yPressed = true;
                    (m_displayInstaHouse)?m_displayInstaHouse = false:m_displayInstaHouse = true;
                }
            }



            if ((sf::Joystick::isButtonPressed(0, 0) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && !buildSelected)
            {// A button
                // ENTER ON BUILDING
                if(!aPressed)
                {
                    aPressed = true;
                    if(m_displayMenu)
                    {
                        m_menu->setEnable(false);
                        //m_displayMenu = false;
                    } else if (m_displayShop)
                    {
                        if(m_hud->getRessourcesValue(RessourcesType::MONEY) >= m_shopHUD->getPrice())
                        {
                            std::cout << "Buy !" << std::endl;
                            std::vector<Building*> buildings = m_level->getBuilding();
                            Event* ev = new EventBonus(buildings[0],true,"Bonus time",counter++,"Shop Bonus");
                            ev->launch();
                            m_triggeredEvent.push_back(ev);
                            increaseRessource(RessourcesType::MONEY,-m_shopHUD->getPrice());
                            m_displayShop = false;
                        } else
                        {
                            if(m_soundError.getStatus() != sf::SoundSource::Playing)
                            {
                                m_soundError.play();
                            }
                        }

                    } else if(m_focusEvent == NULL)
                    {
                        Building* build = m_engine->enterOnBuilding(m_player->getGlobalBounds());
                        if (build != NULL && build->getLevel() > 0)
                        { // Enter on Building
                            build->enter();
                        }
                    } else if (m_focusEvent != NULL)
                    { // Accept event
                        m_focusEvent->launch();
                        m_triggeredEvent.push_back(m_focusEvent);
                        m_focusEvent = NULL;
                    }
                }

            }

            if((sf::Joystick::isButtonPressed(0,1) || sf::Keyboard::isKeyPressed(sf::Keyboard::B)) && !buildSelected)
            {// B button
                if(!bPressed)
                {
                    bPressed = true;
                    if(m_focusEvent != NULL)
                    { // Refuse Event
                        m_focusEvent = NULL;
                    } else if(m_displayShop)
                    {
                        m_displayShop = false;
                    } else if (m_displayMenu)
                    {
                        m_window->close();
                        break;
                        //exit(EXIT_SUCCESS);
                    }
                }
            }
        } else
        {
            timeSinceLastUpdateEvent += TimePerFrameEvent;
        }


        // REMOVE FOR MENU
        triggerEvent();
        updateEvent();
        updateNotoriety();


        m_window->clear();

        if (lbPressed)
        { // Display Victory
            drawViewGame();
            drawViewHUD();
            m_window->setView(m_viewGame);
            m_spriteVictory.setPosition(sf::Vector2f(m_viewGame.getCenter().x-m_viewGame.getSize().x/2.0,m_viewGame.getCenter().y-m_viewGame.getSize().y/2.0));

            m_window->draw(m_spriteVictory);
        } else if (rbPressed)
        {
            drawViewGame();
            drawViewHUD();
            m_window->setView(m_viewGame);
            m_spriteVictory.setPosition(sf::Vector2f(m_viewGame.getCenter().x-m_viewGame.getSize().x/2.0,m_viewGame.getCenter().y-m_viewGame.getSize().y/2.0));
            m_window->draw(m_spriteLoose);
        } else if(m_focusEvent != NULL)
        {
            drawViewGame();
            drawViewHUD();
            m_window->setView(m_viewGame);
            m_focusEvent->draw(m_window, m_viewGame);
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
            drawViewMenu();
            if(!m_menu->isEnable())
            {
                m_displayMenu = false;
            }
        } else if (displayPause)
        {
            drawViewGame();
            drawViewHUD();
            m_window->setView(m_viewGame);
            m_filterPause.setPosition(sf::Vector2f(m_viewGame.getCenter().x-m_viewGame.getSize().x/2.0,m_viewGame.getCenter().y-m_viewGame.getSize().y/2.0));
            m_window->draw(m_filterPause);

        } else if (m_displayShop)
        { // Display Shop
            drawViewGame();
            drawViewHUD();
            drawViewShop();

            speed = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
            timeSinceLastUpdate += tickClock.restart();

            while (timeSinceLastUpdate > TimePerFrame)
            {
                timeSinceLastUpdate -= TimePerFrame;

                // Update the position of the square according to input from joystick
                // 60% dead zone
                if ((speed.x > 20.f || speed.x < -20.f || speed.y > 20.f || speed.y < -20.f) && !m_displayPause)
                {
                    if(!tiltDetected)
                    {
                        tiltDetected = true;
                        if(speed.x > 0.0)
                        {
                               m_shopHUD->select(sf::Vector2f(1,0.0));

                        } else if (speed.x < 0.0)
                        {
                            m_shopHUD->select(sf::Vector2f(-1,0.0));
                        }
                    }
                } else
                {
                    tiltDetected = false;
                }
            }

        } else if (m_displayInstaHouse)
        { // Display Insta House
            drawViewGame();
            drawViewHUD();
            drawViewInstaHouse();
            drawViewPost();
            speed = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
            timeSinceLastUpdate += tickClock.restart();

            while (timeSinceLastUpdate > TimePerFrame)
            {
                timeSinceLastUpdate -= TimePerFrame;

                // Update the position of the square according to input from joystick
                // 60% dead zone
                if ((speed.x > 20.f || speed.x < -20.f || speed.y > 20.f || speed.y < -20.f) && !m_displayPause)
                {
                    if(m_viewPost.getCenter().y-m_viewPost.getSize().y/2.0 + 20*speed.y*TimePerFrame.asSeconds() >= 0
                       && m_viewPost.getCenter().y + m_viewPost.getSize().y/2.0 + 20*speed.y*TimePerFrame.asSeconds() <= m_instaFarm->getNbrPost()*m_viewPost.getSize().y-100.0f)
                    m_viewPost.move(0.0, 20*speed.y*TimePerFrame.asSeconds());
                }
            }


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
            }
            m_level->MoveCloud(sf::Vector2f(rand()%2-1,0.0));
            drawViewGame();
            drawViewHUD();
            if (displayIconBuild)
            {
                showIconBuild(build);
            }


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
    m_transitionMusic = true;
    m_speedPlayer = DEFAULT_SPEED;
    m_displayInstaHouse = false;

    m_menu = new Menu();
    // Load level
    m_level = new Level(defaultLevelPath+"level.lvl", this);
    m_player = new Character("sprite_chara.png",this);
    //m_player = new Chicken("chicken.png",sf::Vector2f(50.0,0.0));
    m_hud = new Hud();
    m_shopHUD = new ShopHUD();

    if(!m_textureFilterPause.loadFromFile(defaultFilterPath+"pause.png"))
    { // RAISE ERROR
    }
    m_textureFilterPause.setSmooth(true);
    m_filterPause.setTexture(m_textureFilterPause);

    // Setting view
    m_viewGame.reset(sf::FloatRect(0, 0, 1920, 1080));
    m_viewMenu.reset(sf::FloatRect(0,0,1920,1080));
    m_viewHUD.reset(sf::FloatRect(0,0,1920,118));
    m_viewInstaHouse.reset(sf::FloatRect(0,0,768,725));
    m_viewPost.reset(sf::FloatRect(0,0,663.0f,565.0f));
    m_viewShop.reset(sf::FloatRect(0,0,1048.0f,824.0f));

    m_viewShop.setViewport(sf::FloatRect(436.0f/1920.0f,124.0f/1080.0f,1048/1920.0f,824/1080.0f));

    m_viewPost.setViewport(sf::FloatRect(628.0f/1920.0f,302.5f/1080.f,663.0f/1920.0f,565.0f/1080.f));
    m_viewInstaHouse.setViewport(sf::FloatRect(576.0f/1920.0f,177.5f/1080.0f,768.0f/1920.0f,725.0f/1080.0f));
    m_viewHUD.setViewport(sf::FloatRect(0,0,1920.0f/1920.0f,118.0f/1080.0f));
    // Set engine
    m_engine = new Engine(m_level, &m_viewGame);

    m_spriteIconBuild.setTextureRect(sf::IntRect(ICON_BUILD_WIDTH*0,0,ICON_BUILD_WIDTH,ICON_BUILD_HEIGHT));
    m_spritesIconsBuilds.push_back(m_spriteIconBuild);
    m_spriteIconBuild.setTextureRect(sf::IntRect(ICON_BUILD_WIDTH*1,0,ICON_BUILD_WIDTH,ICON_BUILD_HEIGHT));
    m_spritesIconsBuilds.push_back(m_spriteIconBuild);
    m_spriteIconBuild.setTextureRect(sf::IntRect(ICON_BUILD_WIDTH*2,0,ICON_BUILD_WIDTH,ICON_BUILD_HEIGHT));
    m_spritesIconsBuilds.push_back(m_spriteIconBuild);
    m_spriteIconBuild.setTextureRect(sf::IntRect(ICON_BUILD_WIDTH*3,0,ICON_BUILD_WIDTH,ICON_BUILD_HEIGHT));
    m_spritesIconsBuilds.push_back(m_spriteIconBuild);
    m_spriteIconBuild.setTextureRect(sf::IntRect(ICON_BUILD_WIDTH*4,0,ICON_BUILD_WIDTH,ICON_BUILD_HEIGHT));
    m_spritesIconsBuilds.push_back(m_spriteIconBuild);

    m_instaFarm = new InstaFarm(this);
    std::cout << "Game init done" << std::endl;


}


void Controller::setLevel(std::string path)
{
    m_level = new Level(path, this);
}

void Controller::updateMusic()
{
    if(m_transitionMusic)
    {
        if(m_introMusic.getStatus() != sf::SoundSource::Status::Playing)
        {
            m_mainThemeMusic.play();
            m_transitionMusic = false;
        }
    }
    //std::cout << "Vol " << m_volumeAmbianceMusique << std::endl;
    if(m_volumeAmbianceMusique < MAX_VOLUME_AMBIANCE)
    {
        m_volumeAmbianceMusique += 0.2;
    }
    std::vector<float> soundAmb = m_engine->getSoundAmbiance(m_player);
    m_ambianceMusic.setVolume(m_volumeAmbianceMusique);
    //std::cout << soundAmb[RessourcesType::EGG] << " " << soundAmb[RessourcesType::MILK] << " " << soundAmb[RessourcesType::MEAT] << std::endl;
    m_soundChicken.setVolume(soundAmb[RessourcesType::EGG]);
    m_soundCow.setVolume(soundAmb[RessourcesType::MILK]);
    m_soundPig.setVolume(soundAmb[RessourcesType::MEAT]);
}

void Controller::drawViewGame()
{
    m_window->setView(m_viewGame);
    m_level->draw(m_window);
    for(int i = 0; i < (int)m_animals.size(); i++)
    {
        if(rand()%1000 < 5)
        {
            m_animals[i]->move(sf::Vector2f((rand()%10-5)*(rand()%20+10),0.0f));
        }
        m_animals[i]->draw(m_window);
    }
    m_player->draw(m_window);
}


void Controller::drawViewMenu()
{
    m_window->setView(m_viewMenu);
    m_menu->draw(m_window);
}

void Controller::drawViewHUD()
{
    m_window->setView(m_viewHUD);
    m_hud->draw(m_window);
}

void Controller::drawViewInstaHouse()
{
    m_window->setView(m_viewInstaHouse);
    m_instaFarm->draw(m_window);
}

void Controller::drawViewPost()
{
    m_window->setView(m_viewPost);
    m_instaFarm->drawPost(m_window);
}

void Controller::drawViewShop()
{
    m_window->setView(m_viewShop);
    m_shopHUD->draw(m_window);
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
            //std::cout << "Draw" << std::endl;
            m_triggeredEvent[i]->draw(m_window, m_viewGame);
        }
    }
    if(eventToDelete > -1)
    {
       std::vector<Event*>::iterator it = m_triggeredEvent.begin()+eventToDelete;
        m_triggeredEvent.erase(it);
        m_triggeredEvent.shrink_to_fit();
    }
}

void Controller::updateNotoriety()
{
    m_instaFarm->updateNotoriety(m_player->getNotoriety());
}

void Controller::addNotoriety(int value)
{
    m_player->addNotoriety(value);
}

void Controller::showIconBuild(Building* build)
{
    if(build != NULL)
    {
        m_window->setView(m_viewGame);

        m_spriteIconPad.setPosition(sf::Vector2f(build->getGlobalBounds().left + build->getGlobalBounds().width/2.0f-m_spriteIconPad.getGlobalBounds().width/2.0,build->getGlobalBounds().top-m_spriteIconPad.getGlobalBounds().height-m_spriteIconBuild.getGlobalBounds().height - PADDING_Y_WORKER_BUILDING));
        m_spritesIconsBuilds[0].setPosition(sf::Vector2f(m_spriteIconPad.getPosition().x,m_spriteIconPad.getPosition().y-ICON_BUILD_HEIGHT-PADDING_Y_WORKER_BUILDING));
        m_spritesIconsBuilds[1].setPosition(sf::Vector2f(m_spriteIconPad.getPosition().x+m_spriteIconPad.getGlobalBounds().width + PADDING_X_WORKER_BUILDING,m_spriteIconPad.getPosition().y));
        m_spritesIconsBuilds[2].setPosition(sf::Vector2f(m_spriteIconPad.getPosition().x,m_spriteIconPad.getPosition().y+ICON_BUILD_HEIGHT+PADDING_Y_WORKER_BUILDING));
        m_spritesIconsBuilds[3].setPosition(sf::Vector2f(m_spriteIconPad.getPosition().x-m_spriteIconPad.getGlobalBounds().width - PADDING_X_WORKER_BUILDING,m_spriteIconPad.getPosition().y));
        m_spriteIconAButton.setPosition(sf::Vector2f(m_spriteIconPad.getPosition().x-m_spriteIconPad.getGlobalBounds().width - 2*m_spriteIconBuild.getGlobalBounds().width,m_spriteIconPad.getPosition().y));
        m_spritesIconsBuilds[4].setPosition(sf::Vector2f(m_spriteIconAButton.getPosition().x-m_spriteIconAButton.getGlobalBounds().width - PADDING_X_WORKER_BUILDING,m_spriteIconAButton.getPosition().y));

        m_window->draw(m_spriteIconPad);
        m_window->draw(m_spriteIconAButton);
        for(int i = 0; i < (int)m_spritesIconsBuilds.size(); i++)
        {
            m_window->draw(m_spritesIconsBuilds[i]);
        }
    }
}

void Controller::increaseSoundAnimal(RessourcesType rt, int level)
{
    switch(rt)
    {
        case RessourcesType::MILK:
            /*if(!m_soundCow.openFromFile(defaultFXPath+"cow"+lvl+".ogg"))
            {// RAISE ERROR
            }*/
            break;
        case RessourcesType::MEAT:
            m_soundPig.stop();
            if(!m_soundPig.openFromFile(defaultFXPath+"pig"+std::to_string(level-1)+".ogg"))
            {// RAISE ERROR
            }
            m_soundPig.setLoop(true);
            m_soundPig.play();
            break;
        case RessourcesType::EGG:
            m_soundChicken.stop();
            if(!m_soundChicken.openFromFile(defaultFXPath+"chicken"+std::to_string(level-1)+".ogg"))
            {// RAISE ERROR
            }
            m_soundChicken.setLoop(true);
            m_soundChicken.play();
            break;
        default:
            break;
    }
}
