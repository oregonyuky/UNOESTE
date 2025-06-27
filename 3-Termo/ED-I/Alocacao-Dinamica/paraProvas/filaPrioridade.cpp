#define MAXFILA 10

struct tpCham { // tempo = tempoC - tempoA
	char prioridade[40]; // tipo
	int tempoA;
	int tempoC;
	char nome[31];
	char data[11];
	char genero[10];
};

struct tpFilaP {
	int FIM;
	tpCham FILA[MAXFILA];
};
void inicializar(tpFilaP &F) {
	F.FIM = -1;	
}
void inserir(tpFilaP &F, tpCham elem) {
	tpCham aux;
	F.FILA[++F.FIM] = elem;
	for(int i=F.FIM; i > 0 && F.FILA[i].prioridade[0] > F.FILA[i-1].prioridade[0]; i--) {
		aux = F.FILA[i];
		F.FILA[i] = F.FILA[i-1];
		F.FILA[i-1] = aux;
	}
}
tpCham retirar(tpFilaP &F) {
	tpCham retirado = F.FILA[0];
	for(int i=0; i<F.FIM; i++) F.FILA[i] = F.FILA[i+1];
	F.FIM--;
	return retirado;
}
char vazia(int FIM) {
	return FIM == -1;
}
char cheia(int FIM) {
	return FIM == MAXFILA-1;
}
tpCham elemInicio(tpFilaP F) {
	return F.FILA[0];
}
tpCham elemFim(tpFilaP F) {
	return F.FILA[F.FIM];
}
void exibir(tpFilaP F) {
	tpCham aux;
	while(!vazia(F.FIM)) {
		aux = retirar(F);
		printf("%s, %d - %d: %s, %s, %s", aux.prioridade, aux.tempoC, aux.tempoA, aux.nome, aux.data, aux.genero);
	}
}

