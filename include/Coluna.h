#ifndef COLUNA_H
#define COLUNA_H

#include <string>
#include <vector>
#include "Tarefa.h"

class Coluna {
public:
    Coluna(const std::string& nome);

    std::string getNome() const;
    int getQuantidade() const;

    void adicionarTarefa(Tarefa* tarefa);
    bool removerTarefa  (int idTarefa);
    Tarefa* buscarTarefa (int idTarefa) const;

    std::vector<Tarefa*> getTarefas() const;
    std::vector<Tarefa*> getTarefasAtrasadas() const;

    void exibir() const;

private:
    std::string nome;
    std::vector<Tarefa*> tarefas;
};

#endif // COLUNA_H