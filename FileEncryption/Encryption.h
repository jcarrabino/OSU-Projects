/*********************************************************************
** Program Filename: Encryption.h
** Author: John Carrabino   
** Date: 7/17/2016
** Description: This is the Encryption class specification file
 * Input: n/a
** Output: n/a
*********************************************************************/
#ifndef ENCRYPTION_H
#define ENCRYPTION_H
#include "Transformer.h"
class Encryption : public Transformer{
public:
    Encryption(int);
    ~Encryption();
    virtual void doFilter(std::ifstream&,std::ofstream&);
    virtual char transform(char);
    virtual void addChar(char);
    virtual void expandArray();
    virtual void nameFiles(std::string, std::string);
    virtual int getKey();
    
protected:
        
private:
};

#endif /* ENCRYPTION_H */

