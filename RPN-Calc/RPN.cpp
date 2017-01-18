/*********************************************************************
** Program Filename: RPN.cpp
** Author: John Carrabino
** Date: 8/12/2016
** Description: This is the RPN class implementation file 
** Input: n/a
** Output: n/a
*********************************************************************/
#include "RPN.hpp"

RPN::RPN() {
    numElements = 0;
    error = false;
}

RPN::~RPN() {
    StackNode *nodePtr = top;
    while (nodePtr) {
        StackNode *garbage = nodePtr; //assigns garbage ptr to the current node
        nodePtr = nodePtr->next; //moves up linked list 
        delete garbage; //deletes previous "garbage" node
    }
    delete nodePtr;
    top = NULL;
}

void RPN::add() {
    int x, y;
    x = this->peek();
    this->pop();
    y = this->peek();
    this->pop();
    this->push(y + x);
    return;
}

void RPN::subtract() {
    int x, y;
    x = this->peek();
    this->pop();
    y = this->peek();
    this->pop();
    this->push(y - x);
    return;

}

void RPN::multiply() {
    int x, y;
    x = this->peek();
    this->pop();
    y = this->peek();
    this->pop();
    this->push(y * x);
    return;

}

void RPN::divide() {
    int x, y;
    x = this->peek();
    if(x == 0){
        std::cout << std::endl << std::endl;
        std::cout << "ERROR: Cannot divide by 0";
        error = true;
        return;
    }
    this->pop();
    y = this->peek();
    this->pop();
    this->push(y / x);
    return;

}

bool RPN::isBinary() {
    if(this->getNum() >= 2)
        return true;
    else 
        return false;
}

int RPN::getNum() {
    StackNode *temp = top;
    numElements = 0;
    while (temp) {
        numElements++;
        temp = temp->next;
    }
    return numElements;
}

void RPN::display() {
    StackNode *temp = top;
    while(temp){
        std::cout << temp->value << " ";
        temp = temp->next;
    }
    return;
}

bool RPN::wasError(){
    if (error)
        return true;
    else
        return false;
}

void RPN::setError(){
    error = true;
    return;
}