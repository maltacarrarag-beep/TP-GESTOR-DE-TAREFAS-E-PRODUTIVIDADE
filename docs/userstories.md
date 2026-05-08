# User Stories 

## 1. Gestão de Tarefas (Core)

### 1.1 — Cadastrar Tarefa
**Como** Membro da equipe  
**Desejo** cadastrar uma tarefa com título, descrição, prazo, prioridade e responsável  
**Para que** o time saiba o que precisa ser feito.

**Critérios de Aceitação:**
* Dado que o usuário está no menu principal e a equipe já possui membros cadastrados.
* Quando o usuário seleciona 'Cadastrar Tarefa' e preenche todos os campos obrigatórios.
* Então a tarefa é criada na coluna 'A Fazer' e exibida no quadro com todos os dados informados.
* **Prioridade:** Alta | **Estimativa:** 4h

---

### 1.2 — Visualizar Quadro Kanban
**Como** Membro da equipe  
**Desejo** visualizar o quadro Kanban com colunas "A Fazer", "Em Andamento" e "Concluído"  
**Para que** possa ter uma visão geral do andamento do projeto.

**Critérios de Aceitação:**
* Dado que o sistema possui ao menos uma tarefa cadastrada.
* Quando o usuário seleciona 'Visualizar Quadro' no menu.
* Então o quadro é exibido no terminal com as três colunas e suas respectivas tarefas listadas.
* **Prioridade:** Alta | **Estimativa:** 3h

---

### 1.3 — Mover Tarefa entre Colunas
**Como** Membro da equipe  
**Desejo** mover uma tarefa entre colunas  
**Para que** possa refletir o progresso real da atividade.

**Critérios de Aceitação:**
* Dado que existe uma tarefa cadastrada em qualquer coluna do quadro.
* Quando o usuário informa o ID da tarefa e seleciona o novo status desejado.
* Então a tarefa é removida da coluna atual e adicionada à nova coluna com o status atualizado.
* **Prioridade:** Alta | **Estimativa:** 2h

---

### 1.4 — Editar Tarefa
**Como** Membro da equipe  
**Desejo** editar dados de uma tarefa existente  
**Para que** possa corrigir ou atualizar informações conforme necessário.

**Critérios de Aceitação:**
* Dado que existe uma tarefa cadastrada no quadro.
* Quando o usuário informa o ID da tarefa e altera um ou mais campos.
* Então os dados da tarefa são atualizados e a alteração é refletida imediatamente no quadro.
* **Prioridade:** Média | **Estimativa:** 3h

---

### 1.5 — Remover Tarefa
**Como** Membro da equipe  
**Desejo** remover uma tarefa do quadro  
**Para que** possa manter o quadro limpo e relevante.

**Critérios de Aceitação:**
* Dado que existe uma tarefa cadastrada no quadro.
* Quando o usuário informa o ID da tarefa e confirma a remoção.
* Então a tarefa é excluída do quadro e não aparece mais em nenhuma listagem.
* **Prioridade:** Média | **Estimativa:** 1h

---

## 2. Gestão de Equipe e Filtros

### 2.1 — Cadastrar Membros
**Como** Membro da equipe  
**Desejo** cadastrar membros da equipe  
**Para que** possa atribuir tarefas aos responsáveis certos.

**Critérios de Aceitação:**
* Dado que o usuário está no menu de gerenciamento de membros.
* Quando o usuário informa o nome de um novo membro e confirma o cadastro.
* Então o membro é registrado no sistema e fica disponível para ser atribuído a tarefas.
* **Prioridade:** Alta | **Estimativa:** 2h

---

### 2.2 — Filtrar por Responsável
**Como** Membro da equipe  
**Desejo** listar tarefas filtradas por responsável  
**Para que** possa ver rapidamente o que cada membro tem pendente.

**Critérios de Aceitação:**
* Dado que existem tarefas cadastradas com diferentes responsáveis.
* Quando o usuário seleciona o filtro por responsável e informa o nome do membro.
* Então apenas as tarefas atribuídas ao membro informado são exibidas no terminal.
* **Prioridade:** Média | **Estimativa:** 2h

---

### 2.3 — Filtrar por Prioridade
**Como** Membro da equipe  
**Desejo** filtrar tarefas por prioridade (Alta, Média, Baixa)  
**Para que** possa focar nas atividades mais urgentes primeiro.

**Critérios de Aceitação:**
* Dado que existem tarefas cadastradas com diferentes níveis de prioridade.
* Quando o usuário seleciona o filtro por prioridade e informa o nível desejado.
* Então somente as tarefas com a prioridade selecionada são listadas no terminal.
* **Prioridade:** Média | **Estimativa:** 2h

---

## 3. Gestão e Relatórios (Métricas)

### 3.1 — Verificar Excesso de Tarefas
**Como** Gestor do projeto  
**Desejo** ver quais membros têm excesso de tarefas atribuídas  
**Para que** possa redistribuir a carga de trabalho de forma equilibrada.

**Critérios de Aceitação:**
* Dado que existem membros com quantidades diferentes de tarefas atribuídas.
* Quando o gestor acessa o relatório de carga de trabalho.
* Então o sistema exibe a lista de membros com suas respectivas cargas e destaca os sobrecarregados.
* **Prioridade:** Alta | **Estimativa:** 3h

---

### 3.2 — Ver Tarefas em Atraso
**Como** Gestor do projeto  
**Desejo** ver quais tarefas estão com prazo vencido  
**Para que** possa agir preventivamente antes que o atraso comprometa a entrega.

**Critérios de Aceitação:**
* Dado que existem tarefas com prazo anterior à data atual e ainda não concluídas.
* Quando o gestor acessa o relatório de atrasos.
* Então o sistema lista todas as tarefas com prazo vencido, indicando o responsável e a coluna em que estão.
* **Prioridade:** Alta | **Estimativa:** 3h

---

### 3.3 — Métricas de Carga por Membro
**Como** Gestor do projeto  
**Desejo** ver métricas de distribuição de carga por membro  
**Para que** possa tomar decisões baseadas em dados sobre a equipe.

**Critérios de Aceitação:**
* Dado que existem membros cadastrados com tarefas atribuídas.
* Quando o gestor acessa o relatório de distribuição de carga.
* Então o sistema exibe o número de tarefas por membro com indicação visual de equilíbrio ou desequilíbrio.
* **Prioridade:** Média | **Estimativa:** 4h

---

### 3.4 — Concentração por Coluna
**Como** Gestor do projeto  
**Desejo** ver a concentração de tarefas por coluna do quadro  
**Para que** possa identificar gargalos no fluxo de trabalho.

**Critérios de Aceitação:**
* Dado que o quadro possui tarefas distribuídas entre as colunas.
* Quando o gestor acessa o relatório de concentração por coluna.
* Então o sistema exibe a contagem de tarefas em cada coluna e destaca colunas com volume acima da média.
* **Prioridade:** Baixa | **Estimativa:** 2h