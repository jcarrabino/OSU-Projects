/*********************************************************************
** Program Filename: Medusa.cpp
** Author: John Carrabino   
** Date: 7/24/2016
** Description: This is the Medusa class implementation file.
** Input: All input parameters for strength, armor, number of dice,
 * number of sides per die, creature type, and creature status must 
 * be passed to the constructor upon initialization.
** Output: If her glare bonus is activated, Medusa will print out 
 * a message to the screen informing the user that her bonus is 
 * activated.
*********************************************************************/
#include "Medusa.h"

/*********************************************************************
** Function: Medusa()
** Description: Medusa class constructor.
** Parameters: strength, armor, number of dice used for attack, 
 * number of sides per die, creature Type, and creature Status
** Pre-Conditions: All of the necessary parameters must be 
 * passed to the constructor to initialize a new object.
** Post-Conditions: n/a
*********************************************************************/
Medusa::Medusa(int strength, int armor, int diceNum, int diceSides, 
                   Type species, Status game)
:Creature(strength, armor, diceNum, diceSides, species, game){
}

/*********************************************************************
** Function: ~Medusa()
** Description: virtual Medusa destructor. I put this here as a 
 * formality and to help emphasize the use of polymorphism. Since the 
 * class objects do not dynamically allocate  memory it was unnecessary
 *  to have a programmer defined constructor, as all new objects are 
 * deallocated at the end of main.cpp
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
Medusa::~Medusa(){
    
}

/*********************************************************************
** Function: attack()
** Description: This is the derived Medusa class's overridden attack
 * function. For every call to attack() Medusa will roll 2 6 sided 
 * dice. If her attackTotal is equal to 12 then her glare bonus is 
 * activated, outputting an attack total of 1000 and instantly 
 * turning her opponent into stone and winning the match.
** Parameters: n/a
** Pre-Conditions: The data members for the number of attack dice 
 * and the sides of the dice must be initialized prior to the 
 * function call.
** Post-Conditions: Returns the total attack points and assigns it
 * to the attackTotal data member so that it may be accessed in main
 * through an accessor function. If glare is activated, then Medusa 
 * wins the current fight.
*********************************************************************/
int Medusa::attack(){
    //2d6*Glare
    attackTotal = diceRoll(2,6);
    if(attackTotal == 12){
        std::cout << "The opposing player has gazed into the eyes of Medusa...";
        std::cout << std::endl << std::endl;
        std::cout << "Press ENTER to continue the battle!" << std::endl;
        std::cin.get();
        return attackTotal = 1000;
    } else{
        return attackTotal;
    }
}


