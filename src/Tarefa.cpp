#include "Tarefa.h"
#include <iostream>
#include <stdexcept>

// Construtor: Inicializa o estado do objeto e valida as invariantes de dados
Tarefa::Tarefa(int id, const std::string& titulo,
               const std::string& descricao, const std::string& prazo,
               Prioridade prioridade, const std::string& responsavel)
    : id(id), prioridade(prioridade), status(Status::A_FAZER) {
    
    // Programação Defensiva: Validação de strings vazias para evitar estados inconsistentes
    if (titulo.empty()) {
        throw std::invalid_argument("Erro: O titulo da tarefa nao pode ser vazio.");
    }
    if (responsavel.empty()) {
        throw std::invalid_argument("Erro: O responsavel pela tarefa deve ser especificado.");
    }
    
    // Validação preliminar do tamanho do prazo (formato esperado: AAAA-MM-DD)
    if (prazo.length() != 10 || prazo[4] != '-' || prazo[7] != '-') {
        throw std::invalid_argument("Erro: O prazo deve estar no formato AAAA-MM-DD.");
    }

    this->titulo = titulo;
    this->descricao = descricao;
    this->prazo = prazo;
    this->responsavel = responsavel;
}

// Implementação dos Métodos Observadores (Getters)
int Tarefa::getId() const {
    return id;
}

std::string Tarefa::getTitulo() const {
    return titulo;
}

std::string Tarefa::getDescricao() const {
    return descricao;
}

std::string Tarefa::getPrazo() const {
    return prazo;
}

Prioridade Tarefa::getPrioridade() const {
    return prioridade;
}

std::string Tarefa::getResponsavel() const {
    return responsavel;
}

Status Tarefa::getStatus() const {
    return status;
}

// Implementação dos Métodos Mutadores (Setters) com Barreiras de Proteção
void Tarefa::setTitulo(const std::string& novoTitulo) {
    if (novoTitulo.empty()) {
        throw std::invalid_argument("Erro: O titulo da tarefa nao pode ser modificado para vazio.");
    }
    titulo = novoTitulo;
}

void Tarefa::setDescricao(const std::string& novaDescricao) {
    descricao = novaDescricao;
}

void Tarefa::setPrazo(const std::string& novoPrazo) {
    if (novoPrazo.length() != 10 || novoPrazo[4] != '-' || novoPrazo[7] != '-') {
        throw std::invalid_argument("Erro: O novo prazo deve respeitar estritamente o formato AAAA-MM-DD.");
    }
    prazo = novoPrazo;
}

void Tarefa::setPrioridade(Prioridade novaPrioridade) {
    prioridade = novaPrioridade;
}

void Tarefa::setResponsavel(const std::string& novoResponsavel) {
    if (novoResponsavel.empty()) {
        throw std::invalid_argument("Erro: O responsavel nao pode ser modificado para um campo vazio.");
    }
    responsavel = novoResponsavel;
}

void Tarefa::setStatus(Status novoStatus) {
    status = novoStatus;
}

// Lógica de Domínio: Verificação de Atraso por Comparação Léxica
bool Tarefa::estaAtrasada() const {
    if (status == Status::CONCLUIDO) {
        return false;
    }

    // Obtenção da data atual simulada do sistema.
    // Como a disciplina desencoraja bibliotecas complexas de tempo no escopo atual,
    // estabelecemos uma string estática representando a data de referência para a verificação.
    // Em produção, esta string seria atualizada dinamicamente pela camada de controle.
    std::string dataAtual = "2026-06-16";

    // A comparação léxica de strings funciona nativamente no padrão ISO 8601 (AAAA-MM-DD).
    // Se a string do prazo for estritamente menor que a data atual, a tarefa expirou.
    return (prazo < dataAtual);
}

// Métodos de Conversão de Enum para String Legível
std::string Tarefa::prioridadeToString() const {
    switch (prioridade) {
        case Prioridade::ALTA:  return "Alta";
        case Prioridade::MEDIA: return "Media";
        case Prioridade::BAIXA: return "Baixa";
        default:                return "Desconhecida";
    }
}

std::string Tarefa::statusToString() const {
    switch (status) {
        case Status::A_FAZER:      return "A Fazer";
        case Status::EM_ANDAMENTO: return "Em Andamento";
        case Status::CONCLUIDO:    return "Concluido";
        default:                   return "Desconhecido";
    }
}

// Interface de Saída: Impressão Formatada no Terminal (CLI)
void Tarefa::exibir() const {
    std::cout << "==================================================\n";
    std::cout << "ID da Tarefa:  " << id << "\n";
    std::cout << "Titulo:        " << titulo << "\n";
    std::cout << "Descricao:     " << descricao << "\n";
    std::cout << "Prazo:         " << prazo;
    if (estaAtrasada()) {
        std::cout << " [ATRASADA]";
    }
    std::cout << "\n";
    std::cout << "Prioridade:    " << prioridadeToString() << "\n";
    std::cout << "Responsavel:   " << responsavel << "\n";
    std::cout << "Status Atual:  " << statusToString() << "\n";
    std::cout << "==================================================" << std::endl;
}