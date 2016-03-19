#ifndef STRUCTURE_H
#define STRUCTURE_H
#include <SFML/Graphics.hpp>

enum MovingState {RIGHT, LEFT, IDLERIGHT, IDLELEFT};

enum MenuState {TITLE, CREDIT, END, NOTHING};

enum RessourcesType {WOOD, IRON, GOLD};

enum EventType {GOOD, BAD};

enum EventState {WAITED, TRIGGERED, ACCEPTED, FINISHED};

enum PostType {LIKE, DISLIKE};

#endif // STRUCTURE_H
