/*****************************************************
 * class: Game
 * The class that encapsulates the game logic/loop
 * ***************************************************/
#ifndef GAME_H
#define GAME_H

#include <vector>
#include <iostream>
#include "item.h"
#include "container.h"

class Game
{
    private:
    std::vector<Container*> containers;
    std::vector<Item*> inventory;
    std::string command;
    void handleCommand(std::string command);
    void handleCommand(std::string command, std::string obj, std::string target);
    void handleCommand(std::string command, std::string target);
    void playGame();
    void help();

    public:
    Game();
    ~Game();
    void startGame();
};

#endif