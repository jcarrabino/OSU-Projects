/*********************************************************************
** Program Filename: main.cpp
** Author: John Carrabino
** Date: 7/24/2016
** Description: This assignment require us to use the concepts of 
 * class inheritance and polymorphism in order to create a fantasy
 * combat game. When the program starts the user is prompted to choose
 * a character for player one and player two. After the characters are
 * chosen the speed of each character is determined by a die roll in
 * order to see which player attacks first. After each round of attack
 * and defense the program makes sure that each player is still alive
 * before moving onto the subsequent attack-defense round. All of the
 * creatures to choose from are derived from the base Creature class 
 * and several of the creatures have special abilities that override 
 * the attack or defense function. When an override occurs a message 
 * will display on the screen in between rounds to notify the user
 * of a special event. After one of the creatures is defeated the
 * program displays the final round and final results of the battle.
 * At the conclusion of each battle the user is prompted to play
 * again or exit the program.
** Input: The user is initially prompted to input an integer from the
 * menu to choose a character for player 1 and player 2. At the 
 * conclusion of each round the user is prompted to press enter to
 * continue on to the next round. At the end of the battle the user 
 * is prompted to play again or exit the game and has to enter the 
 * corresponding integer to those two options.
** Output: This program outputs a list of creatures for the user to
 * choose from. It then informs the user which player rolled highest 
 * to start first. At the conclusion of each round of combat the 
 * results are displayed to the user. If a special overridden function
 * is activated by a derived class object then the program will 
 * display a special message to the screen in between rounds. At the
 * end of each battle the final results are displayed and a menu
 * prompts the user to play again or exit the program.
*********************************************************************/
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>

#include "Creature.h"
#include "ReptilePeople.h"
#include "BlueMen.h"
#include "Gollum.h"
#include "HarryPotter.h" 
#include "Medusa.h"

using std::cout;
using std::cin;
using std::endl;
 
/* function prototypes */
void charMenu();
int charSelect();
int playAgain();
void charStatus(Creature&);

