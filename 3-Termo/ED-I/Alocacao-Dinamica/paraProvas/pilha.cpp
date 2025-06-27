#define MAXPILHAS 100
struct tpPilha{
	int TOPO[MAXPILHAS], BASE[MAXPILHAS];
	char PILHA[MAXPILHAS];
};

void inicializar(tpPilha &p, int qtdePilhas)
{
	int i, qtdeElem = MAXPILHAS/qtdePilhas;
	for(i=0; i<qtdePilhas; i++)
	{
		p.BASE[i] = i * qtdeElem;
		p.TOPO[i] = p.BASE[i] - 1;
	}
}

char vazia(tpPilha p, int np)
{
	return p.TOPO[np] < p.BASE[np];
}

char cheia(tpPilha p, int np)
{
	return p.TOPO[np] == p.BASE[np+1] - 1;
}

void push(tpPilha &p, int np, char elem)
{
    p.PILHA[++p.TOPO[np]] = elem;  
}

char pop(tpPilha &p, int np)
{
		return p.PILHA[p.TOPO[np]--];
}
char elementotopo(tpPilha p, int np)
{
	return p.PILHA[p.TOPO[np]];
}

void exibir(tpPilha p, int np)
{
	while(!vazia(p, np))
	{
		printf("%c", pop(p, np));
	}		
}

