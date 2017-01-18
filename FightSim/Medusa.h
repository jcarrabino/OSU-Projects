/*********************************************************************
** Program Filename: Medusa.h
** Author: John Carrabino
** Date: 7/24/2016
** Description: This is the Medusa class specification file.
** Input: n/a
** Output: n/a
*********************************************************************/
#ifndef MEDUSA_H
#define MEDUSA_H
#include <iostream>
#include "Creature.h"

class Medusa : public Creature{
public:
    Medusa(int, int, int, int, Type, Status);
    virtual ~Medusa();
    virtual int attack();

    
};


#endif /* MEDUSA_H */

