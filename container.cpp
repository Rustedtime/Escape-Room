#include "container.h"
#include <iostream>

// Default constructor
Container::Container()
{
    contents = std::vector<Item*>();
    locked = false;
    opened = false;
    keyId = 0;
    name = "undefined_container";
}

// Non-default constructor
Container::Container(std::string name, bool locked, bool opened, int keyId, std::vector<Item*> contents)
{
    this->name = name;
    this->locked = locked;
    this->opened = opened;
    this->keyId = keyId;
    this->contents = contents;
}

// Deconstructor
Container::~Container()
{
    for (std::vector<Item*>::iterator it = contents.begin(); it != contents.end(); it++)
    {
        if (*it)
        {
            delete *it;
            *it = NULL;
        }
    }
}

// check to see if anything is in the box
bool Container::isEmpty()
{
    return !contents.size();
}

// check to see if the container is open
bool Container::isOpen()
{
    return opened;
}

// attempt to unlock the container using a key
void Container::unlock(int keyId)
{
    if (keyId == this->keyId)
    {
        std::cout << "You use the key to open the box.\n";
        locked = false;
        opened = true;
    }
    else
    {
        std::cout << "The key does not fit in the lock.\n";
    }
    
}

// search the container and add the contents to the inventory if the container is unlocked
std::vector<Item*> & Container::search()
{
    if (locked)
        std::cout << "The " << name << " is locked.\n";
    else
    {
        std::cout << "You find: ";
        for (std::vector<Item*>::iterator it = contents.begin(); it != contents.end(); it++)
        {
            std::cout << (*it)->getName << " ";
        }
        std::cout << std::endl;
        return contents;
    }
    std::vector<Item*> nothing;
    return nothing;
}

// describe the container
void Container::look()
{
    std::cout << "You see a " << name << ". ";
    if (locked) std::cout << "It is locked.";
    std::cout << std::endl;
}

// open the container
void Container::use()
{
    if (opened) std::cout << "The " << name << " is already open.\n";
    else
    {
        std::cout << "You open the " << name << ".\n";
        opened = true;
    }
    
}