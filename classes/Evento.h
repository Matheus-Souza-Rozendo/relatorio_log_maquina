#ifndef EVENTO_H
#define EVENTO_H

#include <bits/stdc++.h>
#include "Data.h"

using namespace std;

class Evento
{
    public:
        Evento();
        void Set_evento(int data, int duration, int operation,int s);
        int Get_duracao();
        int Get_status();
        int Get_operacao();
        int Get_hora();
        int Get_dia();
        int Get_minuto();
    private:
        Data momento;
        int duracao;
        int operacao;
        int status;
};

Evento::Evento(){};

void Evento::Set_evento(int data, int duration, int operation, int s){
    momento.Set_Data(data);
    duracao=duration;
    operacao=operation;
    status = s;
}

int Evento::Get_duracao(){
    return duracao;
}

int Evento::Get_status(){
    return status;
}

int Evento::Get_operacao(){
    return operacao;
}

int Evento::Get_dia(){
    return momento.Get_dia();
}

int Evento::Get_minuto(){
    return momento.Get_minuto();
}

int Evento::Get_hora(){
    return momento.Get_hora();
}

#endif // EVENTO_H
