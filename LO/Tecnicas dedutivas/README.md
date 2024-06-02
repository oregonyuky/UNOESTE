## Ex 1 pagina 71
1) Provar t' dadas as premissas:

| tipo | argumento | regra de inferencia ou equivalencia | 
|:----:|:---------:|:------------------------------------:|
|1)    | $p \to s$ | $p$ |
|2) | $p * q$ | $p$ |
|3) | $s * r \to t'$ | $p$ |
|4) | $q \to r$ | $p$ | 
|5) | $q$ | $S \ 2$ |
|6) | $p$ | $S \ 2$ |
|7) | $s$ | $MP \ 1,6$ | 
|8) | $r$ | $MP \ 4,5$ |
|9) | $s * r$ | $U \ 7,8$ |
|10) | $t'$ | $MP \ 3, 9$ |
---
2) Provar s dadas as premissas:

| tipo | argumento | regra de inferencia ou equivalencia |
|:----:|:---------:|:-----------------------------------:|
|1) | $t \to r$ | $p$ |
|2) | $r'$ | $p$
|3) | $t+s$ | $p$
|4) | $t'$ | $MT \ 1,2$ 
|5) | $s$ | $SD \ 3,4$
---
3) Provar $t * s$ dadas as premissas:

| tipo | argumento | regra de inferencia ou equivalencia |
|:----:|:---------:|:-----------------------------------:|
|1) | $e \to s$ | $p$ |
|2) | $t' \to j'$ | $p$ |
|3) | $e * j$ | $p$ |
|4) | $e$ | $S \ 3$ 
|5) | $j$ | $S \ 3$
|6) | $s$ | $MP \ 1,4$ 
|7) | $t$ | $MT \ 2,5$
|8) | $t * s$ | $U \ 6,7$|
---
4) Provar $s$ dadas as premissas:

| tipo | argumento | regra de inferencia ou equivalencia | 
|:----:|:---------:|:-----------------------------------:|
|1) | $p \to q * r$ | $p$ |
|2) | $p$ | $p$ 
|3) | $t \to q'$ | $p$
|4) | $t' + s$ | $p$
|5) | $q * r$ | $MP \ 1, 2$
|6) | $q$ | $S \ 5$ 
|7) | $t'$ | $MT \ 3,6$
|8) | $s$ | $SD \ 4,7$ 
---
5) Provar $r+s'$ dadas as premissas:

| tipo | argumento | regra de inferencia ou equivalencia | 
|:----:|:---------:|:-----------------------------------:|
|1) | $s * q$ | $p$ 
|2) | $t \to q'$ | $p$
|3) | $t' \to r$ | $p$
|4) | $q$ | $S \ 1$
|5) | $t'$ | $MT \ 2,5$
|6) | $r$ | $MP \ 3,6$
|7) | $r+s'$ | $A \ 6$
---
6) Provar $x+y=5$ dadas as premissas:

$a \implies 3x + y = 11$

$b \implies 3x=9$

$c \implies y=2$

$d \implies x+y=5$

| tipo | argumento | regra de inferencia ou equivalencia |
|:----:|:---------:|:-----------------------------------:|
|1) | $a \longleftrightarrow b$ | $p$ 
|2) | $(b \to a) \longleftrightarrow c$ | $p$
|3) | $c' + d$ | $p$
|4) | $(a \to b) * (b \to a)$ | $bicondicional \ 1$
|5) | $((b \to a) \to c) * (c \to (b \to a))$ | $bicondicional \ 2$ 
|6) | $b \to a$ | $S \ 4$
|7) | $(b \to a) \to c$ | $S \ 5$
|8) | $c$ | $MP \ 7,6$
|9) | $d$ | $SD \ 3,8$
---
## Utilizando a demonstracao condicional
7) Provar $a \to h$ dadas as premissas:

