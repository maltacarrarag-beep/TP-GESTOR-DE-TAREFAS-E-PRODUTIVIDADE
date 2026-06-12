#ifndef COLUNA_H
#define COLUNA_H

#include <string>
#include <vector>
#include "Tarefa.h"

/**
 * @brief Representa uma coluna do quadro Kanban.
 *
 * Cada coluna agrupa tarefas de um mesmo status (ex: "A Fazer", "Em Andamento",
 * "Concluido"). Nao gerencia a memoria das tarefas — apenas armazena ponteiros.
 * A responsabilidade de deletar as tarefas e do Quadro.
 */
class Coluna {
public:

    /**
     * @brief Constrói uma coluna com o nome fornecido.
     * @param nome Nome da coluna (ex: "A Fazer").
     */
    Coluna(const std::string& nome);

    /// @brief Retorna o nome da coluna.
    std::string getNome() const;

    /// @brief Retorna a quantidade de tarefas na coluna.
    int getQuantidade() const;

    /**
     * @brief Adiciona uma tarefa à coluna.
     * @param tarefa Ponteiro para a tarefa a ser adicionada. Ignorado se nulo.
     */
    void adicionarTarefa(Tarefa* tarefa);

    /**
     * @brief Remove a tarefa com o ID fornecido da coluna.
     * @details Nao deleta o objeto — apenas remove o ponteiro do vetor.
     * @param idTarefa ID da tarefa a ser removida.
     * @return true se a tarefa foi encontrada e removida, false caso contrario.
     */
    bool removerTarefa(int idTarefa);

    /**
     * @brief Busca uma tarefa pelo ID.
     * @param idTarefa ID da tarefa a ser buscada.
     * @return Ponteiro para a tarefa, ou nullptr se nao encontrada.
     */
    Tarefa* buscarTarefa(int idTarefa) const;

    /// @brief Retorna uma copia do vetor com todas as tarefas da coluna.
    std::vector<Tarefa*> getTarefas() const;

    /**
     * @brief Retorna apenas as tarefas atrasadas da coluna.
     * @return Vetor com ponteiros para tarefas cujo prazo ja passou.
     */
    std::vector<Tarefa*> getTarefasAtrasadas() const;

    /// @brief Exibe o cabecalho da coluna e todas as suas tarefas no terminal.
    void exibir() const;

private:
    std::string nome;               ///< Nome da coluna.
    std::vector<Tarefa*> tarefas;   ///< Ponteiros para as tarefas desta coluna.
};

#endif // COLUNA_H