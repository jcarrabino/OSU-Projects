/*********************************************************************
** Program Filename: Encryption.cpp
** Author: John Carrabino   
** Date: 7/17/2016
** Description: This is the Encryption class implementation file
 * Input: The constructor requires an int to be passed to it to
 * initialize the encryption key.
** Output: n/a
*********************************************************************/
#include "Encryption.h"

Encryption::Encryption(int k){
    this->key = k;
    if(key == 7){ //Key of 7 results in characters not being transformed...
        key++;
    }
    arraySize = 50;
    arrayEnd = 0;
    
    char *charArray = new char[arraySize];
    
    for (int i=0; i<arraySize; i++){
        charArray[i] = '\0';
    }
    cArray = charArray;
}


Encryption::~Encryption(){
    delete [] cArray;
}

/*********************************************************************
** Function: doFilter()
** Description: This function takes in the name of an input and 
 * output file stream objects by reference. It then opens those
 * file streams, transforms each character from the original 
 * file and writes it to a new file specified by the user.
** Pre-Conditions: the file stream objects must already exist.
 * the Encryption object must also have initialized its 
 * oFile and iFile member variables.
** Post-Conditions: The translated text is written to the output file.
*********************************************************************/
void Encryption::doFilter(std::ifstream& in,std::ofstream& out){
   
    in.open(iFile.c_str());
    
    char c;
    
    while(in >> std::noskipws >> c){
        this->transform(c);
        this->addChar(c);
    }
    
    in.close();
    out.open(oFile.c_str());
    for(int i=0; i<arrayEnd; i++){
        out << cArray[i];
    }
    
    out.close();
    
}

/*********************************************************************
** Function: transform()
** Description: This function reads each char from the file and if
 * the char is within the range of printable characters then it 
 * will use the ASCII value for each char, add the encryption key 
 * to it and perform a modulus for the chars in the printable 
 * range to return an encrypted char.
** Pre-Conditions: a char is passed to the function.
** Post-Conditions: the same char is returned from this function.
*********************************************************************/
char Encryption::transform(char ch){
    int x = ch;
    if(x == 10){
        return ch;
    }
    if(x==9){
        return ch;
    }
    if(x ==0){
        return ch;
    }
    if(x == 32){
        return ch;
    }
    

    if (x >= 97 && x <= 122){
        x+=key;
        x = (x%26) + 97;
        ch = x;
        return ch;
    }
        
    if(x >= 65 && x <= 90){
        x += key;
        x = (x%26) + 65;
        ch = x;
        return ch;
    }
    
    if( x >= 48 && x <= 57){
        x += key;
        x = (x%10) + 48;
        ch = x;
        return ch;
    }
    
    if(x >= 33 && x <= 47){
        x += key;
        x = (x%15) + 32;
        ch = x;
        return ch;
    }
    
    if(x >= 58 && x <= 64){
        x += key;
        x = (x%7) + 58;
        ch = x;
        return ch;
    }
    
    if(x >= 91 && x <= 96){
        x += key; 
        x = (x%6) + 91;
        ch = x;
        return ch;
    }
    
    if(x >= 123 && x <= 126){
        x += key;
        x = (x%4) + 123;
        ch = x; 
        return ch;
    }
     
    else
        return ch = 0;
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
void Encryption::addChar(char x){
    if(arrayEnd == arraySize){
        expandArray();
        cArray[arrayEnd++] = transform(x);
    } else
        cArray[arrayEnd++] = transform(x);
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
void Encryption::expandArray(){
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
void Encryption::nameFiles(std::string in, std::string out){
    this->iFile = in;
    this->oFile = out;
}

/*********************************************************************
** Function: getKey()
** Description: This function returns the int value of the encryption
 * key data member.
** Pre-Conditions: The encryption object must already exist.
** Post-Conditions: int value is returned.
*********************************************************************/
int Encryption::getKey(){
    return this->key;
}