| tipo | argumento | regra de inferencia ou equivalencia |
|:----:|:---------:|:-----------------------------------:|
|1) | $a+f \to g$ | $p$ 
|2) | $j \to g' * h'$ | $p$
|3) | $j$ | $p$ 
|4) | $a$ | $pp$ 
|5) | $a+f$ | $A$
|6) | $g$ | $MP$
|7) | $g' * h'$ | $MP \ 2,3$
|8) | $g'$ | $S \ 7$
|9) | $g+h$ | $A \ 6$
|10) | $g'+h$ | $A \ 9$
|11) | $h$ | $S+ \ 9,10$
|12) | $a \to h$ | $PC 4 \ a \ 11$
---
8) Provar $t+s' \to r$ dadas as premissas:

| tipos | argumento | regra de inferencia ou equivalencia | 
|:-----:|:---------:|:-----------------------------------:|
|1) | $r' \to q$ | $p$ 
|2) | $t'$ | $p$ | $p$
|3) | $s' \to q'$ | $p$
|4) | $t+s'$ | $pp$
|5) | $s'$ | $MT \ 4,2$
|6) | $q'$ | $MP \ 3,5$
|7) | $r$ | $MT \ 1,7$
|8) | $t+s' \to r$ | $PC \ 4 \ a \ 7$
---
9) Provar $q' \to t$ dadas as premissas:

| tipos | argumento | regra de inferencia ou equivalencia | 
|:-----:|:---------:|:-----------------------------------:|
|1) | $s \to r$ | $p$ 
|2) | $s+p$ | $p$ 
|3) | $p \to q$ | $p$
|4) | $r \to t$ | $p$
|5) | $q'$ | $pp$
|6) | $p'$ | $MT \ 3,5$
|7) | $s$ | $SD \ 2,6$
|8) | $r$ | $MP \ 1,7$
|9) | $t$ | $MP \ 4,8$
|10) | $q' \to t$ | $PC \ 5 \ a \ 9$
---
10) Provar $y=2 \to x=y$ dadas as premissas:

$a \implies y=2$

$b \implies x=y$

$c \implies x > y$

$d \implies x < y$

$e \implies x=2$

| tipos | argumento | regra de inferencia ou equivalencia | 
|:-----:|:---------:|:-----------------------------------:|
|1) | $b' \to c+d$ | $p$
|2) | $a' + e$ | $p$
|3) | $c+d \to e'$ | $p$
|4) | $b' \to e'$ | $SH \ 1,3$
|5) | $e \to b$ | $contrapositivo \ 4$
|6) | $a \to e$ | $condicional \ 2$
|7) | $a \to b$ | $SH \ 6,5$  
---
11) Provar $t'$ dadas as premissas:  

| tipos | argumento | regra de inferencia ou equivalencia | 
|:----:|:-----:|:-----:|
|1) | $t \to s'$ | $p$
|2) | $f \to t'$ | $p$
|3) | $s+f$ | $p$
|4) | $t$ | $pp$
|5) | $s'$ | $MP \ 1,4$
|6) | $f'$ | $MT \ 2,4$
|7) | $s$ | $SD \ 3,6$
|8) | $s * s'$ | $U \ 5,7$
|9) | $t'$ | $PI \ 4,8$
---
12) Provar $e'+m$ dadas as premissas:

| tipos | argumetno | regra de inferencia ou equivalencia |
|:-----:|:---------:|:-----------------------------------:|
|1) | $s+r$ | $p$
|2) | $s \to e'$ | $p$
|3) | $r \to m$ | $p$
|4) | $(e'+m)'$ | $pp$
|5) | $e * m'$ | $DM \ 4$
|6) | $e$ | $S \ 5$
|7) | $m'$ | $S \ 5$
|8) | $s'$ | $MT \ 2,6$
|9) | $r'$ | $MT \ 3,7$
|10) | $r$ | $SD \ 1,8$
|11) | $r * r'$ | $U \ 9, 10$
|12) | $e'+m$ | $PI \ 4 \ a \ 11$
---
13) provar $(t+s)'$ dadas as premissas:

