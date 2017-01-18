/*********************************************************************
** Program Filename: OrderedOutput.h
** Author: John Carrabino   
** Date: 7/17/2016
** Description: This is the OrderedOutput class specification file
 * Input: n/a
** Output: n/a
*********************************************************************/
#ifndef ORDEREDOUTPUT_H
#define ORDEREDOUTPUT_H
#include "Transformer.h"
class OrderedOutput : public Transformer{
public:
    OrderedOutput(int);
    ~OrderedOutput();
    virtual void doFilter(std::ifstream&,std::ofstream&);
    virtual char transform(char);
    virtual void addChar(char);
    virtual void expandArray();
    virtual void nameFiles(std::string, std::string);
protected:

private:
    
};


#endif /* ORDEREDOUTPUT_H */

