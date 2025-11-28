#include <stdio.h>
#include <stdlib.h>
typedef struct registro{
    int numero;
    char nome[50];
    int salario;
    char status;
    int elo;
} TpRegistro;
void JaInserir(){
    FILE *file = fopen("arquivo.dat", "wb");
    if(!file)return;
    TpRegistro r[] = {
        {1950, "Enio", 900.0, 'T', 16},
        {1600, "Eber", 800.0, 'F', 0},
        {0, },
        {0, },
        {3150, "Rui", 550.0, 'T', 0},
        {2150, "Flavio", 420.0, 'F', 0},
        {1450, "Diogo", 1200.0, 'T', 0},
        {0, },
        {1100, "Antonio", 750.0, 'T', 0},
        {1400, "Claudio", 600.0, 'T', 0},
        {1050, "Afonso", 3200.0, 'T', 17},
        {0, },
        {1000, "Ademar", 1200.0, 'T', 14},
        {1700, "Edson", 500.0, 'T', 0},
        {2300, "Gerson", 800.0, 'T', 0},
        {3000, "Ivan", 630.0, 'T', 13},
        {2600, "Luis", 5000.0, 'T', 0},
        {2766, "Pedro", 3000.0, 'T', 15}
    };
    fwrite(&r, sizeof(TpRegistro), 18, file);
}
void consultar(FILE *file, int num, int *ender){
    TpRegistro r;
    int pos=0;
    while(fread(&r, sizeof(TpRegistro), 1, file)==1){
        if(r.numero == num)*ender = pos;
        pos++;
    }
}
void alterar(){
    
}
int main(){

}