| tipos | argumentos | regra de inferencia ou equivalencia | 
|:-----:|:----------:|:-----------------------------------:|
|1) | $r'+b'$ | $p$
|2) | $t+s \to r$ | $p$
|3) | $b+s'$ | $p$
|4) | $t'$ | $p$
|5) | $t+s$ | $pp$
|6) | $r$ | $MP \ 2,5$
|7) | $b'$ | $SD \ 1,6$
|8) | $s'$ | $SD \ 3,7$
|9) | $s$ | $SD \ 5,4$
|10) | $s * s'$ | $U \ 8,9$
|11) | $(t+s)'$ | $PI \ 5 \ a \ 10$
---
## Utilizando a demonstracao indireta do condicional
14) Provar $p \to q$ dadas as premissas:

| tipos | argumentos | regra de inferencia ou equivalencia |
|:-----:|:----------:|:------------------------------------|
|1) | $(p \to q)+r$ | $p$
|2) | $s+t \to r'$ | $p$
|3) | $s+(t * u)$ | $p$
|4) | $p$ | $pp$
|5) | $q'$ | $pp$
|6) | $(s+t) * (s+u)$ | $Distributiva \ 3$
|7) | $s+t$ | $S \ 6$
|8) | $r'$ | $MP \ 2,7$ 
|9) | $p \to q$ | $SD \ 1,8$
|10) | $p' + q$ | $Condicional \ 9$
|11) | $p'$ | $SD \ 10,5$
|12) | $p * p'$ | $U 4,11$
|13) | $p \to q$ | $PIC 4 \ a \ 12$
---
15) Provar $p \to q$ dadas as premissas:

| tipos | argumentos | regra de inferencia ou equivalencia |
|:-----:|:-----------|:------------------------------------|
|1) | $p \to q+r$ | $p$
|2) | $r'$ | $p$
|3) | $p$ | $pp$
|4) | $q'$ | $pp$
|5) | $q+r$ | $MP \ 1,3$
|6) | $q$ | $SD \ 5,2$
|7) | $q * q'$ | $U \ 4,6$
|8) | $p \to q$ | $PIC \ 3 \ a \ 7$
---
16) Provar $p \to s$ dadas as premissas:

| tipos | argumentos | regra de inferencia ou equivalencia |
|:-----:|:----------:|:-----------------------------------:|
|1) | $(p \to q)+(r * )$ | $p$
|2) | $q'$ | $p$
|3) | $p$ | $pp$
|4) | $s'$ | $pp$
|5) | $p'+q+(r * s)$ | $DM \ 1$
|6) | $(p'+(r * s))+q$ | $ASS \ 5$
|7) | $p'+(r * s)$ | $MT \ 6,2$
|8) | $r * s$ | $SD \ 7,3$
|9) | $s$ | $S \ 8$
|10) | $s * s'$ | $U \ 4,9$
|11) | $p \to s$ | $PIC \ 3 \ a \ 10$

## Utilizando um metodo dedutivo de sua escolha
17) Provar $p \to q'$ dadas as premissas:

| tipos | argumentos | regra de inferencia ou equivalencia | 
|:-----:|:----------:|:-----------------------------------:|
|1) | $p * q \to r'+s'$ | $p$
|2) | $r * s$ | $p$
|3) | $p$ | $pp$
|4) | $p * q \to (r*s)'$ | $DM \ 1$
|5) | $(p*q)'$ | $MT \ 4,2$
|6) | $p'+q'$ | $DM \ 5$
|7) | $q'$ | $MT \ 6,3$
|8) | $p \to q'$ | $PC \ 3 \ a \ 7$
---
18) Provar $p' \to r'$ dadas as premissas:

| tipos | argumentos | regra de inferencia ou equivalencia |
|:-----:|:----------:|:-----------------------------------:|
|1) | $p+q$ | $p$
|2) | $r'+q'$ | $p$
|3) | $p'$ | $pp$
|4) | $q$ | $SD \ 1,3$ 
|5) | $r'$ | $SD \ 2,4$
|6) | $p' \to r'$ | $PC \ 3 \ a \ 5$
---
19) provar $s'$ dadas as premissas:

