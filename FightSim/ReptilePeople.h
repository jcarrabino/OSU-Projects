/*********************************************************************
** Program Filename: ReptilePeople.h
** Author: John Carrabino
** Date: 7/24/2016
** Description: This is the ReptilePeople class specification file.
** Input: n/a
** Output: n/a
*********************************************************************/
#ifndef REPTILEPEOPLE_H
#define REPTILEPEOPLE_H

#include "Creature.h"

class ReptilePeople : public Creature{
public:
    ReptilePeople(int, int, int, int, Type, Status);
    virtual ~ReptilePeople();
   
    
};

#endif /* REPTILEPEOPLE_H */

