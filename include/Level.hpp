#ifndef LEVEL_HPP
#define LEVEL_HPP
#include <SFML/Graphics.hpp>
#include <vector>

#include "Reader.hpp"
#include "Constante.hpp"
#include "ChickenCoop.hpp"
#include "Barn.hpp"
#include "House.hpp"
#include "Piggery.hpp"
#include "SellStore.hpp"
#include "Controller.hpp"

class Controller;

class Level : public Reader
{
    public:
        Level(const std::string& path, Controller* controller);
        virtual ~Level();

        // Function

        // Inline
        void draw(sf::RenderWindow* window);

        sf::Vector2f getSizeLevel() {return m_sizeLevel;}
        void remplaceBuild(Building* build);
        void moveBackGround(sf::Vector2f motion);
        void generateMontain();
        void generateCloud();
        void MoveCloud(sf::Vector2f motion);
        inline std::vector<Building*> getBuilding() {return m_buildings;}

    protected:
    private:
        // Function
        void read();
        void buildLevel();

        // Attribut
        std::string m_path;
        sf::Texture m_tileset;
        sf::Vector2i m_levelSize;
        sf::Vector2f m_sizeLevel;
        Controller* m_controller;

        std::vector<Building*> m_buildings;

        sf::Sprite m_backGround;
        sf::Texture m_textureMontain;
        std::vector<sf::Sprite> m_montains;
        sf::Texture m_textureSecondGround;
        sf::Sprite m_secondGround;
        sf::Texture m_textureThirdGround;
        sf::Sprite m_thirdGround;
        sf::Texture m_textureGround;
        sf::Sprite m_ground;
        sf::Texture m_textureBackGround;
        sf::Sprite m_spriteBackGround;

        sf::Texture m_textureElements;
        std::vector<sf::Sprite> m_elements;

        sf::Texture m_textureCloud;
        std::vector<sf::Sprite> m_clouds;

        //sf::VertexArray m_levelVertices;
};
#endif // LEVEL_HPP
