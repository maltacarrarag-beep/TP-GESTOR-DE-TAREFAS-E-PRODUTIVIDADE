#include "AgileManager.h"

#include <iostream>
#include <limits>
#include <string>


static int lerInteiro(const std::string& prompt) {
    int valor;
    while (true) {
        std::cout << prompt;
        if (std::cin >> valor) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return valor;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "  [!] Entrada invalida. Digite um numero inteiro.\n";
    }
}

static std::string lerLinha(const std::string& prompt) {
    std::string linha;
    std::cout << prompt;
    std::getline(std::cin, linha);
    return linha;
}

static Prioridade lerPrioridade() {
    while (true) {
        std::cout << "  Prioridade (1=ALTA, 2=MEDIA, 3=BAIXA): ";
        int op = lerInteiro("");
        switch (op) {
            case 1: return Prioridade::ALTA;
            case 2: return Prioridade::MEDIA;
            case 3: return Prioridade::BAIXA;
            default: std::cout << "  [!] Opcao invalida.\n";
        }
    }
}

// Construtor / Destrutor
AgileManager::AgileManager()
    : quadro(new Quadro()), metricas(new Metricas(quadro)) {}

AgileManager::~AgileManager() {
    delete metricas;
    delete quadro;
}

// Loop principal
void AgileManager::executar() {
    std::cout << "\n╔══════════════════════════════════╗\n";
    std::cout << "║      Bem-vindo ao AgileManager   ║\n";
    std::cout << "╚══════════════════════════════════╝\n";

    int opcao = -1;
    while (opcao != 0) {
        exibirMenu();
        opcao = lerInteiro(">> Escolha: ");
        if (opcao != 0)
            processarOpcao(opcao);
    }

    std::cout << "\nAte logo!\n";
}

// Menu principal

void AgileManager::exibirMenu() const {
    std::cout << "\n┌─────────────────────────────────┐\n";
    std::cout << "│          MENU PRINCIPAL         │\n";
    std::cout << "├─────────────────────────────────┤\n";
    std::cout << "│  1. Visualizar quadro           │\n";
    std::cout << "│  2. Cadastrar tarefa            │\n";
    std::cout << "│  3. Mover tarefa                │\n";
    std::cout << "│  4. Editar tarefa               │\n";
    std::cout << "│  5. Remover tarefa              │\n";
    std::cout << "│  6. Filtrar tarefas             │\n";
    std::cout << "│  7. Gerenciar membros           │\n";
    std::cout << "│  8. Metricas e relatorios       │\n";
    std::cout << "│  0. Sair                        │\n";
    std::cout << "└─────────────────────────────────┘\n";
}

void AgileManager::processarOpcao(int opcao) {
    switch (opcao) {
        case 1: quadro->exibir();        break;
        case 2: menuCadastrarTarefa();   break;
        case 3: menuMoverTarefa();       break;
        case 4: menuEditarTarefa();      break;
        case 5: menuRemoverTarefa();     break;
        case 6: menuFiltrarTarefas();    break;
        case 7: menuGerenciarMembros();  break;
        case 8: menuVisualizarMetricas(); break;
        default:
            std::cout << "  [!] Opcao invalida. Tente novamente.\n";
    }
}
// 2. Cadastrar tarefa
void AgileManager::menuCadastrarTarefa() {
    std::cout << "\n── Cadastrar Nova Tarefa ──\n";

    std::string titulo      = lerLinha("  Titulo: ");
    std::string descricao   = lerLinha("  Descricao: ");
    std::string prazo       = lerLinha("  Prazo (AAAA-MM-DD): ");
    Prioridade  prioridade  = lerPrioridade();

    // Lista membros disponíveis para facilitar a escolha
    auto membros = quadro->getMembros();
    if (membros.empty()) {
        std::cout << "  [!] Nenhum membro cadastrado. Adicione membros primeiro (opcao 7).\n";
        return;
    }

    std::cout << "  Membros disponiveis:\n";
    for (auto* m : membros)
        std::cout << "    - " << m->getNome()
                  << (m->estaSobrecarregado() ? " [SOBRECARREGADO]" : "") << "\n";

    std::string responsavel = lerLinha("  Responsavel: ");

    if (quadro->buscarMembro(responsavel) == nullptr) {
        std::cout << "  [!] Membro \"" << responsavel << "\" nao encontrado no projeto.\n";
        return;
    }

    try {
        quadro->adicionarTarefa(titulo, descricao, prazo, prioridade, responsavel);
        std::cout << "  [OK] Tarefa cadastrada com sucesso.\n";
    } catch (const std::invalid_argument& e) {
        std::cout << "  [!] Erro ao cadastrar: " << e.what() << "\n";
    }
}
// 3. Mover tarefa
void AgileManager::menuMoverTarefa() {
    std::cout << "\n── Mover Tarefa ──\n";
    quadro->exibir();

    int id = lerInteiro("  ID da tarefa: ");

    Tarefa* t = quadro->buscarTarefa(id);
    if (!t) {
        std::cout << "  [!] Tarefa #" << id << " nao encontrada.\n";
        return;
    }

    std::cout << "  Status atual: " << t->statusToString() << "\n";
    std::cout << "  Novo status:\n";
    std::cout << "    1. A Fazer\n";
    std::cout << "    2. Em Andamento\n";
    std::cout << "    3. Concluido\n";

    int op = lerInteiro("  Escolha: ");
    Status novoStatus;
    switch (op) {
        case 1: novoStatus = Status::A_FAZER;      break;
        case 2: novoStatus = Status::EM_ANDAMENTO; break;
        case 3: novoStatus = Status::CONCLUIDO;    break;
        default:
            std::cout << "  [!] Opcao invalida.\n";
            return;
    }

    if (quadro->moverTarefa(id, novoStatus))
        std::cout << "  [OK] Tarefa movida com sucesso.\n";
    else
        std::cout << "  [!] Nao foi possivel mover a tarefa.\n";
}

