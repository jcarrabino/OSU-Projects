/*********************************************************************
** Program Filename: BlueMen.cpp
** Author: John Carrabino
** Date: 7/24/2016
** Description: This is the derived BlueMen class implementation file.
** Input:All input parameters for strength, armor, number of dice,
 * number of sides per die, creature type, and creature status must 
 * be passed to the constructor upon initialization.
** Output: If the BlueMen's Mob bonus is activated then a message
 * will be printed to the screen in between rounds notifying the
 * user if the BlueMen's defense has been weakened.
*********************************************************************/
#include "BlueMen.h"

/*********************************************************************
** Function: BlueMen()
** Description: BlueMen class constructor.
** Parameters: strength, armor, number of dice used for attack, 
 * number of sides per die, creature Type, and creature Status
** Pre-Conditions: All of the necessary parameters must be 
 * passed to the constructor to initialize a new object.
** Post-Conditions: n/a
*********************************************************************/
BlueMen::BlueMen(int strength, int armor, int diceNum, int diceSides, 
                   Type species, Status game)
:Creature(strength, armor, diceNum, diceSides, species, game){
  
}

/*********************************************************************
** Function: ~BlueMen()
** Description: virtual BlueMen destructor. I put this here as a 
 * formality and to help emphasize the use of polymorphism. Since the 
 * class objects do not dynamically allocate  memory it was unnecessary
 *  to have a programmer defined constructor, as all new objects are 
 * deallocated at the end of main.cpp
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
BlueMen::~BlueMen(){
    
}

/*********************************************************************
** Function: defend();
** Description: This is the overridden defend function for the BlueMen
 * derived class. This defense function looks at the current strength 
 * of the BlueMen object and for each 4 points deducted it removes
 * one of the BlueMen's 3 defensive dice. So at 8 strength points
 * they are left wit h2 dice and at 4 strength points they are left
 * with 1 die. When a die is removed a message is displayed in between
 * rounds to inform the user of their weakening defense. 
** Parameters: Attack total of opposing creature.
** Pre-Conditions: Opposing creature has already calculated its attack
 * which is assigned to the attack variable in main then passed to this
 * function. 
** Post-Conditions: The Status of this creature object as well as its
 * strength points are changed appropriately. If its defense points
 * are lowered by 4 or more points a message is printed to the screen
 * between rounds to inform the used of the weakening defense of the
 * BlueMen. 
*********************************************************************/
void BlueMen::defend(int attack){
    //3d6
    int buff;
    int damage;
    
    if(attack == 1000){
        this->game = STONE;
    }
    
    if(this->strengthP > 8){
        defenseTotal = diceRoll(3,6);
        buff = attack - defenseTotal;
        damage = buff - armorP;
        this->dCount = 1;
        if (damage > 0){
            strengthP -= damage;
        }
    }
    if(this->strengthP > 4 && this->strengthP <= 8){
        
        defenseTotal = diceRoll(2,6); 
        buff = attack - defenseTotal;
        damage = buff - armorP;
        if (damage > 0){
            strengthP -= damage;
        }
        if(this->dCount == 1){
            this->dCount++;
            std::cout << "You've weakened the Blue Men's defense...";
            std::cout << std:: endl << std:: endl;
            std::cout << "Press ENTER to continue the fight!" << std::endl;
            std::cin.get();
        } 
    } 
    if (this->strengthP <= 4){
        defenseTotal = diceRoll(1,6); 
        buff = attack - defenseTotal;
        damage = buff - armorP;
        if (damage > 0){
            strengthP -= damage;
        }
        if (this->dCount > 1){
            std::cout << "You've further weakened the Blue Men's defense...";
            std::cout << std::endl << std::endl;
            this->dCount = -100;
            std::cout << "Press ENTER to continue the fight!" << std::endl;
            std::cin.get();
        }
    }
    
    if(this->strengthP > 0){
        this->game = CONTINUE;
    }
    
    if(this->strengthP <= 0){
        this->game = LOSE;
    }
}
