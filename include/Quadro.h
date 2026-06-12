#ifndef QUADRO_H
#define QUADRO_H

#include <string>
#include <vector>
#include "Tarefa.h"
#include "Coluna.h"
#include "Membro.h"

/**
 * @brief Banco de dados central do sistema Kanban.
 *
 * Gerencia todas as colunas, tarefas e membros do projeto.
 * E responsavel pela criacao, edicao, remocao e movimentacao de tarefas,
 * alem do controle de carga dos membros. Detem a propriedade (ownership)
 * de todos os objetos Coluna, Tarefa e Membro — libera a memoria no destrutor.
 */
class Quadro {
public:

    /**
     * @brief Constrói o quadro e inicializa as tres colunas padrao.
     * @details Cria automaticamente as colunas "A Fazer", "Em Andamento" e "Concluido".
     */
    Quadro();

    /// @brief Destroi o quadro e libera toda a memoria alocada (colunas, tarefas e membros).
    ~Quadro();

    /**
     * @brief Cadastra uma nova tarefa no quadro, inserindo-a na coluna "A Fazer".
     * @param titulo Titulo da tarefa.
     * @param descricao Descricao da tarefa.
     * @param prazo Prazo no formato AAAA-MM-DD.
     * @param prioridade Nivel de prioridade da tarefa.
     * @param nomeResponsavel Nome do membro responsavel (deve existir no quadro).
     */
    void adicionarTarefa(const std::string& titulo,
                         const std::string& descricao,
                         const std::string& prazo,
                         Prioridade         prioridade,
                         const std::string& nomeResponsavel);

    /**
     * @brief Move uma tarefa para uma nova coluna conforme o status informado.
     * @param idTarefa ID da tarefa a ser movida.
     * @param novoStatus Novo status (A_FAZER, EM_ANDAMENTO ou CONCLUIDO).
     * @return true se a tarefa foi encontrada e movida com sucesso.
     */
    bool moverTarefa(int idTarefa, Status novoStatus);

    /**
     * @brief Edita os dados de uma tarefa existente.
     * @param idTarefa ID da tarefa a ser editada.
     * @param novoTitulo Novo titulo.
     * @param novaDescricao Nova descricao.
     * @param novoPrazo Novo prazo no formato AAAA-MM-DD.
     * @param novaPrioridade Nova prioridade.
     * @param novoResponsavel Nome do novo responsavel (deve existir no quadro).
     * @return true se a edicao foi realizada com sucesso.
     */
    bool editarTarefa(int                idTarefa,
                      const std::string& novoTitulo,
                      const std::string& novaDescricao,
                      const std::string& novoPrazo,
                      Prioridade         novaPrioridade,
                      const std::string& novoResponsavel);

    /**
     * @brief Remove e deleta uma tarefa do quadro.
     * @param idTarefa ID da tarefa a ser removida.
     * @return true se a tarefa foi encontrada e removida.
     */
    bool removerTarefa(int idTarefa);

    /**
     * @brief Busca uma tarefa em todas as colunas pelo ID.
     * @param idTarefa ID da tarefa.
     * @return Ponteiro para a tarefa, ou nullptr se nao encontrada.
     */
    Tarefa* buscarTarefa(int idTarefa) const;

    /**
     * @brief Retorna todas as tarefas atribuidas a um membro.
     * @param nome Nome do membro.
     * @return Vetor de ponteiros para as tarefas do membro.
     */
    std::vector<Tarefa*> getTarefasPorMembro(const std::string& nome) const;

    /**
     * @brief Retorna todas as tarefas com a prioridade informada.
     * @param p Prioridade desejada.
     * @return Vetor de ponteiros para as tarefas filtradas.
     */
    std::vector<Tarefa*> getTarefasPorPrioridade(Prioridade p) const;

    /**
     * @brief Retorna todas as tarefas atrasadas do quadro.
     * @return Vetor de ponteiros para tarefas com prazo vencido.
     */
    std::vector<Tarefa*> getTarefasAtrasadas() const;

    /// @brief Retorna todas as colunas do quadro.
    std::vector<Coluna*> getColunas() const;

    /**
     * @brief Adiciona um novo membro ao quadro.
     * @param nome Nome do membro (deve ser unico).
     */
    void adicionarMembro(const std::string& nome);

    /**
     * @brief Busca um membro pelo nome.
     * @param nome Nome do membro.
     * @return Ponteiro para o membro, ou nullptr se nao encontrado.
     */
    Membro* buscarMembro(const std::string& nome) const;

    /// @brief Retorna todos os membros cadastrados no quadro.
    std::vector<Membro*> getMembros() const;

    /// @brief Exibe o quadro completo com todas as colunas e membros no terminal.
    void exibir() const;

private:
    std::vector<Coluna*> colunas_;  ///< Colunas do quadro Kanban.
    std::vector<Membro*> membros_;  ///< Membros da equipe.
    int proximoId_;                 ///< Contador para gerar IDs unicos de tarefas.

    /**
     * @brief Retorna a coluna correspondente ao status informado.
     * @param status Status desejado.
     * @return Ponteiro para a coluna, ou nullptr se status invalido.
     */
    Coluna* buscarColuna(Status status) const;
};

#endif