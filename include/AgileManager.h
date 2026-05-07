#ifndef AGILEMANAGER_H
#define AGILEMANAGER_H

#include "Quadro.h"
#include "Metricas.h"


 //Classe AgileManager
 // Atua como a interface principal (Controller) que gerencia o fluxo do aplicativo,
 //unindo a gestao das tarefas (Quadro) com a analise de dados (Metricas).
 
class AgileManager {
public:
    AgileManager();

    ~AgileManager();

    // Inicia o loop principal do programa (o menu que fica rodando ate o usuario sair)
    void executar();

private:
    Quadro* quadro;     // Ponteiro para o banco de dados das tarefas e colunas
    Metricas* metricas; // Ponteiro para o motor de analise estatistica

    // Funcoes auxiliares de Interface (Menu)
    void exibirMenu() const;        // Apenas imprime as opcoes no terminal
    void processarOpcao(int opcao); // Direciona a escolha do usuario para a funcao correta

    // Submenus de Gerenciamento de Tarefas 
    void menuCadastrarTarefa();     // Captura dados para criar nova tarefa
    void menuMoverTarefa();         // Altera a coluna de uma tarefa (ex: To Do -> Doing)
    void menuEditarTarefa();        // Modifica descricao, prioridade ou prazos
    void menuRemoverTarefa();       // Exclui uma tarefa do quadro
    void menuFiltrarTarefas();      // Busca tarefas por prioridade, membro ou data

    // Submenus de Gestao de Equipe e Analise
    void menuGerenciarMembros();    // Adiciona ou remove pessoas do projeto
    void menuVisualizarMetricas();  // Chama as funcoes da classe Metricas para exibir relatorios
};

#endif