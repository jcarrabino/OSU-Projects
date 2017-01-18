/*********************************************************************
** Program Filename: ToUpper.cpp
** Author: John Carrabino   
** Date: 7/17/2016
** Description: This is the ToUpper class implementation file
 * Input: n/a
** Output: n/a
*********************************************************************/
#include "ToUpper.h"
#include "Copy.h"

ToUpper::ToUpper(){
    arraySize = 50;
    arrayEnd = 0;
    
    char *charArray = new char[arraySize];
    
    for (int i=0; i<arraySize; i++){
        charArray[i] = '\0';
    }
    cArray = charArray;
}

ToUpper::~ToUpper(){
    delete [] cArray;
}

/*********************************************************************
** Function: transform()
** Description: This function reads each char from the file and if 
 * it is a lower or uppercase letter, it returns the uppercase version
 * of that letter.
** Pre-Conditions: a char is passed to the function.
** Post-Conditions: the same char is returned from this function.
*********************************************************************/
char ToUpper::transform(char ch){
    int x = ch;
    if(x >= 0 && x < 65){
        return 0;
    }
    if(x > 90 && x < 97){
        return 0;
    }
    if (x >= 65 && x <= 90){
        return ch;
    }
    if(x >= 97 && x <= 122){
        x = (x - 32);
        ch = x;
        return ch;
    }
    
    
    else 
        return ch = 0;
}

/*********************************************************************
** Function: doFilter()
** Description: This function takes in the name of an input and 
 * output file stream objects by reference. It then opens those
 * file streams, transforms each character from the original 
 * file and writes it to a new file specified by the user.
** Pre-Conditions: the file stream objects must already exist.
 * the ToUpper object must also have initialized its 
 * oFile and iFile member variables.
** Post-Conditions: The translated text is written to the output file.
*********************************************************************/
void ToUpper::doFilter(std::ifstream &in, std::ofstream &out){
   
    in.open(iFile.c_str());
    
    char c;
    int count=0;
    
    while(in >> std::noskipws >> c){
        char x = this->transform(c);
        if( x != 0){
            this->addChar(x);
        }
    }
    
    in.close();
    out.open(oFile.c_str());
    for(int i=0; i<arrayEnd; i++){
        out << cArray[i];
        count++;
        if( count % 25 == 0 ){
            out << std::endl;
        }
    }
    
    out.close();
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
void ToUpper::addChar(char x){
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
void ToUpper::expandArray(){
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
void ToUpper::nameFiles(std::string in, std::string out){
    this->iFile = in;
    this->oFile = out;
}
