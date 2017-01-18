/*********************************************************************
** Program Filename: Creature.cpp
** Author: John Carrabino
** Date: 7/24/2016
** Description: This is the base class implementation file. It contains
 * all of the base class functions used by the derived class objects.
 * Since this is a pure abstract class it can not be initiated, but 
 * allows all derived class objects to access its members unless the
 * derived class object has overridden member functions.
** Input: n/a
** Output: n/a
*********************************************************************/
#include "Creature.h"

/*********************************************************************
** Function: Creature()
** Description: Creature class constructor.
** Parameters: strength, armor, number of dice used for attack, 
 * number of sides per die, creature Type, and creature Status
** Pre-Conditions: All of the necessary parameters must be 
 * passed to the constructor to initialize a new object.
** Post-Conditions: n/a
*********************************************************************/
Creature::Creature(int strength, int armor, int diceNum, int diceSides, 
                   Type species, Status game){
    this->strengthP = strength;
    this->armorP = armor;
    this->type = species;
    this->game = game;
    this->dNum = diceNum;
    this->dSides = diceSides;
    this->speedP = diceRoll(1,12);
    this->attackTotal = 0;
    this->defenseTotal = 0;
 
    
}

/*********************************************************************
** Function: ~Creature()
** Description: virtual creature destructor. I put this here as a 
 * formality and to help emphasize that this is the abstract base
 * class. Since the class objects do not dynamically allocate 
 * memory it was unnecessary to have a programmer defined constructor,
 * as all new objects are deallocated at the end of main.cpp
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
Creature::~Creature(){
    
}

/*********************************************************************
** Function: getArmor()
** Description: Accessor function for the armor points data member.
** Parameters: n/a
** Pre-Conditions: armor points need to be initialized by the 
 * constructor before function is called
** Post-Conditions: returns armor points
*********************************************************************/
int Creature::getArmor(){
    return this->armorP;
}

/*********************************************************************
** Function: getStrength()
** Description: Accessor function for the strength points data member.
** Parameters: n/a
** Pre-Conditions: strength points need to be initialized by the 
 * constructor before function is called
** Post-Conditions: returns strength points
*********************************************************************/
int Creature::getStrength(){
    if(this->strengthP <= 0)
        this->strengthP = 0;
        
    return this->strengthP;
}

/*********************************************************************
** Function: getArmor()
** Description: Accessor function for the status of the object.
 * used to determine game state and whether the battle has concluded.
** Parameters: n/a
** Pre-Conditions: game data member need to be initialized by the 
 * constructor before function is called
** Post-Conditions: returns integer value corresponding to a 
 * specific game state. 
*********************************************************************/
int Creature::getStatus(){
    if(this->game == CONTINUE){
        return 0;
    }else if(this->game == WIN){
        return 1;
    }else if(this->game == LOSE){
        return 2;
    }else{
        return 3; /* Creature has been turned to stone */
    }
}

/*********************************************************************
** Function: attack()
** Description: This is the base attack function, it is utilized by 
 * all objects which do not override the base class's virtual 
 * attack function.
** Parameters: n/a
** Pre-Conditions: The data members for the number of attack dice 
 * and the sides of the dice must be initialized prior to the 
 * function call.
** Post-Conditions: Returns the total attack points and assigns it
 * to the attackTotal data member so that it may be accessed in main
 * through an accessor function.
*********************************************************************/
int Creature::attack(){
    //3d6 for RP, 2d10 for BM, & 2d6 for HP
    attackTotal = diceRoll(dNum, dSides);
    return attackTotal;
}

/*********************************************************************
** Function: defend();
** Description: The base class defend function takes the opposing
 * creatures attackTotal as a parameter. It uses conditional statements 
 * to determine if medusa has turned them to stone or not. If not then
 * if rolls a die for its defensive points, adds that to the creatures
 * armor points and subtracts that value from the opposing creatures
 * attack. After the damage has been dealt the function then uses a 
 * series of conditional statements to determine if the creature is
 * still alive or not and uses that to change the game Status of that 
 * creature.
** Parameters: Attack total of opposing creature.
** Pre-Conditions: Opposing creature has already calculated its attack
 * which is assigned to the attack variable in main then passed to this
 * function. 
** Post-Conditions: The Status of this creature object as well as its
 * strength points are changed appropriately.
*********************************************************************/
void Creature::defend(int attack){
    //1d6 for Medusa, Gollum & Reptile People
    if(attack == 1000){
            this->game = STONE;
        } else {
            defenseTotal = diceRoll(1,6);
            int buff = attack - defenseTotal;
            int damage = buff - this->armorP;
            if (damage > 0){
                this->strengthP -= damage;
            }
            if(this->strengthP > 0){
                this->game = CONTINUE;
            }
            if(this->strengthP <= 0){
                this->game = LOSE;
            }
        }
}

/*********************************************************************
** Function: diceRoll()
** Description: A modified diceRoll function from our lab B. 
** Parameters: It takes two integers as parameters which represent
 * the number of dice to be rolled and the number of sides on those
 * dice
** Pre-Conditions: Creature object must already exist
** Post-Conditions: Returns the sum of the dice rolls
*********************************************************************/
int Creature::diceRoll(int num, int sides){
    int roll, sum=0;
    for(int i=0; i<num; i++){
       roll = rand() % sides + 1;
       sum += roll;
    }
    return sum;
}

/*********************************************************************
** Function: getSpeed()
** Description: Accessor function for the speed points data member.
** Parameters: n/a
** Pre-Conditions: speed points need to be initialized by the 
 * constructor before function is called
** Post-Conditions: returns speed points
*********************************************************************/
int Creature::getSpeed(){
    return this->speedP;
}

/*********************************************************************
** Function: setSpeed()
** Description: Mutator function for the speed points data member. 
 * This function is called if two opposing creatures roll the same
 * speed at the beginning of their fight. It dolls a new speed die 
 * and changes the value of the object's speed points
** Parameters: It takes two integers as parameters which represent
 * the number of dice to be rolled and the number of sides on those
 * dice
** Pre-Conditions: The Creature object must already exist.
** Post-Conditions: The speed points of the object is updated
*********************************************************************/
void Creature::setSpeed(int num, int sides){
    this->speedP = diceRoll(1,12);
}

/*********************************************************************
** Function: getAttack()
** Description: Accessor function for the attack total data member.
** Parameters: n/a
** Pre-Conditions: This function is called after the objects attack
 * function in main.
** Post-Conditions: Returns attack total and assigns it to the attack
 * variable in main.cpp
*********************************************************************/
int Creature::getAttack(){
    return this->attackTotal;
}

/*********************************************************************
** Function: getDefense()
** Description: Accessor function for the defense total data member.
** Parameters: n/a
** Pre-Conditions: The creature object must already exist and its
 * defense function must be called prior to this accessor function.
** Post-Conditions: Returns defense total
*********************************************************************/
int Creature::getDefense(){
    return this->defenseTotal;
}