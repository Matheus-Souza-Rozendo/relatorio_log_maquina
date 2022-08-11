#ifndef ARQUIVO_TXT_DE_ENTRADA_LOG_H
#define ARQUIVO_TXT_DE_ENTRADA_LOG_H
#include <bits/stdc++.h>
#include "Arquivo_TXT_de_Entrada.h"
#include "Evento.h"

using namespace std;

class Arquivo_TXT_de_Entrada_log : protected Arquivo_TXT_de_Entrada
{
    public:
        Arquivo_TXT_de_Entrada_log();
        bool Set_arquivo_log(string c);
        vector <Evento> Get_eventos();
};

Arquivo_TXT_de_Entrada_log::Arquivo_TXT_de_Entrada_log(){};

bool Arquivo_TXT_de_Entrada_log::Set_arquivo_log(string c){
    return Set_arquivo(c);
}

vector <Evento> Arquivo_TXT_de_Entrada_log::Get_eventos(){
    FILE *aux = Get_arquivo();
    vector <Evento> eventos;
    int momento,duracao,status,operacao;
    fscanf(aux,"%i,%i,%i,%i",&momento,&duracao,&operacao,&status);
    while(!feof(aux)){
        Evento E;
        E.Set_evento(momento,duracao,operacao,status);
        eventos.push_back(E);
        fscanf(aux,"%i,%i,%i,%i",&momento,&duracao,&operacao,&status);
    }
    fclose(aux);
    return eventos;
}



#endif // ARQUIVO_TXT_DE_ENTRADA_LOG_H
