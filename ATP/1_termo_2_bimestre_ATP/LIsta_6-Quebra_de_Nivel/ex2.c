#include <stdio.h>
int main(){
    int lab, aluno, num, micro, tempo, menor, ra, l=1, maior,
         maior_lab, menor_ra, mulheres, homens, total_aluno;
    char sexo;
    maior=0;
    total_aluno=0;
    homens=0;
    printf("Digite o numero do laboratorio:");
    scanf("%d", &lab);
    while(lab>0){
        aluno=0;
        mulheres=0;
        l=1;
        printf("Digite o Num.Micro:\n");
        scanf("%d", &num);
        while(num>0){
            printf("Digite o RA:\n");
            scanf("%d", &ra);
            printf("Digite o sexo:\n");
            scanf(" %c", &sexo);
            printf("Digite o tempo:\n");
            scanf("%d", &tempo);
            aluno++;
            if(l==1){
                menor = tempo;
                menor_ra = ra;
            }
            l=0;
            if(menor > tempo){
                menor = tempo;
                menor_ra = ra;
            }
            if(sexo == 'F')mulheres++;
            else homens++;
            printf("Digite o Num.micro:\n");
            scanf("%d", &num);
        }
        printf("Laboratorio %d o aluno com RA %d possui menos tempo com %d\n", lab, menor_ra, menor);
        printf("A porcentagem de mulheres em cada laboratorio: %.2f%%\n", (float)mulheres*100/aluno);
        if(maior < aluno){
            maior = aluno;
            maior_lab = lab;
        }
        total_aluno += aluno;
        printf("Digite o numero do laboratorio:");
        scanf("%d", &lab);
    }
    printf("Porcentagem de homens entre todos os laboratorios:%.2f%%\n", (float)homens*100/total_aluno);
    printf("laboratorio %d possui mais qtd de alunos: %d\n", maior_lab, maior);

}
