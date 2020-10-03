/*********************************************************************
 * class: Item
 * This class encapsulates the game objects that can be added to the 
 * player's inventory
**********************************************************************/
#ifndef ITEM_H
#define ITEM_H

#include "gameObject.h"
#include "container.h"
#include <iostream>

class Item: public GameObject
{
    public:
    Item();
    Item(int keyId, std::string name, std::string description);
    void use(Container & target);
    void look();

    private:
    int keyId;
    std::string description;
};


#endif