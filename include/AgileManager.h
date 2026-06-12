#ifndef AGILEMANAGER_H
#define AGILEMANAGER_H

#include "Quadro.h"
#include "Metricas.h"

/**
 * @brief Controller principal do sistema AgileManager.
 *
 * Atua como a interface principal que gerencia o fluxo do aplicativo,
 * unindo a gestao das tarefas (Quadro) com a analise de dados (Metricas).
 * Contem o loop principal do programa e todos os submenus de interacao
 * com o usuario via terminal.
 */
class AgileManager {
public:

    /**
     * @brief Constrói o AgileManager, inicializando o Quadro e as Metricas.
     */
    AgileManager();

    /**
     * @brief Destroi o AgileManager e libera os objetos Quadro e Metricas.
     */
    ~AgileManager();

    /**
     * @brief Inicia o loop principal do programa.
     * @details Exibe o menu e processa as escolhas do usuario ate que
     *          a opcao de saida (0) seja selecionada.
     */
    void executar();

private:
    Quadro*   quadro;   ///< Ponteiro para o banco de dados das tarefas e colunas.
    Metricas* metricas; ///< Ponteiro para o motor de analise estatistica.

    /// @brief Imprime as opcoes do menu principal no terminal.
    void exibirMenu() const;

    /**
     * @brief Direciona a escolha do usuario para a funcao correspondente.
     * @param opcao Numero da opcao selecionada pelo usuario.
     */
    void processarOpcao(int opcao);

    /// @brief Captura os dados necessarios e cadastra uma nova tarefa no quadro.
    void menuCadastrarTarefa();

    /// @brief Solicita o ID e o novo status para mover uma tarefa entre colunas.
    void menuMoverTarefa();

    /// @brief Solicita o ID e os novos dados para editar uma tarefa existente.
    void menuEditarTarefa();

    /// @brief Solicita o ID e confirma a remocao de uma tarefa do quadro.
    void menuRemoverTarefa();

    /// @brief Exibe submenu para filtrar tarefas por prioridade, membro ou atraso.
    void menuFiltrarTarefas();

    /// @brief Exibe submenu para adicionar ou listar membros da equipe.
    void menuGerenciarMembros();

    /// @brief Exibe submenu com as opcoes de metricas e relatorios.
    void menuVisualizarMetricas();
};

#endif