| tipos | argumentos | regra de inferencia ou equivalencia | 
|:-----:|:----------:|:-----------------------------------:|
|1) | $p+q$ | $p$
|2) | $s \to p'$ | $p$
|3) | $(q+r)'$ | $p$
|4) | $s$ | $pp$
|5) | $p'$ | $MP \ 2,4$
|6) | $q$ | $MT \ 1,5$
|7) | $q' * r'$ | $DM \ 3$
|8) | $q'$ | $S \ 7$
|9) | $q * q'$ | $U \ 6,8$
|10) | $s'$ | $PI 4 \ a \ 9$
---
20) Provar $s'$ dadas as premissas:

| tipos | argumentos | regra de inferencia ou equivalencia | 
|:-----:|:----------:|:-----------------------------------:|
|1) | $(p \to q) \to (r * s \to t)$ | $p$
|2) | $p \to q * r$ | $p$ 
|3) | $r$ | $p$
|4) | $(q * r)' + r$ | $A \ 3$
|5) | $(q * r) \to r$ | $Condicional \ 4$
|6) | $p \to r$ | $SH \ 2,5$
|7) | $(r * s \to t)' + (p \to r)$ | $A \ 6$
|8) | $(r * s \to t) \to (p \to r)$ | $Condicional \ 7$
|9) | $(p \to q) \to (p \to r)$ | $SH \ 1,8$
|10) | $(p' + q)' + (p' + r)$ | $Condicional \ 9$
|11) | $p * q' + p * r'$ | $DM \ 10$
|12) | $p * (q'+r')$ | $Distributiva \ 11$
|13) | $p$ | $S \ 12$
|14) | $(q'+r')$ | $S \ 12$
|15) | $(q*r)'$ | $DM \ 14$
|16) | $p'$ | $MT \ 2,15$
|17) | $p * p'$ | $U \ 13,16$
|18) | s' | $PI \ 4 \ a \ 17$
---
21) Provar $2x = 12 \to y = 4$ dadas as premissas:

$a \implies 2x + 3y = 24$

$b \implies x=6$

$c \implies y=4$

$d \implies 2x=12$

| tipos | argumentos | regra de inferencia ou equivalencia | 
|:-----:|:----------:|:-----------------------------------:|
|1) | $a$ | $p$
|2) | $(b \to c) + d$ | $p$
|3) | $(d \to b) + a'$ | $p$
|4) | $b'$ | $p$
|5) | $d \to b$ | $SD \ 3,1$
|6) | $d'$ | $MT \ 5,4$
|7) | $d'+c$ | $A \ 6$
|8) | $d \to c$ | $Condicional \ 7$
---
23) Nas demonstracoes abaixo, justificar as passagens indicadas

