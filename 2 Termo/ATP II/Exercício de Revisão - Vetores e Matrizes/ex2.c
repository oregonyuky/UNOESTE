#include <stdio.h>
int main(){
    for(int i=0;i<TFP;i++){
        printf("Digite o produto:\n");
        gets(vProduto[i]);
        getchar();
        printf("Digite o preco\n");
        scanf("%f", &vPreco[i]);
        printf("Digite o estoque\n");
        scanf("%d", &vEstoque[i]);
    }
    for(int i=0;i<TFC;i++){
        printf("Digite o nome dos clientes:\n");
        gets(vClientes[i]);
    }
    printf("Digite o nome do cliente:\n");
    gets(nome);
    getchar();
    while(i<TFV){
        while(pos<TL && nome!=vClientes[pos])
            pos++;
        if(pos==TL){
            printf("Codigo nao existe\n");
        }
        else{
            
        }
    }
}