# Cartões CRC

## Class Tarefa
### Responsabilidade:
* Armazenar dados da tarefa (id, título, descrição,
prazo, prioridade, responsável, status)
* Informar se está atrasada (prazo vencido)
* Converter prioridade e status para texto legível
* Exibir seus dados formatados no terminal
### Colaboração:
* Membro
* Coluna

---

## Class Membro
### Responsabilidade:
* Armazenar nome do membro
* Controlar carga de trabalho (quantidade de
tarefas ativas)
* Indicar se está sobrecarregado (carga > limite)
### Colaboração:
* Tarefa

---

## Class Coluna
### Responsabilidade:
* Representar uma etapa do fluxo (A Fazer, Em
Andamento, Concluído)
* Armazenar e gerenciar a lista de tarefas nessa
etapa
* Buscar, adicionar e remover tarefas
* Listar tarefas atrasadas dentro da coluna
### Colaboração:
* Tarefa

---

## Class Quadro
### Responsabilidade:
* Gerenciar as três colunas do Kanban
* Criar tarefas e atribuí-las à coluna correta
* Mover tarefa entre colunas ao mudar status
* Cadastrar e gerenciar membros da equipe
* Fornecer filtros (por membro, prioridade, atraso)
### Colaboração:
* Coluna
* Membro
* Tarefa

---

## Class Metricas
### Responsabilidade:
* Calcular e exibir carga de trabalho por membro
* Listar tarefas atrasadas em todo o quadro
* Exibir concentração de tarefas por coluna
* Identificar e alertar sobre membros
sobrecarregados
* Gerar relatório completo de produtividade
### Colaboração:
* Quadro
* Membro
* Tarefa

---

## Class AgileManager
### Responsabilidade:
* Exibir menu principal no terminal
* Receber e validar entrada do usuário
* Coordenar as operações entre Quadro e Metricas
* Controlar o loop principal da aplicação
### Colaboração:    
* Quadro
* Metricas