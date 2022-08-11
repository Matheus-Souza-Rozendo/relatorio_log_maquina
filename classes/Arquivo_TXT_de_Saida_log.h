#ifndef ARQUIVO_TXT_DE_SAIDA_LOG_H
#define ARQUIVO_TXT_DE_SAIDA_LOG_H
#include <bits/stdc++.h>
#include "Arquivo_TXT_de_Saida.h"
#include "Evento.h"

using namespace std;

class Arquivo_TXT_de_Saida_log : protected Arquivo_TXT_de_Saida
{
    public:
        Arquivo_TXT_de_Saida_log();
        void gerar_relatorio(vector <Evento> events);
        bool Set_arquivo_saida_log(string n, string p);
    private:
        string nomes_operacao[7]={"","carregar matéria-prima 1","carregar matéria-prima 2","carregar matéria-prima 3","processo de secagem","processo de lavagem","processo de tingimento"};
        vector <Evento> eventos;
        string nome_status[4]={"operação bem sucedida","sobrecarga leve","sobrecarga com probabilidade de dano","parada por erro"};
        void total_duracao_operacao_por_semana(ofstream *aux);
        void menor_erro(ofstream *aux);
        void resumo_operacoes_por_semana(ofstream *aux);
        void paradas_por_semana(ofstream *aux);
        void materia_mais_carregada_por_dia(ofstream *aux);
        void dias_aconteceu_status(ofstream *aux);
        void status_hora_do_dia(ofstream *aux);
        void sucesso_depois_erro(ofstream *aux);
        void sucesso_depois_erro_operacao_diferente(ofstream *aux);
};

bool Arquivo_TXT_de_Saida_log::Set_arquivo_saida_log(string n,string p){
    return cria_arquivo(n,p,".txt");
}

void Arquivo_TXT_de_Saida_log::gerar_relatorio(vector <Evento> events){
    eventos=events;
    ofstream *aux = Get_arquivo();
    *aux << " ------- Duração das Operações por Semana ------------- \n";
    total_duracao_operacao_por_semana(aux);
    *aux << " ------- Operação que Apresentou Erro mais Rápido ------------- \n";
    menor_erro(aux);
    *aux << " ------- Resumo das Operações por Semana ------------- \n formato usado: semana, oper, status, soma; \n";
    resumo_operacoes_por_semana(aux);
    *aux << " ------- Paradas por Semana ------------- \n";
    paradas_por_semana(aux);
    *aux << " ------- Matéria-Prima mais carregada em cada Dia ------------- \n";
    materia_mais_carregada_por_dia(aux);
    *aux << "\n ------- Numero de Dias que aconteceram cada status ------------- \n";
    dias_aconteceu_status(aux);
    *aux << " ------- Status que mais ocorreram por hora do dia ------------- \n";
    status_hora_do_dia(aux);
    *aux << "\n ------- Operação bem-sucedida seguida de erro ------------- \n";
    sucesso_depois_erro(aux);
    *aux << "\n ------- Operação bem-sucedida seguida de erro considerando operações diferentes ------------- \n";
    sucesso_depois_erro_operacao_diferente(aux);
    aux->close();
}

void Arquivo_TXT_de_Saida_log::total_duracao_operacao_por_semana(ofstream *aux){
    int semana=1;
    int i=0;
    while(i<eventos.size()){
        int duracao_total[7] = {0,0,0,0,0,0,0};
        while(eventos[i].Get_dia() < 7*semana && i<eventos.size()){
            duracao_total[eventos[i].Get_operacao()]+=eventos[i].Get_duracao();
            i++;
        }
        *aux << "Semana " << semana << endl;
        for(int j=1;j<7;j++){
            *aux << nomes_operacao[j] << " : " << duracao_total[j] << " min" << endl;
        }
        *aux << endl;
        semana++;
    }
}

void Arquivo_TXT_de_Saida_log::menor_erro(ofstream *aux){
    int semana=1;
    int i=0;
    while(i<eventos.size()){
        int menor=-1;
        int op;
        while(eventos[i].Get_dia() < 7*semana && i<eventos.size()){
            if(menor==-1 && eventos[i].Get_status()==3){
                menor = eventos[i].Get_duracao();
                op = eventos[i].Get_operacao();
            }
            if(eventos[i].Get_duracao()<menor && eventos[i].Get_status()==3){
                menor = eventos[i].Get_duracao();
                op = eventos[i].Get_operacao();
            }
            i++;
        }
        *aux << "Semana " << semana << endl;
        *aux << "Menor duração da parada por erro - " << nomes_operacao[op]  << " : " << menor << " min \n\n";
        semana++;
    }
}

