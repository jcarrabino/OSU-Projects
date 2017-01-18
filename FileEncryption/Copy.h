/*********************************************************************
** Program Filename: Copy.h
** Author: John Carrabino   
** Date: 7/17/2016
** Description: This is the Copy class specification file
 * Input: n/a
** Output: n/a
*********************************************************************/
#ifndef COPY_H
#define COPY_H
#include "Transformer.h"
class Copy : public Transformer{
public:
    Copy();
    ~Copy();
    virtual void doFilter(std::ifstream&, std::ofstream&);
    virtual char transform(char);
    virtual void addChar(char);
    virtual void expandArray();
    virtual void nameFiles(std::string, std::string);

protected:

private:
        
};


#endif /* COPY_H */

