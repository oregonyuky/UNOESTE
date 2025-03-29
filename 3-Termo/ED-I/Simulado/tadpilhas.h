#define MAXPILHA 10
struct TpPilha{
    int TOPO;
    char PILHA[MAXPILHA];
};
void inicializar(TpPilha &p){
    p.TOPO = -1;
}
void push(TpPilha &p, char elemento){
    p.PILHA[++p.TOPO] = elemento;
}
char pop(TpPilha &p){
    return p.PILHA[p.TOPO--];
}
char cheia(TpPilha p){
    return p.topo == MAXPILHA-1;
}
char vazia(TpPilha p){
    return p.topo == -1;
}
char elementoTopo(TpPilha p){
    return p.PILHA[p.TOPO];
}
void exibir(TpPilha p){
    while(!vazia(p)){
        printf("%c ", pop(p));
    }
}
