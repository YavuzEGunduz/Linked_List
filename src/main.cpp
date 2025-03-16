
#include "Sayi.hpp"
#include "SayilarListesi.hpp"
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

void addN(Sayi& list, int number) {
    while (number > 0) {
        int digit = number % 10;
        list.addD(digit);
        number /= 10;
    }
}


int main()
{
    ifstream file("Sayilar.txt");
    if(!file.is_open())
    {
        cout<<"Dosya Açilamadi"<<endl;
        return 1;
    }

    string row;
    SayiL liste;
    Sayi lists[1000];
    int ind=0;

    getline(file,row);
    istringstream iss(row);
    int num;

    while(iss>>num){
        liste.numm(num);
        Sayi& list=lists[ind];

        while(num>0)
        {
            int d=num%10;
            list.addD(d);
            num/=10;
        }
        ++ind;
    }
    liste.reverseList();
    file.close();


    while(true)
    {
        cout<<endl<<endl;
         for(int i=0;i<ind;i++)
        {
                cout<<"###########";
                int a=lists[i].i();

                if(a!=0)cout<<setw(11);
                for(int j=0;j<a;j++){
                    cout<<setw(8)<<"*******";
                }

                cout<<endl;
                cout<<"#"<<setw(9)<<liste.printadress(i+1)<<"#"<<setw(2);
                for(int j=0;j<a;j++){
                    cout<<setw(2)<<"*"<<setw(4)<<lists[i].threedigit(j)<<setw(2)<<"*";
                }
                cout<<endl;

                cout<<"#---------#";
                if(a!=0)cout<<setw(11);
                for(int j=0;j<a;j++){
                    cout<<setw(8)<<"*******";
                }

                cout<<endl;
                cout<<"#"<<setw(9);
                liste.printnum(i+1);
                cout<<"#"<<setw(4);
                for(int j=0;j<a;j++){

                    cout<<setw(2)<<"*"<<setw(4)<<lists[i].numprint(j)<<setw(2)<<"*";
                }
                cout<<endl;
                cout<<"###########";
                if(a!=0)cout<<setw(11);
                for(int j=0;j<a;j++){
                    cout<<setw(8)<<"*******";
                }
                cout<<endl;
                cout<<endl;
        }
        
        cout<<endl;

        cout<<"1) Tek basamaklilari Basa Al"<<endl;
        cout<<"2) Basamaklari Tersle"<<endl;
        cout<<"3) En Buyuk Cikar"<<endl;
        cout<<"4) Cikis"<<endl;
        int chc;
        cin>>chc;
        if(chc==1)
        {
            for(int i=0;i<ind;i++)
                lists[i].tekbasa();
            liste.tekbasaL();
        }
        else if(chc==2)
        {
            for(int i=0;i<ind;++i)
                lists[i].reverseDigits();
            liste.reverseDigitsL();
        }
        else if(chc==3)
        {
            for (int i = 0; i < ind; ++i)
                lists[i].bigdel();
            liste.bigdelL();
        }
        else if(chc==4)
        {
            for(int i=0;i<ind;i++)
                lists[i].~Sayi();
            liste.~SayiL();
            break;
        }
        else
        {
            cout<<"geçersiz seçenek"<<endl;
        }
    }
    return 0;
}