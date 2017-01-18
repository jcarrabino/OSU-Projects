/*********************************************************************
** Program Filename: Gollum.h
** Author: John Carrabino
** Date: 7/24/2016
** Description: This is the Gollum class specification file.
** Input: n/a
** Output: n/a
*********************************************************************/
#ifndef GOLLUM_H
#define GOLLUM_H

#include <iostream>
#include "Creature.h"

class Gollum : public Creature{
public:
    Gollum(int, int, int, int, Type, Status);
    virtual ~Gollum();
    virtual int attack();

    
};


#endif /* GOLLUM_H */

