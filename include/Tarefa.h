#ifndef TAREFA_H
#define TAREFA_H

#include <string>

enum class Prioridade { ALTA, MEDIA, BAIXA };
enum class Status { A_FAZER, EM_ANDAMENTO, CONCLUIDO };

class Tarefa {
public:

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
    void setPrazo      (const std::string& prazo);
    void setPrioridade (Prioridade prioridade);
    void setResponsavel(const std::string& responsavel);
    void setStatus     (Status status);

    // Métodos de utilidade 
    bool        estaAtrasada()       const; 
    std::string prioridadeToString() const;
    std::string statusToString()     const;
    void        exibir()             const;

private:
    int         id;             
    std::string titulo;
    std::string descricao;
    std::string prazo;          // Formato AAAA-MM-DD
    Prioridade  prioridade;
    std::string responsavel;
    Status      status;         
};

#endif // TAREFA_H