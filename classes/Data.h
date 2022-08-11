#ifndef DATA_H
#define DATA_H
#include <bits/stdc++.h>

using namespace std;

class Data
{
    public:
        Data();
        void Set_Data(int data);
        int Get_dia();
        int Get_hora();
        int Get_minuto();
    private:
        int dia;
        int hora;
        int minuto;
};

void Data::Set_Data(int data){
    dia = data/10000;
    data = data%10000;
    hora = data/100;
    minuto = data%100;
}

int Data::Get_dia(){
    return dia;
}

int Data::Get_hora(){
    return hora;
}

int Data::Get_minuto(){
    return minuto;
}

Data::Data(){}
#endif // DATA_H
