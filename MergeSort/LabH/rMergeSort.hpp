/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   rMergeSort.hpp
 * Author: John
 *
 * Created on August 12, 2016, 1:18 PM
 */

#ifndef RMERGESORT_HPP
#define RMERGESORT_HPP

#include <cstdlib>
#include <iostream>
#include <fstream>

class rMergeSort{
public:
    rMergeSort();
    ~rMergeSort();
    void rMerge(int l, int m, int r);
    void recMergeSort(int l, int r);
    void rAddInt(int x);
    void rExpandArray();
    void printArray(int size);
private:
    int rArraySize;
    int rArrayEnd;
    int *rArray;
    std::ifstream inFile;
    std::ofstream outFile;
    
};


#endif /* RMERGESORT_HPP */

