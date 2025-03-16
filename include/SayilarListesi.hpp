
#ifndef SayilarListesi_hpp
#define SayilarListesi_hpp
#include "Dugum.hpp"

class SayiL
{
    public:
    SayiL();
    ~SayiL();
    void numm(int);
    void printnum(int);
    Dugum* printadress(int)const;
    void reverseList();
    void bigdelL();
    void reverseDigitsL();
    void tekbasaL();
    Dugum* firstnum;

};

#endif