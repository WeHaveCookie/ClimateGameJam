#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>

#include "Engine.hpp"
#include "Character.hpp"
#include "Menu.hpp"
#include "Structure.hpp"
#include "Level.hpp"
#include "Hud.hpp"
#include "Ressources.hpp"

class Character;
class Engine;
class Menu;
class Level;

class Controller
{
    public:
        Controller(sf::RenderWindow* window);
        virtual ~Controller();

        // Function
        int start();
        void setLevel(std::string path);

        // Inline
        inline sf::RenderWindow* getWindow() {return m_window;}
        inline void displayMenu(bool b) {m_displayMenu = b;}
        inline Level* getLevel() {return m_level;}
        void increaseRessource(RessourcesType rt);

    protected:
    private:
        // Function
        void update();
        void updateMusic();
        void reload();
        void init();
        void drawViewGame();
        void drawViewMenu();
        void drawViewHUD();

        // Attribut
        sf::RenderWindow* m_window;
        Character* m_player;
        //Menu* m_menu;
        bool m_displayMenu;
        bool m_displayPause;
        sf::View m_viewGame;
        sf::View m_viewMenu;
        sf::View m_viewHUD;

        Level* m_level;
        Engine* m_engine;
        Hud* m_hud;

        //Sound
        //sf::Music m_mainThemeMusic;

        bool m_victory;
        sf::Sprite m_filterPause;
        sf::Texture m_textureFilterPause;


        float m_speedPlayer;
};

#endif // CONTROLLER_HPP
