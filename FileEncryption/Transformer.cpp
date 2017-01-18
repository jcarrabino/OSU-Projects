/*********************************************************************
** Program Filename: Transformer.cpp
** Author: John Carrabino   
** Date: 7/17/2016
** Description: This is the Transformer class implementation file
 * Input: n/a
** Output: n/a
*********************************************************************/
#include "Transformer.h"
#include "Copy.h"

//abstract base class constructor, cannot be initialized
Transformer::Transformer(){
    
}

//overridden destructor
Transformer::~Transformer(){
    
}

//virtual function, defined in derived class implementation files
void Transformer::doFilter(std::ifstream &in,std::ofstream &out){
    
}

//virtual function, defined in derived class implementation files
char Transformer::transform(char ch){
    return 0;
}

//virtual function, defined in derived class implementation files
void Transformer::addChar(char ch){
    
}

//virtual function, defined in derived class implementation files
void Transformer::expandArray(){
    
}

//virtual function, defined in derived class implementation files
void Transformer::nameFiles(std::string in, std::string out){
    
}

/*********************************************************************
** Function: nameFiles()
** Description: This function takes the input and output file names
 * as specified by the user and uses them to initialize the iFile 
 * and oFile member objects.
** Pre-Conditions: the input file must already exist.
** Post-Conditions: the iFile & oFile data members are initialized.
*********************************************************************/
int Transformer::getKey(){
    return this->key;
}