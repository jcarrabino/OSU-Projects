/*********************************************************************
** Program Filename: LinearSearch
** Author: John Carrabino   
** Date: 8/7/2016
** Description: This is the LinearSearch class implementation file.
** Input: n/a
** Output: n/a
*********************************************************************/
#include "LinearSearch.hpp"

/* Constructor */
LinearSearch::LinearSearch(){
    arraySize = 10;
    arrayEnd = 0;
    
    int *intArray = new int[arraySize];
    
    iArray = intArray;
}

/* Destructor */
LinearSearch::~LinearSearch(){
    delete [] iArray;
}

/*********************************************************************
** Function: search()
** Description: This function searches through the int array member 
 * for a user designated target. It returns the index position of the 
 * target if found, if not it will return the value -1 as a flag to
 * indicate that no target was found. I designed this algorithm
 * based off of the following pseudocode;
 * 
 * 1) Start with the first item in the list.
 * 2) Compare the current item to the target
 * 3) If the current value matches the target 
 *    then we declare victory and stop.
 * 4) If the current value is less than the 
 *    target then set the current item to be 
 *    the next item and repeat from 2. 
 * 
 * Source:
 * http://www.cs.toronto.edu/~reid/search/algs.html
 * 
** Parameters: This function takes the int the user wishes to search
 * for as its parameter.
** Pre-Conditions: An object must already exist.
** Post-Conditions: If the target is found it will return its index 
 * position, otherwise it will return -1.
*********************************************************************/
int LinearSearch::search(int target){
    int index=0,fail=-1;
    
    while(index < arrayEnd){
        if(iArray[index] == target){
                return index;
        }
        index++;
    }
    return fail;
}

/*********************************************************************
** Function: addInt()
** Description: Used a similar function to my addItem() function 
 * from the grocery list assignment. It adds the int passed to it 
 * to the end of the array then increments the arrayEnd index.
** Parameters: n/a
** Pre-Conditions: the array must exist
** Post-Conditions: the int passed to it must be at the end of the
 * array before returning to main.
*********************************************************************/
void LinearSearch::addInt(int x){
    if(arrayEnd == arraySize){
        expandArray();
        iArray[arrayEnd++] = x;
    } else
        iArray[arrayEnd++] = x;
}

/*********************************************************************
** Function: expandArray()
** Description: This function is called in the addInt() function. It
 * is called on once the arrayEnd is equal to the arraySize. The 
 * function then doubles the size of the array.
** Parameters: N/A
** Pre-Conditions: The size of the int array has to be equal to the
 * total size of the array. 
** Post-Conditions: Using dynamic memory allocation it creates a new 
 * array, fills it with all the values stored in the original array,
 * deletes the original array, then copies the new array into the 
 * original array.
*********************************************************************/
void LinearSearch::expandArray(){
    arraySize *= 2;
    int *newArray = new int[arraySize];
    for(int i=0; i<arrayEnd; i++){
        newArray[i] = iArray[i];
    }
    delete [] iArray;
    iArray = newArray;
}

/*********************************************************************
** Function: getEnd()
** Description: returns the last index position of the iArray data
 * memeber.
** Parameters: n/a
** Pre-Conditions: the array must exist
** Post-Conditions: returns index position of last int in the array
*********************************************************************/
int LinearSearch::getEnd(){
    return this->arrayEnd;
}

/*********************************************************************
** Function: printArray()
** Description: Prints the contents of the array to the screen for
 * testing purposes.
** Parameters: n/a
** Pre-Conditions: the array must exist
** Post-Conditions: none
*********************************************************************/
void LinearSearch::display(){
    for (int i=0; i<arrayEnd; i++){
        std::cout << iArray[i] << " ";
    }
}