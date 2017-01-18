/*********************************************************************
** Program Filename: ReptilePeople.cpp
** Author: John Carrabino
** Date: 7/24/2016
** Description:This is the derived ReptilePeople class implementation 
 * file.
** Input: All input parameters for strength, armor, number of dice,
 * number of sides per die, creature type, and creature status must 
 * be passed to the constructor upon initialization.
** Output: n/a
*********************************************************************/
#include "ReptilePeople.h"

/*********************************************************************
** Function: ReptilePeople()
** Description: ReptilePeople class constructor.
** Parameters: strength, armor, number of dice used for attack, 
 * number of sides per die, creature Type, and creature Status
** Pre-Conditions: All of the necessary parameters must be 
 * passed to the constructor to initialize a new object.
** Post-Conditions: n/a
*********************************************************************/
ReptilePeople::ReptilePeople(int strength, int armor, int diceNum, int diceSides, 
                   Type species, Status game)
:Creature(strength, armor, diceNum, diceSides, species, game){
}

/*********************************************************************
** Function: ~ReptilePeople()
** Description: virtual ReptilePeople destructor. I put this here as a 
 * formality and to help emphasize the use of polymorphism. Since the 
 * class objects do not dynamically allocate  memory it was unnecessary
 *  to have a programmer defined constructor, as all new objects are 
 * deallocated at the end of main.cpp
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
ReptilePeople::~ReptilePeople(){
    
}