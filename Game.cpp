#include <SFML/Graphics.hpp>
#include <time.h>
#include <SFML/Audio.hpp>

#include "include/Controller.hpp"


int main()
{
    sf::VideoMode vm = sf::VideoMode::getDesktopMode();
    std::cout << vm.height << " " << vm.width << std::endl;
    if(vm.height>1080 || vm.width > 1920)
    {
        std::cout << "CHange vm" << std::endl;
        vm = sf::VideoMode(1920,1080);
    }
    sf::RenderWindow* window = new sf::RenderWindow(vm/*sf::VideoMode::getDesktopMode()*/ /*sf::VideoMode(1920,1080)*/, "Rural Network", sf::Style::Default /*| sf::Style::Fullscreen*/);
    window->setFramerateLimit(60);
    window->setVerticalSyncEnabled(true);
    srand(time(NULL));

    Controller* controller = new Controller(window);
    sf::Joystick::update();

    controller->start();

    delete controller;
    return 0;
}
