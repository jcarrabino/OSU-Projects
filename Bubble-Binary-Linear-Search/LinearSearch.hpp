/*********************************************************************
** Program Filename: LinearSearch
** Author: John Carrabino   
** Date: 8/7/2016
** Description: This is the LinearSearch class specification file.
** Input: n/a
** Output: n/a
*********************************************************************/
#ifndef LINEARSEARCH_HPP
#define LINEARSEARCH_HPP

#include <iomanip>
#include <iostream>
#include <fstream>

class LinearSearch{
public:
    LinearSearch();
    LinearSearch(std::string);
    ~LinearSearch();
    int search(int);
    void addInt(int);
    void expandArray();
    int getEnd();
    void display();
private:
    int arraySize;
    int arrayEnd;
    int *iArray;
    std::ifstream inFile;
    std::string iFile;
};

#endif /* LINEARSEARCH_HPP */

