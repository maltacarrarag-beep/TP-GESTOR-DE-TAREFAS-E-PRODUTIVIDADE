
// Quadro.h

// MÓDULO: Quadro
// DEPENDE DE: Tarefa.h, Coluna.h, Membro.h


//Adicionar ao menos um membro antes de adicionar tarefas
//Fornecer apenas IDs válidos nas operações de busca/edição/remoção
//Toda memória alocada dinamicamente será liberada no destrutor
//Nenhum ID de tarefa se repete durante a vida do objeto
 
#ifndef QUADRO_H
#define QUADRO_H
 
// Biblioteca padrão
#include <string>
#include <vector>
 
// Módulos deste projeto 
#include "Tarefa.h"   // define: Tarefa, Status, Prioridade
#include "Coluna.h"   // define: Coluna
#include "Membro.h"   // define: Membro
 
 


 
class Quadro {

    public:
 
    // Cria um quadro vazio, sem tarefas nem membros
    // Inicializa o gerador de IDs e cria as colunas padrão do Kanban
    Quadro();
 
    // (Coluna* e Membro*), o destrutor DEVE percorrer cada vetor e chamar
    // delete em cada elemento. Sem isso, ocorre memory leak
    ~Quadro();
 
    // Cria uma nova tarefa com os dados fornecidos e a insere na coluna
    // O ID da tarefa é gerado automaticamente (proximoId_)
    // PRECONDIÇÃO: nomeResponsavel deve ser o nome de um membro já cadastrado

    // constante para evitar cópias desnecessárias.
    void adicionarTarefa(const std::string& titulo,
                         const std::string& descricao,
                         const std::string& prazo,
                         Prioridade         prioridade,
                         const std::string& nomeResponsavel);
 
    // Move a tarefa de ID idTarefa para a coluna correspondente a novoStatus
    // Retorna true se a tarefa foi encontrada e movida com sucesso
    // Retorna false se idTarefa não corresponde a nenhuma tarefa existente
    bool moverTarefa(int idTarefa, Status novoStatus);
 
    // Atualiza os campos editáveis da tarefa de ID idTarefa
    // Retorna true se a tarefa foi encontrada e editada com sucesso.
    // Retorna false se idTarefa não corresponde a nenhuma tarefa existente
    //
    // PRECONDIÇÃO: novoResponsavel deve ser o nome de um membro já cadastrado
    //
    // NOTA (coesão — Cap. 11): este método recebe os novos valores como
    // parâmetros. A classe Quadro NÃO faz leitura de dados (cin); essa
    // responsabilidade pertence ao main ou à camada de interface
    bool editarTarefa(int                idTarefa,
                      const std::string& novoTitulo,
                      const std::string& novaDescricao,
                      const std::string& novoPrazo,
                      Prioridade         novaPrioridade,
                      const std::string& novoResponsavel);
 
    // Remove do quadro a tarefa de ID idTarefa, liberando sua memória
    // Retorna true se encontrada e removida, false caso contrário
    bool removerTarefa(int idTarefa);
 
    // Retorna um ponteiro para a tarefa de ID idTarefa
    // Retorna nullptr se não houver tarefa com esse ID

    // 'const' no final não modifica o estado do Quadro
    Tarefa* buscarTarefa(int idTarefa) const;
 
    // Retorna um vetor com ponteiros para todas as tarefas atribuídas ao membro cujo nome é 'nome'. Retorna vetor vazio se não houver nenhuma.
    std::vector<Tarefa*> getTarefasPorMembro(const std::string& nome) const;
 
    // Retorna um vetor com ponteiros para todas as tarefas com prioridade p.
    std::vector<Tarefa*> getTarefasPorPrioridade(Prioridade p) const;
 
    // Retorna um vetor com ponteiros para as tarefas cujo prazo já passou e que ainda não foram concluídas (status != CONCLUIDO)
    std::vector<Tarefa*> getTarefasAtrasadas() const;
 
    // Cria um novo Membro com o nome fornecido e o adiciona ao quadro
    // PRECONDIÇÃO: não deve existir membro com o mesmo nome
    void adicionarMembro(const std::string& nome);
 
    // Retorna um ponteiro para o membro de nome 'nome'
    // Retorna nullptr se não houver membro com esse nome
    Membro* buscarMembro(const std::string& nome) const;
 
    std::vector<Membro*> getMembros() const;
 
    void exibir() const;

 
    private:
  
    std::vector<Coluna*> colunas_;
 
    std::vector<Membro*> membros_;
 
    int proximoId_;

    Coluna* buscarColuna(Status status) const;
};
 
#endif 