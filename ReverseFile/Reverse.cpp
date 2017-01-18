/*********************************************************************
** Program Filename: Reverse.cpp
** Author: John Carrabino   
** Date: 7/10/2016
** Description: This is the Reverse class implementation file. It
 * contains all of the function definitions for the Reverse class.
 * Input: n/a
** Output: n/a
*********************************************************************/
#include "Reverse.h"

//Constructor that initializes a char array with 50 elements
Reverse::Reverse(){
    arraySize = 50;
    arrayEnd = 0;
    
    char *charArray = new char[arraySize];
    
    for (int i=0; i<arraySize; i++){
        charArray[i] = '\0';
    }
    arrayItem = charArray;
}

//Destructor that frees memory from the heap
Reverse::~Reverse(){
    delete [] arrayItem;
}

//returns array size
int Reverse::getSize(){
    return this->arraySize;
}

//returns end index of the array
int Reverse::getEnd(){
    return this->arrayEnd;
}

/*********************************************************************
** Function: expandArray()
** Description: This function is called in the addChar() function. It
 * is called on once the arrayEnd is equal to the arraySize. The 
 * function then doubles the size of the array.
** Parameters: N/A
** Pre-Conditions: The size of the char array has to be equal to the
 * total size of the array. 
** Post-Conditions: Using dynamic memory allocation it creates a new 
 * array, fills it with all the values stored in the original array,
 * deletes the original array, then copies the new array into the 
 * original array.
*********************************************************************/
void Reverse::expandArray(){
    arraySize *= 2;
    char *newArray = new char[arraySize];
    for(int i=0; i<arrayEnd; i++){
        newArray[i] = arrayItem[i];
    }
    delete [] arrayItem;
    arrayItem = newArray;
 
}

/*********************************************************************
** Function: reverseArray()
** Description: This is a recursive function that continues to call 
 * upon itself until the contents of the original array are in the
 * reverse order. For this function I dereferenced the array and 
 * used that and the index of the array to sort through its contents, 
 * reversing the first and last elements of the array, and decrementing/
 * incrementing the indices appropriately before calling the function
 * in itself to repeat the process.
** Parameters: This function needs the first and last index of the 
 * array to be passed to it.
** Pre-Conditions: The char array must already exist
** Post-Conditions: This function must reverse all of the contents
 * of the array before the base case is met.
*********************************************************************/
void Reverse::reverseArray(int firstIndex,int lastIndex){
    int i;
    if (firstIndex >= lastIndex)
            return;

    i = *(arrayItem+firstIndex);
    *(arrayItem+firstIndex)=*(arrayItem+lastIndex);
    *(arrayItem+lastIndex)= i;
    reverseArray(++firstIndex,--lastIndex);
}

/*********************************************************************
** Function: printArray()
** Description: Prints the contents of the array to the screen.
** Parameters: n/a
** Pre-Conditions: the array must exist
** Post-Conditions: none
*********************************************************************/
void Reverse::printArray(){
    for (int i=0; i<arraySize; i++){
        std::cout << arrayItem[i];
    }
}

/*********************************************************************
** Function: addChar()
** Description: Used a similar function to my addItem() function 
 * from the grocery list assignment. It adds the char passed to it 
 * to the end of the array then increments the arrayEnd index.
** Parameters: n/a
** Pre-Conditions: the array must exist
** Post-Conditions: the char passed to it must be at the end of the
 * array before returning to main.
*********************************************************************/
void Reverse::addChar(char x){
    if(arrayEnd == arraySize){
        expandArray();
        arrayItem[arrayEnd++] = x;
    } else
        arrayItem[arrayEnd++] = x;
}

/*********************************************************************
** Function: toOutput()
** Description: This function opens or creates the output file named
 * by the user then writes the contents of the character array to 
 * that file.
** Parameters: n/a
** Pre-Conditions: The file name must not be an empty string
** Post-Conditions: The output file must have the contents of the
 * char array written to it.
*********************************************************************/
void Reverse::toOutput(std::string fileName){
    std::ofstream outputFile;
    outputFile.open(fileName.c_str());
    
    for(int i=0; i< arrayEnd; i++){
        outputFile << arrayItem[i];
    }
    outputFile.close();
}