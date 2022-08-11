#ifndef TABELA_LOG_H
#define TABELA_LOG_H
#include <bits/stdc++.h>
#include "Evento.h"

class Tabela_log
{
    public:
        Tabela_log();
        void Set_tabela_log(vector <Evento> events);
        vector <Evento> operacoes_sem_erro();
        int duracao_por_status(int status);
        int numero_carregamento_materia_prima(int materia);
        int numero_operacao_por_status(int status);
        int numero_carregamentos__materia_prima_manha(int materia);
        int numero_erro_maior_5_minutos();
    private:
        vector <Evento> eventos;

};

void Tabela_log::Set_tabela_log(vector <Evento> events){
    eventos=events;
}

vector <Evento> Tabela_log::operacoes_sem_erro(){
    vector <Evento> aux;
    aux.push_back(eventos[0]);
    aux.push_back(eventos[1]);
    if(aux[0].Get_duracao()<aux[1].Get_duracao()){
        Evento E;
        E=aux[1];
        aux[0]=aux[1];
        aux[1]=E;
    }
    for(int i=0; i<eventos.size()-1;i++){
        if(eventos[i].Get_status()!=3 && eventos[i+1].Get_status()!=3){
            if(eventos[i].Get_duracao()>aux[0].Get_duracao()){
                aux[0]=eventos[i];
            }else{
                if(eventos[i].Get_duracao()>aux[1].Get_duracao()){
                    aux[1]=eventos[i];
                }
            }
        }
    }
    return aux;
}

int Tabela_log::duracao_por_status(int status){
    int n=0;
    for(int i=0;i<eventos.size();i++){
        if(eventos[i].Get_status()==status){
            n+=eventos[i].Get_duracao();
        }
    }
    return n;
}

int Tabela_log::numero_carregamento_materia_prima(int materia){
    int n=0;
    for(int i=0;i<eventos.size();i++){
        if(eventos[i].Get_operacao()==materia){
            n++;
        }
    }
    return n;
}

int Tabela_log::numero_operacao_por_status(int status){
    int n=0;
    for(int i=0;i<eventos.size();i++){
        if(eventos[i].Get_status()==status){
            n++;
        }
    }
    return n;
}

int Tabela_log::numero_erro_maior_5_minutos(){
    int n=0;
    for(int i=0;i<eventos.size();i++){
        if(eventos[i].Get_status()==3 && eventos[i].Get_duracao()>5){
            n++;
        }
    }
    return n;
}

int Tabela_log::numero_carregamentos__materia_prima_manha(int materia){
    int n=0;
    for(int i=0;i<eventos.size();i++){
        if(eventos[i].Get_operacao()==materia && eventos[i].Get_hora()<=12){
            n++;
        }
    }
    return n;
}
Tabela_log::Tabela_log(){};
#endif // TABELA_LOG_H
