#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadFilaP.h"
int main(){
    FILE *arq = fopen("arquivo.txt", "w");
    if(arq==NULL)printf("Erro na hora de ler o arquivo\n");
    else{
        //ID Nome prioridade duracao
        tpCham reg, usuario[1];
        do{
            if(!cheia(F.qtde)){
                fscanf(arq, "%[^;];%[^;];%d;%d\n", reg.id, reg.nome, reg.prioridade, reg.duracao);
                reg.tempoC = duracao;
                inserir(F. reg);
            }
            printf("Duracao: %d\n", duracao);
            for(int j=0;j<1;j++){
                if((usuario[j].tempoA == 0) && !vazia(F.qtde)){

                } 
            }

        }while(duracao-- && !__kbhit());
    }
}
