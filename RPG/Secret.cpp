/*********************************************************************
** Program Filename: Secret.cpp
** Author: John Carrabino
** Date: 8/7/2016
** Description:This is the secret class implementation file
** Input: n/a
** Output: n/a
*********************************************************************/
#include "Secret.hpp"

/* Constructor */
Secret::Secret(int steps){
    // sets steps to the players step count at the end of the woods level
    stepCount = steps;
    head = back = NULL;
    fCount = rCount = lCount = 0;
}

/* Overridden Destructor */
Secret::~Secret(){
    Node *nodePtr;
    nodePtr = back;
    while (nodePtr != this->head){
        Node *garbage = nodePtr; //assigns garbage ptr to the current node
        nodePtr = nodePtr->prev; //moves up linked list 
        delete garbage; //deletes previous "garbage" node
    }
    delete nodePtr;
    head = back = NULL;
}

/*********************************************************************
** Function: special()
** Description: This function returns an int as a flag indicating
 * if the player is close to their goal. For the shadows level if the 
 * player has taken 5 steps forward it notifies them that their 
 * goal is one step ahead. If they take the step ahead it triggers
 * a transition to the end of the game.
** Parameters: n/a
** Pre-Conditions: An object must already exist.
** Post-Conditions: The appropriate int is returned 
*********************************************************************/
int Secret::special(){
    if(fCount == 5){
        return 1;
    }
    if(fCount == 6){
        return 2;
    }else
        return 0;
}