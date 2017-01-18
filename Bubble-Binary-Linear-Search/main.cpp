/*********************************************************************
** Program Filename: SearchSort
** Author: John Carrabino   
** Date: 8/7/2016
** Description: This is the main file for Lab G. It contains the 
 * test driver functions for our linear search, bubble sort, and 
 * binary search algorithms.
** Input: User is prompted to choose which type of operation they
 * want to perform. They are then prompted for the appropriate input
 * and/or output file names they wish to search or sort trough.
** Output: This program will notify the user if their search target 
 * was found by printing a message to the console, any sorted files
 * are saved to an output file specified by the user.
*********************************************************************/
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "LinearSearch.hpp"
#include "BubbleSort.hpp"
#include "BinarySearch.hpp"

using std::cout;
using std::cin;
using std::endl;

//Initializes/Randomizes test files 
void initialize(std::ofstream&, std::ofstream&, std::string&, std::string&);
bool itExists(std::string); //Used in try catch block for file errors
int didFind(int, LinearSearch*); //Used in try catch block for invalid searches
int didFind(int, BinarySearch*); //Used in try catch block for invalid searches
int displayMenu(); //display the menu

int main(int argc, char** argv) {
    srand(time(NULL));
    std::ifstream in;
    std::ofstream out, outCopy;
    std::string oFile, oFileName, oFileCopy, iFile, iFileName;
    std::string origName, origCopy;
    bool i;
    int choice, num, target, position;
    LinearSearch *lSearch;
    BubbleSort *bSort;
    BinarySearch *bSearch;
        
    do{//do-while loop to repeat through test functions until user opts to quit
        choice = displayMenu();
        switch (choice){
            case 1: //Lets user name file to conduct Linear Search for target
                lSearch = new LinearSearch;
                cout << endl << "What would you like to name the file \n"
                        "to search through?";
                cout << endl << endl;
                cout << "File Name: ";
                do{
                    i = true;
                    cin.sync();
                    getline(cin,iFileName);
                    try{
                        itExists(iFileName);
                    }
                    catch (bool exists){
                        cout << endl;
                        cout << "That file cannot be found \n";
                        cout << "Please enter the name of an \n"
                                "existing file \n";
                        cout << "File Name: ";
                        i = exists;
                    }
                }while(!i);
                iFile = iFileName;
                in.open(iFile.c_str());
                
                while (in >> num){
                    lSearch->addInt(num);
                }
                in.close();
                cout << endl 
                     << "Now enter the target number you wish \n"
                        "to search for?" << endl << "Target: ";
                cin.clear();
                cin.sync();
                cin >> target;
                while(!cin || target < 0 || target > 9){
                    cout << endl << "Please enter a number between"
                            "0 and 9" << endl;
                    cin.clear();
                    cin.sync(); 
                    cin >> target;
                }
                try{
                    position = didFind(target, lSearch);
                }
                catch (int found){
                    cout << endl << "The file " << iFile << " does not contain"
                            " the value " << target << endl;
                    delete lSearch;
                    break;
                }           
                position = lSearch->search(target); 
                cout << endl;
                cout << "The value " << target << " is located at "
                "index position: " << position << endl;
                delete lSearch;
                break;                
                
            case 2: //Let's user input a file to sort in ascending order
                bSort = new BubbleSort;
                cout << endl << "What is the name of the file you wish \n"
                        "to be sorted in ascending order?";
                cout << endl << endl;
                cout << "File Name: ";
                do{
                    i = true;
                    cin.sync();
                    getline(cin,iFileName);
                    try{
                        itExists(iFileName);
                    }
                    catch (bool exists){
                        cout << endl;
                        cout << "That file cannot be found \n";
                        cout << "Please enter the name of an "
                                "existing file \n";
                        cout << "File Name: ";
                        i = exists;
                    }
                }while(!i);
                iFile = iFileName;
                in.open(iFile.c_str());
                
                while (in >> num){
                    bSort->addInt(num);
                }
                in.close();
                cout << endl;
                cout << "What would you like to name the file that \n" 
                     << "contains the sorted contents of your \n"
                        "original file?";
                cout << endl << endl;
                cout << "File Name: ";
                cin.clear();
                cin.sync();
                getline(cin,oFileName);
                cin.sync();
                while (!cin || oFileName == ""){
                    cout << "Please enter a valid file name: " 
                         << endl;
                    cin.clear();
                    cin.sync();
                    cin >> oFileName;
                }
                oFile = oFileName;
                bSort->sort(oFile);
                cout << endl;
                cout << endl << "Your file has been sorted and saved \n"
                        "under the name " << oFile << endl;
                delete bSort;
                break;      
                
            case 3: //lets user choose file they to conduct binary search on
                bSearch = new BinarySearch;
                cout << endl << "What would you like to name the file to \n"
                        "search through?";
                cout << endl;
                cout << "File Name: ";
                do{
                    i = true;
                    cin.sync();
                    getline(cin,iFileName);
                    try{
                        itExists(iFileName);
                    }
                    catch (bool exists){
                        cout << endl;
                        cout << "That file cannot be found \n";
                        cout << "Please enter the name of an "
                                "existing file \n";
                        cout << "File Name: ";
                        i = exists;
                    }
                }while(!i);
                iFile = iFileName;
                in.open(iFile.c_str());
                while (in >> num){
                    bSearch->addInt(num);
                }
                in.close();
                cout << endl;
                cout << "Binary Searches require a pre-sorted file. \n";
                cout << "What would you like to name the file that \n" 
                     << "contains the sorted contents of " << iFile << "?";
                cout << endl << endl;
                cout << "File Name: ";
                cin.clear();
                cin.sync();
                getline(cin,oFileName);
                cin.sync();
                while (!cin || oFileName == ""){
                    cout << "Please enter a valid file name: " 
                         << endl;
                    cin.clear();
                    cin.sync();
                    cin >> oFileName;
                }
                oFile = oFileName;
                bSearch->sort(oFile);
                cout << endl 
                     << "Now enter the target number you wish to \n"
                        "search for" << endl << "Target: ";
                cin.clear();
                cin.sync();
                cin >> target;
                while(!cin || target < 0 || target > 9){
                    cout << endl << "Please enter a number between"
                            "0 and 9" << endl;
                    cin.clear();
                    cin.sync(); 
                    cin >> target;
                }
                try{
                    position = didFind(target, bSearch);
                }
                catch (int found){
                    cout << endl << "The file " << iFile << " does not contain"
                            " the value " << target << endl;
                    delete bSearch;
                    break;
                }
                                
                position = bSearch->search(target); 
                cout << endl << "The value " << target << " is located at "
                "index position: " << position << endl;
                delete bSearch;
                break;
                
                
            case 4: //randomizes test file values for testing purposes
                oFileName = "test.txt";
                oFileCopy = "testCopy.txt";
                initialize(out, outCopy, oFileName, oFileCopy);
                cout << endl;
                cout << "The test files test.txt & testCopy.txt have "
                        "been randomized" << endl;
                break;
            case 5:
                cout << endl;
                break;
            default:
                break;
        }
    }while(choice != 5);
    
    cout << "Goodbye!";

    return 0;
}

