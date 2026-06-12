#ifndef TAREFA_H
#define TAREFA_H

#include <string>

/// @brief Representa a prioridade de uma tarefa.
enum class Prioridade { ALTA, MEDIA, BAIXA };

/// @brief Representa o status atual de uma tarefa no quadro Kanban.
enum class Status { A_FAZER, EM_ANDAMENTO, CONCLUIDO };

/**
 * @brief Entidade principal do sistema. Representa uma tarefa do quadro Kanban.
 *
 * Armazena todas as informacoes de uma tarefa: titulo, descricao, prazo,
 * prioridade, responsavel e status. Possui validacao defensiva no construtor
 * e nos setters para garantir a integridade dos dados.
 */
class Tarefa {
public:

    /**
     * @brief Constrói uma nova tarefa com os dados fornecidos.
     * @param id Identificador unico da tarefa.
     * @param titulo Titulo da tarefa (nao pode ser vazio).
     * @param descricao Descricao detalhada da tarefa.
     * @param prazo Prazo no formato AAAA-MM-DD.
     * @param prioridade Nivel de prioridade (ALTA, MEDIA ou BAIXA).
     * @param responsavel Nome do membro responsavel (nao pode ser vazio).
     * @throws std::invalid_argument Se titulo, responsavel ou prazo forem invalidos.
     */
    Tarefa(int id, const std::string& titulo,
           const std::string& descricao, const std::string& prazo,
           Prioridade prioridade, const std::string& responsavel);

    /// @brief Retorna o ID unico da tarefa.
    int         getId()          const;

    /// @brief Retorna o titulo da tarefa.
    std::string getTitulo()      const;

    /// @brief Retorna a descricao da tarefa.
    std::string getDescricao()   const;

    /// @brief Retorna o prazo da tarefa no formato AAAA-MM-DD.
    std::string getPrazo()       const;

    /// @brief Retorna a prioridade da tarefa.
    Prioridade  getPrioridade()  const;

    /// @brief Retorna o nome do responsavel pela tarefa.
    std::string getResponsavel() const;

    /// @brief Retorna o status atual da tarefa.
    Status      getStatus()      const;

    /**
     * @brief Define um novo titulo para a tarefa.
     * @param titulo Novo titulo (nao pode ser vazio).
     * @throws std::invalid_argument Se o titulo for vazio.
     */
    void setTitulo     (const std::string& titulo);

    /// @brief Define uma nova descricao para a tarefa.
    void setDescricao  (const std::string& descricao);

    /**
     * @brief Define um novo prazo para a tarefa.
     * @param prazo Novo prazo no formato AAAA-MM-DD.
     * @throws std::invalid_argument Se o formato for invalido.
     */
    void setPrazo      (const std::string& prazo);

    /// @brief Define uma nova prioridade para a tarefa.
    void setPrioridade (Prioridade prioridade);

    /**
     * @brief Define um novo responsavel para a tarefa.
     * @param responsavel Nome do novo responsavel (nao pode ser vazio).
     * @throws std::invalid_argument Se o nome for vazio.
     */
    void setResponsavel(const std::string& responsavel);

    /// @brief Define um novo status para a tarefa.
    void setStatus     (Status status);

    /**
     * @brief Verifica se a tarefa esta atrasada.
     * @details Compara o prazo com a data atual usando comparacao lexicografica
     *          no formato ISO 8601. Tarefas concluidas nunca sao consideradas atrasadas.
     * @return true se o prazo ja passou e a tarefa nao esta concluida.
     */
    bool        estaAtrasada()       const;

    /// @brief Converte a prioridade para string legivel (ex: "Alta").
    std::string prioridadeToString() const;

    /// @brief Converte o status para string legivel (ex: "Em Andamento").
    std::string statusToString()     const;

    /// @brief Exibe os dados completos da tarefa no terminal.
    void        exibir()             const;

private:
    int         id;
    std::string titulo;
    std::string descricao;
    std::string prazo;          ///< Formato AAAA-MM-DD
    Prioridade  prioridade;
    std::string responsavel;
    Status      status;
};

#endif // TAREFA_H