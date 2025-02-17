#include <stdio.h>
#define TF 10
int main(){
    int i;
    float vet[TF], vet2[TF], media[TF], media_turma, qtd, aprovados, reprovados;
    for(i=0;i<TF;i++){
        printf("Digite a nota da 1o. prova do aluno %d\n", i+1);
        scanf("%f", &vet[i]);
    }
    for(i=0;i<TF;i++){
        printf("Digite a nota da 2o. nota da prova do aluno %d\n", i+1);
        scanf("%f", &vet2[i]);
    }
    media_turma=0;
    qtd=0;
    aprovados=0;
    reprovados=0;
    for(i=0;i<TF;i++){
        media[i] = (vet[i]+vet2[i])/2.0;
        media_turma += media[i];
    }
    media_turma /= TF;
    for(i=0;i<TF;i++){
        if(media[i] < media_turma)qtd++;
        if(media[i] >= 7.0)aprovados++;
        if(media[i] < 7.0)reprovados++;
    }
    printf("\nMedia da turma: %.2f\n", media_turma);
    printf("Quantidade de alunos que obtiveram emdia menor que media geral: %.0f\n", qtd);
    printf("Quantidade de alunos aprovados, isto e, com media >= 7.0: %.0f\n", aprovados);
    printf("Quantidade de alunos reprovados, isto e, com media < 7.0: %.0f\n", reprovados);
    return 0;
}