a)  
| tipos | argumento | regra de inferencia ou equivalencia | 
|:-----:|:---------:|:-----------------------------------:|
|1) | $p \to q$ | $p$
|2) | $r' \to q'$ | $p$
|3) | $(p'+s')'$ | $p$
|4) | $p * s$ | `DM 4` |
|5) | $p$ | `S 4` | 
|6) | $q$ | `MP 1,5` |
|7) | $r$ | `MT 2,6` | 
|8) | $s$ | `S 4` |
|9) | $r * s$ | `U 7,8` | 
---
b)  
| tipos | argumento | regra de inferencia ou equivalencia | 
|:-----:|:---------:|:-----------------------------------:|
|1) | $j \to e'$ | $p$
|2) | $(s' * s')'$ | $p$
|3) | $j$ | $p$ 
|4) | $e+s$ | `DN 2` |
|5) | $e'$ | `MP 1,3` |
|6) | $s$ | `MD 4,5` |
---
c)  
| tipos | argumento | regra de inferencia ou equivalencia | 
|:-----:|:---------:|:-----------------------------------:|
|1) | $a \to (b \to c)$ | $p$
|2) | $(c * d) \to e$ | $p$
|3) | $f \to (b * d)$ | $p$
|4) | $(f'+a')'$ | $p$
|5) | $f * a$ | `DM 4` | 
|6) | $f$ | `S 5` | 
|7) | $b * d$ | `MP 3,6` | 
|8) | $a$ | `S 5` |
|9) | $b \to c$ | `MP 1,8` |
|10) | $b$ | `S 7` |
|11) | $c$ | `MP 9,10` |
|12) | $d$ | `S 7` | 
|13) | $c * d$ | `U 11,12` | 
|14) | $e$ | `MP 2,13` |
---
d)  
| tipos | argumento | regra de inferencia ou equivalencia | 
|:-----:|:---------:|:-----------------------------------:|
|1) | $(p * q')+(q * r')$ | $p$
|2) | $p \to s$ | $p$
|3) | $s'+t$ | $p$
|4) | $t'$ | $p$
|5) | $s'$ | `SD 3,4` |
|6) | $p'$ | `MT 2,5` |
|7) | $p'+q$ | `A 6` |
|8) | $(p' * q')'$ | `Equivalencia 7` |
|9) | $q * r'$ | `SD 1,8` |
|10) | $q$ | `S 9` |
---
e)  
| tipos | argumento | regra de inferencia ou equivalencia | 
|:-----:|:---------:|:-----------------------------------:|
|1) | $(b * c') \to a'$ | $p$
|2) | $a \to (b' * d)$ | $p$
|3) | $a$ | $pp$
|4) | $b'*d$ | `MP 2,3` |
|5) | $b'$ | `S 4` |
|6) | $b * c$ | `MT 1,3` |
|7) | $b$ | `S 6` |
|8) | $a'$ | `PC 3 a 7` |
---
f)  
| tipos | argumentos | regra de inferencia ou equivalencia |
|:-----:|:----------:|:-----------------------------------:|
|1) | $(a' \to b')'+c$ | $p$
|2) | $d * a + d * b'$ | $p$
|3) | $c \to (d \to b)$ | $p$
|4) | $d * (a+b')$ | `Distributiva 2` |
|5) | $a+b'$ | `S 4` |
|6) | $a' \to b'$ | `Condicional 5` |
|7) | $c$ | `SD 1,6` |
|8) | $d \to b$ | `MP 3,7` |
|9) | $d$ | `S 4` |
|10) | $b$ | `MP 8,9` |
|11) | $a$ | `MT 6,10` |
---
g)  
| tipos | argumentos | regra de inferencia ou equivalencia |
|:-----:|:----------:|:-----------------------------------:|
|1) | $b' \to a'$ | $p$
|2) | $b \to (c+d)$ | $p$
|3) | $a * c'$ | $pp$
|4) | $a$ | `S 3` |
|5) | $b$ | `MT 1,3` |
|6) | $c+d$ | `MP 2,5` |
|7) | $c'$ | `S 3` |
|8) | $d$ | `SD 6,7` |
|9) | $(a * c') \to d$ | `PC 3 a 8` |
---
h)  
| tipos | argumentos | regra de inferencia ou equivalencia |
|:-----:|:----------:|:-----------------------------------:|
|1) | $r \to (p+q)'$ | $p$
|2) | $s \to p$ | $p$
|3) | $(s \to r')'$ | $pp$
|4) | $(s'+r')'$ | `Condicional 3` |
|5) | $s * r$ | `DM 4` |
|6) | $s$ | `S 5` |
|7) | $p$ | `MP 2,6` |
|8) | $r$ | `S 5` |
|9) | $(p+q)'$ | `MP 1,8` |
|10) | $p' * q'$ | `DM 9` |
|11) | $p'$ | `S 10` |
|12) | $s \to r'$ | `PI 3 a 11` |
---
i)  
| tipos | argumentos | regra de inferencia ou equivalencia |
|:-----:|:----------:|:-----------------------------------:|
|1) | $a \to (b \to c)$ | $p$
|2) | $(a * d) + (a * a)$ | $p$
|3) | $(b'+d)'$ | $pp$
|4) | $a * (d+e)$ | `Distributiva 2` |
|5) | $a$ | `S 4` |
|6) | $b \to c$ | `MP 1,5` |
|7) | $b * d'$ | `DM 3` |
|8) | $b$ | `S 7` |
|9) | $c$ | `MP 6,8` |
|10) | $d + e$ | `S 4` |
|11) | $d'$ | `S 7` |
|12) | $e$ | `SD 10,11` |
|13) | $c * e$ | `U 9,12` |
|14) | $(b'+d)' \to (c * a)$ | `PC 3 a 13` |
