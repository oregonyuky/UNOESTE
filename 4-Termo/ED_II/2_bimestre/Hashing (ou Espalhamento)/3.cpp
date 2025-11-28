#include <stdio.h>
#include <stdlib.h>
typedef struct registro{
    int numero;
    char nome[50];
    float salario;
    char status;
    int elo;
} TpRegistro;
void JaInserir(FILE *file){
    TpRegistro r[] = {
        {1950, "Enio", 900.0, 'T', 16},
        {1600, "Eber", 800.0, 'F', 0},
        {0, "", 0.0, '\0', 0},      // lixo
        {0, "", 0.0, '\0', 0},      // lixo
        {3150, "Rui", 550.0, 'T', 0},
        {2150, "Flavio", 420.0, 'F', 0},
        {1450, "Diogo", 1200.0, 'T', 0},
        {0, "", 0.0, '\0', 0},      // lixo
        {1100, "Antonio", 750.0, 'T', 0},
        {1400, "Claudio", 600.0, 'T', 0},
        {1050, "Afonso", 3200.0, 'T', 17},
        {0, "", 0.0, '\0', 0},      // lixo
        {1000, "Ademar", 1200.0, 'T', 14},
        {1700, "Edson", 500.0, 'T', 0},
        {2300, "Gerson", 800.0, 'T', 0},
        {3000, "Ivan", 630.0, 'T', 13},
        {2600, "Luis", 5000.0, 'T', 0},
        {2766, "Pedro", 3000.0, 'T', 15}
    };
    fwrite(r, sizeof(TpRegistro), 18, file);
}
void consultar(FILE *file, int num, int *ender, int *achou){
    TpRegistro r;
    int pos=0;
    while(fread(&r, sizeof(TpRegistro), 1, file)==1){
        if(r.numero == num)*ender = pos;
        pos++;
    }
    if(*ender!=-1)*achou = 1;
    else *achou = -1;
}
void alterar(FILE *file){
    int ender, num, achou;
    file = fopen("arquivo.dat", "r+b");
    do{
        printf("\nNum (-1 para terminar): ");
        scanf("%d", &num);
        if(num == -1) return;
        consultar(file, num, &ender, &achou);
        if(achou==-1){
            puts("Numero nao encontrado.");
            continue;
        }
        TpRegistro r;
        r.numero = num;
        printf("Nome: ");
        getchar(); 
        fgets(r.nome, sizeof(r.nome), stdin);
        printf("Salario: ");
        scanf("%f", &r.salario);
        printf("Status: ");
        getchar();
        scanf("%c", &r.status);
        printf("Elo: ");
        scanf("%d", &r.elo);
        fseek(file, ender * sizeof(TpRegistro), SEEK_SET);
        fwrite(&r, sizeof(TpRegistro), 1, file);
        puts("Alteracao sucedida!");
    } while(1);
}
void relatorio(FILE *file) {
    file = fopen("arquivo.dat", "rb");
    TpRegistro r;
    printf("+--------+----------------------+------------+--------+-----+\n");
    printf("| Numero | Nome                 | Salario    | Status | Elo |\n");
    printf("+--------+----------------------+------------+--------+-----+\n");
    while (fread(&r, sizeof(TpRegistro), 1, file) == 1) {
        printf("| %-6d | %-20s | %10.2f |   %-4c | %-3d |\n",
               r.numero, r.nome, r.salario, r.status, r.elo);
    }
    printf("+--------+----------------------+------------+--------+-----+\n");
}

int main(){
    FILE *file = fopen("arquivo.dat", "wb");
    if(!file)return 1;
    JaInserir(file); fclose(file);
    relatorio(file); fclose(file);
    alterar(file); fclose(file);
    relatorio(file); fclose(file);
}