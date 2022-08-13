#include <bits/stdc++.h>
#include "classes/Arquivo_TXT_de_Entrada_log.h"
#include "classes/Arquivo_TXT_de_Saida_log.h"
#include "classes/Tabela_log.h"
#include "classes/Evento.h"
#include "classes/leitura_dados.h"

#define numero_de_materias_primas 3
#define numero_de_status 4

using namespace std;

void gerar_relatorio(Arquivo_TXT_de_Entrada_log E){
    Arquivo_TXT_de_Saida_log S;
    if(S.Set_arquivo_saida_log("relatorio","relatorios")){
        S.gerar_relatorio(E.Get_eventos());
        cout << "Relatório Gerado com Sucesso\n";
    }else{
        cout << "Falha ao criar o Arquivo\n";
    }

}

void mostrar_informacoes(Arquivo_TXT_de_Entrada_log E){
    cout << fixed << setprecision(2);
    string nomes_operacao[7]={"","carregar matéria-prima 1","carregar matéria-prima 2","carregar matéria-prima 3","processo de secagem","processo de lavagem","processo de tingimento"};
    string nome_status[4]={"operação bem sucedida","sobrecarga leve","sobrecarga com probabilidade de dano","parada por erro"};
    Tabela_log tabela;
    tabela.Set_tabela_log(E.Get_eventos());
    vector <Evento> maiores;
    maiores = tabela.operacoes_sem_erro();
    cout<< "\n\n --------------------------Maiores operações sem terminar com erro ------------------------------------------\n";
    for(int i=0;i<maiores.size();i++){
        cout << "OPERAÇÃO " << i+1 << endl;
        cout << "Data: Dia "<< maiores[i].Get_dia() << "   as  " << maiores[i].Get_hora() << ":" << maiores[i].Get_minuto() << endl;
        cout << "Operação: " << nomes_operacao[maiores[i].Get_operacao()] << endl;
        cout << "Duração: " << maiores[i].Get_duracao() << " min\n";
        cout << "Status: " << nome_status[maiores[i].Get_status()] << endl << endl;
    }
    cout <<"\n\n --------------------- Total de Duração de Cada Status ---------------------------------------------------\n";
    for(int i=0;i<numero_de_status;i++){
        cout << nome_status[i] << " : " << tabela.duracao_por_status(i) <<" min" << endl;
    }
    cout <<"\n\n --------------------- Percentual de Cada Matéria Prima Carregada na Maquina ------------------------------\n";
    for(int i=1;i<=numero_de_materias_primas;i++){
        float percentual = tabela.numero_carregamento_materia_prima(i)/float(tabela.numero_carregamento_materia_prima(1)+tabela.numero_carregamento_materia_prima(2)+tabela.numero_carregamento_materia_prima(3));
        cout << "Matéria-Prima " << i << " : " << percentual*100 << "%" << endl;
    }
    cout <<"\n\n --------------------- Percentual de Operações Bem-sucedidas em relação as demais ------------------------------\n";
    float percentual = tabela.numero_operacao_por_status(0)/float(tabela.numero_operacao_por_status(0)+tabela.numero_operacao_por_status(1)+tabela.numero_operacao_por_status(2)+tabela.numero_operacao_por_status(3));
    cout << percentual*100 << '%' << endl;
    cout <<"\n\n --------------------- Percentual de operações Bem-sucedidas em relação as mal-sucedidas ------------------------------\n";
    percentual=tabela.numero_operacao_por_status(0)/tabela.numero_operacao_por_status(3);
    percentual=percentual*100;
    cout<<percentual << '%' << endl;
    cout << "\n\n --------------------------------------------------------------------------------------------------------------------\n";
    cout << "a máquina foi carregada com a matéria-prima 1 no período da manhã: " << tabela.numero_carregamentos__materia_prima_manha(1) << " vezes\n";
    cout <<"\n\n ---------------------- os dois status de menor duração desconsiderando-se os erros -----------------------------------\n";
    vector <vector<int>> matriz = cria_matriz(3,2);
    for(int i=0;i<numero_de_status-1;i++){
        matriz[i][0]=i;
        matriz[i][1]=tabela.duracao_por_status(i);
    }
    matriz=ordenar_matriz_ordem_crescente<vector<vector<int>>>(matriz,1);
    for(int i=0;i<2;i++){
        cout << nome_status[matriz[i][0] << " : " <<  matriz[i][1] <<" min" << endl;
    }
    cout <<"\n\n ------------------------------------------------------------------------------------------------\n";
    cout << "Número de Erros com mais de 5 minutos: " << tabela.numero_erro_maior_5_minutos() << endl;
}

int main(){
    setlocale(LC_ALL, "ptb");
    string op;
    troca_caminho:
    system("cls");
    Arquivo_TXT_de_Entrada_log E;
    string caminho;
    cout <<"\nDigite o caminho para o arquivo .log\ncaminho: ";
    cin >> caminho;
    if(E.Set_arquivo_log(caminho)){
        inicio:
        system("cls");
        cout << "Digite 1 para Gerar um Relatório\n";
        cout << "Digite 2 para Mostrar Informações\n";
        cout <<"opção: ";
        cin >> op;
        if(op=="1"){
            gerar_relatorio(E);
            cout << endl << endl;
            system("pause");
        }else{
            if(op=="2"){
                mostrar_informacoes(E);
                cout << endl << endl;
                system("pause");
            }else{
                cout << "Opção Invalida" << endl;
                system("pause");
            }
        }
        cout << "\n\n\nDigite 1 para Sair\n";
        cout <<"Digite 2 para trocar o arquivo de log\n";
        cout << "Digite qualquer outra tecla para voltar ao menu principal\n";
        cout <<"opção: ";
        cin >> op;
        if(op=="2"){
            goto troca_caminho;
        }else{
            if(op!="1"){
                goto inicio;
            }
        }
    }else{
        cout << "Arquivo não encontrado\n";
        cout << "\n\n\nDigite 1 para Sair\nDigite qualquer tecla para continuar\nop: ";
        cin >> op;
        if(op!="1"){
            goto troca_caminho;
        }
    }
    return 0;
}
