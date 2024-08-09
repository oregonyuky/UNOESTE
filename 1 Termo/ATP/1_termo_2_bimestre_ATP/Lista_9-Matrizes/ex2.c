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

