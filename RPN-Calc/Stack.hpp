/*********************************************************************
** Program Filename: Stack.hpp
** Author: John Carrabino
** Date: 8/12/2016
** Description: This is the Stack specification file provided by
 * my TA for this lab.
** Input: n/a
** Output: n/a
*********************************************************************/
#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <cstddef>


class Stack
{
	protected://changed from private to protected so RPN could access.
                //Changed from class to struct so RPN can access data members.
		struct StackNode 
		{
			int value;
			StackNode* next;
			//Constructor
			StackNode(int value1, StackNode* next1 = NULL)
			{
				value = value1;
				next = next1;
			}
		};
		StackNode* top;

	public:
		Stack();
                virtual ~Stack()=0;
		void push(int input);
		int peek();
		void pop();
		bool isEmpty() const;
		
		//Stack Exception
		//class Underflow {};

};
#endif
