#include "Quadro.h"
#include <iostream>

using namespace std;


// Construtor e Destrutor
Quadro::Quadro() {
    proximoId_ = 1;


    colunas_.push_back(new Coluna("A Fazer"));
    colunas_.push_back(new Coluna("Em Andamento"));
    colunas_.push_back(new Coluna("Concluido"));
}

Quadro::~Quadro() {
    
    for (Coluna* c : colunas_) {
        delete c;
    }

    
    for (Membro* m : membros_) {
        delete m;
    }
}



// Método auxiliar privado
Coluna* Quadro::buscarColuna(Status status) const {
    switch (status) {
        case Status::A_FAZER:       return colunas_[0];
        case Status::EM_ANDAMENTO:  return colunas_[1];
        case Status::CONCLUIDO:     return colunas_[2];
        default:                    return nullptr;
    }
}


// Gestão de tarefas

void Quadro::adicionarTarefa(const string& titulo,
                             const string& descricao,
                             const string& prazo,
                             Prioridade    prioridade,
                             const string& nomeResponsavel) {

    Membro* membro = buscarMembro(nomeResponsavel);
    if (membro == nullptr) {
        cout << "Erro: membro \"" << nomeResponsavel
             << "\" nao encontrado." << endl;
        return;
    }

    if (membro->estaSobrecarregado()) {
        cout << "Erro: membro \"" << nomeResponsavel
             << "\" ja atingiu o limite de tarefas." << endl;
        return;
    }

    Tarefa* nova = new Tarefa(proximoId_, titulo, descricao,
                              prazo, prioridade, nomeResponsavel);
    proximoId_++;


    Coluna* coluna = buscarColuna(Status::A_FAZER);
    if (coluna != nullptr) {
        coluna->adicionarTarefa(nova);
    }


    membro->incrementarCarga();
}


bool Quadro::moverTarefa(int idTarefa, Status novoStatus) {

    for (Coluna* c : colunas_) {
        Tarefa* t = c->buscarTarefa(idTarefa);
        if (t != nullptr) {

            c->removerTarefa(idTarefa);

            t->setStatus(novoStatus);

            Coluna* destino = buscarColuna(novoStatus);
            if (destino != nullptr) {
                destino->adicionarTarefa(t);
            }
            return true;
        }
    }
    return false;
}


bool Quadro::editarTarefa(int            idTarefa,
                          const string&  novoTitulo,
                          const string&  novaDescricao,
                          const string&  novoPrazo,
                          Prioridade     novaPrioridade,
                          const string&  novoResponsavel) {

    Tarefa* t = buscarTarefa(idTarefa);
    if (t == nullptr) {
        return false;
    }

    Membro* novoResp = buscarMembro(novoResponsavel);
    if (novoResp == nullptr) {
        cout << "Erro: membro \"" << novoResponsavel
             << "\" nao encontrado." << endl;
        return false;
    }

    string antigoNome = t->getResponsavel();
    if (antigoNome != novoResponsavel) {
        Membro* antigoResp = buscarMembro(antigoNome);
        if (antigoResp != nullptr) {
            antigoResp->decrementarCarga();
        }

        if (novoResp->estaSobrecarregado()) {
            cout << "Erro: membro \"" << novoResponsavel
                 << "\" ja atingiu o limite de tarefas." << endl;
            if (antigoResp != nullptr) {
                antigoResp->incrementarCarga();
            }
            return false;
        }

        novoResp->incrementarCarga();
    }

    t->setTitulo(novoTitulo);
    t->setDescricao(novaDescricao);
    t->setPrazo(novoPrazo);
    t->setPrioridade(novaPrioridade);
    t->setResponsavel(novoResponsavel);

    return true;
}


bool Quadro::removerTarefa(int idTarefa) {
    for (Coluna* c : colunas_) {
        Tarefa* t = c->buscarTarefa(idTarefa);
        if (t != nullptr) {
            Membro* resp = buscarMembro(t->getResponsavel());
            if (resp != nullptr) {
                resp->decrementarCarga();
            }

            c->removerTarefa(idTarefa);
            delete t;       
            return true;
        }
    }
    return false;
}


Tarefa* Quadro::buscarTarefa(int idTarefa) const {
    for (Coluna* c : colunas_) {
        Tarefa* t = c->buscarTarefa(idTarefa);
        if (t != nullptr) {
            return t;
        }
    }
    return nullptr;
}


// Filtros
vector<Tarefa*> Quadro::getTarefasPorMembro(const string& nome) const {
    vector<Tarefa*> resultado;

    for (Coluna* c : colunas_) {
        vector<Tarefa*> tarefas = c->getTarefas();
        for (Tarefa* t : tarefas) {
            if (t->getResponsavel() == nome) {
                resultado.push_back(t);
            }
        }
    }
    return resultado;
}


vector<Tarefa*> Quadro::getTarefasPorPrioridade(Prioridade p) const {
    vector<Tarefa*> resultado;

    for (Coluna* c : colunas_) {
        vector<Tarefa*> tarefas = c->getTarefas();
        for (Tarefa* t : tarefas) {
            if (t->getPrioridade() == p) {
                resultado.push_back(t);
            }
        }
    }
    return resultado;
}


vector<Tarefa*> Quadro::getTarefasAtrasadas() const {
    vector<Tarefa*> resultado;

    for (Coluna* c : colunas_) {
        vector<Tarefa*> atrasadas = c->getTarefasAtrasadas();
        for (Tarefa* t : atrasadas) {
            resultado.push_back(t);
        }
    }
    return resultado;
}


// Gestão de membros
void Quadro::adicionarMembro(const string& nome) {
    if (buscarMembro(nome) != nullptr) {
        cout << "Erro: membro \"" << nome
             << "\" ja existe." << endl;
        return;
    }

    Membro* novo = new Membro(nome);
    membros_.push_back(novo);
}


Membro* Quadro::buscarMembro(const string& nome) const {
    for (Membro* m : membros_) {
        if (m->getNome() == nome) {
            return m;
        }
    }
    return nullptr;
}


vector<Membro*> Quadro::getMembros() const {
    return membros_;
}

vector<Coluna*> Quadro::getColunas() const {
    return colunas_;
}


// Exibição
void Quadro::exibir() const {
    cout << "========================================" << endl;
    cout << "           QUADRO KANBAN                " << endl;
    cout << "========================================" << endl;

    for (Coluna* c : colunas_) {
        c->exibir();
    }

    cout << "----------------------------------------" << endl;
    cout << "Membros: ";
    for (int i = 0; i < (int)membros_.size(); i++) {
        if (i > 0) cout << ", ";
        cout << membros_[i]->getNome();
    }
    cout << endl;
    cout << "========================================" << endl;
}