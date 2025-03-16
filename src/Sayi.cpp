
#include "Sayi.hpp"
#include <string>
#include <sstream>

Sayi::Sayi()
{
    first=NULL;
}

Sayi::~Sayi()
{
    while (first != 0)
    {
        Bsmk* sil = first;
        first = first->next;
        delete sil;
    }
}

void Sayi::addD( int value)
{
    Bsmk* newd =new Bsmk(value);
    newd->next=first;
    first=newd;
}
int Sayi::numprint(int i) {

    if (first == nullptr) {
        return 0;
    }
    Bsmk* current = first;
    for(int j=0;j<i;j++) {
        current = current->next;
    }
    return current->data;
}

void Sayi::bigdel()
{
    if (first == nullptr) {
        return;
    }

    Bsmk* current = first;
    Bsmk* max=first;
    Bsmk* prev = nullptr;

    while (current != nullptr) {
        if (current->data > max->data) {
            max = current;
        }
        current=current->next;
    }
    current=first;

    while(current!=0)
    {
        if(current->data == max->data)
        {       
            Bsmk*del=current; 
            if (del == first) 
            {
            first = first->next;
            }              
            else 
            {
                current = first;
                while (current != del) 
                {
                    prev = current;
                    current = current->next;
                }
                prev->next = current->next;
            }           
            current=current->next;
            del->next = nullptr;
            delete del;    
        } 
        else
            current=current->next;
    }
    current=max=prev=0;
    delete max;
    delete prev;
    delete current;
}

int Sayi::i()
{
    if(first==0)
        return 0;
    int i=0;
    Bsmk* current=first;
    while (current!= 0) {
        current = current->next;
        i++;
    }    
    current=0;
    delete current;
    return i;
}

string Sayi::threedigit(int i)
{
    if (first == nullptr) {
        return 0;
    }
    Bsmk* current=first;
    for(int j=0;j<i;j++)
    {
        current=current->next;
    }
    stringstream adresscurrent;
    adresscurrent<<current;
    string adresstr=adresscurrent.str();
    return adresstr.substr(adresstr.size()-3);
}

void Sayi::reverseDigits() {
    Bsmk* current = first;
    Bsmk* prev = nullptr;
    Bsmk* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    first = prev;
    prev=current=next=0;
    delete current;
    delete next;
    delete prev;
}

void Sayi::tekbasa()
{
    if(first==0)return;
    Bsmk* current = first->next;
    Bsmk* prev = first;
    Bsmk* tek = first;

    while(current!=nullptr)
    {
        if(current->data%2==1)
        {        
            tek=current;
            prev->next=current->next;
            current=current->next;
            tek->next=first;
            first=tek;
        }
        else{
            current=current->next;
            prev=prev->next;
        }
    }
    current=prev=tek=0;
    delete current;
    delete prev;
    delete tek;
}
    