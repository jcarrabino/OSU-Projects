/*********************************************************************
** Program Filename: CryptKeeper
** Author: John Carrabino   
** Date: 7/17/2016
** Description: This program allows the user to take a text
 * file and either copy it, encrypt it, make it all uppercase 
 * letters, or translate it into ciphertext. The new documents
 * are then saved to a file specified by the user.
 * Input: This program prompts the user to choose between
 * copying, encrypting, to Uppercase, or to Ciphertext a file
 * of their choosing. The user is then prompted for the input
 * and output file names. If the user opted to encrypt or 
 * ciphertext a file then they are also prompted to input a 
 * numeric key.
** Output: After all of the input is received the program will
 * create a copied or altered version of the original file and 
 * save the new file to the output file they specified.
*********************************************************************/
#include "Transformer.h"
#include "Copy.h"
#include "Encryption.h"
#include "OrderedOutput.h"
#include "ToUpper.h"

using std::cout;
using std::cin;
using std::endl;

int displayMenu(); //display the menu
bool itExists(std::string); //check if a file already exists
void doCopy(); //copies file
void doEncrypt(); //encrypts file
void doUpper(); //turns file into all uppercase alphabetic text
void doOrdered(); //encrypts file to ciphertext

int main(int argc, char** argv) {

    int choice;
    //loops through display menu that passes an integer into a switch
    do{
        choice = displayMenu();
        switch(choice)
        {
            case 1: //copies file
                doCopy();
                break;
            case 2: //encrypts file
                doEncrypt();
                break;
            case 3: // takes all letters of file and makes them uppercase
                doUpper();
                break;

            case 4: //translates file into ciphertext
                doOrdered();
                break;
            case 5: // ends program
                cout << endl << "Goodbye!" << endl;
                break;

            default: // default switch in case something goes terribly wrong...
                cout << "It appears something went wrong..." << endl;
                break;
        }
    }while(choice != 5);
    
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
        cout << "1 - Copy a file" << endl;
        cout << "2 - Encrypt a file" << endl;
        cout << "3 - Create an all Uppercase alphabetic text file" << endl;
        cout << "4 - Encrypt a file to Ciphertext" << endl;
        cout << "5 - Exit the program" << endl;
        int choice;
        cin >> choice;
        while (!cin || (choice < 0) || (choice > 5)){
            cin.clear();
            cin.ignore(80,'\n');
            cout << "Please enter 1, 2, 3, or 4 to continue, "
                    "or enter 5 to quit: " << endl;
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

/*********************************************************************
** Function: doCopy()
** Description: This function prompts the user for the names of the
 * input file they want to have copied and the name of the output
 * file that they wish to save the copied document to.
** Pre-Conditions: The input file must already exist
** Post-Conditions: The copied document is saved to the file
 * specified by the user.
*********************************************************************/
void doCopy(){
    Transformer *ptTrans;
    std::ifstream inputFile;
    std::ofstream outputFile;
    std::string iFileName;
    std::string oFileName;
    cin.clear();
                cout << endl << "What is the name of the file you"
                        " would like to copy?";
                cout << endl;
                cin.sync();
                getline(cin,iFileName);
             //test to make sure file exists and that they entered a valid name
                while (!(itExists(iFileName)) || iFileName == ""){
                    cout << "Please enter a valid file name: " << endl;
                    cin.clear();
                    cin.sync();
                    cin >> iFileName;
                }                

                cout << endl << "What is the name of the file you"
                        " would like to save your copied document to?";
                cout << endl;
                cin.clear();
                cin.sync();
                getline(cin,oFileName);
                while (!cin || oFileName == ""){
                    cout << "Please enter a valid file name: " << endl;
                    cin.clear();
                    cin.sync();
                    cin >> oFileName;
                }
                
                if(itExists(oFileName)){
                    int rewrite;
                    cout << "That file already exists." << endl
                         << "Choose one of the following options: " << endl
                         << "1 - Overwrite existing file" << endl
                         << "2 - Choose a new output file name" << endl;
                       
                        do{
                            cin.sync();
                            cin >> rewrite;
                            if (!cin || rewrite < 1 || rewrite > 3){
                                cin.clear();
                                cin.ignore(80,'\n');
                                cout <<"Please enter the number 1 or 2 \n";
                            } else
                                break;
                        } while (!(cin >> rewrite)|| rewrite < 1 || rewrite > 3);
                        cin.clear();
                        cin.ignore(90,'\n');
                        
                        if(rewrite == 2){
                            cout << "What is the name of the file you would like" 
                                 << " to save your all uppercase document to?";
                            cout << endl;
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
                        } 
                }

                ptTrans = new Copy;
                ptTrans->nameFiles(iFileName,oFileName);
                ptTrans->doFilter(inputFile,outputFile);
                delete ptTrans;
}
/*********************************************************************
** Function: doEncrypt()
** Description: This function prompts the user for the names of the
 * input file they want to have encrypted and the name of the output
 * file that they wish to save the encrypted document to.
** Pre-Conditions: The input file must already exist
** Post-Conditions: The copied document is saved to the file
 * specified by the user.
*********************************************************************/
void doEncrypt(){
    Transformer *ptTrans;
    std::ifstream inputFile;
    std::ofstream outputFile;
    std::string iFileName;
    std::string oFileName;
    int daKey;
    cin.clear();
                cout << endl << "What is the name of the file you"
                        " would like to encrypt?";
                cout << endl;
                cin.sync();
                getline(cin,iFileName);
             //test to make sure file exists and that they entered a valid name
                while (!(itExists(iFileName)) || iFileName == ""){
                    cout << "Please enter a valid file name: " << endl;
                    cin.clear();
                    cin.sync();
                    cin >> iFileName;
                }

                cout << endl << "What is the name of the file you"
                        " would like to save your encrypted document to?";
                cout << endl;
                cin.clear();
                cin.sync();
                getline(cin,oFileName);
                while (!cin || oFileName == ""){
                    cout << "Please enter a valid file name: " << endl;
                    cin.clear();
                    cin.sync();
                    cin >> oFileName;
                }
                
                if(itExists(oFileName)){
                    int rewrite;
                    cout << "That file already exists." << endl
                         << "Choose one of the following options: " << endl
                         << "1 - Overwrite existing file" << endl
                         << "2 - Choose a new output file name" << endl;
                       
                        do{
                            cin.sync();
                            cin >> rewrite;
                            if (!cin || rewrite < 1 || rewrite > 3){
                                cin.clear();
                                cin.ignore(80,'\n');
                                cout <<"Please enter the number 1 or 2 \n";
                            } else
                                break;
                        } while (!(cin >> rewrite)|| rewrite < 1 || rewrite > 3);
                        cin.clear();
                        cin.ignore(90,'\n');
                        
                        if(rewrite == 2){
                            cout << "What is the name of the file you would like" 
                                 << " to save your all uppercase document to?";
                            cout << endl;
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
                        } 
                }

                cout << endl 
                     << "Now you need to choose a key to create your cipher";
                cout << endl << "Please enter a whole number"
                        " greater than zero: " <<endl;
                cin.clear();
                cin.sync();
                cin >> daKey;
                while(!cin || daKey < 0 || daKey > 2000000000){
                    cout << endl << "Please enter a number greater than zero "
                            "and less than 2 billion" << endl;
                    cin.clear();
                    cin.sync(); 
                    cin >> daKey;
                }

                ptTrans = new Encryption(daKey);
                ptTrans->nameFiles(iFileName,oFileName);
                ptTrans->doFilter(inputFile,outputFile);
                delete ptTrans;
}
/*********************************************************************
** Function: doUpper()
** Description: This function prompts the user for the names of the
 * input file they want to have all uppercase and the name of the output
 * file that they wish to save the copied document to.
** Pre-Conditions: The input file must already exist
** Post-Conditions: The copied document is saved to the file
 * specified by the user.
*********************************************************************/
void doUpper(){
   Transformer *ptTrans;
    std::ifstream inputFile;
    std::ofstream outputFile;
    std::string iFileName;
    std::string oFileName;
    cin.clear();
                cout << endl << "What is the name of the file you"
                        " would like to make all uppercase?";
                cout << endl;
                cin.sync();
                getline(cin,iFileName);
             //test to make sure file exists and that they entered a valid name
                while (!(itExists(iFileName)) || iFileName == ""){
                    cout << "Please enter a valid file name: " << endl;
                    cin.clear();
                    cin.sync();
                    cin >> iFileName;
                }

                cout << endl << "What is the name of the file you would like " 
                     << "to save your all uppercase document to?";
                cout << endl;
                cin.clear();
                cin.sync();
                getline(cin,oFileName);
                while (!cin || oFileName == ""){
                    cout << "Please enter a valid file name: " << endl;
                    cin.clear();
                    cin.sync();
                    cin >> oFileName;
                }
                
                if(itExists(oFileName)){
                    int rewrite;
                    cout << "That file already exists." << endl
                         << "Choose one of the following options: " << endl
                         << "1 - Overwrite existing file" << endl
                         << "2 - Choose a new output file name" << endl;
                       
                        do{
                            cin.sync();
                            cin >> rewrite;
                            if (!cin || rewrite < 1 || rewrite > 3){
                                cin.clear();
                                cin.ignore(80,'\n');
                                cout <<"Please enter the number 1 or 2 \n";
                            } else
                                break;
                        } while (!(cin >> rewrite)|| rewrite < 1 || rewrite > 3);
                        cin.clear();
                        cin.ignore(90,'\n');
                        
                        if(rewrite == 2){
                            cout <<"What is the name of the file you would like" 
                                 << " to save your all uppercase document to?";
                            cout << endl;
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
                        } 
                }

                ptTrans = new ToUpper;
                ptTrans->nameFiles(iFileName,oFileName);
                ptTrans->doFilter(inputFile,outputFile);
                delete ptTrans; 
}
/*********************************************************************
** Function: doOrdered()
** Description: This function prompts the user for the names of the
 * input file they want to have translated into Ciphertext and the 
 * name of the output file that they wish to save the new document to.
** Pre-Conditions: The input file must already exist
** Post-Conditions: The copied document is saved to the file
 * specified by the user.
*********************************************************************/
void doOrdered(){
    Transformer *ptTrans;
    Transformer *ptOrdered;
    int daKey;
    std::ifstream inputFile;
    std::ofstream outputFile;
    std::string iFileName;
    std::string oFileName;
    
                cout << endl << "What is the name of the file you"
                        " would like to encrypt?";
                cout << endl;
                cin.sync();
                getline(cin,iFileName);
             //test to make sure file exists and that they entered a valid name
                while (!(itExists(iFileName)) || iFileName == ""){
                    cout << "Please enter a valid file name: " << endl;
                    cin.clear();
                    cin.sync();
                    cin >> iFileName;
                }

                cout << endl 
                     << "What is the name of the file you would like" << '\n'
                     << "to save your encrypted document to?";
                cout << endl;
                cin.clear();
                cin.sync();
                getline(cin,oFileName);
                while (!cin || oFileName == ""){
                    cout << "Please enter a valid file name: " << endl;
                    cin.clear();
                    cin.sync();
                    cin >> oFileName;
                }
                
                if(itExists(oFileName)){
                    int rewrite;
                    cout << "That file already exists." << endl
                         << "Choose one of the following options: " << endl
                         << "1 - Overwrite existing file" << endl
                         << "2 - Choose a new output file name" << endl;
                       
                        do{
                            cin.sync();
                            cin >> rewrite;
                            if (!cin || rewrite < 1 || rewrite > 3){
                                cin.clear();
                                cin.ignore(80,'\n');
                                cout <<"Please enter the number 1 or 2 \n";
                            } else
                                break;
                        } while (!(cin >> rewrite)|| rewrite < 1 || rewrite > 3);
                        cin.clear();
                        cin.ignore(90,'\n');
                        
                        if(rewrite == 2){
                            cout << "What is the name of the file you would like" 
                                 << " to save your all uppercase document to?";
                            cout << endl;
                            cin.clear();
                            cin.sync();
                            getline(cin,oFileName);
                            cin.sync();
                            while (!cin || oFileName == ""){
                                cout << "Please enter a valid file name: " << endl;
                                cin.clear();
                                cin.sync();
                                cin >> oFileName;
                            } 
                        } 
                }

                cout << "Now you need to choose a key to create your cipher";
                cout << endl << "Please enter a whole number"
                        " greater than zero: " <<endl;
                cin.clear();
                cin.sync();
                cin >> daKey;
                while(!cin || daKey < 0 || daKey > 2000000000){
                    cout << endl << "Please enter a number greater than zero "
                            "and less than 2 billion" << endl;
                    cin.clear();
                    cin.sync();
                    cin >> daKey;
                }

                ptOrdered = new OrderedOutput(daKey);
                ptOrdered->nameFiles(iFileName,oFileName);
                ptOrdered->doFilter(inputFile,outputFile);
                delete ptOrdered;
}