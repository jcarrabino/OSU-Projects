/*********************************************************************
** Program Filename: LabB Dice
** Author: John Carrabino   
** Date: 7/10/2016
** Description: This is the Reverse class specification file. It contains 
 * all of the function prototypes for the Reverse class.
 * Input: n/a
** Output: n/a
*********************************************************************/
#ifndef REVERSE_H
#define REVERSE_H
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

class Reverse{
public: 
    Reverse();
    ~Reverse();
    int getSize();
    int getEnd();
    void expandArray();
    void reverseArray(int,int);
    void printArray();
    void addChar(char);
    void toOutput(std::string);
    
private:
    int arraySize;
    int arrayEnd;
    char *arrayItem; // pointer to char in the array initialized by Reverse()
};

#endif /* REVERSE_H */

