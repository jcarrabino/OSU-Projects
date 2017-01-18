/*********************************************************************
** Program Filename: Gollum.cpp
** Author: John Carrabino
** Date: 7/24/2016
** Description: This is the derived Gollum class implementation file.
** Input: All input parameters for strength, armor, number of dice,
 * number of sides per die, creature type, and creature status must 
 * be passed to the constructor upon initialization.
** Output: If his ring bonus is activated, Gollum will print out 
 * a message to the screen informing the user that his bonus is 
 * activated.
*********************************************************************/
#include "Gollum.h"

/*********************************************************************
** Function: Gollum()
** Description: Gollum class constructor.
** Parameters: strength, armor, number of dice used for attack, 
 * number of sides per die, creature Type, and creature Status
** Pre-Conditions: All of the necessary parameters must be 
 * passed to the constructor to initialize a new object.
** Post-Conditions: n/a
*********************************************************************/
Gollum::Gollum(int strength, int armor, int diceNum, int diceSides, 
                   Type species, Status game)
:Creature(strength, armor, diceNum, diceSides, species, game){
}

/*********************************************************************
** Function: ~Gollum()
** Description: virtual Gollum destructor. I put this here as a 
 * formality and to help emphasize the use of polymorphism. Since the 
 * class objects do not dynamically allocate  memory it was unnecessary
 *  to have a programmer defined constructor, as all new objects are 
 * deallocated at the end of main.cpp
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
Gollum::~Gollum(){
    
}

/*********************************************************************
** Function: attack()
** Description: This is the overridden derived class attack function 
 * for the Gollum class. This function rolls a 100 sided die and 
 * if the result of the roll % 20 equals 0 then Gollum's speial attack
 * will activate. Once activates a message will appear in between 
 * rounds notifying the user's that his ring bonus has been activated.
 * After being activated his attack will be the sum of 3 dice rolls, 
 * with each die having 6 sides. There is only a 5% chance of this
 * happening, so the other 95% of the time Gollum's attack will be the 
 * sum of 1 six-sided die.
** Parameters: n/a
** Pre-Conditions: A Gollum derived class object has been initialized.
** Post-Conditions: Returns the total attack points and assigns it
 * to the attackTotal data member so that it may be accessed in main
 * through an accessor function. There is a 5% chance that Gollum's
 * attack will be tripled to 3 die rolls instead of just one.
*********************************************************************/
int Gollum::attack(){
    //1d6*ring
    int theOneTrueRing = diceRoll(1,100);
    
    if(theOneTrueRing % 20 == 0){
        std::cout << "MY PRECIOUS!!!" << std::endl;
        std::cout << "Gollum has activated his Ring bonus!" << std::endl;
        std::cout << std::endl;
        std::cout << "Press ENTER to continue the battle!" << std::endl;
        std::cin.get();
        attackTotal = diceRoll(3,6);
        return attackTotal;
    } else{
        attackTotal = diceRoll(1,6);
        return attackTotal;
    }
   
}