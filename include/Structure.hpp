#ifndef STRUCTURE_H
#define STRUCTURE_H
#include <SFML/Graphics.hpp>

enum MovingState {RIGHT, LEFT, IDLE};

enum MenuState {TITLE, CREDIT, END, NOTHING};

enum RessourcesType {WOOD, IRON, GOLD};

enum EventType {GOOD, BAD};

enum EventState {WAITED, TRIGGERED, ACCEPTED, FINISHED};

#endif // STRUCTURE_H
