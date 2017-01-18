/*********************************************************************
** Program Filename: BubbleSort
** Author: John Carrabino   
** Date: 8/7/2016
** Description: This is the BubbleSort class specification file.
** Input: n/a
** Output: n/a
*********************************************************************/
#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

#include <iomanip>
#include <iostream>
#include <fstream>

class BubbleSort{
public:
    BubbleSort();
    ~BubbleSort();
    void sort(std::string);
    void addInt(int);
    void expandArray();
    int getEnd();
    void display();
    
private:
    int arraySize;
    int arrayEnd;
    int *iArray;
    std::ifstream inFile;
    std::ofstream outFile;
};

#endif /* BUBBLESORT_HPP */

