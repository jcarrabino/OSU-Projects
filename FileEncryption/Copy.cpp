/*********************************************************************
** Program Filename: Copy.cpp
** Author: John Carrabino   
** Date: 7/17/2016
** Description: This is the Copy class implementation file
 * Input: n/a
** Output: n/a
*********************************************************************/
#include "Copy.h"


Copy::Copy(){
    arraySize = 50;
    arrayEnd = 0;
    
    char *charArray = new char[arraySize];
    
    for (int i=0; i<arraySize; i++){
        charArray[i] = '\0';
    }
    cArray = charArray;
}

Copy::~Copy(){
    delete [] cArray;
}

/*********************************************************************
** Function: doFilter()
** Description: This function takes in the name of an input and 
 * output file stream objects by reference. It then opens those
 * file streams, copies each character from the original 
 * file and writes it to a new file specified by the user.
** Pre-Conditions: the file stream objects must already exist.
 * the Copy object must also have initialized its 
 * oFile and iFile member variables.
** Post-Conditions: The translated text is written to the output file.
*********************************************************************/
void Copy::doFilter(std::ifstream &in, std::ofstream &out){
   
    in.open(iFile.c_str());
    
    char c;
    
    while(in >> std::noskipws >> c){
        this->addChar(c);
    }
    
    in.close();
    out.open(oFile.c_str());
    for(int i=0; i<arrayEnd; i++){
        out << transform(cArray[i]);
    }
    
    out.close();
}

/*********************************************************************
** Function: transform()
** Description: This just returns an unaltered version of each char
 * from the file being read.
** Pre-Conditions: a char is passed to the function.
** Post-Conditions: a char is returned from the function.
*********************************************************************/
char Copy::transform(char ch){
    return ch;
}

/*********************************************************************
** Function: addChar()
** Description: This function adds the character passed to it to a
 * dynamic array. If the last element of the array is reached then
 * the array will double in size and amend the character to the new
 * lengthened array.
** Pre-Conditions: A char is passed to it.
** Post-Conditions: The char passed to it is added to the cArray.
*********************************************************************/
void Copy::addChar(char x){
    if(arrayEnd == arraySize){
        expandArray();
        cArray[arrayEnd++] = x;
    } else
        cArray[arrayEnd++] = x;
}

/*********************************************************************
** Function: expandArray()
** Description: This function is called when addChar finds that the
 * arrayEnd is equal to the arraySize. It creates a dynamically 
 * expanding char array that doubles in size each time the function
 * is called.
** Pre-Conditions: arrayEnd == arraySize
** Post-Conditions: The array size is doubles and all of the elements
 * of the original array are added to the new array.
*********************************************************************/
void Copy::expandArray(){
    arraySize *= 2;
    char *newArray = new char[arraySize];
    for(int i=0; i<arrayEnd; i++){
        newArray[i] = cArray[i];
    }
    delete [] cArray;
    cArray = newArray;
}

/*********************************************************************
** Function: nameFiles()
** Description: This function takes the input and output file names
 * as specified by the user and uses them to initialize the iFile 
 * and oFile member objects.
** Pre-Conditions: the input file must already exist.
** Post-Conditions: the iFile & oFile data members are initialized.
*********************************************************************/
void Copy::nameFiles(std::string in, std::string out){
    this->iFile = in;
    this->oFile = out;
}