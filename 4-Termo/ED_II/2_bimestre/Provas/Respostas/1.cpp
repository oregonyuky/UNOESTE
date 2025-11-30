#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Fila.h"
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
    Fila *f; int pos;
    fseek(file, 0, 0);
    fread(&r, sizeof(Reg),1 , file);
    enqueue(&f, 0);
    while(!isEmptyF(f)){
        dequeue(&f, &pos);
        fseek(file, pos * sizeof(Reg), 0);
        fread(&r, sizeof(Reg), 1, file);
        printf("%d ", r.info);
        if(r.esq!=-1)enqueue(&f, r.esq);
        if(r.dir!=-1)enqueue(&f, r.dir);
    }
    fclose(file);
}
int BuscaIndex(FILE *file, int info){
    Reg T;
    int pos=0;
    char flag = 1;
    rewind(file);
    while(fread(&T, sizeof(Reg), 1, file)==1 && flag){
        if(T.info == info)flag=0;
        else pos++;
    }
    return pos;
}
void apagarPorPos(FILE *file, int pos){
    Reg T;
    fseek(file, 0, 2);
    int total = ftell(file)/sizeof(Reg);
    for(int i=pos;i<total-1;i++){
        fseek(file, (i+1)*sizeof(Reg), 0);
        fread(&T, sizeof(Reg), 1, file);
        fseek(file, i * sizeof(Reg), 0);
        fwrite(&T, sizeof(Reg), 1, file);
    }
     #ifdef _WIN32
        _chsize(_fileno(file), (total - 1) * sizeof(Reg));
    #else
        ftruncate(fileno(file), (total - 1) * sizeof(Reg));
    #endif
}

void excluirNodo(int eInfo, int paiInfo){
    FILE *file = fopen("arquivo.dat", "r+b");
    Reg e, pai, aux, paiAux, temp;
    int posE = BuscaIndex(file, eInfo);
    int posPai = BuscaIndex(file, paiInfo);
    if(posE < 0) return;
    if(posPai < 0) return;
    fseek(file, posE * sizeof(Reg), SEEK_SET);
    fread(&e, sizeof(Reg), 1, file);
    fseek(file, posPai * sizeof(Reg), SEEK_SET);
    fread(&pai, sizeof(Reg), 1, file);
    if(e.esq==-1 && e.dir==-1){
        if(pai.esq == posE) pai.esq = -1;
        else pai.dir = -1;
        fseek(file, posPai * sizeof(Reg), SEEK_SET);
        fwrite(&pai, sizeof(Reg), 1, file);
        apagarPorPos(file, posE);
        return;
    }
    else if(e.esq==-1 || e.dir==-1){
        int filho = (e.esq != -1 ? e.esq : e.dir);
        if(pai.esq == posE) pai.esq = filho;
        else pai.dir = filho;
        fseek(file, posPai * sizeof(Reg), SEEK_SET);
        fwrite(&pai, sizeof(Reg), 1, file);
        apagarPorPos(file, posE);
        return;
    }
    int posAux = e.esq;        // começa pelo maior da subárvore esquerda
    int posPaiAux = posE;
    fseek(file, posAux * sizeof(Reg), SEEK_SET);
    fread(&aux, sizeof(Reg), 1, file);
    paiAux = e;
    while(aux.dir != -1){
        posPaiAux = posAux;

        fseek(file, aux.dir * sizeof(Reg), SEEK_SET);
        fread(&aux, sizeof(Reg), 1, file);

        posAux = aux.dir;
    }
    e.info = aux.info;
    fseek(file, posE * sizeof(Reg), SEEK_SET);
    fwrite(&e, sizeof(Reg), 1, file);
    fseek(file, posPaiAux * sizeof(Reg), SEEK_SET);
    fread(&paiAux, sizeof(Reg), 1, file);
    if(aux.esq != -1)
        paiAux.dir = aux.esq;
    else
        paiAux.dir = -1;
    fseek(file, posPaiAux * sizeof(Reg), SEEK_SET);
    fwrite(&paiAux, sizeof(Reg), 1, file);
    apagarPorPos(file, posAux);
    fclose(file);
}
void teste(){
    FILE *file = fopen("arquivo.dat", "wb");
    Reg r[7] = {
        {4, 10, 1},
        {2, 12, 3},
        {-1, 11, -1},
        {-1, 14, -1},
        {5, 8, 6},
        {-1, 6, -1},
        {-1, 9, -1}
    };
    fwrite(r, sizeof(Reg), 7, file);
    fclose(file);
}
void imprimir(){
    FILE *file = fopen("arquivo.dat", "rb");
    if(!file)perror("Deu erro");
    Reg r;
    while(fread(&r, sizeof(Reg), 1, file)==1){
        printf("(%d, %d, %d)\n", r.esq, r.info, r.dir);
    }
    fclose(file);
}
int main(){
    teste();
    imprimir();
    excluirNodo(11, 12);puts("");
    imprimir();
    //insercaoDiscoABB(file);
}