/*********************************************************************
** Function: displayMenu
** Description: This function prompts the user with a menu containing
 * four different choices. There is an input validation loop after 
 * the user enters their choice to verify that a valid choice was made.
** Parameters: N/A
** Pre-Conditions: The function was designed to have the return value
 * passed into a switch statement. 
** Post-Conditions: The function must return an integer from 1 to 2.
*********************************************************************/
int displayMenu(){
     cout << endl;
        cout << "Choose one of the following options:" << endl;
        cout << "1 - Test Linear Search" << endl;
        cout << "2 - Test Bubble Sort" << endl;
        cout << "3 - Test Binary Search" << endl;
        cout << "4 - Randomize Contents of" << endl;
        cout << "    test.txt & testCopy.txt" << endl;
        cout << "5 - Exit the Program" << endl;
        int choice;
        cin >> choice;
        while (!cin || (choice < 0) || (choice > 5)){
            cin.clear();
            cin.ignore(80,'\n');
            cout << endl;
            cout << "Please enter a selection from 1 to 5" << endl;
            cin >> choice;
        }
        cin.ignore(100,'\n');
        cin.clear();
        return choice;
}


/*********************************************************************
** Function: itExists()
** Description: This function takes the input file name provided
 * by the user and attempts to open it to make sure that it exists.
** Parameters: string of the file name
** Pre-Conditions: the user must input a non-empty string
** Post-Conditions: the function will return false if the program 
 * is unable to find/open the file name that the user provided.
*********************************************************************/
bool itExists(std::string file){
    bool exists;
    std::ifstream inputFile;
    inputFile.open(file.c_str());
    
    if(!(inputFile)){
        inputFile.close();
        throw false;
    }    
    else{
        exists = true;
        inputFile.close();
        return exists;
    }
}

/*********************************************************************
** Function: itExists()
** Description: This function takes the target number you wish to 
 * find along with a pointer to a LinearSearch object as its 
 * parameters. It will return a flag of -1 to indicate that the
 * target number was not found or the index position the target
 * was found at.
** Pre-Conditions: the LinearSearch object must already exist and
 * its array data member must already be initialized.
** Post-Conditions: the function will return -1 if the target
 * cannot be found within the LinearSearch object's array.
*********************************************************************/
int didFind(int n, LinearSearch *refObj){
    int notFound = -1;
    int found;
    if(refObj->search(n) < 0 || refObj->search(n) > refObj->getEnd()){
        throw notFound;
    }
    else{
        found = refObj->search(n);
        return found;
    }
}

/*********************************************************************
** Function: itExists()
** Description: This function takes the target number you wish to 
 * find along with a pointer to a BinarySearch object as its 
 * parameters. It will return a flag of -1 to indicate that the
 * target number was not found or the index position the target
 * was found at.
** Pre-Conditions: the BinarySearch object must already exist and
 * its array data member must already be initialized.
** Post-Conditions: the function will return -1 if the target
 * cannot be found within the BinarySearch object's array.
*********************************************************************/
int didFind(int n, BinarySearch *refObj){
    int notFound = -1;
    int found;
    if(refObj->search(n) < 0 || refObj->search(n) > refObj->getEnd()){
        throw notFound;
    }
    else{
        found = refObj->search(n);
        return found;
    }
}

/*********************************************************************
** Function: initialize()
** Description: This function creates two output stream objects
 * and fills one with 20 random integers from 1-9. It then copies
 * the first output files contents into the second with a zero
 * amended to the end of the file.
** Pre-Conditions: the user must input a non-empty strings.
** Post-Conditions: It creates two text files and saves them in
 * the directory you're working in.
*********************************************************************/
void initialize(std::ofstream &out1, std::ofstream &out2, 
                std::string &orig, std::string &copy){
    out1.open(orig.c_str());
    out2.open(copy.c_str());
    
    int x;
    for(int i=0; i<20; i++){
        x = rand() % 9 + 1;
        out1 << x << endl;
        out2 << x << endl;
    }
    out2 << 0 << endl;
    
    out1.close();
    out2.close();
    
}