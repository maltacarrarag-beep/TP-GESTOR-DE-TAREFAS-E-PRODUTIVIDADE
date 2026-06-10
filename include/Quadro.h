#ifndef QUADRO_H
#define QUADRO_H
 

#include <string>
#include <vector>
 

#include "Tarefa.h"   
#include "Coluna.h"   
#include "Membro.h"  
 
 


 
class Quadro {

    public:
 
    
    Quadro();
 
    
    ~Quadro();
 
   
    void adicionarTarefa(const std::string& titulo,
                         const std::string& descricao,
                         const std::string& prazo,
                         Prioridade         prioridade,
                         const std::string& nomeResponsavel);
 
    
    bool moverTarefa(int idTarefa, Status novoStatus);
 
    
    bool editarTarefa(int                idTarefa,
                      const std::string& novoTitulo,
                      const std::string& novaDescricao,
                      const std::string& novoPrazo,
                      Prioridade         novaPrioridade,
                      const std::string& novoResponsavel);
 
    
    bool removerTarefa(int idTarefa);
 
    
    Tarefa* buscarTarefa(int idTarefa) const;
 
    std::vector<Tarefa*> getTarefasPorMembro(const std::string& nome) const;
 

    std::vector<Tarefa*> getTarefasPorPrioridade(Prioridade p) const;
 
    std::vector<Tarefa*> getTarefasAtrasadas() const;

    std::vector<Coluna*> getColunas() const;
 
    void adicionarMembro(const std::string& nome);
 
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