/***********************************************************
 * Class: GameObject
 * The base class that all of the game objects inherit from
 * *********************************************************/
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <string>

class GameObject
{
    public:
    virtual void look() = 0;
    virtual void use() = 0;
    std::string getName() { return name; }

    protected:
    std::string name;
};


#endif