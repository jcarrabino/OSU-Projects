/*********************************************************************
** Program Filename: Creature.h
** Author: John Carrabino
** Date: 7/24/2016
** Description: This is the Creature base class specification file.
** Input: n/a
** Output: n/a
*********************************************************************/
#ifndef CREATURE_H
#define CREATURE_H
#include <ctime>
#include <cstdlib>

/* enum definition for game Status */
enum Status {CONTINUE, WIN, LOSE, STONE};

/* enum definition for creature type */
enum Type {MEDUSA, GOLLUM, REPTILEPEOPLE, BLUEMEN, HARRYPOTTER};

class Creature{
public:
    Creature(int, int, int, int, Type, Status);
    virtual ~Creature()= 0;
    int getArmor();
    int getStrength();
    int getStatus();
    int diceRoll(int, int);
    int getSpeed();
    void setSpeed(int, int);
    int getAttack();
    int getDefense();
    virtual int attack();
    virtual void defend(int);
    
protected:
    /* Protected data members store each creatures stats and allows
     each derived class object to access and modify their values. */
    int armorP;
    int strengthP;
    int speedP;
    int attackTotal;
    int defenseTotal;
    int dNum;
    int dSides;
    Status game;
    Type type;
};

#endif /* CREATURE_H */

