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
        inline std::vector<Building*> getBuilding() {return m_buildings;}

    protected:
    private:
        // Function
        void read();
        void buildLevel();

        // Attribut
        std::string m_path;
        sf::Sprite m_backGround;
        sf::Texture m_tileset;
        sf::Vector2i m_levelSize;
        sf::Vector2f m_sizeLevel;
        Controller* m_controller;

        std::vector<Building*> m_buildings;

        //sf::VertexArray m_levelVertices;
};
#endif // LEVEL_HPP
