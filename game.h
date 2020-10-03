/*****************************************************
 * class: Game
 * The class that encapsulates the game logic/loop
 * ***************************************************/
#ifndef GAME_H
#define GAME_H

#include <vector>
#include <iostream>
#include "item.h"

class Game
{
    private:
    std::vector<GameObject> environment;
    std::vector<Item> items;
    std::string command;
    void handleCommand(std::string command, std::string target = std::string());
    void playGame();
    void help();

    public:
    Game();
    void startGame();
};

#endif