/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: John
 *
 * Created on August 8, 2016, 12:13 PM
 */

#include<cstdlib>
#include<ctime>
#include<iomanip>
#include "iMergeSort.hpp"
#include "rMergeSort.hpp"

using std::cout;
using std::cin;
using std::endl;

void initialize(std::ofstream&, std::string&, int);
int randomInt();
int displayMenu(); //display the menu
int main()
{
    srand(time(NULL));
    std::ifstream in;
    std::ofstream out;
    std::string testFile;
    int choice, amount, num;
    double iStart, iStop, rStart, rStop, iResult, rResult;
    
    iMergeSort *iterative;
    rMergeSort *recursive;
    
    do{
        choice = displayMenu();
        switch(choice){
            case 1:
                iterative = new iMergeSort;
                recursive = new rMergeSort;
                cout << "What would you like to name the file \n"
                        "you wish to add random integers to?" << endl << endl;
                cout << "File Name: ";
                cin.sync(); 
                getline(cin,testFile);
                cin.sync();
                while (!cin || testFile == ""){
                    cout << "Please enter a valid file name: " 
                         << endl;
                    cin.clear();
                    cin.sync();
                    cin >> testFile;
                }
                
                cout << endl << endl;
                cout << "How many integers would you like to add \n"
                        "to the file, " << testFile << "?" << endl;
                cout << "Amount: ";
                cin.clear();
                cin.sync();
                cin >> amount;
                while(!cin || amount < 0 || amount > 2000000000){
                    cout << endl << "Please enter a positive integer greater \n"
                            "than 0 and less than 2 Billion." << endl;
                    cin.clear();
                    cin.sync(); 
                    cin >> amount;
                }
                
                cout << endl << endl;
                
                cout << "Now initializing test file..." <<endl;
                initialize(out, testFile, amount);
                cout << "The test files have been initialized" << endl << endl;
                
                cout << "Now adding file contents to recursive \n"
                        "and iterative implementations of the \n"
                        "MergeSort algorithm..." << endl << endl;
                
                in.open(testFile.c_str());
                while (in >> num){
                    iterative->iAddInt(num);
                    recursive->rAddInt(num);
                    //cout << "Added " << num << endl;
                }
                in.close();
                
//                cout << endl << endl;
//                cout << "RecArray: ";
//                recursive->printArray(amount);
//                cout << endl << endl;
//                cout << "ItArray: ";
//                iterative->printArray(amount);
//                cout << endl << endl;
                

                cout << "The recursive and iterative arrays \n"
                        "have been initialized." << endl;
                
                cout << "Now sorting your arrays" << endl << endl;
                iStart = clock();
                iterative->itMergeSort();
                iStop = clock();
                
                rStart = clock();
                recursive->recMergeSort(0,amount-1);
                rStop = clock();
                
                iResult = (iStop - iStart) / CLOCKS_PER_SEC;
                rResult = (rStop - rStart) / CLOCKS_PER_SEC;
                
                cout << std::fixed << std::showpoint << std::setprecision(10);
                cout << "The arrays have been sorted" << endl;
                cout << "Results (measured in seconds): \n";
                cout << "Iterative MergeSort: " << iResult<<" seconds" << endl;
                cout << "Recursive MergeSort: " << rResult<<" seconds" << endl;
                delete iterative;
                delete recursive;
                break;
            case 3:
                cout << "The first 10 Items in each \n"
                        "array are as follows, \n";
                cout << "Iterative: ";
                iterative->printArray(10);
                cout << endl << "Recursive: ";
                recursive->printArray(10);
                cout << endl << endl;
            case 2:
                cout << endl << endl << "Goodbye!" << endl;
                break;
            default:
                cout << endl << endl;
                cout << "Something has gone terribly wrong..." << endl;
                break;
        }
    }while(choice != 2);
    
    
//    int arr[] = {12, 11, 13, 5, 6, 7};
//    int arr2[] = {12, 11, 13, 5, 6, 7}; 
//    int arr_size = sizeof(arr)/sizeof(arr[0]);
//    int start1, start2, stop1, stop2;
//    double time1, time2;
//    
//    printf("Given array is \n");
//    printArray(arr, arr_size);
// 
//    start1 = clock();
//    iMergeSort(arr, arr_size);
//    stop1 = clock();
//    
//    start2 = clock();
//    rMergeSort(arr, 0, arr_size - 1);
//    stop2 = clock();
//    
//    time1 = (double)(stop1 - start1)/double(CLOCKS_PER_SEC)*1000;
//    time2 = (double)(stop2 - start2)/double(CLOCKS_PER_SEC)*1000;
//    
//    cout << "Iterative Merge Sort Time: " << time1 << endl;
//    cout << "Recursive Merge Sort Time: " << time2 << endl;
    
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
        cout << "1 - Test MergeSort Functions" << endl;
        cout << "2 - Exit the program" << endl;
        cout << "Choice: ";
        int choice;
        cin >> choice;
        while (!cin || (choice < 0) || (choice > 2)){
            cin.clear();
            cin.ignore(80,'\n');
            cout << endl;
            cout << "Please enter a 1 to continue or 2 to quit" << endl;
            cin >> choice;
        }
        cin.ignore(100,'\n');
        cin.clear();
        cout << endl;
        return choice;
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
void initialize(std::ofstream &out1, std::string &orig, int max){
    out1.open(orig.c_str());
    int x;
    for(int i=0; i<max; i++){
        x = randomInt();
        out1 << x << endl;
    }
    
    out1.close();    
}

int randomInt(){
    int x = rand() % 100;
    return x;
}