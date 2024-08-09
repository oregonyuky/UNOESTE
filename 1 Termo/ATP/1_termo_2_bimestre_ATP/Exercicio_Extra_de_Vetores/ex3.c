#include <stdio.h>
#include <string.h>
#define TF 3
int main(){
    int i, vconta[TF], saldo[TF], op, conta, depos, pos, saque, soma=0, por;
    char nome[TF][100];
    for(i=0;i<TF;i++){
        printf("Digite o numero da conta %d\n", i+1);
        scanf("%d", &vconta[i]);
    }
    for(i=0;i<TF;i++){
        printf("Digite o seu nome da conta %d:\n", vconta[i]);
        fflush(stdin);
        scanf("%s", nome[i]);
    }
    for(i=0;i<TF;i++){
        printf("Digite o seu saldo da conta %d:\n", i+1);
        scanf("%d", &saldo[i]);
    }
    printf("\n1.Efetuar deposito\n");
    printf("2.Efetuar saque\n");
    printf("3.Consultar o ativo bancario (ou seja, o somatorio do ssaldos de todos os clientes)\n");
    printf("4.Aplicar uma porcentagem de juros mensal (acrescimo)\n");
    printf("5.Finalizar o programa\n\n");
    scanf("%d", &op);
    while(op!=5){
        switch(op){
            case 1:
                pos=0;
                printf("Digite o codigo da conta:\n");
                scanf("%d", &conta);
                while(pos<TF && conta!=vconta[pos])
                    pos++;
                if(pos==TF){
                    printf("Conta nao encontrada\n");
                }
                else{
                    printf("Qual e o valor a ser depositado?\n");
                    scanf("%d", &depos);
					printf("Nome: %s\n", nome[pos]);
                    printf("Saldo atual: %d\n", saldo[pos]);
                    saldo[pos]+=depos;
                    printf("Saldo atualizado: %d\n", saldo[pos]);
                }
                break;
            case 2:
                pos=0;
                printf("Digite o codigo da conta:\n");
                scanf("%d", &conta);
                while(pos<TF && conta!=vconta[pos])
                    pos++;
                if(pos==TF){
                    printf("Conta nao encontrada\n");
                }
                else{
                    printf("Qual e o valor do saque?\n");
                    scanf("%d", &saque);
                    if(saldo[pos]<saque)
                        printf("Saldo insuficiente\n");
                    else{
                        printf("Nome: %s\n", nome[pos]);
                        printf("Saldo: %d\n", saldo[pos]);
                        saldo[pos]-=saque;
                        printf("Saldo atualizado:%d\n", saldo[pos]);
                    }
                }
                break;
            case 3:
                for(i=0;i<TF;i++){
                    soma += saldo[i];
                }
                printf("Saldo de todas as contas do banco: %d\n", soma);
                break;
            case 4:
                printf("Digite o acrescimo da conta bancaria:\n");
                scanf("%d", &por);
                for(i=0;i<TF;i++){
                    saldo[i]*=(1+por/100);
                }
                break;
			default:
				break;

        }
        printf("\n1.Efetuar deposito\n");
        printf("2.Efetuar saque\n");
        printf("3.Consultar o ativo bancario (ou seja, o somatorio do ssaldos de todos os clientes)\n");
        printf("4.Aplicar uma porcentagem de juros mensal (acrescimo)\n");
        printf("5.Finalizar o programa\n\n");
        scanf("%d", &op);
    }
    return 0;
}
