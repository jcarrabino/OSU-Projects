/*********************************************************************
** Program Filename: Transformer.h
** Author: John Carrabino   
** Date: 7/17/2016
** Description: This is the Transformer class specification file
 * Input: n/a
** Output: n/a
*********************************************************************/
#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <iomanip>
#include <iostream>
#include <fstream>

class Transformer{
public:
    //completely abstract base class
    Transformer();
    virtual ~Transformer()=0;
    virtual void doFilter(std::ifstream&,std::ofstream&);
    virtual char transform(char) = 0;
    virtual void addChar(char) = 0;
    virtual void expandArray();
    virtual void nameFiles(std::string, std::string);
    virtual int getKey();
    
protected:
    int arraySize;
    int arrayEnd;
    int key;
    char *cArray;
    std::ifstream inFile;
    std::ofstream outFile;
    std::string oFile;
    std::string iFile;
};

#endif /* TRANSFORMER_H */

