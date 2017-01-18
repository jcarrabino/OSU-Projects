/*********************************************************************
** Program Filename: Space.hpp
** Author: John Carrabino
** Date: 8/7/2016
** Description:This is the space class specification file
** Input: n/a
** Output: n/a
*********************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;


class Space{
protected:
    struct Node{
        bool itemFound;
        Node *next;
        Node *prev;
        Node *left;
        Node *right;
        Node(bool i = false, Node *n = NULL,
              Node *p = NULL , Node *l = NULL, Node *r = NULL){
            itemFound = i;
            next = n;
            prev = p;
            left = l;
            right = r;
        }
    };
    Node *head;
    Node *back;
    int stepCount;
    int fCount, lCount, rCount;
    bool foundAll;
    
public:
    Space();
    virtual ~Space()=0;
    int forward();
    int backward();
    void right();
    void left();
    int getSteps();
    void setSteps(int);
    // void getCount();
    bool complete(bool);
    virtual int special();
    bool itemFound();
    void mLeft();
    void mRight();
    int mForward();
    int mBack();
};


#endif /* SPACE_HPP */

