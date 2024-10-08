# Logica
## Aqui estao todos os assuntos que a gente aprendeu na aula do PANDUR
### Equivalencia
| Equivalencia notavel     | formula                               | $$2\circ formula$$|
|--------------------------|---------------------------------------|-------------------|
|`Idempotencia`            |$$p*p \Leftrightarrow p$$              | $$p+p \Leftrightarrow p$$|
|`dupla negacao`           |$$(p')' \Leftrightarrow p$$            | $$(((p')')')' \Leftrightarrow p$$|
|`lei comutativa`          |$$p+q \Leftrightarrow q+p$$            | $$(a+b)+c \Leftrightarrow c+(a+b)$$|
|`leis de Morgan`          |$$(p+q)' \Leftrightarrow p'  *  q'$$    | $$(p*q)' \Leftrightarrow p'+q'$$|
|`lei distributiva`        |$$p*(q+r) \Leftrightarrow p*q + p *r$$  | $$p+(q*r) \Leftrightarrow (p+q) * (p+r)$$||
### Regras de Inferencia    
| Regras de Inferencia     | Sigla| formula                  |
|--------------------------|------|--------------------------|
|`Uniao`                   |  `U`  | $$\frac{p', q}{p' * q}$$|
|`Modulus Ponens`          |  `MP` |  $$\frac{p \to q, p}{q}$$|
|`Modulus Tollens`         |  `MT` | $$\frac{p \to q, q'}{p'}$$|
|`Adicao`                  |  `A`  | $$\frac{p}{p+q}$$|
|`Simplificacao`           |  `S`  |$$\frac{p*q}{q}$$|
|`Silogismo disjuntivo`    | `SD`  | $$\frac{p+q, p'}{q}$$|
|`Simplificacao Disjuntiva`|  `S+` | $$\frac{p+q, p+q'}{p}$$|
|`Silogismo Hipotetico`    |  `SH`|$$\frac{p \to q, q \to r}{p \to r}$$|
|`Regra de absorcao`       | `RA` |  $$\frac{p \to q}{p \to p*q}$$|
## Agora usando a prova direta
### Tecnica dedutiva
Existem 4 tecnicas dedutivas 
> [!IMPORTANT]
> - prova direta
> - prova indireta
> - prova condicional
> - prova indireta condicional
#### prova direta
> [!NOTE]
> Encontre o s'. Usando $t, t \to q', q' \to s'$
> |tipo | argumentos | regra de inferencia ou equivalencia notavel |
> | --- | ---------- | --------------------------------------------|
> |1)   | $t$ | $p$ |
> |2)   | $t' \to q'$ | $p$ |
> |3)   | $q' \to s'$ | $p$ |
> |4)   | $t \to s'$ | $SH \ 2,3$ |
> |5)   | $s'$ | $MP \ 1, 4$ |

---

***exercicio 1***


> [!TIP]
> Encontre o a. Usando $c', b \to c, a' \to b$
> |tipo | argumentos | regra de inferencia ou equivalencia notavel |
> | --- | ---------- | --------------------------------------------|
> |1)   | $c'$ | $p$ |
> |2)   | $b \to c$ | $p$ |
> |3)   | $a' \to b$ | $p$ |
> |4)   | $b'$ | $MT \ 2, 1$ |
> |5)   | $a$ | $MT \ 3, 4$ |

---

***exercicio 2***

> [!TIP]
> Encontre $r \to q'$. Usando $r'+s', q \to s$
> | tipo | argumentos | regra de inferencia ou equivalencia notavel |
> | --- | ------------| --------------------------------------------|
> |1)   | $r'+s'$ | $p$ |
> |2)   | $q \to s$ | $p$ |
> |3)   | $r$ | $pp$ |
> |4)   | $s'$ | $SD \ 1, 3$ |
> |5)   | $q'$ | $MT \ 2, 4$ |
> |6)   | $r \to q'$ | $PC \ 3 \ a \ 5$ |

---

***exercicio 3***

> [!TIP]
> Encontre r. Usando $p' \to r, r' \to q, (p*q)'$
> | tipo | argumentos | regra de inferencia ou equivalencia notavel |
> | ---- | -----------| --------------------------------------------|
> |1) | $p' \to r$ | $p$ |
> |2) | $r' \to q$ | $p$ |
> |3) | $(p*q)'$ | $p$ |
> |4) | $r'$ | $pp$ |
> |5) | $q$ | $MP \ 2, 4$ |
> |6) | $p'+q'$ | $DM \ 3$ |
> |7) | $(q')'$ | $DN \ 5$ |
> |8) | $p'$ | $SD \ 6,7$ |
> |9) | $r$ | $MP \ 1,8$ |
> |10) | $r*r'$ | $U \ 4, 9$ |
> |11) | $r$ | $PI \ 4, 10$ |



