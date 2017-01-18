/*********************************************************************
** Program Filename: Room.hpp
** Author: John Carrabino
** Date: 8/7/2016
** Description:This is the room class specification file
** Input: n/a
** Output: n/a
*********************************************************************/
#ifndef ROOM_HPP
#define ROOM_HPP
#include "Space.hpp"

class Room : public Space{
private:
    Node *main,*one,*two,*three,*four;
public:
    Room();
    ~Room();
    int special();
};

#endif /* ROOM_HPP */

