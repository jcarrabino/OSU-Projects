/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   iMergeSort.hpp
 * Author: John
 *
 * Created on August 12, 2016, 1:18 PM
 */

#ifndef IMERGESORT_HPP
#define IMERGESORT_HPP

#include <cstdlib>
#include <iostream>
#include <fstream>

class iMergeSort{
public:
    iMergeSort();
    ~iMergeSort();
    void iMerge(int l, int m, int r);
    void itMergeSort();
    int min(int x, int y);
    void iAddInt(int x);
    void iExpandArray();
    void printArray(int size);
private:
    int iArraySize;
    int iArrayEnd;
    int *iArray;
    std::ifstream inFile;
    std::ofstream outFile;
    
};

#endif /* IMERGESORT_HPP */

