/*********************************************************************
** Program Filename: Stack.cpp
** Author: John Carrabino
** Date: 8/12/2016
** Description: This is the Stack implementation file provided by
 * my TA for this lab.
** Input: n/a
** Output: n/a
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "Stack.hpp"

using std::cout;


/*********************************************************************
** Function: Stack
** Description: Constructor sets top pointer to NULL
** Parameters: N/A
*********************************************************************/
Stack::Stack()
{
	top = NULL; 
}

/*********************************************************************
** Function: Stack
** Description: Destructor added to destroy the nodes created by the 
 * stack
** Parameters: N/A
*********************************************************************/
Stack::~Stack(){
    
}

/*********************************************************************
** Function: push
** Description: pushes the argument onto the stack
** Parameters: int input
*********************************************************************/
void Stack::push(int input)
{
	top = new StackNode(input, top);
}

/*********************************************************************
** Function: peek
** Description: returns the value on top of the stack
*********************************************************************/
int Stack::peek()
{

	if (isEmpty())
	{
		cout << "The stack is empty.\n";
		exit(1);
	}
	else
	{
		return top->value;
	}

	//Code for Exception
	/*if (isEmpty()) throw Stack::Underflow();
	return top->value;*/
}

/*********************************************************************
** Function: pop
** Description: removes the value at the top of the stack
** Parameters: int input
*********************************************************************/
void Stack::pop()
{
	StackNode* temp;

	if (isEmpty())
	{
		cout << "The stack is empty.\n";
		exit(1);
	}
	else
	{
		temp = top;
		top = top->next;
		delete temp;
	}

	//Code for Exception
	/*if (isEmpty()) throw Stack::Underflow();	
	temp = top;
	top = top->next;
	delete temp;*/
	
}

/*********************************************************************
** Function: isEmpty
** Description: returns true if the stack is empty or false if stack
is not empty
*********************************************************************/
bool Stack::isEmpty() const
{
	if (!top)
		return true;
	else
		return false;
}