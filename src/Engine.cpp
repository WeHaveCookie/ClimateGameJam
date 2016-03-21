#include "../include/Engine.hpp"

Engine::Engine(Level* level, sf::View* viewGame)
{
    m_level = level;
    m_sizeLevel = m_level->getSizeLevel();
    m_viewGame = viewGame;
}

Engine::Engine()
{
}

Engine::~Engine()
{
}

bool Engine::collisionCircle(sf::FloatRect box1, sf::CircleShape circle)
{
   int d2 = (box1.left-circle.getPosition().x)*(box1.left-circle.getPosition().x) + (box1.top-circle.getPosition().y)*(box1.top-circle.getPosition().y);
   if (d2>pow(circle.getRadius(),2))
      return false;
   else
      return true;
}

bool Engine::collisionAABB(sf::FloatRect box1, sf::FloatRect box2)
{
    return !((box2.left >= box1.left + box1.width) ||
        (box2.left  + box2.width <= box1.left) ||
        (box2.top >= box1.top + box1.height) ||
        (box2.top + box2.height <= box1.top));
}

bool Engine::move(DrawableObject* obj, const sf::Vector2f& motion, const bool collision)
{
    if(!collision)
    {
        obj->move(motion);
        return true;
    }

    sf::Vector2f realMotion = motion;
    if(realMotion.y != 0)
    {
        realMotion.y = 0;
    }

    sf::Vector2f posPlayer = obj->getPosition();
    //std::cout << "Pos player x : " << realMotion.x + posPlayer.x + SPRITE_WIDTH  << " | Word size x : " << m_sizeLevel.x << " | motion : " << realMotion.x << std::endl;
    if(realMotion.x*obj->getSpeed() + posPlayer.x + CHARACTER_WIDTH > m_sizeLevel.x || realMotion.x*obj->getSpeed() + posPlayer.x < 0)
    { // Block
        return false;
    } else
    {
        //if(m_viewGame->getCenter().x - (m_viewGame->getSize().x/2.0) + realMotion.x < 0)
        //std::cout << "Pos player x : " << floor(posPlayer.x + realMotion.x + (SPRITE_WIDTH/2.0)) << " | Center View x : " << m_viewGame->getCenter().x << std::endl;
        if(m_viewGame->getCenter().x - (m_viewGame->getSize().x/2.0) + realMotion.x*obj->getSpeed() >= 0 && m_viewGame->getCenter().x + (m_viewGame->getSize().x/2.0) + realMotion.x*obj->getSpeed() <= m_sizeLevel.x
           && posPlayer.x + (CHARACTER_WIDTH/2.0) >= m_viewGame->getCenter().x - CHARACTER_WIDTH
           && posPlayer.x + (CHARACTER_WIDTH/2.0) <= m_viewGame->getCenter().x + CHARACTER_WIDTH)
        {
            m_viewGame->move(realMotion*obj->getSpeed());
            m_level->moveBackGround(realMotion*obj->getSpeed());
        }
        enterOnBuilding(obj->getGlobalBounds());
        obj->move(realMotion);
        return true;
    }
}

Building* Engine::enterOnBuilding(sf::FloatRect bounds)
{
    std::vector<Building*> buildings = m_level->getBuilding();
    for(int i = 0; i < (int)buildings.size(); i++)
    {
        if(collisionAABB(bounds,buildings[i]->getGlobalBounds()))
        {
            buildings[i]->displayButton(true);
            return buildings[i];
        } else
        {
            buildings[i]->displayButton(false);
        }
    }
    return NULL;
}

std::vector<float> Engine::getSoundAmbiance(DrawableObject* obj)
{
    std::vector<Building*> buildings = m_level->getBuilding();
    std::vector<float> soundAmb;
    for(int i = 0; i < NBR_ANIMALS+1; i++)
    {
        soundAmb.push_back(0);
    }
    for(int i = 0; i < (int)buildings.size(); i++)
    {
        RessourcesType rt = buildings[i]->getType();
        if(rt > 0)
        {
            soundAmb[rt] += 100*(1920 - abs(buildings[i]->getGlobalBounds().left - obj->getPosition().x))/1920;
            //std::cout << " build : " << buildings[i]->getGlobalBounds().left << " char : " << obj->getPosition().x << " Value : " << 100*(1920 - abs(buildings[i]->getGlobalBounds().left - obj->getPosition().x))/1920 << std::endl;
            if(soundAmb[rt] < 0.0)
            {
                soundAmb[rt] = 0.0;
            } else if (soundAmb[rt] > 100.0)
            {
                soundAmb[rt] = 100.0;
            }
        }
    }
    return soundAmb;
}
