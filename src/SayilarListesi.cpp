
#include "SayilarListesi.hpp"

SayiL::SayiL()
{
    firstnum=0;
}

SayiL::~SayiL()
{
	
	while(firstnum!=0)
	{
		Dugum* del=firstnum;
		firstnum=firstnum->next;
		delete del;
	}
}

void SayiL::numm(int take)
{
    Dugum* oth =new Dugum(take);
    oth->next=firstnum;
    firstnum=oth;
}
void SayiL::reverseList()
{
        Dugum* current = firstnum;
        Dugum* prev = nullptr;
        Dugum* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        firstnum = prev;

        current=prev=next=0;
        delete current;
        delete prev;
        delete next;
}

void SayiL::printnum(int i){
    if (firstnum == nullptr) {
        cout<<" ";
    }
    else{
        Dugum* current=firstnum;
        for(int j=1;j<i;j++)
        {
            current=current->next;
        }
        cout<<current->data;
        current=0;
        delete current;
    }
} 

Dugum* SayiL::printadress(int i)const
{
    Dugum* current=firstnum;
    for(int j=1;j<i&& current != nullptr;j++)
    {
        current=current->next;
    }
    return current;
}

void SayiL::bigdelL()
{
    Dugum* current=firstnum;

    while(current!=0)
    {       
        int eb = -1;
        int gecici=0;
        gecici=current->data;
        while (gecici > 0) 
        {
            int basamak = gecici % 10;
            if (basamak > eb) 
            {
            eb = basamak;
            }
            gecici /= 10;
        }
        int snum=0;
       gecici = current->data;

           while (gecici > 0) {
        int basamakDegeri = gecici % 10;
        if (basamakDegeri != eb) {
            snum = snum * 10 + basamakDegeri;
        }
        gecici /= 10;
    }
               while (snum > 0) {
        int basamakDegeri = snum % 10;
        if (basamakDegeri != eb) {
            gecici = gecici * 10 + basamakDegeri;
        }
        snum /= 10;
    }
        current->data=gecici;
        current=current->next;
    }
    current=0;
    delete current;

}

void SayiL::reverseDigitsL()
{
    Dugum* current=firstnum;
    while(current!=nullptr)
    {
        int gecici=current->data;
        current->data=0;
        while (gecici > 0) {
            int basamakDegeri = gecici % 10;
            current->data = current->data * 10 + basamakDegeri;
            gecici /= 10;
        }
        current=current->next;
    }
    current=0;
    delete current;
}   


void SayiL::tekbasaL(){
    if(firstnum==0)return;
    Dugum* current=firstnum;
    while(current!=nullptr)
    {
        int gecici=current->data;
        int gecici2=0;
        current->data=0;
        while (gecici > 0) {
            int basamakDegeri = gecici % 10;
            if(basamakDegeri%2==1)
            {
                current->data = current->data * 10 + basamakDegeri;
            }
            else{
                gecici2=gecici2*10+basamakDegeri;
            }
            gecici /= 10;
        }
        while(gecici2>0)
        {
            int basamakDegeri = gecici2 % 10;
            current->data = current->data * 10 + basamakDegeri;
            gecici2/=10;
        }
        current=current->next;
    }
    current=0;
    delete current;
}


