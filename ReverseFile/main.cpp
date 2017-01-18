/*********************************************************************
** Program Filename: Reverse
** Author: John Carrabino   
** Date: 7/10/2016
** Description: This is the main file for Lab C. For this lab we 
 * were asked to write a program that reads the contents of the 
 * file, store those contents in an array that uses dynamic memory
 * allocation, and output the contents of the reversed file into
 * a new file.
 * Input: This program prompts the user for the name of a pre-existing 
 * input file and to create a name for an output file. 
** Output: Once the user passes two valid filenames to the program
 * it will then reverse the contents of the first file and output 
 * the reversed contents of the first file onto the second. 
 * The program also outputs the contents of the file to 
 * the user's screen.
*********************************************************************/
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Reverse.h"

using std::cout;
using std::cin;
using std::endl;

int displayMenu();
bool itExists(std::string);


int main(int argc, char** argv) {
    // define all variables used outside of the do-while loop
    // in order to avoid cross-initialization.
    std::string iFileName, oFileName;
    Reverse myFile;
    char element;
    std::ifstream inputFile;
    int last,choice;
    
    choice = displayMenu();
    //loops through the menu options until user prompts to quit
    do{
        
        switch(choice)
        {
            case 1:
                cin.clear();
                cout << "What is the name of the file you"
                        " would like to reverse?";
                cout << endl;
                getline(cin,iFileName);
             //test to make sure file exists and that they entered a valid name
                while (!(itExists(iFileName)) || iFileName == ""){
                    cout << "Please enter a valid file name: " << endl;
                    cin.clear();
                    cin >> iFileName;
                }

                cout << "What is the name of the file you"
                        " would like to output to?";
                cout << endl;
                cin.clear();
                getline(cin,oFileName);
                while (!cin || oFileName == ""){
                    cout << "Please enter a valid file name: " << endl;
                    cin.clear();
                    cin >> oFileName;
                }

                //open input file
                inputFile.open(iFileName.c_str());
                //read through each element of file, skipping white space
                while (inputFile >> std::noskipws >> element){
                    myFile.addChar(element);
                }
                cout << endl;
                inputFile.close(); //close input file

                last = myFile.getEnd();

                myFile.reverseArray(0,last); //reverses contents of input file
                myFile.toOutput(oFileName); // writes the reversed array to the output file
                myFile.printArray(); // prints the reversed array to the screen

                break;

            case 2:
                cout << "Goodbye!" << endl;
                break;

            default:
                //default switch in case something goes terribly wrong...
                cout << "It appears something went wrong..." << endl;
                break;
        }
    }while(choice != 2);

    
    return 0;
}

/*********************************************************************
** Function: displayMenu
** Description: This function prompts the user with a menu containing
 * two different choices. There is an input validation loop after 
 * the user enters their choice to verify that a valid choice was made.
** Parameters: N/A
** Pre-Conditions: The function was designed to have the return value
 * passed into a switch statement. 
** Post-Conditions: The function must return an integer from 1 to 2.
*********************************************************************/
int displayMenu(){
     cout << endl;
        cout << "Choose one of the following options:" << endl;
        cout << "1 - Reverse a file" << endl;
        cout << "2 - Exit the program" << endl;
        int choice;
        cin >> choice;
        while (!cin || (choice < 1) || (choice > 2)){
            cin.clear();
            cin.ignore(80,'\n');
            cout << "Please enter 1 to continue or 2 to quit: " << endl;
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
    
    if(!(inputFile))
        exists = false;
    else
        exists = true;
    
    inputFile.close();
    
    return exists;
}