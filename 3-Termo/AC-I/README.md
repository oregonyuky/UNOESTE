# Barramentos 

- Conceito de comunicação de dados: 
- Paralelo e Série

### Tipos de comunicação série

| Comunicação Série | Explicação |
|----|----|
| `Simplex` | A sempre transmite e o B sempre recebe |
| `Half-Duplex` | A pode transmitir ao B e vice-versa, mas não simultaneamente (unidirecional) |
| `Duplex` | A pode transmitir ao B e vice-versa simultaneamente |

Clock: sinal periódico e com característica conhecida. Frequência medida em Hertz (Hz), indica a quantidade de ciclos por segundo que ocorre no sinal.

### Taxa de transferência

- Medida de desempenho de sistemas em que ocorre uma comunicação de dados.

> **Nota:** 
> Taxa de transferência = Clock * Quantidade de dados manipulados (bits ou Bytes)

O resultado é expresso em: 
- Bits por segundo (b/s ou bps)
- Bytes por segundo (B/s ou Bps)

Barramentos são responsáveis pela interligação dos circuitos/módulos do computador. Existem barramentos internos ou externos, seriais ou paralelos.

Um barramento é formado por 3 subsistemas:
- Dados (bidirecional)
- Endereço (unidirecional)
- Controle (bidirecional)

Em um barramento paralelo, essa divisão é física.
Em um barramento serial, a divisão é lógica/virtual.

### Barramento paralelo

A quantidade de bits define a largura do barramento.

# Memórias

Dispositivo que armazena informação de forma temporária ou permanente. Considerando o meio de armazenamento, podem ser divididas em 2 grupos:

- Eletrônicas
- Não eletrônicas

Em um computador, tem-se memórias primárias e secundárias. A análise dos diferentes critérios de avaliação permite uma noção geral do modo de funcionamento de uma memória. Esses critérios são:

### Curso

- Sequencial
- Aleatório

### Troca de dados

Considerando a memória em funcionamento normal no sistema em que está inserida, tem-se:
- Leitura
- Leitura / Escrita

### Tempo de acesso

Tempo decorrido entre uma solicitação à memória e o efetivo atendimento desta solicitação.

### Volatilidade

Relacionado à capacidade da memória em manter (ou não) os dados armazenados, mesmo com ela desligada.
- Volátil: perde os dados.
- Não volátil: não perde os dados (não eletrônico).

### Tipo de armazenamento

- Estática: não é necessário nenhum procedimento para manter os dados válidos em sua estrutura.
- Dinâmica: é necessário um procedimento periódico de validação dos dados.

Comparado a uma memória dinâmica equivalente, uma estática é mais cara, mais rápida e com menor densidade de armazenamento.

### Memórias Eletrônicas

Acesso aleatório, leitura ou leitura/escrita, volátil ou não, dinâmica ou estática. São especificadas pela notação N x m, com:
- N: quantidade de posições de memória.
- m: comprimento das posições em bits.

A capacidade de uma memória em bits é dada pelo produto N x m. Exemplo: 32 x 4.

### Memória Volátil

Podem ser estáticas ou dinâmicas. Uma memória volátil estática utiliza flip-flop como elemento de armazenamento. Uma célula básica deste tipo de memória é ilustrada a seguir.

