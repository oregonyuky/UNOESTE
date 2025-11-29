#include <stdio.h>
#include <stdlib.h>
typedef struct reg{
    int esq, info, dir;
} Reg;
char arquivoVazio(FILE *file){
    fseek(file, 0, 2);
    int t = ftell(file);
    rewind(file);
    return t == 0;
}
int gravar(FILE *file, int info){
    Reg r;
    r.dir = r.esq = -1;
    r.info = info;
    fseek(file, 0, 2);
    fwrite(&r, sizeof(Reg),1 , file);
    return ftell(file)/sizeof(Reg) - 1;
}
void insercaoDiscoABB(FILE *file, int info){
    Reg r;
    if(arquivoVazio(file)){
        r.esq = r.dir = -1;
        r.info = info;
        fwrite(&r, sizeof(Reg), 1, file);
    }else{
        char e = 1;
        int posA = 0;
        while(e){
            fseek(file, posA * sizeof(Reg), 0);
            fread(&r, sizeof(Reg), 1, file);
            if(r.info < info){
                if(r.dir == -1){
                    r.dir = gravar(file, info);
                    fseek(file, posA * sizeof(Reg), 0);
                    fwrite(&r, sizeof(Reg), 1, file);
                    e = 0;
                }
                else posA = r.dir;
            } else if(r.info > info){
                if(r.esq == -1){
                    r.esq = gravar(file, info);
                    fseek(file, posA * sizeof(Reg), 0);
                    fwrite(&r, sizeof(Reg), 1, file);
                    e = 0;
                }
                else posA = r.esq;
            }
        }
    }
    fclose(file);
}
void exibirEmNivel(FILE *file){
    file = fopen("arquivo.dat", "rb");
    Reg r;
    Fila *f;
    fseek(file, 0, 0);
    fread(&r, sizeof(Reg),1 , file);
    enqueue(&f, 0);
    while(!isEmpty(f)){
        dequeue(&f, &pos);
        fseek(file, pos * sizeof(Reg), 0);
        fread(&r, sizeof(Reg), 1, file);
        printf("%d ", r.info);
        if(r.esq!=-1)enqueue(&f, r.esq);
        if(r.dir!=-1)enqueue(&f, r.dir);
    }
    fclose(file);
}
void excluirNodo(FILE *file, int info){
    
}
int main(){
    FILE *file = fopen("arquivo.dat", "wb");
    if(!file)return 1;
    insercaoDiscoABB(file);
}