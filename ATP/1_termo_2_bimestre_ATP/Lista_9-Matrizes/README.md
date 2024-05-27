![image](https://github.com/oregonyuky/UNOESTE/assets/152916454/282681b1-a500-4a2e-9e02-27d757a3bd69)
![image](https://github.com/oregonyuky/UNOESTE/assets/152916454/3a8917da-6d4c-43e6-a7ac-9c828af23592)

## Ex 1
```c
 #include <stdio.h>
 int main(){
    int ma[3][3], maior=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d", &ma[i][j]);
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            maior = (maior < ma[i][j]) ? ma[i][j] : maior;
        }
    }
    printf("maior numero eh %d\n", maior);
    return 0;
 }
 ```
 ## Ex 2
 ```c
 #include <stdio.h>

int main() {
    int ma[5][4], qtd_itens[5] = {0}, maior, menor, l=1,
		custo_total[5], custo_armazem[5];
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 4; j++) {
            scanf("%d", &ma[i][j]);
            if(i != 4) {
                qtd_itens[i] += ma[i][j];
            }
        }
    }
    maior = ma[0][1];
    menor = ma[0][3];
    int maior_index = 0;
    int menor_index = 0;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(ma[i][1] > maior) {
				maior = ma[i][1];
				maior_index = i;
			}
			if(ma[i][3] < menor) {
				menor = ma[i][3];
				menor_index = i;
			}
			custo_total[i] += ma[4][i]*ma[j][i];
			custo_armazem[i] += ma[4][i]*ma[i][j];
		}
	}
    for(int i = 0; i < 4; i++) {
        printf("Qtd de Armazem %d: %d\n", i + 1, qtd_itens[i]);
    }
    printf("\nMaior estoque do produto 2: Armazem %d\n", maior_index + 1);
    printf("Menor estoque do produto 4: Armazem %d\n\n", menor_index + 1);

	for(int i=0;i<4;i++){
		printf("Custo total do produto %d: %d\n", i+1, custo_total[i]);
	}
	printf("\n");
	for(int i=0;i<4;i++){
		printf("Custo total de armazem %d: %d\n", i+1, custo_armazem[i]);
	}

    return 0;
}
```
## Ex 3
```c
#include <stdio.h>
int main(){
	int vet[5][5], vendas[5]={0}, vendas2[5]={0}, total=0, semana[5]={0},k=1;
	for(int i=0;i<4;i++){
		for(int j=0;j<5;j++){
			printf("Digite o dia %d:\n", k);
			scanf("%d", &vet[i][j]);
			vendas[i] += vet[i][j];
			k++;
		}
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<4;j++)
			semana[i] += vet[j][i];
	}
	for(int i=0;i<5;i++){
		printf("Total de vendas do mes do vendedor %d: %d\n", i+1, semana[i]);
		total+=semana[i];
	}
	for(int i=0;i<4;i++){
		printf("Total de vendas da semana %d: %d\n", i+1, vendas[i]);
	}
	printf("total de vendas do mes: %d\n", total);
	return 0;
}
```
## Ex 4
```c
#include <stdio.h>
int main(){
    int vet[3][4], vet1[3][4], vet2[3][4];
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            scanf("%d", &vet[i][j]);
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            scanf("%d", &vet1[i][j]);
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            vet2[i][j] = vet[i][j] + vet1[i][j];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            printf("%d ", vet2[i][j]);
        }
        printf("\n");
    }
    return 0;
}
```
## Ex 5
```c
#include <stdio.h>
#define TF 5
int main(){
    int soma=0, vet[TF][TF];
    for(int i=0;i<TF;i++){
        for(int j=0;j<TF;j++){
            scanf("%d", &vet[i][j]);
            if(i==j)soma+=vet[i][j];
        }
    }
    printf("A soma do elemento da diagonal %d\n", soma);
    return 0;
}
```
## Ex 6 
```c
#include <stdio.h>
#define TF 3
int main(){
    int vet[TF][TF], maior, menor, pos[TF], posl[TF], k=0;
    for(int i=0;i<TF;i++){
        for(int j=0;j<TF;j++){
            scanf("%d", &vet[i][j]);
        }
    }
    maior = menor = vet[0][0];
    for(int i=0;i<TF;i++){
        for(int j=0;j<TF;j++){
            if(maior < vet[i][j]){
                maior = vet[i][j];
                
            }
        }
    }
    for(int i=0;i<TF;i++){
        for(int j=0;j<TF;j++){
            if(vet[i][j]==maior){
                pos[k] = i;
                posl[k] = j;
                k++;
            }
        }
    }
    printf("maior numero eh %d\n", maior);
    for(int i=0;i<k;i++)
        printf("na linha[%d] coluna[%d]\n", pos[i], posl[i]);
    return 0;
}
```
## Ex 7
```c
#include <stdio.h>
#define n 3
#define m 3
int main(){
    float vet[n][m], vet1[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%f", &vet[i][j]);
            vet1[i][j] = vet[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            vet[i][j] /= vet1[i][i];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%.2f ", vet[i][j]);
        }
        printf("\n");
    }
    return 0;
}
```
## Ex 8
```c
#include <stdio.h>
int main(){
    int n, m, k, l, vet[100][100], vet1[100][100];
    printf("digite o n:\n");
    scanf("%d", &n);
    printf("digite o m:\n");
    scanf("%d", &m);
    printf("digite o k:\n");
    scanf("%d", &k);
    printf("digite o l:\n");
    scanf("%d", &l);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &vet[i][j]);
        }
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<l;j++){
            scanf("%d", &vet1[i][j]);
        }
    }
    if(n==k && m==l){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vet[i][j] *= vet1[i][j];
            }
        }
        printf("\n");
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                printf("%d ", vet[i][j]);
            }
            printf("\n");
        }
    }
    else
        printf("nao da para multiplicar\n");
    return 0;
}
```
## Ex 9
```c
#include <stdio.h>
#define TF 3
int main(){
    int vet[TF][TF], vet1[TF][TF];
    for(int i=0;i<TF;i++){
        for(int j=0;j<TF;j++){
            scanf("%d", &vet[i][j]);
        }
    }
    for(int i=0;i<TF;i++){
        for(int j=0;j<TF;j++){
            scanf("%d", &vet1[i][j]);
        }
    }
    for(int i=0;i<TF;i++){
        for(int j=0;j<TF;j++){
            vet[i][j] -= vet1[i][j];
        }
    }
    for(int i=0;i<TF;i++){
        for(int j=0;j<TF;j++){
            printf("%d ", vet[i][j]);
        }
        printf("\n");
    }
    return 0;
}
```
## Ex 10
```c
#include <stdio.h>
#define TF 3
int main(){
    int aux[TF][TF], vet[TF][TF];
    for(int i=0;i<TF;i++){
        for(int j=0;j<TF;j++){
            scanf("%d", &vet[i][j]);
        }
    }
    for(int i=0;i<TF;i++){
        for(int j=0;j<TF;j++){
            aux[i][j]=1;
            while(vet[i][j]>0){
                aux[i][j] *= vet[i][j];
                vet[i][j]--;
            }
        }
    }
    printf("\n");
    for(int i=0;i<TF;i++){
        for(int j=0;j<TF;j++){
            printf("%d ", aux[i][j]);
        }
        printf("\n");
    }
    return 0;
}
```
## Ex 11
```c
#include <stdio.h>
#define TF 3
int main(){
    int aux[TF][TF], vet[TF][TF];
    for(int i=0;i<TF;i++){
        for(int j=0;j<TF;j++){
            scanf("%d", &vet[i][j]);
        }
    }
    for(int i=0;i<TF;i++){
        for(int j=0;j<TF;j++){
            aux[i][j]=1;
            while(vet[i][j]>0){
                aux[i][j] *= vet[i][j];
                vet[i][j]--;
            }
        }
    }
    printf("\n");
    for(int i=0;i<TF;i++){
        for(int j=0;j<TF;j++){
            printf("%d ", aux[i][j]);
        }
        printf("\n");
    }
    return 0;
}
```
## Ex 12
```c
#include <stdio.h>
#define M 3
int main(){
    int vet[M][M], vet1[M][M], vet2[M][M], vet3[M][M], soma[M][M],
    multi[M][M], quatro[M][M];
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            scanf("%d", &vet[i][j]);
        }
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            scanf("%d", &vet1[i][j]);
        }
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            vet2[i][j] = vet1[j][i];
        }
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            vet3[i][j] = vet[j][i];
        }
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            soma[i][j] = vet[i][j] + vet2[i][j];
            multi[i][j] = vet1[i][j] * vet3[i][j];
            quatro[i][j] = vet2[i][j] + vet3[i][j]*4;
        }
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            printf("%d ", soma[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            printf("%d ", multi[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            printf("%d ", quatro[i][j]);
        }
        printf("\n");
    }
    return 0;
}
```
## Ex 13
```c
#include <stdio.h>
int main(){
    int junho[5][5], julho[5][5], agosto[5][5], produto[5]={0}, soma[5]={0};
    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            scanf("%d", &junho[i][j]);
        }
    }
    printf("\n");
    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            scanf("%d", &julho[i][j]);
        }
    }
    printf("\n");
    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            scanf("%d", &agosto[i][j]);
        }
    }
    for(int i=0;i<3;i++){
        printf("loja %d:\n",i+1);
        for(int j=0;j<5;j++){
            printf("Produto %d: %d estoques\n", j+1, junho[j][i]+julho[j][i]+agosto[j][i]);
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            produto[i] += junho[i][j]+julho[i][j]+agosto[i][j];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            soma[i] += junho[j][i]+julho[j][i]+agosto[j][i];
        }
    }
    printf("\n");
    for(int i=0;i<5;i++){
        printf("Total vendido de produto %d: %d estoques\n", i+1, produto[i]);
    }
    printf("\n");
    for(int i=0;i<3;i++){
        printf("Total vendido de loja %d: %d estoques\n",i+1, soma[i]);
    }
    return 0;
}
```
## Ex 14
```c
#include <stdio.h>
#include <math.h>
#define TF 5
int main(){
    int a[TF], vet[TF][TF], aux, k=0, b[TF]; 
    for(int i=0;i<TF;i++){
        printf("digite o elemento %d:\n",i+1);
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    for(int i=0;i<TF;i++){
        for(int j=0;j<3;j++){
            if(j==0){
                vet[i][j] = a[i]+5;
            }
            if(j==1){
                aux=1;
                while(a[i]>0){
                    aux*=a[i];
                    a[i]--;
                }
                vet[i][j] = aux;
            }
            if(j==2){
                vet[i][j] = b[i]*b[i];
            }
        }
    }
    for(int i=0;i<TF;i++){
        for(int j=0;j<3;j++){
            printf("%d ", vet[i][j]);
        }
        printf("\n");
    }
    return 0;
}
```
