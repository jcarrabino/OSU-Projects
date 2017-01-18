/*********************************************************************
** Program Filename: ToUpper.h
** Author: John Carrabino   
** Date: 7/17/2016
** Description: This is the ToUpper class specification file
 * Input: n/a
** Output: n/a
*********************************************************************/
#ifndef TOUPPER_H
#define TOUPPER_H
#include "Transformer.h"
class ToUpper : public Transformer{
public:
    ToUpper();
    ~ToUpper();
    virtual char transform(char);
    virtual void doFilter(std::ifstream&, std::ofstream&);
    virtual void addChar(char);
    virtual void expandArray();
    virtual void nameFiles(std::string, std::string);

protected:

private:

};


#endif /* TOUPPER_H */