int main(int argc, char** argv) {
    srand(time(NULL));
    int choice = 1;
    int selection1, selection2;
    int attack;
    int damageTaken;
    std::string player1, player2;
    /* Initializes Creature pointers which can be assigned to any derived
     class object that the player chooses */
    Creature *pt1;
    Creature *pt2;
    
    /* do-while loop that contains all combat functions */
    do{
    int count = 0;  /* round count */  
    
    cout << "Welcome to the Fantasy Arena!" << endl << endl;
   
    charMenu(); /* displays creature menu */
    /* Lets player 1 select the creature of their choosing, then 
     initialized the derived class object of their choice and 
     assigns it to the base class pointer */
    cout << "Player 1: ";
    selection1 = charSelect();
    if(selection1 == 1){
        pt1 = new ReptilePeople(18,7,3,6,REPTILEPEOPLE,CONTINUE);
        player1 = "Reptile Person";
    } else if(selection1 == 2){
        pt1 = new Medusa(8,3,2,6,MEDUSA,CONTINUE);
        player1 = "Medusa";
    } else if (selection1 == 3){
        pt1 = new Gollum(8,3,1,6,GOLLUM,CONTINUE);
        player1 = "Gollum";
    } else if (selection1 == 4){
        pt1 = new BlueMen(12,3,2,10,BLUEMEN,CONTINUE);
        player1 = "Blue Men";
    } else if(selection1 == 5){
        pt1 = new HarryPotter(10,0,2,6,HARRYPOTTER,CONTINUE);
        player1 = "Harry Potter";
    }
    
    cout << "Player 2: ";
    selection2 = charSelect();
    /* Lets player 2 select the creature of their choosing, then 
     initialized the derived class object of their choice and 
     assigns it to the base class pointer */
    if(selection2 == 1){
        pt2 = new ReptilePeople(18,7,3,6,REPTILEPEOPLE,CONTINUE);
        player2 = "Reptile Person";
    } else if(selection2 == 2){
        pt2 = new Medusa(8,3,2,6,MEDUSA,CONTINUE);
        player2 = "Medusa";
    } else if (selection2 == 3){
        pt2 = new Gollum(8,3,1,6,GOLLUM,CONTINUE);
        player2 = "Gollum";
    } else if (selection2 == 4){
        pt2 = new BlueMen(12,3,2,10,BLUEMEN,CONTINUE);
        player2 = "Blue Men";
    } else if(selection2 == 5){
        pt2 = new HarryPotter(10,0,2,6,HARRYPOTTER,CONTINUE);
        player2 = "Harry Potter";
    }   
    
    /* Rolls die to set the speed of each player to determine who goes first */
    cout << endl << "Rolling to see who goes first..." << endl;
    while(pt1->getSpeed() == pt2->getSpeed()){
        pt1->setSpeed(1,12);
        pt2->setSpeed(1,12);
    }
    
    /* Notifies user if player 1 goes first */
    if(pt1->getSpeed() > pt2->getSpeed()){
        cout << "Player 1's ";
        cout << player1 << " rolled a(n) " << pt1->getSpeed() << endl;
        cout << "Player 2's ";
        cout << player2 << " rolled a(n) " << pt2->getSpeed() << endl;
        cout << endl;
        cout << "Player 1's " << player1 << " attacks first." << endl;
        cout << endl;
     }
    /* Notifies user if player 1 goes first */
    if(pt1->getSpeed() < pt2->getSpeed()){
        cout << "Player 1's "; 
        cout << player1 << " rolled a(n) " << pt1->getSpeed() << endl;
        cout << "Player 2's ";
        cout << player2 << " rolled a(n) " << pt2->getSpeed() << endl;
        cout << endl;
        cout << "Player 2's " << player2 << " attacks first." << endl;
        cout << endl;
     }
    cin.clear();
    cin.sync();
    cout << "Press ENTER to start the battle!" << endl;
    cin.ignore(100,'\n');
    cin.get();
    /* beginning of combat loop */
    do{
        if(pt1->getSpeed() > pt2->getSpeed()){ /* player 1 attacks first */
            attack = pt1->attack();
            pt2->defend(attack);
            /* Checks if the player being attacked survived, if they die then
             the inner do-while loop is terminated with the break statement and 
             the final round results will be displayed */
            if(pt2->getStatus() == 2 || pt2->getStatus() == 3){
                count++;
                break;
            }
            attack = pt2->attack();
            pt1->defend(attack);
            if(pt1->getStatus() == 2 || pt1->getStatus() == 3){
                count++;
                break;
            }
        count++;
        /* if each player is alive at the end of the round then the 
         result menu will inform the user of the events of that round */
        cout << "__________ROUND " << count << " RESULTS__________" << endl; 
        cout << endl;
        cout << "Player 1: Attack = " << pt1->getAttack() << endl;
        cout << "Player 2: Defense = " << pt2->getDefense() << endl;
        damageTaken = (pt1->getAttack() - pt2->getDefense() - pt2->getArmor());
        if (damageTaken < 0 || damageTaken > 100)
            damageTaken = 0;
        cout << "Player 2: Damage Taken = " << damageTaken << endl << endl;
        cout << "Player 2: Attack = " << pt2->getAttack() << endl;
        cout << "Player 1: Defense = " << pt1->getDefense() << endl;
        damageTaken = (pt2->getAttack() - pt1->getDefense() - pt1->getArmor());
        if (damageTaken < 0 || damageTaken > 100)
            damageTaken = 0;
        cout << "Player 1: Damage Taken = " << damageTaken << endl << endl;
        cout << "Player 1's "<< player1 << endl;
        charStatus(*pt1);
        cout << endl << "Player 2's "<< player2 << endl;
        charStatus(*pt2);
        cout << "____________________________________" << endl << endl;
        }
        
        
        if(pt1->getSpeed() < pt2->getSpeed()){/* player 2 attacks first */
            attack = pt2->attack();
            pt1->defend(attack);
            if(pt1->getStatus() == 2 || pt1->getStatus() == 3){
                count++;
                break;
            }
            attack = pt1->attack();
            pt2->defend(attack);
            if(pt2->getStatus() == 2 || pt2->getStatus() == 3){
                count++;
                break;
            }
        count++;
        /* if each player is alive at the end of the round then the 
         result menu will inform the user of the events of that round */
        cout << "__________ROUND " << count << " RESULTS__________" << endl;
        cout << endl;
        cout << "Player 2: Attack = " << pt2->getAttack() << endl;
        cout << "Player 1: Defense = " << pt1->getDefense() << endl;
        damageTaken = (pt2->getAttack() - pt1->getDefense() - pt1->getArmor());
        if (damageTaken < 0 || damageTaken > 100)
            damageTaken = 0;
        cout << "Player 1: Damage Taken = " << damageTaken << endl << endl;
        cout << "Player 1: Attack = " << pt1->getAttack() << endl;
        cout << "Player 2: Defense = " << pt2->getDefense() << endl;
        damageTaken = (pt1->getAttack() - pt2->getDefense() - pt2->getArmor());
        if (damageTaken < 0 || damageTaken > 100)
            damageTaken = 0;
        cout << "Player 2: Damage Taken = " << damageTaken << endl << endl;
        cout << "Player 1's "<< player1 << endl;
        charStatus(*pt1);
        cout << endl << "Player 2's "<< player2 << endl;
        charStatus(*pt2);
        cout << "____________________________________" << endl << endl;
        }     
        
        
        
        cout << "Press ENTER to continue the fight!" << endl;
        cin.clear();
        cin.sync();
        cin.get();
        /* loop continues so long as both players are still alive */
    }while(pt1->getStatus() == CONTINUE && pt2->getStatus() == CONTINUE);
    
    /* post-loop output that displays the result of the final round for 
     * player 1 start*/
    if(pt1->getSpeed() > pt2->getSpeed()){    
        cout << "____________FINAL_ROUND____________" << endl << endl;
        cout << "Player 1: Attack = " << pt1->getAttack() << endl;
        cout << "Player 2: Defense = " << pt2->getDefense() << endl;
        damageTaken = (pt1->getAttack() - pt2->getDefense() - pt2->getArmor());
        if (damageTaken<0 || damageTaken > 100)
            damageTaken = 0;
        cout << "Player 2: Damage Taken = " << damageTaken << endl << endl;
        cout << "Player 2: Attack = " << pt2->getAttack() << endl;
        cout << "Player 1: Defense = " << pt1->getDefense() << endl;
        damageTaken = (pt2->getAttack() - pt1->getDefense() - pt1->getArmor());
        if (damageTaken < 0 || damageTaken > 100)
            damageTaken = 0;
        cout << "Player 1: Damage Taken = " << damageTaken << endl << endl;
        cout << "Player 1's "<< player1 << endl;
        charStatus(*pt1);
        cout << endl << "Player 2's "<< player2 << endl;
        charStatus(*pt2);
        cout << "____________________________________" << endl << endl;
        cout << "Press ENTER to view final results!" << endl;
        cin.clear();
        cin.sync();
        cin.get();
    }
    
    /* post-loop output that displays the result of the final round for 
     * player 2 start*/
    if(pt1->getSpeed() < pt2->getSpeed()){    
        cout << "____________FINAL_ROUND____________" << endl << endl;
        cout << "Player 2: Attack = " << pt2->getAttack() << endl;
        cout << "Player 1: Defense = " << pt1->getDefense() << endl;
        damageTaken = (pt2->getAttack() - pt1->getDefense() - pt1->getArmor());
        if (damageTaken<0 || damageTaken > 100)
            damageTaken = 0;
        cout << "Player 1: Damage Taken = " << damageTaken << endl << endl;
        cout << "Player 1: Attack = " << pt1->getAttack() << endl;
        cout << "Player 2: Defense = " << pt2->getDefense() << endl;
        damageTaken = (pt1->getAttack() - pt2->getDefense() - pt2->getArmor());
        if (damageTaken < 0 || damageTaken > 100)
            damageTaken = 0;
        cout << "Player 2: Damage Taken = " << damageTaken << endl << endl;
        cout << "Player 1's "<< player1 << endl;
        charStatus(*pt1);
        cout << endl << "Player 2's "<< player2 << endl;
        charStatus(*pt2);
        cout << "____________________________________" << endl << endl;
        cout << "Press ENTER to view final results!" << endl;
        cin.clear();
        cin.sync();
        cin.get();
    }
    
    /* post-loop output that displays the final results of the battle
     * if player 1 wins  */
    if(pt2->getStatus() == LOSE || pt2->getStatus() == STONE){
        cout << "____________FINAL_RESULTS____________" << endl << endl;
        cout << "Player 1's " << player1 << " has defeated" << endl;
        cout << "Player 2's " << player2 <<" in " << count << " turns!" << endl;
        cout << endl;
        cout << "Player 1: " << player1 << endl;
        cout << "Strength Points = " << pt1->getStrength() << endl;
        cout << "Status = Victor!" << endl;
        cout << endl << "Player 2: " << player2 << endl;
        cout << "Strength Points = " << pt2->getStrength() << endl;
        if(pt2->getStatus() == LOSE){
            cout << "Status = Defeated" << endl;
        } else{
            cout << "Status = Statue..." << endl;
        }
        cout << "____________________________________" << endl << endl;
    }
   
    /* post-loop output that displays the final results of the battle
      * if player 2 wins  */ 
    if(pt1->getStatus() == LOSE || pt1->getStatus() == STONE){
        cout << "____________FINAL_RESULTS____________" << endl << endl;
        cout << "Player 2's " << player2 << " has defeated" << endl;
        cout << "Player 1's " <<player1 <<" in " << count << " turns!" << endl;
        cout << endl;
        cout << "Player 1: " << player1 << endl;
        cout << "Strength Points = " << pt1->getStrength() << endl;
        if(pt1->getStatus() == LOSE){
            cout << "Status = Defeated" << endl;
        } else{
            cout << "Status = Statue..." << endl;
        }
        cout << endl << "Player 2: " << player2 << endl;
        cout << "Strength Points = " << pt2->getStrength() << endl;
        cout << "Status = Victor!" << endl;
        cout << "____________________________________" << endl << endl;
    }
        /* deallocates memory from the heap */
        delete pt1;
        delete pt2;
        /* Prompts user to play again or exit */
        choice = playAgain();
    }while(choice == 1);
    
    cout << endl << endl;
    cout << "Valar Morghulis!" << endl;
    return 0;
}

