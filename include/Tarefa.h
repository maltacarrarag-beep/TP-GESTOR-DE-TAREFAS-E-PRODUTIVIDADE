#ifndef TAREFA_H
#define TAREFA_H

#include <string>

/**
 * @brief Enumeração para classificar a urgência de uma Tarefa.
 */
enum class Prioridade { ALTA, MEDIA, BAIXA };

/**
 * @brief Enumeração para rastrear o progresso no Kanban.
 */
enum class Status { A_FAZER, EM_ANDAMENTO, CONCLUIDO };

/**
 * @class Tarefa
 * @brief Representa uma unidade de trabalho dentro do sistema Agile Manager.
 * * A classe encapsula os dados operacionais de uma demanda. O ciclo de vida
 * do objeto impõe que o ID seja imutável após a instanciação, operando como
 * chave primária.
 */

class Tarefa {
public:
    /**
     * @brief Construtor principal da classe Tarefa.
     * * @param id Identificador único gerado externamente (Quadro).
     * @param titulo Descrição curta da atividade.
     * @param descricao Detalhamento completo da atividade.
     * @param prazo Data limite no formato ISO 8601 (AAAA-MM-DD) para permitir comparação léxica.
     * @param prioridade Nível de urgência estipulado.
     * @param responsavel Nome do membro alocado (deve existir previamente no Quadro).
     */
    Tarefa(int id, const std::string& titulo,
           const std::string& descricao, const std::string& prazo,
           Prioridade prioridade, const std::string& responsavel);

    // Getters
    int         getId()          const;
    std::string getTitulo()      const;
    std::string getDescricao()   const;
    std::string getPrazo()       const;
    Prioridade  getPrioridade()  const;
    std::string getResponsavel() const;
    Status      getStatus()      const;

    // Setters
    void setTitulo     (const std::string& titulo);
    void setDescricao  (const std::string& descricao);
    /**
     * @brief Atualiza a data de entrega.
     * @param prazo Nova data (obrigatoriamente no formato AAAA-MM-DD).
     */
    void setPrazo      (const std::string& prazo);
    void setPrioridade (Prioridade prioridade);
    void setResponsavel(const std::string& responsavel);
    void setStatus     (Status status);

    // Utilidades
    /**
     * @brief Verifica se a data atual do sistema ultrapassou o prazo estipulado.
     * @return true se o prazo for anterior à data de hoje e o status for diferente de CONCLUIDO.
     */
    bool        estaAtrasada()       const;
    std::string prioridadeToString() const;
    std::string statusToString()     const;
    
    /**
     * @brief Formata e imprime os dados da tarefa na saída padrão de terminal.
     */
    void        exibir()             const;

private:
    int         id;             ///< Identificador numérico imutável
    std::string titulo;
    std::string descricao;
    std::string prazo;          ///< Armazenado obrigatoriamente como AAAA-MM-DD
    Prioridade  prioridade;
    std::string responsavel;
    Status      status;         ///< Inicializado como A_FAZER
};

#endif // TAREFA_H