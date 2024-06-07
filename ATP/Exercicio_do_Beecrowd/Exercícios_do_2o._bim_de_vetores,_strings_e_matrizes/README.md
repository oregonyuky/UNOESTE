## 1026 - Carrega ou não Carrega?
```c
#include <stdio.h>
#include <math.h>
#define max(a, b) (a)<(b) ? (b) : (a)
#define min(a, b) (a)>(b) ? (b) : (a)
#define ll long long
int main(){
    ll n1, n2, ma, me, sta[33], stb[33], so,i;
    while(scanf("%lld %lld", &n1, &n2)!=EOF){
        so=0;
        i=0;
        ma = max(n1, n2);
        me = min(n1, n2);
        while(ma!=0){
            sta[i] = ma%2;
            stb[i] = me%2;
            ma/=2;
            me/=2;
            i++;
        }
        for(int k=0;k<i;k++){
            if((sta[k]==0 && stb[k]==1) || (sta[k]==1 && stb[k]==0))
                so+=pow(2, k);
        }
        printf("%lld\n", so);
    }
    return 0;
}

```
## 1174 - Seleção em Vetor I
```c
#include <stdio.h>
int main(){
    int a, i;
    float array[100];
    for(i=0;i<100;i++){
        scanf("%f", &array[i]);
    }
    for(i=0;i<100;i++){
        if(array[i]>10)continue;
        printf("A[%d] = %.1f\n", i, array[i]);
    }
    return 0;
}
```
## 1175 - Troca em Vetor I
```c
#include <stdio.h>
int main(){
    int array[20];
    int a, i, j=0;
    for(i=0;i<20;i++){
        scanf("%d", &array[i]);
    }
    for(i=19;i>=0;i--){
        printf("N[%d] = %d\n", j, array[i]);
        j++;
    }
    return 0;
}
```
## 1176 - Fibonacci em Vetor
```c
#include <stdio.h>
#include <math.h>
double fibonaci(double x){
    return (pow((1+sqrt(5))/2.0, x)-pow((1-sqrt(5))/2.0, x))/sqrt(5);
}
int main(){
    double a;
    int b;
    scanf("%d", &b);
    while(b!=0){
        b--;
        scanf("%lf", &a);
        printf("Fib(%.0lf) = %.0lf\n",a ,fibonaci(a));
    }
        return 0;

}
```
## 1179 - Preenchimento de Vetor IV
```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max 5

int main() {
    int array[15], par[max], impar[max];
    int conta_par = 0, conta_impar = 0;
    int i, j;

    for (i = 0; i < 15; i++) {
        scanf("%d", &array[i]);
        
        if (array[i] % 2 == 0) {
            par[conta_par] = array[i];
            conta_par++;
            
            if (conta_par == max) {
                for (j = 0; j < max; j++) {
                    printf("par[%d] = %d\n", j, par[j]);
                }
                conta_par = 0;
            }
        } else {
            impar[conta_impar] = array[i];
            conta_impar++;
            
            if (conta_impar == max) {
                for (j = 0; j < max; j++) {
                    printf("impar[%d] = %d\n", j, impar[j]);
                }
                conta_impar = 0;
            }
        }
    }

    for (i = 0; i < conta_impar; i++) {
        printf("impar[%d] = %d\n", i, impar[i]);
    }

    for (i = 0; i < conta_par; i++) {
        printf("par[%d] = %d\n", i, par[i]);
    }

    return 0;
}

```
## 1182 - Coluna na Matriz
```c
#include <stdio.h>
#define max 12
int main(){
    int a, b, c, d, e;
    float soma=0, soma1=0, numero[max][max], soma2=0;
    char letra;
    scanf("%d", &a);
    scanf(" %c", &letra);
    for(int i=0;i<max;i++){
        for(int j=0;j<max;j++){
            scanf("%f", &numero[i][j]);
        }
    }
    for(int i=0;i<max;i++){
        for(int j=0;j<max;j++){
            soma+=numero[i][j];
        }
    }
    if(letra=='S'){
        for(int j=0;j<max;j++){
            soma1+=numero[j][a];
        }
        printf("%.1f\n", soma1);
    } else if(letra=='M'){
        for(int j=0;j<max;j++){
            soma2+=numero[j][a];
        }
        printf("%.1f\n", soma2/max);
    }
    return 0;
}
```
## 1186 - Abaixo da Diagonal Secundária
```c
#include <stdio.h>
#define max 12
int main(){
    char letra;
    float a, b, c, d, soma=0, soma1=0, soma4=0, numero[max][max];
    scanf(" %c", &letra);
    for(int i=0;i<max;i++){
        for(int j=0;j<max;j++){
            scanf("%f", &numero[i][j]);
        }
    }
    if(letra=='S'){
        for(int i=0;i<max;i++){
            for(int j=0;j<max;j++){
                if(i+j>=12){
                    soma4+=numero[i][j];
                }
            }
        }
        printf("%.1f\n", soma4);
    } else{
        for(int i=0;i<max;i++){
            for(int j=0;j<max;j++){
                if(i+j>=12){
                    soma1+=numero[i][j];
                }
            }
        }
        printf("%.1f\n", soma1/66.0);
    }
    return 0;
}
```
## 1241 - Encaixa ou Não II
```c
#include <stdio.h>
#include <string.h>
int main() {
    int a;
    char de[1001], dp[1001];
    scanf("%d", &a);
    
    while (a--) {
        scanf("%s %s", de, dp);
        int res = 1;
        int i = strlen(de) - 1;
        int j = strlen(dp) - 1;
        
        if (strlen(dp) > strlen(de)) {
            res = 0;
        } else {
            while (i >= 0 && j >= 0) {
                if (de[i] != dp[j]) {
                    res = 0;
                    break;
                }
                i--;
                j--;
            }
        }
        
        res ? printf("encaixa\n") : printf("nao encaixa\n");
    }
    return 0;
}
```
## 1278 - Justificador II
```c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
typedef struct{

	char palavra[51];

} string;
typedef struct{

	char saida[51];

} saida;
int main()
{

	unsigned short casos, aux, tam;
	unsigned short maior, atual, i, j, k;

	scanf("%hu", &casos);
	while (true)
	{	

		if (casos == 0)
			break;
		aux = casos;
		string palavra[aux];
		saida textoSaida[aux];

		i = 0;
		while (casos--)
			scanf(" %[^\n]", palavra[i++].palavra);

		i = 0;
		tam = aux;
		while (aux--)
		{
			j = 0;
			k = 0;
			while (true)
			{
				while (isalpha(palavra[i].palavra[j]))	
					textoSaida[i].saida[k++] = palavra[i].palavra[j++];
				if (palavra[i].palavra[j] == '\0')
					break;
				while (!isalpha(palavra[i].palavra[j]))
				{	
					j++;
					if (palavra[i].palavra[j] == '\0')
						break;
				}
				if (palavra[i].palavra[j] == '\0')
					break;
				textoSaida[i].saida[k++] = ' ';

			}
				textoSaida[i].saida[k] = '\0';
				i++;

				
		}	

				maior = 0;
				for(i = 0; i < tam; i++)
				{
					atual = strlen(textoSaida[i].saida);
					if (atual > maior)
						maior = atual;

				}
		for (i = 0; i < tam; i++)
			printf("%*s\n", maior, textoSaida[i].saida);

		scanf("%hu", &casos);

		if(casos != 0)
			printf("\n");
		
	}
}
```
## 2231 - Temperatura Lunar
```c
#include <stdio.h>
#include <limits.h>
#define MAX_SIZE 10001
int main() {
    int a, b, tem, k = 1;
    int v1[MAX_SIZE];
    
    while (scanf("%d %d", &a, &b) == 2 && a != 0 && b != 0) {
        for (int i = 0; i < a; i++) {
            scanf("%d", &v1[i]);
        }
        
        int menor = INT_MAX;
        int maior = INT_MIN;
        
        for (int i = 0; i < a - b + 1; i++) {
            int sum = 0;
            for (int j = i; j < b + i; j++) {
                sum += v1[j];
            }
            if (sum / b < menor) {
                menor = sum / b;
            }
            if (sum / b > maior) {
                maior = sum / b;
            }
        }
        
        printf("Teste %d\n", k);
        printf("%d %d\n", menor, maior);
        printf("\n");
        k++;
    }
    
    return 0;
}

```
## 2727 - Código Secreto
```c
#include <stdio.h>
#include <string.h>
#define TF 26

int main()
{
    int j;
    char name[100];
    char res[TF], alfa[TF] = "abcdefghijklmnopqrstuvwxyz";

    char ponto[TF][100] = 
    {
    ".", "..", "...",
    ". .", ".. ..", "... ...",
    ". . .", ".. .. ..", "... ... ...",
    ". . . .", ".. .. .. ..", "... ... ... ...",
    ". . . . .", ".. .. .. .. ..", "... ... ... ... ...",
    ". . . . . .", ".. .. .. .. .. ..", "... ... ... ... ... ...",
    ". . . . . . .", ".. .. .. .. .. .. ..", "... ... ... ... ... ... ...",
    ". . . . . . . .", ".. .. .. .. .. .. .. ..", "... ... ... ... ... ... ... ...",
    ". . . . . . . . .", ".. .. .. .. .. .. .. .. .."
    };

    int a;

    while(scanf("%d", &a)!=EOF)
    {
        j=0;
        getchar();
        while(a--)
        {
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';

            for(int i = 0; i < 26; i++)
            {
                if(strcmp(name, ponto[i]) == 0)
                {
                    res[j] = alfa[i];
                    j++;
                }
            }
        }
        for(int i = 0; i < j; i++)
        {
            printf("%c\n", res[i]);
        }
    }
    return 0;
}
```
