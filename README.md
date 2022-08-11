# Relatorio Log Máquina
![GitHub repo size](https://img.shields.io/github/repo-size/Matheus-Souza-Rozendo/relatorio_log_maquina)
![GitHub](https://img.shields.io/github/license/Matheus-Souza-Rozendo/relatorio_log_maquina)
![GitHub language count](https://img.shields.io/github/languages/count/Matheus-Souza-Rozendo/relatorio_log_maquina)
![GitHub top language](https://img.shields.io/github/languages/top/Matheus-Souza-Rozendo/relatorio_log_maquina)
> Relatório do funcionamento de uma maquina a partir de um arquivo .log.

Software que fornece um relatório completo de um funcionamento de uma maquina a partir do log gerado por ela

## Formato do Log
As informações (log) são geradas no formato de linhas de texto agrupando as seguintes informações em cada linha: 

`{ longint momento, int duracao, int operacao, int status }`

- momento (dia*10000+hora*100+minuto) é o momento de início da operação, onde dia é o número do dia no ano, hora é a hora desse dia, minuto é o minuto dessa hora;

- duracao é o tempo em minutos que a operacao levou para ser concluída ou apresentar erro;

- operacao pode ser:
    
    1 - operação de carregar matéria-prima 1;

    2 - operação de carregar matéria-prima 2;

    3 - operação de carregar matéria-prima 3;

    4 - operação de processo de secagem;

    5 - operação de processo de lavagem; ou

    6 - operação de processo de tingimento;

- status pode ser:

     0 - operação bem sucedida;

     1 - sobrecarga leve;

     2 - sobrecarga com probabilidade de dano; ou

     3 - parada por erro de funcionamento;

## Funcionalidades 
O programa gera dois tipos de relatório. Um no formato .txt e o outro mostrando as informações na tela.

### Relatório em .txt
Contem as seguintes informações:
* Duração das Operações em cada Semana
* Operação que Apresentou Erro mais Rápido em cada semana
* Resumo das Operações por Semana 
* Paradas por erros em cada Semana
* Matéria-Prima mais carregada em cada Dia
* Numero de Dias que aconteceram cada status
* Status que mais ocorreram por hora do dia
* Número de Operações bem-sucedidas seguida de erro
* Número de Operações bem-sucedidas seguida de erro considerando operações diferentes 

[Veja exemplo de relatório gerado](https://github.com/Matheus-Souza-Rozendo/relatorio_log_maquina/blob/main/documenta%C3%A7%C3%A3o/relatorio.txt)

### Relatório mostrado na tela
Contem as seguintes informações:
* Maiores operações sem terminar com erro
* Total de Duração de Cada Status
* Percentual de Cada Matéria Prima Carregada na Maquina
* Percentual de Operações Bem-sucedidas em relação as demais
* Percentual de operações Bem-sucedidas em relação as mal-sucedidas
* Número de vezes que a máquina foi carregada com a matéria-prima 1 no período da manhã
* Os dois status de menor duração desconsiderando-se os erros
* Número de Erros com mais de 5 minutos

Exemplo de Relatório


         --------------------------Maiores operações sem terminar com erro ------------------------------------------
          OPERAÇÃO 1
          Data: Dia 5   as  13:12
          Operação: processo de lavagem
          Duração: 123 min
          Status: sobrecarga leve

          OPERAÇÃO 2
          Data: Dia 8   as  17:1
          Operação: carregar matéria-prima 2
          Duração: 122 min
          Status: operação bem sucedida
          
          --------------------- Total de Duração de Cada Status ---------------------------------------------------
          operação bem sucedida : 11208 min
          sobrecarga leve : 5680 min
          sobrecarga com probabilidade de dano : 4722 min
          parada por erro : 2339 min


          --------------------- Percentual de Cada Matéria Prima Carregada na Maquina ------------------------------
          Matéria-Prima 1 : 32.03%
          Matéria-Prima 2 : 32.03%
          Matéria-Prima 3 : 35.94%

         --------------------- Percentual de Operações Bem-sucedidas em relação as demais ------------------------------
          48.81%

         --------------------- Percentual de operações Bem-sucedidas em relação as mal-sucedidas ------------------------------
          600.00%

         --------------------------------------------------------------------------------------------------------------------
          a máquina foi carregada com a matéria-prima 1 no período da manhã: 19 vezes


        ---------------------- os dois status de menor duração desconsiderando-se os erros -----------------------------------
        sobrecarga com probabilidade de dano : 4722 min
        sobrecarga leve : 5680 min


        ------------------------------------------------------------------------------------------------
        Número de Erros com mais de 5 minutos: 30

## Contato

Matheus Souza Rozendo  – matheusrozendo234674@gmail.com

