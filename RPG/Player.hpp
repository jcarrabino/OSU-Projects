/*********************************************************************
** Program Filename: Player.hpp
** Author: John Carrabino
** Date: 8/7/2016
** Description:This is the space player specification file
** Input: n/a
** Output: n/a
*********************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <cstdlib>
#include <ctime>
#include "Space.hpp"

using std::cout;
using std::cin;
using std::endl;

enum Item{EMPTY, GEM, AMULET, ORB, TOME};

class Player{
private:
    int realmCount, findCount, nextSlot;
    Item inventory[4];
    Item available[4];
    Space *map;
public:
    Player();
    ~Player(); 
    int moveForward();
    int moveBackward();
    void moveLeft();
    void moveRight();
    int taskMenu();
    int moveMenu();
    int stepsTaken();
    int playerTurn();
    void viewInventory();
    void itemName(int);
    // void getCounts();
    void startLevel();
    int isSpecial();
    int itemSearch();
    void foundItem();
    void iFoundAll();
    bool didLose();
};


#endif /* PLAYER_HPP */

