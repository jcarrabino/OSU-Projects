/*********************************************************************
** Program Filename: BinarySearch
** Author: John Carrabino   
** Date: 8/7/2016
** Description: This is the BinarySearch class specification file.
** Input: n/a
** Output: n/a
*********************************************************************/
#ifndef BINARYSEARCH_HPP
#define BINARYSEARCH_HPP

#include <iomanip>
#include <iostream>
#include <fstream>

class BinarySearch{
public:
    BinarySearch();
    ~BinarySearch();
    int search(int);
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


#endif /* BINARYSEARCH_HPP */

