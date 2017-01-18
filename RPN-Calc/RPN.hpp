/*********************************************************************
** Program Filename: Stack.cpp
** Author: John Carrabino
** Date: 8/12/2016
** Description: This is the RPN class implementation file 
** Input: n/a
** Output: n/a
*********************************************************************/

#ifndef RPN_HPP
#define RPN_HPP
#include "Stack.hpp"

class RPN : public Stack{
    public:
        RPN();
        ~RPN();
        void add();
        void subtract();
        void multiply();
        void divide();
        bool isBinary();
        void display();
        int getNum();
        bool wasError();
        void setError();
    private:
        int numElements;
        bool error;
            
};


#endif /* RPN_HPP */

