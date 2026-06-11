# TP* PDS2* Gestor de Tarefas e Produtividade

Laís Santos Barbosa;
Luís Felipe Resende Martini;
Gabriel Malta Carrara;
Dante Rabelo Ferreira;
Eduarda Morrison de Gouvêa.

Gerenciador de tarefas e produtividade no estilo Kanban, executado no terminal.
O sistema permite organizar tarefas em tres colunas (A Fazer, Em Andamento, Concluido),
gerenciar membros da equipe e visualizar metricas de desempenho.

## Como compilar e executar?
### Compilar
make
### Executar
./agilemanager
### Atalhos
make rebuild   (recompila do zero)
make clean     (remove arquivos gerados)

## Arquitetura e Organização
AgileManager/
├── Makefile
├── README.md
├── Doxyfile
├── .gitignore
├── include/
│   ├── AgileManager.h   
│   ├── Coluna.h         
│   ├── Membro.h         
│   ├── Metricas.h       
│   ├── Quadro.h         
│   └── Tarefa.h         
├── src/
│   ├── main.cpp
│   ├── AgileManager.cpp
│   ├── Coluna.cpp
│   ├── Membro.cpp
│   ├── Metricas.cpp
│   ├── Quadro.cpp
│   └── Tarefa.cpp
├── docs/
│   ├── cartoesCRC.md
│   ├── tutorialcommit.txt
│   └── userstories.md
└── data/
    └── .gitkeep

## Funcionalidades entregues
* Cadastrar tarefas com titulo, descricao, prazo e prioridade
* Mover tarefas entre colunas (A Fazer, Em Andamento, Concluido)
* Editar tarefas existentes
* Remover tarefas
* Filtrar tarefas por prioridade, membro ou atraso
* Gerenciar membros da equipe
* Gerenciar membros da equipe
* Controle de sobrecarga de membros (limite de 3 tarefas)
* Metricas: carga por membro, tarefas atrasadas, distribuicao por coluna
* Relatorio completo

## Funcionalidades não entregues
* Interface gréfica / dashboard visual (estilo Trello): foi considerado durante o planejamento, mas não foi implementado por limitações de tempo. O foco se manteve na lógica de negócio e na funcionalidade do código.
* Persistência de dados (salvar/carregar em arquivo): os dados existem apenas em memória durante a execução.

## Instruções de uso como exemplos
### 1. Adicionar membros (opção 7 -> 1)
Nome do novo membro: Ana
[OK] Membro "Ana" adicionado.
### 2. Cadastrar tarefa (opcao 2)
Titulo: Criar site para a empresa
Descricao: Usar lovable com auxílio dos membros da T.I.
Prazo (AAAA-MM-DD): 2026-12-01
Prioridade (1=ALTA, 2=MEDIA, 3=BAIXA): 2
Responsavel: Ana
[OK] Tarefa cadastrada com sucesso.
### 3. Visualizar o quadro (opcao 1)
----------------------------------
QUADRO KANBAN 
----------------------------------
A Fazer
Tarefas: 1
----------------------------------
ID: 1 | Criar site para a empresa | Media | Ana | Prazo: 2026-12-01
### 4. Mover tarefa (opcao 3)
ID da tarefa: 1
Novo status:
1.A Fazer
2.Em Andamento
3.Concluido
Escolha: 2
[OK] Tarefa movida com sucesso.
### 5. Ver relatorio completo (opcao 8 -> 5)
==================================
        RELATORIO COMPLETO
==================================
--- Distribuicao por Coluna ---
  A Fazer        [....................] 0 tarefa(s)
  Em Andamento   [####################] 1 tarefa(s)
  Concluido      [....................] 0 tarefa(s)

--- Carga por Membro ---
  Ana | Tarefas: 1 | Carga: 1

## Tratamento de excecoes e programacao defensiva
### Titulo ou responsavel vazio
Tarefa.cpp (construtor): std::invalid_argument
### Prazo fora do formato AAAA-MM-DD
Tarefa.cpp (construtor e setPrazo): std::invalid_argument
### Membro nao encontrado ao cadastrar tarefa
Quadro.cpp (adicionarTarefa): retorna sem criar a tarefa
### Membro sobrecarregado (mais de 3 tarefas)
Quadro.cpp e Membro.cpp: bloqueia nova atribuicao
### Carga negativa de membro
Membro.cpp (decrementarCarga): guarda contra valor abaixo de zero
### Ponteiro nulo na coluna
Coluna.cpp (adicionarTarefa): verifica nullptr antes de inserir
### Excecoes de entrada invalida na interface
AgileManager.cpp (menus de cadastro e edicao): try/catch com mensagem clara ao usuario
### Entrada nao numerica no menu
AgileManager.cpp (lerInteiro): loop com cin.clear() ate entrada valida

## Documentação (Doxygen)
O Doxygen nao foi configurado neste projeto durante o ciclo de desenvolvimento.
Como trabalho futuro, os comentarios do codigo poderiam ser convertidos para o
formato Doxygen (/** */) e o arquivo Doxyfile gerado com:
doxygen -g Doxyfile
doxygen Doxyfile

## Equipes e Contribuições
* Dante: Tarefa.h, Tarefa.cpp, contribuições na pasta docs/
* Lais: AgileManager.h, AgileManager.cpp
* Luís Felipe: Quadro.h, Quadro.cpp
* Eduarda: Cartoes CRC, User Stories, Membro.cpp
* Gabriel: Membro.h, Coluna.h, Coluna.cpp, main.cpp, Makefile, contribuicoes na pasta docs/

## Linha do tempo das sprints
### Sprint 1 (semana 1) 
* Objetivo: Definicao do tema, acesso ao GitHub, tutorial de commits
* Entregue: Tema definido, repositorio criado, equipe alinhada
### Sprint 2 (semana 2-3)
* Objetivo: Estrutura de diretorios, Cartoes CRC, User Stories, criacao dos .h
* Entregue: Todos os headers entregues e validados
### Sprint 4 (semana 4-7)
* Objetivo: Implementacao dos .cpp, Makefile, ajustes de programacao defensiva, finalizacao do README
* Entregue: Versao funcional completa entregue

##  Planejado x realizado
* A estrutura de classes foi definida antes da implementacao, o que facilitou a divisao de tarefas entre os integrantes sem conflitos de interface.
* O dashboard visual (estilo Trello) foi cogitado nas sprints iniciais, mas descartado nas sprints finais para priorizar a qualidade da logica de negocio e do tratamento de erros.
* A programacao defensiva foi revisada e reforçada nas sprints finais apos revisao conjunta do codigo, resultando em validacoes mais robustas em Tarefa.cpp e AgileManager.cpp.
