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
#include "Event.hpp"
#include "EventRessources.hpp"
#include "EventBonus.hpp"
#include "InstaFarm.hpp"
#include "Chicken.hpp"
#include "Cow.hpp"
#include "Pig.hpp"
#include "ShopHUD.hpp"
#include "Menu.hpp"
#include "Pnj.hpp"
#include "Animal.hpp"

class Character;
class Engine;
class Menu;
class Level;
class InstaFarm;

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
        void increaseRessource(RessourcesType rt, int value);
        void triggerEvent();
        void updateEvent();
        void updateNotoriety();
        void addNotoriety(int value);
        void showIconBuild(Building* build);
        void increaseSoundAnimal(RessourcesType rt, int level);
        inline void showShop(bool b) {m_displayShop = b;}

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
        void drawViewInstaHouse();
        void drawViewPost();
        void drawViewShop();

        // Attribut
        sf::RenderWindow* m_window;
        Character* m_player;
        //Menu* m_menu;
        bool m_displayMenu;
        bool m_displayPause;
        bool m_displayInstaHouse;
        bool m_displayShop;
        sf::View m_viewGame;
        sf::View m_viewMenu;
        sf::View m_viewHUD;
        sf::View m_viewInstaHouse;
        sf::View m_viewPost;
        sf::View m_viewShop;


        Level* m_level;
        Engine* m_engine;
        Hud* m_hud;
        ShopHUD* m_shopHUD;
        Menu* m_menu;
        std::vector<Event*> m_events;
        std::vector<Event*> m_triggeredEvent;
        Event* m_focusEvent;
        InstaFarm* m_instaFarm;
        std::vector<Pnj*> m_pnjs;

        //Sound
        sf::Music m_introMusic;
        sf::Music m_mainThemeMusic;
        sf::Music m_ambianceMusic;
        sf::Music m_soundCow;
        sf::Music m_soundChicken;
        sf::Music m_soundPig;
        sf::Music m_soundBuild;
        sf::Music m_soundError;

        bool m_transitionMusic;

        bool m_victory;
        sf::Sprite m_filterPause;
        sf::Texture m_textureFilterPause;

        sf::Texture m_textureIconBuild;
        sf::Sprite m_spriteIconBuild;
        std::vector<sf::Sprite> m_spritesIconsBuilds;

        sf::Texture m_textureIconPad;
        sf::Sprite m_spriteIconPad;

        sf::Texture m_textureAButton;
        sf::Sprite m_spriteIconAButton;

        std::vector<Animal*> m_animals;
        float m_volumeAmbianceMusique;
        float m_volumeCow;
        float m_volumeChicken;
        float m_volumePig;


        // VICTORY
        sf::Texture m_textureVictory;
        sf::Sprite m_spriteVictory;

        // LOOSE
        sf::Texture m_textureLoose;
        sf::Sprite m_spriteLoose;



        float m_speedPlayer;
};

#endif // CONTROLLER_HPP
