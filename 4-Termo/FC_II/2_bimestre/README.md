Opção 2: Adicionar o psql.exe ao PATH

Descubra onde o PostgreSQL foi instalado
Exemplo comum:
```bash
C:\Program Files\PostgreSQL\16\bin\
```
Copie o caminho completo da pasta bin, onde está o psql.exe.

Adicione ao PATH do sistema:

Vá em: Painel de Controle > Sistema > Configurações Avançadas do Sistema

Clique em Variáveis de Ambiente

Em Variáveis do sistema, encontre e edite a variável Path

Clique em Novo e cole o caminho da pasta bin do PostgreSQL

Salve tudo e reinicie o terminal (CMD ou PowerShell)

Depois disso, tente no terminal:
```bash
psql -U postgres -h localhost -d postgres
```
Alternativa sem terminal: Usar pgAdmin

Se você tem o pgAdmin instalado:

Abra o pgAdmin

Conecte-se ao servidor localhost

Clique em "Query Tool"

Execute o comando:
```bash
ALTER USER postgres WITH PASSWORD 'postgres123';
```