#include "Metricas.h"
#include <iostream>
// Construtor
Metricas::Metricas(Quadro* quadro)
    : quadro(quadro) {}

// Carga por membro
void Metricas::exibirCargaPorMembro() const {
    std::cout << "\n═══ Carga por Membro ═══\n";

    auto membros = quadro->getMembros();
    if (membros.empty()) {
        std::cout << "  Nenhum membro cadastrado.\n";
        return;
    }

    for (auto* m : membros) {
        auto tarefas = quadro->getTarefasPorMembro(m->getNome());
        std::cout << "  " << m->getNome()
                  << " | Tarefas: " << tarefas.size()
                  << " | Carga: "   << m->getCarga()
                  << (m->estaSobrecarregado() ? " [SOBRECARREGADO]" : "")
                  << "\n";
    }
}
// Tarefas atrasadas
void Metricas::exibirTarefasAtrasadas() const {
    std::cout << "\n═══ Tarefas Atrasadas ═══\n";

    auto atrasadas = quadro->getTarefasAtrasadas();
    if (atrasadas.empty()) {
        std::cout << "  Nenhuma tarefa atrasada.\n";
        return;
    }

    std::cout << "  Total: " << atrasadas.size() << "\n\n";
    for (auto* t : atrasadas)
        t->exibir();
}

// Distribuição por coluna
void Metricas::exibirDistribuicaoPorColuna() const {
    std::cout << "\n═══ Distribuicao por Coluna ═══\n";

    auto colunas = quadro->getColunas();
    if (colunas.empty()) {
        std::cout << "  Nenhuma coluna disponivel.\n";
        return;
    }

    int total = 0;
    for (auto* c : colunas)
        total += c->getQuantidade();

    for (auto* c : colunas) {
        int qtd = c->getQuantidade();
        int barras = (total > 0) ? (qtd * 20 / total) : 0; // barra proporcional de até 20 chars

        std::cout << "  " << c->getNome();
        // padding para alinhar as barras
        int padding = 15 - static_cast<int>(c->getNome().size());
        for (int i = 0; i < padding; i++) std::cout << ' ';

        std::cout << "[";
        for (int i = 0; i < barras;      i++) std::cout << "█";
        for (int i = barras; i < 20;     i++) std::cout << "░";
        std::cout << "] " << qtd << " tarefa(s)\n";
    }

    std::cout << "  Total geral: " << total << " tarefa(s)\n";
}
// Membros sobrecarregados
void Metricas::exibirMembrosSobrecarregados() const {
    std::cout << "\n═══ Membros Sobrecarregados ═══\n";

    auto membros = quadro->getMembros();
    bool encontrou = false;

    for (auto* m : membros) {
        if (m->estaSobrecarregado()) {
            m->exibir();
            encontrou = true;
        }
    }

    if (!encontrou)
        std::cout << "  Nenhum membro sobrecarregado.\n";
}
// Relatório completo
void Metricas::exibirRelatorioCompleto() const {
    std::cout << "\n╔══════════════════════════════════╗\n";
    std::cout << "║       RELATORIO COMPLETO         ║\n";
    std::cout << "╚══════════════════════════════════╝\n";

    exibirDistribuicaoPorColuna();
    exibirCargaPorMembro();
    exibirMembrosSobrecarregados();
    exibirTarefasAtrasadas();

    std::cout << "\n══════════════════════════════════\n";
}