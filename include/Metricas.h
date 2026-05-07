#ifndef METRICAS_H // Proteção contra inclusão duplicada (Header Guard)
#define METRICAS_H

#include "Quadro.h"


  //Classe Metricas
 // Responsavel por gerar analises estatisticas e relatorios sobre o estado do Quadro.

class Metricas {
public:
    // Construtor: Recebe um ponteiro para o Quadro que sera analisado
    Metricas(Quadro* quadro);

    // Calcula e mostra quantas tarefas ou pontos de esforco cada membro da equipe possui
    void exibirCargaPorMembro() const;

    // Lista todas as tarefas que passaram do prazo (deadline) definido
    void exibirTarefasAtrasadas() const;

    // Mostra o total de tarefas em cada coluna (ex: To Do, Doing, Done) para medir o fluxo
    void exibirDistribuicaoPorColuna() const;

    // Identifica membros que possuem mais tarefas do que um limite definido
    void exibirMembrosSobrecarregados() const;

    // Consolida todas as metricas acima em um unico relatorio geral no console
    void exibirRelatorioCompleto() const;

private:
    Quadro* quadro; // Ponteiro para o objeto Quadro que contem os dados a serem processados
};

#endif 