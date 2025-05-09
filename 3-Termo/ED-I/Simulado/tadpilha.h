#define MAXPILHA 10

struct TpPilha
{
    int TOPO;
    char PILHA[MAXPILHA];
};

void inicializar(TpPilha &p);
void push(TpPilha &p, char Elemento);
char pop(TpPilha &p);
char elementoTopo(TpPilha p);
char cheia(int topo);
char vazia(int topo);
int exibe(TpPilha p);

void inicializar(TpPilha &p)
{
    p.TOPO = -1;
}

void push(TpPilha &p, char Elemento)
{
    p.PILHA[++p.TOPO] = Elemento;
}

char pop(TpPilha &p)
{
    return p.PILHA[p.TOPO--];
}

char elementoTopo(TpPilha p)
{
    return p.PILHA[p.TOPO];
}

char cheia(int topo)
{
    return topo == MAXPILHA-1;
}

char vazia(int topo)
{
    return topo == -1;
}

int exibe(TpPilha p)
{
   while( !vazia(p.TOPO) )
        printf("\n%c",pop(p));
}



