/*****************************************************************
 * class: container
 * encapsulates a container game object such as a box or a table
 * ***************************************************************/
#ifndef CONTAINER_H
#define CONTAINER_H
#include "gameObject.h"
#include "item.h"
#include <vector>

class Container: public GameObject
{
    public:
    Container();
    Container(std::string name, bool locked, bool opened, int keyId, std::vector<Item*> contents);
    ~Container();
    bool isEmpty();
    bool isOpen();
    void unlock(int keyId);
    std::vector<Item*> & search();
    void look();
    void use();

    private:
    std::vector<Item*> contents;
    bool locked;
    bool opened;
    int keyId;
};


#endif