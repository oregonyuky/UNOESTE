1. O que é condição de corrida?

Condição de corrida ocorre quando o resultado da execução de um programa depende da ordem de escalonamento dos processos/threads que acessam dados compartilhados. Se dois processos acessam e modificam a mesma variável sem sincronização adequada, o resultado pode ser incorreto e não determinístico.

2. Explique a diferença entre espera ocupada e bloqueio.

Espera ocupada (busy waiting):
O processo fica em loop ativo, verificando continuamente se pode entrar na região crítica. Consome CPU enquanto espera.

Bloqueio:
O processo é colocado em estado de bloqueado pelo sistema operacional e não consome CPU até poder prosseguir.

3. A solução com espera ocupada (estrita alternância usando turn) funciona em um sistema multiprocessador com memória compartilhada?

Não.
A solução de estrita alternância não garante exclusão mútua em multiprocessadores porque não impede que ambos os processos verifiquem a variável turn ao mesmo tempo devido a instruções que podem não ser atômicas. Além disso, mesmo funcionando, ela impõe alternância rígida — um processo lento pode atrasar o outro.

4. Principais diferenças entre semáforos e monitores.

Semáforos:

São variáveis inteiras acessadas por P() (wait) e V() (signal).

São mecanismos de baixo nível.

Dependem da disciplina do programador (fáceis de usar errado).

Monitores:

Estrutura de alto nível que combina dados + procedimentos sincronizados.

A exclusão mútua é automática: só um processo entra no monitor por vez.

Usam variáveis de condição (wait/signal) dentro do monitor.

5. Por que é necessário o uso de “inversão de prioridades”?

É necessário para evitar o problema da Prioridade Inversion, quando um processo de alta prioridade fica esperando um recurso que está sendo usado por um processo de baixa prioridade, que por sua vez pode ser preemptado por um processo de prioridade intermediária.
A solução é elevar temporariamente a prioridade do processo de baixa prioridade enquanto ele mantém o recurso crítico.

6. Problema da solução de Peterson.

O problema é que ela depende de operações em memória sem garantias de ordenação e atomicidade em arquiteturas modernas (principalmente multiprocessadores).
Em processadores atuais, otimizações como reordenação de memória e caches podem quebrar a lógica da solução.

7. As quatro condições para evitar que dois processos estejam na região crítica ao mesmo tempo.

Exclusão mútua:
Apenas um processo pode estar na região crítica por vez.

Progresso:
Se a região crítica está livre, o processo que decidirá quem entra não deve estar bloqueado fora da zona crítica.

Espera limitada (bounded waiting):
Deve haver um limite máximo de vezes que outros processos podem entrar na região crítica antes que um processo que pediu acesso entre.

Não Assunção de Velocidade / Independência de velocidade (no assumptions about speed):
A solução deve funcionar independentemente da velocidade relativa dos processos e do número de CPUs.

8. Segunda condição de corrida no problema Sleep/Wakeup (além da perda do WAKEUP).

A segunda condição de corrida envolve a variável count, quando ambos os processos (produtor e consumidor) a modificam simultaneamente:

count++ e count-- não são operações atômicas.

Portanto, updates podem se perder, resultando em valores incorretos (por exemplo, count ficar negativo ou maior que o buffer).

9. Por que TSL e semáforos/monitores não competem entre si?

TSL (Test-and-Set Lock) é uma instrução de hardware usada para implementar primitivas de exclusão mútua.

Semáforos/monitores são mecanismos de software construídos sobre instruções de hardware como TSL.

Ou seja, TSL é um tijolo, semáforos/monitores são a casa construída com os tijolos.

10. Por que é necessária a exclusão mútua na concorrência entre processos?

Para proteger regiões críticas, evitando que múltiplos processos modifiquem dados compartilhados simultaneamente, o que gera condições de corrida, inconsistências e corrupção de dados.

11. Dois problemas de sincronização na comunicação entre processos.

Deadlock:
Dois ou mais processos ficam esperando indefinidamente por recursos que nunca serão liberados.

Starvation:
Um processo pode nunca ter a chance de executar porque sempre é preterido pelos outros.

12. O que é Exclusão Mútua e Região Crítica?

Região crítica:
Trecho de código que acessa dados compartilhados e não pode ser executado por mais de um processo simultaneamente.

Exclusão mútua:
Propriedade que garante que apenas um processo por vez entre na região crítica.

13. O que é starvation e como solucionar?

Starvation ocorre quando um processo nunca recebe a chance de progredir, geralmente por políticas injustas de escalonamento ou sincronização.

Soluções:

Uso de escalonamento justo (fair scheduling).

Semáforos ou locks com fila FIFO.

Algoritmos que garantem bounded waiting.

14. Problema da solução que desabilita interrupções para implementar exclusão mútua.

Funciona apenas em uniprocessadores; em multiprocessadores isso não impede acesso simultâneo.

Um processo pode desabilitar interrupções e nunca habilitá-las de volta, travando o sistema.

É uma solução insegura, pois dá ao usuário controle sobre o hardware.

Desabilitar interrupções por muito tempo prejudica o desempenho e a capacidade do SO de responder a eventos.