/*********************************************************************
** Function: charMenu()
** Description: Displays a list of all the characters to choose from
 * for the user.
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void charMenu(){
    cout << "Please choose from the following characters: " << endl;
    cout << "1 - Reptile People" << endl;
    cout << "2 - Medusa" << endl;
    cout << "3 - Gollum" << endl;
    cout << "4 - Blue Men" << endl;
    cout << "5 - Harry Potter" << endl;
}

/*********************************************************************
** Function: charSelect()
** Description: Lets user enter the corresponding integer for the 
 * character they wish to choose. Validates user input to ensure 
 * that only a valid integer from 1-5 will be returned from the 
 * function.
** Parameters: n/a
** Pre-Conditions: charMenu() is printed on the screen
** Post-Conditions: The function returns and integer from 1-5
*********************************************************************/
int charSelect(){
    int choice=1;
    cin >> choice;
    cin.sync();
    while(!cin || choice < 1 || choice > 5){
        cin.sync();
        cout << "Please select a number from 1 to 5: " << endl;
        cin.clear();
        cin.ignore(80,'\n');
        cin >> choice;
    }
    return choice;
}

/*********************************************************************
** Function: charStatus(Creature&)
** Description: Displays the strength points of each player at the
 * end of every round.
** Parameters: This function require a creature object to be passed
 * by reference to the function in order to get the strength points
 * of that creature.
** Pre-Conditions: the creature object must already exist
** Post-Conditions: prints the creatures strength points to the 
 * screen.
*********************************************************************/
void charStatus(Creature &player){
    cout << "Strength Points = " << player.getStrength() << endl;
}

/*********************************************************************
** Function: playAgain()
** Description: Placed at the end of the outer do-while loop. This
 * function prompts the user to enter the corresponding integer to 
 * either play again or exit the program.
** Parameters: n/a
** Pre-Conditions: The current battle has finished.
** Post-Conditions: The user gets to start a new battle from the 
 * creature select menu, or the program terminates.
*********************************************************************/
int playAgain(){
    cout << endl;
    cout << "Choose one of the following options:" << endl;
    cout << "1 - Play Again" << endl;
    cout << "2 - Exit the program" << endl;
    int choice;
    cin >> choice;
    while (!cin || (choice < 1) || (choice > 2)){
        cin.clear();
        cin.ignore(80,'\n');
        cout << "Please enter 1 to continue or 2 to quit: " << endl;
        cin >> choice;
    }
    cin.ignore(100,'\n');
    cin.clear();
    return choice; 
}