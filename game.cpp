#include "game.h"
#include <algorithm>
#include <cctype>

// Deconstructor
Game::~Game()
{
    for (std::vector<Container*>::iterator it = containers.begin(); it != containers.end(); it++)
    {
        if (*it)
        {
            delete *it;
            *it = NULL;
        }
    }
    for (std::vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); it++)
    {
        if (*it)
        {
            delete *it;
            *it = NULL;
        }
    }
}

// initialize the room and start the main game loop
void Game::startGame()
{
    std::vector<Item*> contents;
    std::string keyDesc = "A rusty key found under a door mat. I wonder what it goes to.\n";
    Item * key = new Item(1000, "key", keyDesc);
    contents.push_back(key);
    Container * mat = new Container("mat", false, true, 0, contents);
    containers.push_back(mat);
    keyDesc = "A brass doorknob. I can use this to open the door.";
    Item * doorknob = new Item(1001, "doorknob", keyDesc);
    contents.clear();
    contents.push_back(doorknob);
    Container * cabinet = new Container("cabinet", true, false, 1000, contents);
    containers.push_back(cabinet);
    Container * door = new Container("doorknobless-door", true, false, 1001, std::vector<Item*>());
    std::cout << "Welcome to the escape room. Type help for list of commands.\n";
    playGame();
}

// handle help, inventory, look (no object)
void Game::handleCommand(std::string command)
{
    std::transform(command.begin(), command.end(), command.begin(),
    [](unsigned char c){ return std::tolower(c); });
    if (command == "help") help();
    else if (command == "inventory")
    {
        if (inventory.empty()) std::cout << "You don't have any items.\n";
        else
        {
            std::cout << "You have:";
            for (std::vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); it++)
            {
                std::cout << " a " << (*it)->getName();
            }
            std::cout << std::endl;
        }
        
    }
    else if (command == "look")
    {
        std::cout << "You see a cabinet on the wall, a doorknob-less door, and a mat that says, \"Welcome\".\n";
    }
    else std::cout << "I don't understand.\n";
}

void Game::handleCommand(std::string command, std::string obj, std::string target)
{
    //TODO
}

void Game::handleCommand(std::string command, std::string target)
{
    //TODO
}

// The main game loop
void Game::playGame()
{
    while (1)
    {
        std::string command;
        std::string arg1;
        std::string arg2;
        std::cin >> command;
        if (std::cin.eof())
        {
            handleCommand(command);
        }
        else
        {
            std::cin >> arg1;
            if (std::cin.eof())
            {
                handleCommand(command, arg1);
            }
            else
            {
                std::cin >> arg2;
                handleCommand(command, arg1, arg2);
            }
        }
        if (!std::cin.eof())
        {
            while (!std::cin.eof()) std::cin >> arg2;
        }
        for (std::vector<Container*>::iterator it = containers.begin(); it != containers.end(); it++)
        {
            Container * c = *it;
            if ((c->getName() == "doorknobless-door") && (c->isOpen()))
            {
                std::cout << "You go through the door and exit the room.\nYou win!\n";
                return;
            }
        }
    }
}

// help command
void Game::help()
{
    std::cout << "List of commands are:\nhelp\nlook\nlook [object]\n"
    << "inventory\nuse [object]\nuse [object1] [object2]\nsearch [object]\n";
}