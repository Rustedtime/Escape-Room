/*********************************************************************
 * class: Item
 * This class encapsulates the game objects that can be added to the 
 * player's inventory
**********************************************************************/
#ifndef ITEM_H
#define ITEM_H

#include "gameObject.h"

class Item: public GameObject
{
    public:
    Item(): inventoryStatus(false) {}
    bool isInInventory();
    void take();
    private:
    bool inventoryStatus;
};


#endif