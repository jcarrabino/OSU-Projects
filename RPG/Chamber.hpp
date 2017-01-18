/*********************************************************************
 ** Program Filename: Chamber.hpp
 ** Author: John Carrabino
 ** Date: 8/7/2016
 ** Description:This is the chamber class specification file
 ** Input: n/a
 ** Output: n/a
 *********************************************************************/
#ifndef CHAMBER_HPP
#define CHAMBER_HPP

#include "Space.hpp"

class Chamber : public Space {
public:
    Chamber(int);
    ~Chamber();
    int special();
};

#endif /* CHAMBER_HPP */

