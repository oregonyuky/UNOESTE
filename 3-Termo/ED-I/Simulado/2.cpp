#define MAXPILHA 10
struct tpPilha{
    int TOPO;
    int PILHA[MAXPILHA];
};
void inicializar(tpPilha p){
    p.TOPO = -1;
}
void push(tpPilha p, char elemento){
    p.PILHA[++p.TOPO] = elemento;
}
char pop(tpPilha p){
    return p.PILHA[p.TOPO--];
}
char vazia(int topo){
    return topo == -1;
}
char cheia(int topo){
    return topo == MAXPILHA-1;
}
char elementoTopo(tpPilha p){
    return p.PILHA[p.TOPO];
}
struct tpFila{
    Pilha p1;
    Pilha p2;
}
//Fila usando 2 pilhas
void inicializarFila(tpFila &f){
    inicializar(f.p1);
    inicializar(f.p1);
}
void inserirFila(tpFila &f, char elemento){
    push(f.p1, valor);
}
char retirar(tpFila &f){
    while(!vazia(f.p1)){
        push(f.p2, pop(f.p1));
    }
    return pop(f.p2);
}



