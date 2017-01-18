/*********************************************************************
** Program Filename: Chamber.cpp
** Author: John Carrabino
** Date: 8/7/2016
** Description:This is the chamber class implementation file
** Input: n/a
** Output: n/a
*********************************************************************/
#include "Chamber.hpp"

/* Constructor */
Chamber::Chamber(int steps){
    //sets step count to 0 for the start of the woods level
    stepCount = steps;
    head = back = NULL;
    fCount = rCount = lCount = 0;
}
Chamber::~Chamber(){
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

int Chamber::special(){
    if(this->foundAll == true){
        return 2;
    }
    else 
        return 0;
    
}