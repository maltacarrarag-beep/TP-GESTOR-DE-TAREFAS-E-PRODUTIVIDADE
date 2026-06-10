#include "Coluna.h"
#include <iostream>
 
// Construtor: inicializa a coluna com um nome e vetor vazio de tarefas
Coluna::Coluna(const std::string& nome)
    : nome(nome) {}
 
// Retorna o nome da coluna (ex: "A Fazer", "Em Andamento", "Concluido")
std::string Coluna::getNome() const {
    return nome;
}
 
// Retorna a quantidade de tarefas presentes na coluna
int Coluna::getQuantidade() const {
    return static_cast<int>(tarefas.size());
}
 
// Adiciona um ponteiro de tarefa ao final do vetor
void Coluna::adicionarTarefa(Tarefa* tarefa) {
    if (tarefa != nullptr) {
        tarefas.push_back(tarefa);
    }
}
 
// Remove a tarefa com o id informado do vetor (NÃO deleta o objeto)
// Retorna true se encontrou e removeu, false caso contrário
bool Coluna::removerTarefa(int idTarefa) {
    for (auto it = tarefas.begin(); it != tarefas.end(); ++it) {
        if ((*it)->getId() == idTarefa) {
            tarefas.erase(it);
            return true;
        }
    }
    return false;
}
 
// Busca e retorna o ponteiro da tarefa com o id informado
// Retorna nullptr se não encontrar
Tarefa* Coluna::buscarTarefa(int idTarefa) const {
    for (Tarefa* t : tarefas) {
        if (t->getId() == idTarefa) {
            return t;
        }
    }
    return nullptr;
}
 
// Retorna uma cópia do vetor com todos os ponteiros de tarefas da coluna
std::vector<Tarefa*> Coluna::getTarefas() const {
    return tarefas;
}
 
// Retorna apenas as tarefas que estão atrasadas (delega para Tarefa::estaAtrasada)
std::vector<Tarefa*> Coluna::getTarefasAtrasadas() const {
    std::vector<Tarefa*> atrasadas;
    for (Tarefa* t : tarefas) {
        if (t->estaAtrasada()) {
            atrasadas.push_back(t);
        }
    }
    return atrasadas;
}
 
// Exibe o cabeçalho da coluna e delega a exibição para cada tarefa
void Coluna::exibir() const {
    std::cout << "\n----------------------------------\n";
    std::cout << "  " << nome << "\n";
    std::cout << "  Tarefas: " << tarefas.size() << "\n";
    std::cout << "----------------------------------\n";
 
    if (tarefas.empty()) {
        std::cout << "  (nenhuma tarefa nesta coluna)\n";
    } else {
        for (Tarefa* t : tarefas) {
            t->exibir();
        }
    }
}