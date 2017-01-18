/*********************************************************************
** Program Filename: BubbleSort
** Author: John Carrabino   
** Date: 8/7/2016
** Description: This is the BubbleSort class implementation file.
** Input: n/a
** Output: n/a
*********************************************************************/
#include "BubbleSort.hpp"

/* Constructor */
BubbleSort::BubbleSort(){
    arraySize = 10;
    arrayEnd = 0;
    
    int *intArray = new int[arraySize];
    
    iArray = intArray;
}

/* Destructor */
BubbleSort::~BubbleSort(){
    delete [] iArray;
}

/*********************************************************************
** Function: sort()
** Description: This function sorts through the int array member and
 * sorts its contents in ascending order. I designed this algorithm
 * based off of the following pseudocode;
 * 
 * 1) Compare each pair of adjacent elements from the
 * beginning of an array and, if they are in reversed 
 * order, swap them.
 * 2) If at least one swap has been done, repeat step 1.
 * 
 * Source:
 *  http://www.algolist.net/Algorithms/Sorting/Bubble_sort
 * 
** Parameters: This function takes the name of the output file 
 * the user wishes to save the sorted file contents to as a string.
** Pre-Conditions: An object must already exist.
** Post-Conditions: The sorted contents are save to the output file 
 * specified by the user.
*********************************************************************/
void BubbleSort::sort(std::string copy){
    bool switched;
    int x;
    do{
        switched = false;
        for(int i=0; i < (arrayEnd-1); i++){
            
            if(iArray[i] > iArray[i+1]){
                    x = iArray[i];
                    iArray[i] = iArray[i+1];
                    iArray[i+1] = x;
                    switched = true;
            }
        }
    }while(switched);
    
    outFile.open(copy.c_str());
    for(int i=0; i<arrayEnd; i++){
        outFile << iArray[i] << " ";
    }
    outFile.close();
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
void BubbleSort::addInt(int x){
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
void BubbleSort::expandArray(){
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
int BubbleSort::getEnd(){
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
void BubbleSort::display(){
    for (int i=0; i<arrayEnd; i++){
        std::cout << iArray[i] << " ";
    }
}
