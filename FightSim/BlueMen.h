/*********************************************************************
** Program Filename: BlueMen.h
** Author: John Carrabino
** Date: 7/24/2016
** Description: This is the BlueMen class specification file.
** Input: n/a
** Output: n/a
*********************************************************************/
#ifndef BLUEMEN_H
#define BLUEMEN_H

#include <iostream>
#include "Creature.h"

class BlueMen : public Creature{
public:
    BlueMen(int, int, int, int, Type, Status);
    virtual ~BlueMen();
    virtual void defend(int);
    
protected:
    int dCount;

};

#endif /* BLUEMEN_H */