void Arquivo_TXT_de_Saida_log::resumo_operacoes_por_semana(ofstream *aux){
    int semana=1;
    int i=0;

    while(i<eventos.size()){
        int tabela_duracao[7][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}}; //armazena a soma da duração da compinação da operaçao (linha) com o status (coluna)
        while(eventos[i].Get_dia() < 7*semana && i<eventos.size()){
            tabela_duracao[eventos[i].Get_operacao()][eventos[i].Get_status()]=eventos[i].Get_duracao();
            i++;
        }
        for(int j=1;j<7;j++){
            for(int k=0;k<4;k++){
                *aux << semana << "," << j <<"," << k << "," << tabela_duracao[j][k] << endl;
            }
        }
        semana++;
    }
}

void Arquivo_TXT_de_Saida_log::paradas_por_semana(ofstream *aux){
    int semana=1;
    int i=0;
    while(i<eventos.size()){
        int soma=0;
        while(eventos[i].Get_dia() < 7*semana && i<eventos.size()){
            if(eventos[i].Get_status()==3){
                soma++;
            }
            i++;
        }
        *aux << "Semana " << semana << endl;
        *aux <<"Paradas: " << soma << endl << endl;
        semana++;
    }
}

void Arquivo_TXT_de_Saida_log::materia_mais_carregada_por_dia(ofstream *aux){
    int i=0;
    int dia=1;
    while(i<eventos.size()){
        int op[4]={0,0,0,0};
        while(eventos[i].Get_dia() <= dia && i<eventos.size()){
            if(eventos[i].Get_operacao()<=3){
                op[eventos[i].Get_operacao()]++;
            }
            i++;
        }
        int maior = op[1];
        int k=1;
        for(int j=1;j<4;j++){
            if(op[j]>maior){
                maior = op[j];
                k=j;
            }
        }
        *aux << "Dia" << dia <<" : materia prima " << k << endl;
        dia++;
    }
}

void Arquivo_TXT_de_Saida_log::dias_aconteceu_status(ofstream *aux){
    int i=0;
    int dias_ocorrencias[4]={0,0,0,0};
    int dia=1;
    while(i<eventos.size()){
        bool ocorreu[4]={false,false,false,false};
        while(eventos[i].Get_dia() <= dia && i<eventos.size()){
            ocorreu[eventos[i].Get_status()]=true;
            i++;
        }
        for(int j=0;j<4;j++){
            if(ocorreu[j]){
                dias_ocorrencias[j]++;
            }
        }
        dia++;
    }
    *aux << "operação bem sucedida: " << dias_ocorrencias[0] << " dias" << endl;
    *aux << "sobrecarga leve: " << dias_ocorrencias[1] << " dias" << endl;
    *aux << "sobrecarga com probabilidade de dano: " << dias_ocorrencias[2] << " dias" << endl;
    *aux << " parada por erro: " << dias_ocorrencias[3] << " dias" << endl << endl;
}

void Arquivo_TXT_de_Saida_log::status_hora_do_dia(ofstream *aux){
    int tabela[24][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    int i=0;
    while(i<eventos.size()){
        tabela[eventos[i].Get_hora()][eventos[i].Get_status()]++;
        i++;
    }
    for(i=0;i<24;i++){
        int maior = tabela[i][0];
        int k=0;
        for(int j=0;j<4;j++){
            if(tabela[i][j]>maior){
                k=j;
                maior = tabela[i][j];
            }
        }
        *aux << i  << " horas: " << nome_status[k] << endl;
    }
}

void Arquivo_TXT_de_Saida_log::sucesso_depois_erro(ofstream *aux){
    int n=0;
    for(int i=0;i<eventos.size()-1;i++){
        if(eventos[i].Get_status()==0 && eventos[i+1].Get_status()==3){
            n++;
        }
    }
    *aux << "n° : " << n << endl;
}

void Arquivo_TXT_de_Saida_log::sucesso_depois_erro_operacao_diferente(ofstream *aux){
    int n=0;
    for(int i=0;i<eventos.size()-1;i++){
        if(eventos[i].Get_status()==0 && eventos[i+1].Get_status()==3 && eventos[i].Get_operacao()!=eventos[i+1].Get_operacao()){
            n++;
        }
    }
    *aux << "n° : " << n << endl;
}

Arquivo_TXT_de_Saida_log::Arquivo_TXT_de_Saida_log(){};


#endif // ARQUIVO_TXT_DE_SAIDA_LOG_H
