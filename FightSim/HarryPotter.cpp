/*********************************************************************
** Program Filename: HarryPotter.cpp
** Author: John Carrabino
** Date: 7/24/2016
** Description: This is the derived HarryPotter class implementation 
 * file.
** Input: All input parameters for strength, armor, number of dice,
 * number of sides per die, creature type, and creature status must 
 * be passed to the constructor upon initialization.
** Output: When Harry Potter's hogwarts bonus is activated a message
 * will be printed to the screen between round results informing
 * the user that hogwarts has saved you, but he's on his own now.
*********************************************************************/
#include "HarryPotter.h"

/*********************************************************************
** Function: HarryPotter()
** Description: HarryPotter class constructor.
** Parameters: strength, armor, number of dice used for attack, 
 * number of sides per die, creature Type, and creature Status
** Pre-Conditions: All of the necessary parameters must be 
 * passed to the constructor to initialize a new object.
** Post-Conditions: n/a
*********************************************************************/
HarryPotter::HarryPotter(int strength, int armor, int diceNum, int diceSides, 
                   Type species, Status game)
:Creature(strength, armor, diceNum, diceSides, species, game){
    this->hogwarts = 1;
}

/*********************************************************************
** Function: ~HarryPotter()
** Description: virtual HarryPotter destructor. I put this here as a 
 * formality and to help emphasize the use of polymorphism. Since the 
 * class objects do not dynamically allocate  memory it was unnecessary
 *  to have a programmer defined constructor, as all new objects are 
 * deallocated at the end of main.cpp
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
HarryPotter::~HarryPotter(){
    this->hogwarts = 1;
}

/*********************************************************************
** Function: defend();
** Description: This is the overridden defense function for the 
 * HarryPotter derived class. When HarryPotter's health drops from 10 
 * to 0, he is instantly revived at hogwarts. This causes his protected
 * data member hogwarts to go from 1 to 0. After being revived a message
 *  is displayed between rounds informing the user that he was revived,
 * but that it will not happen again.
** Parameters: Attack total of opposing creature.
** Pre-Conditions: Opposing creature has already calculated its attack
 * which is assigned to the attack variable in main then passed to this
 * function. 
** Post-Conditions: The Status of this creature object as well as its
 * strength points are changed appropriately. If HarryPotter's hogwarts
 * bonus is activated then a message is displayed to the user in between
 * turns informing the user that his bonus was activated.
*********************************************************************/
void HarryPotter::defend(int attack){
    //2d6
    int damage;
    if(attack == 1000){
        this->game = STONE;
    } else {
        defenseTotal = diceRoll(2,6);
        int buff = attack - defenseTotal;
        damage = buff - this->armorP;
    }
    if (damage > 0){
        this->strengthP -= damage;
    }

    if(this->strengthP > 0){
        this->game = CONTINUE;
    }else if(this->strengthP <= 0 && this->hogwarts == 1){
        this->strengthP = 10;
        this->hogwarts = 0;
        std::cout << "By Hagrid's beard that was close!" << std::endl; 
        std::cout << std::endl;
        std::cout << "Hogwarts can only revive you once,\n"
                "so you're on your own now..." << std::endl << std::endl;
        std::cout << "Press ENTER to continue the battle!" << std::endl;
        std::cin.get();
    }else if(this->strengthP <= 0 && this->hogwarts != 1)
        this->game = LOSE;       
}