// 4. Editar tarefa
void AgileManager::menuEditarTarefa() {
    std::cout << "\n── Editar Tarefa ──\n";
    quadro->exibir();

    int id = lerInteiro("  ID da tarefa a editar: ");

    Tarefa* t = quadro->buscarTarefa(id);
    if (!t) {
        std::cout << "  [!] Tarefa #" << id << " nao encontrada.\n";
        return;
    }

    std::cout << "  (Enter para manter o valor atual)\n";

    // Captura novos valores mas mantém o atual se o usuário deixar em branco
    auto lerCampo = [](const std::string& prompt, const std::string& atual) {
        std::cout << prompt << " [" << atual << "]: ";
        std::string entrada;
        std::getline(std::cin, entrada);
        return entrada.empty() ? atual : entrada;
    };

    std::string novoTitulo      = lerCampo("  Novo titulo",     t->getTitulo());
    std::string novaDescricao   = lerCampo("  Nova descricao",  t->getDescricao());
    std::string novoPrazo       = lerCampo("  Novo prazo",      t->getPrazo());

    std::cout << "  Prioridade atual: " << t->prioridadeToString()
              << "  (0 para manter)\n";
    int pOp = lerInteiro("  Nova prioridade (1=ALTA 2=MEDIA 3=BAIXA 0=manter): ");
    Prioridade novaPrioridade = t->getPrioridade();
    if      (pOp == 1) novaPrioridade = Prioridade::ALTA;
    else if (pOp == 2) novaPrioridade = Prioridade::MEDIA;
    else if (pOp == 3) novaPrioridade = Prioridade::BAIXA;

    std::string novoResponsavel = lerCampo("  Novo responsavel", t->getResponsavel());
    if (novoResponsavel != t->getResponsavel() &&
        quadro->buscarMembro(novoResponsavel) == nullptr) {
        std::cout << "  [!] Membro \"" << novoResponsavel << "\" nao encontrado. Responsavel mantido.\n";
        novoResponsavel = t->getResponsavel();
    }

    try {
        if (quadro->editarTarefa(id, novoTitulo, novaDescricao,
                                novoPrazo, novaPrioridade, novoResponsavel))
            std::cout << "  [OK] Tarefa atualizada.\n";
        else
            std::cout << "  [!] Erro ao atualizar tarefa.\n";
    } catch (const std::invalid_argument& e) {
        std::cout << "  [!] Erro ao editar: " << e.what() << "\n";
    }
}
// 5. Remover tarefa
void AgileManager::menuRemoverTarefa() {
    std::cout << "\n── Remover Tarefa ──\n";
    quadro->exibir();

    int id = lerInteiro("  ID da tarefa a remover: ");

    Tarefa* t = quadro->buscarTarefa(id);
    if (!t) {
        std::cout << "  [!] Tarefa #" << id << " nao encontrada.\n";
        return;
    }

    std::cout << "  Confirmar remocao de \"" << t->getTitulo() << "\"? (s/n): ";
    std::string conf;
    std::getline(std::cin, conf);

    if (conf == "s" || conf == "S") {
        if (quadro->removerTarefa(id))
            std::cout << "  [OK] Tarefa removida.\n";
        else
            std::cout << "  [!] Erro ao remover tarefa.\n";
    } else {
        std::cout << "  Operacao cancelada.\n";
    }
}
// 6. Filtrar tarefas
void AgileManager::menuFiltrarTarefas() {
    std::cout << "\n── Filtrar Tarefas ──\n";
    std::cout << "  1. Por prioridade\n";
    std::cout << "  2. Por membro responsavel\n";
    std::cout << "  3. Tarefas atrasadas\n";

    int op = lerInteiro("  Filtro: ");

    switch (op) {
        case 1: {
            Prioridade p = lerPrioridade();
            auto tarefas = quadro->getTarefasPorPrioridade(p);
            if (tarefas.empty()) {
                std::cout << "  Nenhuma tarefa com essa prioridade.\n";
            } else {
                std::cout << "\n  Tarefas encontradas (" << tarefas.size() << "):\n";
                for (auto* t : tarefas) t->exibir();
            }
            break;
        }
        case 2: {
            std::string nome = lerLinha("  Nome do membro: ");
            auto tarefas = quadro->getTarefasPorMembro(nome);
            if (tarefas.empty()) {
                std::cout << "  Nenhuma tarefa atribuida a \"" << nome << "\".\n";
            } else {
                std::cout << "\n  Tarefas de " << nome << " (" << tarefas.size() << "):\n";
                for (auto* t : tarefas) t->exibir();
            }
            break;
        }
        case 3: {
            auto tarefas = quadro->getTarefasAtrasadas();
            if (tarefas.empty()) {
                std::cout << "  Nenhuma tarefa atrasada. \n";
            } else {
                std::cout << "\n  Tarefas atrasadas (" << tarefas.size() << "):\n";
                for (auto* t : tarefas) t->exibir();
            }
            break;
        }
        default:
            std::cout << "  [!] Opcao invalida.\n";
    }
}
// 7. Gerenciar membros
void AgileManager::menuGerenciarMembros() {
    std::cout << "\n── Gerenciar Membros ──\n";
    std::cout << "  1. Adicionar membro\n";
    std::cout << "  2. Listar membros\n";

    int op = lerInteiro("  Opcao: ");

    switch (op) {
        case 1: {
            std::string nome = lerLinha("  Nome do novo membro: ");
            if (nome.empty()) {
                std::cout << "  [!] Nome invalido.\n";
                break;
            }
            if (quadro->buscarMembro(nome) != nullptr) {
                std::cout << "  [!] Membro \"" << nome << "\" ja existe.\n";
                break;
            }
            quadro->adicionarMembro(nome);
            std::cout << "  [OK] Membro \"" << nome << "\" adicionado.\n";
            break;
        }
        case 2: {
            auto membros = quadro->getMembros();
            if (membros.empty()) {
                std::cout << "  Nenhum membro cadastrado.\n";
            } else {
                std::cout << "\n  Membros (" << membros.size() << "):\n";
                for (auto* m : membros) m->exibir();
            }
            break;
        }
        default:
            std::cout << "  [!] Opcao invalida.\n";
    }
}
// 8. Métricas e relatórios
void AgileManager::menuVisualizarMetricas() {
    std::cout << "\n── Metricas e Relatorios ──\n";
    std::cout << "  1. Carga por membro\n";
    std::cout << "  2. Tarefas atrasadas\n";
    std::cout << "  3. Distribuicao por coluna\n";
    std::cout << "  4. Membros sobrecarregados\n";
    std::cout << "  5. Relatorio completo\n";

    int op = lerInteiro("  Opcao: ");

    switch (op) {
        case 1: metricas->exibirCargaPorMembro();        break;
        case 2: metricas->exibirTarefasAtrasadas();      break;
        case 3: metricas->exibirDistribuicaoPorColuna(); break;
        case 4: metricas->exibirMembrosSobrecarregados(); break;
        case 5: metricas->exibirRelatorioCompleto();     break;
        default: std::cout << "  [!] Opcao invalida.\n";
    }
}