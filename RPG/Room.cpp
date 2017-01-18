/*********************************************************************
** Program Filename: Room.cpp
** Author: John Carrabino
** Date: 8/7/2016
** Description:This is the room class implementation file
** Input: n/a
** Output: n/a
*********************************************************************/
#include "Room.hpp"

/* Constructor */
Room::Room(){
    main = new Node;
    one = new Node;
    two = new Node;
    three = new Node;
    four = new Node;
    
    main->next = one;
    main->prev = three;
    main->left = two;
    main->right = four;
    
    one->next = NULL;
    one->prev = main;
    one->left = two;
    one->right = four;
    
    two->next = NULL;
    two->prev = main;
    two->left = three;
    two->right = one;
    
    three->next = NULL;
    three->prev = main;
    three->right = two;
    three->left = four;
    
    four->next = NULL;
    four->prev = main;
    four->left = one;
    four->right = three;
    
    head = back = main;
    fCount = rCount = lCount = 0;
    stepCount = 1;
}

/* Overridden Destructor */
Room::~Room(){
    delete main;
    delete one;
    delete two;
    delete three;
    delete four;
    head = back = NULL;
}

/*********************************************************************
** Function: special()
** Description: This function returns an int as a flag indicating
 * if the player is close to their goal. For the town level if the 
 * player has taken 4 steps forward it notifies them that their 
 * goal is one step ahead. If they take the step ahead it triggers
 * a transition to the next level.
** Parameters: n/a
** Pre-Conditions: An object must already exist.
** Post-Conditions: The appropriate int is returned 
*********************************************************************/
int Room::special(){
    if(stepCount == 4){
        return 1;
    }
    if(stepCount == 5){
        return 2;
    }
    
    return 0;
}