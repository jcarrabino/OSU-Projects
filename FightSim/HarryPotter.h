/*********************************************************************
** Program Filename: HarryPotter.h
** Author: John Carrabino
** Date: 7/24/2016
** Description: This is the HarryPotter class specification file.
** Input: n/a
** Output: n/a
*********************************************************************/
#ifndef HARRYPOTTER_H
#define HARRYPOTTER_H

#include <iostream>
#include "Creature.h"

class HarryPotter : public Creature{
public:
    HarryPotter(int, int, int, int, Type, Status);
    virtual ~HarryPotter();
    virtual void defend(int);
    
protected:
    int hogwarts;
    
};


#endif /* HARRYPOTTER_H */

