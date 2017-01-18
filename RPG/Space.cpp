/*********************************************************************
** Program Filename: Space.cpp
** Author: John Carrabino
** Date: 8/7/2016
** Description:This is the space class implementation file
** Input: n/a
** Output: This program will output a message only if the player 
 * attempts to make more than two turns in any direction. This is
 * to prevent the player from looping back to the main path.
*********************************************************************/
#include "Space.hpp"
#include "Chamber.hpp"

/* Constructor */
Space::Space(){
    head = back = NULL;
    stepCount = fCount = lCount = rCount = 0;
    foundAll = false;
}

/* Virtual Destructor */
Space::~Space(){
    
}

/*********************************************************************
** Function: forward()
** Description: This function adds a 'Space' to the end of the linked
 * map structure for the player to explore.
** Parameters: n/a
** Pre-Conditions: An object must already exist.
** Post-Conditions: A new node is created and added to the front
 * of the structure.
*********************************************************************/
int Space::forward(){
    Node *temp;
    if (head == NULL){
        temp = new Node;
        head = back = temp;
        stepCount++;
        fCount++;
        return 1;
    }
    else if(back == head){
        temp = new Node;
        back = temp;
        back->prev = head;
        stepCount++;
        fCount++;
        return 1;
    }
    else{
        temp  = new Node;
        back->next = temp;
        temp = back;
        back = back->next;
        back->prev = temp;
        stepCount++;
        fCount++;
        return 1;
    }
    return 1;
}

/*********************************************************************
** Function: backward()
** Description: This function puts the player in the previous 'Space'
 * they were in. It then deletes the space in front of it.
** Parameters: n/a
** Pre-Conditions: An object must already exist.
** Post-Conditions: The old node at the back of the structure is 
 * properly removed.
*********************************************************************/
int Space::backward(){
    Node *temp;
    if(back == NULL || back == head){
        return 0;
    }
    if(back->prev == head){
        temp = back; 
        back = head;
        stepCount++;
        fCount--;
        lCount--;
        rCount--;
        if(fCount <= 0){
            fCount = 0;
        }
        if(lCount <= 0){
            lCount = 0;
        }
        if(rCount <= 0){
            rCount = 0;
        }
        delete temp;
        return 1;
    }
    else{
        temp = back;
        back = back->prev;
        stepCount++;
        
        fCount--;
        lCount--;
        rCount--;
        if(fCount <= 0){
            fCount = 0;
        }
        if(lCount <= 0){
            lCount = 0;
        }
        if(rCount <= 0){
            rCount = 0;
        }
        delete temp;
        return 1;
    }
}

/*********************************************************************
** Function: right()
** Description: This function adds a 'Space' to the right of the linked
 * map structure for the player to explore.
** Parameters: n/a
** Pre-Conditions: An object must already exist.
** Post-Conditions: A new node is created and added to the front
 * of the structure.
*********************************************************************/
void Space::right(){
    Node *temp;
    if(rCount >= 1 && fCount <= 1){
        cout << "It appears to be a dead end...";
        return;
    }
    if(rCount >= 2){
        cout << "It appears to be a dead end...";
        return;
    }
    if(back == NULL){
        temp = new Node;
        back = head = temp;
        stepCount++;
        rCount++;
        return;
    }
    if(back == head){
        temp  = new Node;
        back->right = temp;
        temp = back;
        back = back->right;
        back->prev = head;
        stepCount++;
        rCount++;
        return;
    }
    else{
        temp = new Node;
        back->right = temp;
        temp = back;
        back = back->right;
        back->prev = temp;
        stepCount++;
        rCount++;
        return;
    }
}

/*********************************************************************
** Function: left()
** Description: This function adds a 'Space' to the left of the linked
 * map structure for the player to explore.
** Parameters: n/a
** Pre-Conditions: An object must already exist.
** Post-Conditions: A new node is created and added to the front
 * of the structure.
*********************************************************************/
void Space::left(){
    Node *temp;
    if(lCount >= 1 && fCount <= 1){
        cout << "It appears to be a dead end...";
        return;
    }
    if(lCount >= 2){
        cout << "It appears to be a dead end...";
        return;
    }
    if(back == NULL){
        temp = new Node;
        back = head = temp;
        stepCount++;
        lCount++;
        return;
    }
    if(back == head){
        temp = new Node;
        back->left = temp;
        temp = back;
        back = back->left;
        back->prev = temp;
        stepCount++;
        lCount++;
        return;
    }
    else{
        temp  = new Node;
        back->left = temp;
        temp = back;
        back = back->left;
        back->prev = temp;
        stepCount++;
        lCount++;
        return;
    }
}

/*********************************************************************
** Function: getSteps()
** Description: This function returns the players total steps as an 
 * int value.
** Parameters: n/a
** Pre-Conditions: An object must already exist.
** Post-Conditions: The appropriate int is returned 
*********************************************************************/
int Space::getSteps(){
    return this->stepCount;
}

/*********************************************************************
** Function: setSteps()
** Description: This function allows the Player class to reset the 
 * total step count when transitioning between the town and woods level.
** Parameters: n/a
** Pre-Conditions: An object must already exist.
** Post-Conditions: The stepCount variable is set to whatever int is
 * passed to it
*********************************************************************/
void Space::setSteps(int count){
    stepCount = count;
    return;
}

// test driver function to get left, right, and forward step counts.
//void Space::getCount(){
//    cout << "fCount: " << this->fCount << endl;
//    cout << "lCount: " << this->lCount << endl;
//    cout << "rCount: " << this->rCount << endl;
//    return;
//}

/* Virtual special function which is defined in each derived class */
int Space::special(){
    return 0;
}

/*********************************************************************
** Function: complete()
** Description: This function accepts a bool value from the player
 * class that sets the foundAll data member to true once all items
 * are found.
** Parameters: This function takes a bool variable as a parameter
** Pre-Conditions: An object must already exist.
** Post-Conditions: The appropriate int is returned 
*********************************************************************/
bool Space::complete(bool found){
    foundAll = found;
    return foundAll;
}

/*********************************************************************
** Function: itemFound()
** Description: This function is called from the Player class and 
 * sets the itemFound variable to true after an item is found in 
 * the players current space.
** Parameters: n/a
** Pre-Conditions: An object must already exist.
** Post-Conditions: the itemFound variable in the back node is set to 
 * true.
*********************************************************************/
bool Space::itemFound(){
    this->back->itemFound = true;
    return true;
}


void Space::mLeft(){
    this->back = back->left;
    stepCount++;
    return;
}
void Space::mRight(){
    this->back = back->right;
    stepCount++;
    return;
}
int Space::mForward(){
    if(back->next == NULL){
        return 0;
    }
    else{
        this->back = back->next;
        stepCount++;
        return 1;
    }
}
int Space::mBack(){
    this->back = back->prev;
    stepCount++;
    return 1;
}