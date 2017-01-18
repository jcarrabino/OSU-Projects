/*********************************************************************
 ** Program Filename: Secret.hpp
 ** Author: John Carrabino
 ** Date: 8/7/2016
 ** Description:This is the secret class specification file
 ** Input: n/a
 ** Output: n/a
 *********************************************************************/
#ifndef SECRET_HPP
#define SECRET_HPP

#include "Space.hpp"

class Secret : public Space {
public:
    Secret(int);
    ~Secret();
    int special();
};

#endif /* SECRET_HPP */

