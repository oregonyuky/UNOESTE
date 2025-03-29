#define MAXPILHA 30
struct tpPilha{
    int TOPO;
    int PILHA[MAXPILHA];
};
void inicializar(tpPilha &p){
    p.TOPO = -1;
}
void push(tpPilha &p, char elemento){
    p.PILHA[++p.TOPO] = elemento;
}
char pop(tpPilha &p){
    return p.PILHA[p.TOPO--];
}
char vazia(tpPilha p){
    return p.TOPO == -1;
}
char cheia(tpPilha p){
    return p.TOPO == MAXPILHA-1;
}
char elementoTopo(tpPilha p){
    return p.PILHA[p.TOPO];
}
struct tpFila{
    tpPilha p1;
    tpPilha p2;
};
//Fila usando 2 pilhas
void inicializarFila(tpFila &f){
    inicializar(f.p1);
    inicializar(f.p2);
}
void inserirFila(tpFila &f, char elemento){
    push(f.p1, elemento);
}
char retirarFila(tpFila &f){
    while(!vazia(f.p1)){
        push(f.p2, pop(f.p1));
    }
    char elem = pop(f.p2);
    while(!vazia(f.p2)){
        push(f.p1, pop(f.p2));
    }
    return elem;
}
char vaziaFila(tpFila f){
    return vazia(f.p1) && vazia(f.p2);
}
char cheiaFila(tpFila f){
    return cheia(f.p1);
}
char elementoInicio(tpFila f){
    while(!vazia(f.p1)){
        push(f.p2, pop(f.p1));
    }
    return elementoTopo(f.p2);
}
char elementoFim(tpFila f){
    return elementoTopo(f.p1);
}



