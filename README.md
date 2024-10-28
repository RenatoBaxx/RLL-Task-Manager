# RLL-Task-Manager
Um gerenciador de tarefas simples e intuitivo que permite a criação e gerenciamento de equipes, bem como a adição de tarefas específicas para cada equipe. O programa é desenvolvido em C e utiliza um sistema de menus no terminal, além de armazenar dados em arquivos de texto para persistência.

# Funcionalidades
Gerenciamento de Equipes

Criar novas equipes.
Listar equipes existentes.
Adicionar ou remover equipes.
Gerenciamento de Tarefas

Adicionar tarefas a equipes específicas.
Listar todas as tarefas de uma equipe.
Marcar tarefas como concluídas.
Remover tarefas.
Persistência de Dados

Os dados das equipes e tarefas são salvos em arquivos de texto, garantindo que as informações sejam mantidas entre as execuções do programa.
Estrutura do Projeto

# 1. Menu Principal
O usuário pode navegar pelas opções disponíveis:

text
Copiar código
-----------------------------
   Gerenciador de Tarefas
-----------------------------
1. Gerenciar Equipes
2. Gerenciar Tarefas
3. Sair
-----------------------------
Escolha uma opção: 
2. Gerenciar Equipes
Adicionar nova equipe.
Listar equipes existentes.
Remover equipe.
text
Copiar código
-----------------------------
   Gerenciar Equipes
-----------------------------
1. Adicionar nova equipe
2. Listar equipes
3. Remover equipe
-----------------------------
Escolha uma opção: 
3. Gerenciar Tarefas
Adicionar nova tarefa a uma equipe específica.
Listar tarefas de uma equipe.
Marcar tarefa como concluída.
Remover tarefa.
text
Copiar código
-----------------------------
   Gerenciar Tarefas
-----------------------------
1. Adicionar nova tarefa
2. Listar tarefas
3. Marcar tarefa como concluída
4. Remover tarefa
-----------------------------
Escolha uma opção: 

# Tecnologias Utilizadas
Linguagem: C
Persistência de dados: Arquivos de texto
Terminal: Interface baseada em texto
Como Executar o Projeto
# Clone o repositório:

bash
Copiar código
git clone [https://github.com/renato/rll-task-manager.git](https://github.com/RenatoBaxx/RLL-Task-Manager.git)
cd gerenciador-tarefas
# Compile o código:

bash
Copiar código
gcc -o main.c
Execute o programa:

bash
Copiar código
./rll-task-manager

# Contribuições
Contribuições são bem-vindas! Sinta-se à vontade para abrir um issue ou fazer um pull request.

Licença
Este projeto está licenciado sob a Licença MIT. Consulte o arquivo LICENSE para obter detalhes.
