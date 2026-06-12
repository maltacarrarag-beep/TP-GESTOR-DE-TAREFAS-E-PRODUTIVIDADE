#ifndef METRICAS_H
#define METRICAS_H

#include "Quadro.h"

/**
 * @brief Motor de analise estatistica do quadro Kanban.
 *
 * Responsavel por gerar relatorios e metricas sobre o estado atual do Quadro.
 * Nao modifica nenhum dado — apenas le e processa as informacoes existentes.
 */
class Metricas {
public:

    /**
     * @brief Constrói o objeto Metricas vinculado a um Quadro.
     * @param quadro Ponteiro para o quadro que sera analisado.
     */
    Metricas(Quadro* quadro);

    /**
     * @brief Exibe a carga de trabalho de cada membro da equipe.
     * @details Mostra o numero de tarefas e a carga atual de cada membro,
     *          sinalizando os que estao sobrecarregados.
     */
    void exibirCargaPorMembro() const;

    /**
     * @brief Lista todas as tarefas que ultrapassaram o prazo definido.
     * @details Tarefas com status CONCLUIDO nao sao incluidas no relatorio.
     */
    void exibirTarefasAtrasadas() const;

    /**
     * @brief Exibe a distribuicao de tarefas por coluna com barra de progresso.
     * @details Mostra o total de tarefas em cada coluna de forma proporcional.
     */
    void exibirDistribuicaoPorColuna() const;

    /**
     * @brief Lista os membros que ultrapassaram o limite de carga.
     * @see Membro::estaSobrecarregado()
     */
    void exibirMembrosSobrecarregados() const;

    /**
     * @brief Gera um relatorio completo consolidando todas as metricas.
     * @details Chama em sequencia: exibirDistribuicaoPorColuna,
     *          exibirCargaPorMembro, exibirMembrosSobrecarregados
     *          e exibirTarefasAtrasadas.
     */
    void exibirRelatorioCompleto() const;

private:
    Quadro* quadro; ///< Ponteiro para o quadro que contem os dados analisados.
};

#endif