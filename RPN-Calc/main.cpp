/*********************************************************************
** Program Filename: main.cpp
** Author: John Carrabino
** Date: 8/12/2016
** Description: This is the main file for lab Fb. For this lab we
 * were given Stack and Queue source and header files written by our
 * fellow peers from a previous lab. We needed to implement the Stack 
 * Class and use it to create a Reverse Polish Notation calculator. 
 * The program prompts the user to enter an expression in RPN, and 
 * evaluates the expression, either returning the solution or 
 * returning an error message and any valid entries pushed onto the
 * stack prior to the invalid entry.
** Input: User enters a mathematical expression in RPN format.
** Output: This program will evaluate and return expressions written
 * in RPN format.
*********************************************************************/
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include "Stack.hpp"
#include "RPN.hpp"

using std::cout;
using std::cin;
using std::endl;

//function prototypes
int displayMenu();
int exception(int);
bool isOperator(std::string&);
void doMath(std::string, RPN*);
int main(int argc, char** argv) {
    RPN *calc;
    std::string input;
    int num, choice;
    bool isValid;
        
    do{ 
        choice = displayMenu();
        switch(choice){
            case 1:
                calc = new RPN;
                cout << "Please enter a positive integer expression in \n"
                        "RPN format. Once you have finished press any \n"
                        "letter then hit ENTER to view the solution \n"
                        "to your expression." << endl << endl;
                cout << "Please note that if you enter a number with \n"
                        "more than ten digits then the program will \n"
                        "terminate and evaluate your expression based \n"
                        "on all input recieved prior to the bad input \n";
                cout << endl;
                cout << "Expression: ";
                isValid = true;
                while(isValid){
                    cin >> input;
                    if(std::istringstream(input) >> num){
                        calc->push(num);
                    }
                    else if(isOperator(input)){
                        if(calc->isBinary())
                            doMath(input, calc);
                        else {
                            cout << endl << endl;
                            cout << "There are not enough operands to \n"
                                    "perform the requested operation(s).";
                            cout << endl << endl;
                            cout << "These are the values stored in \n"
                                    "your stack before the error was \n"
                                    "reached \n";
                            cout << "Stack: ";
                            calc->display();
                            cout << endl << endl;
                            isValid = false;
                            break;
                        }
                    }else{
                        cout << endl;
                        if (calc->wasError()){
                            cout << endl;
                            cout << "The expression you entered contained \n"
                                    "a division by zero and could not \n"
                                    "be calculated. The contents of your \n"
                                    "current Stack are listed below." << endl;
                            cout << "Stack: ";
                            calc->display() ;
                            cout << endl << endl;
                        }
                        else if(calc->isEmpty()){
                            cout << "No valid integers were entered, so \n"
                                    "no calculations could be performed.";
                            cout << endl << endl;
                        }
                        else{
                            cout << "Solution: ";
                            calc->display();
                            cout << endl << endl;
                        }
                        isValid = false;
                        break;
                    }
                }
                delete calc;
                break;
            case 2:
                cout << "Goodbye!" << endl << endl;
                break;
            default:
                cout << "ERROR: Something has gone wrong and I don't know what!"
                     << endl;
                break;
        }
    }while(choice != 2);   
       
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
        std::cout << "Choose one of the following options:" << std::endl;
        std::cout << "1 - Enter an expression in RPN format" << std::endl;
        std::cout << "2 - Exit the program" << std::endl;
        std::cout << "Choice: ";
        int choice;
        std::cin.clear();
        std::cin.sync();
        std::cin >> choice;
        std::cin.sync();
        while (!std::cin || (choice < 1) || (choice > 2)){
            std::cin.clear();
            std::cin.ignore(80,'\n');
           std::cin >> choice;
        }
        std::cin.ignore(100,'\n');
        std::cin.clear();
        std::cout << std::endl << std::endl;
        return choice;
}

/*********************************************************************
** Function: isOperator();
** Description: This function evaluates non integer input entered
 * by the user in to the string stream object and returns true if
 * the user inputs one of the 4 valid mathematical operators.
** Parameters: This function takes a non integer value string as
 * its only argument.
** Pre-Conditions: n/a
** Post-Conditions: returns true if the input passed to it is an
 * operator.
*********************************************************************/
bool isOperator(std::string &in){
    if(in == "+"){
        return true;
    }
    if(in == "-"){
        return true;
    }
    if(in == "*"){
        return true;
    }
    if(in == "/"){
        return true;
    }
    
    return false;
    
}

/*********************************************************************
** Function: doMath();
** Description: This function evaluates non integer input entered
 * by the user that was deemed to be an operator. It then performs 
 * the appropriate operation from the pointer to an RPN object 
 * passed to the function.
** Parameters: This function takes a non integer value string and
 * a pointer to an RPN calculator object.
** Pre-Conditions: RPN object must already exist.
** Post-Conditions: Performs the appropriate operation to the stack
 * contained in the RPN object.
*********************************************************************/
void doMath(std::string in, RPN *calculator){
    
    const char *inc;
    inc = in.c_str();
    switch(inc[0]){
        case '+':
            calculator->add();
            break;
            
        case '-':
            calculator->subtract();
            break;
            
        case '*':
            calculator->multiply();
            break;
            
        case '/':
            calculator->divide();
            break;
            
        default:
            cout << "ERROR: Something has gone terribly wrong.." << endl;
            break;
            
    }
    
    return;
}