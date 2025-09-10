typedef struct reg_list{ 
    struct listaGen *cabeca;
    struct listaGen *cauda;
} lista;
union info_lista{
    char info[8];
    struct reg_list lista;
};
typedef struct listaGen{
    char terminal;
    union info_lista no;
} ListaGen;
typedef struct fila{
    ListaGen *l;
    struct fila *prox;
} Fila;
ListaGen *Head(ListaGen *l){
	return l->no.lista.cabeca;
}
ListaGen *Tail(ListaGen *l){
	return l->no.lista.cauda;
}
ListaGen *Cons(ListaGen *h, ListaGen *t){
    ListaGen *aux = (ListaGen*)malloc(sizeof(ListaGen));
    aux->terminal = 0;
    aux->no.lista.cabeca = h;
    aux->no.lista.cauda = t;
    return aux;
}
ListaGen *CriaT(char *str){
    ListaGen *aux = (ListaGen*)malloc(sizeof(ListaGen));
    aux->terminal = 1;
    strcpy(aux->no.info, str);
    return aux;
}
void init(Fila **f){
    *f = NULL;
}
void enqueue(Fila **f, ListaGen *l){
    Fila *aux = (Fila*)malloc(sizeof(Fila));
    aux->l = l;
    aux->prox = NULL; 
    if(!*f)
        *f = aux;
    else{
        Fila *aux1 = *f;
        while(aux1->prox)aux1 = aux1->prox;
        aux1->prox = aux;
    }
}
void dequeue(Fila **f, ListaGen **l){
    Fila *aux = *f;
    *f = (*f)->prox;
    *l = aux->l;
    free(aux);
}
char isEmpty(Fila *f){
    return f == NULL;
}
char Nula(ListaGen *l){
    return l == NULL;
}
char Atomo(ListaGen *l){
	return !Nula(l) && l->terminal;
}
void Exibir(ListaGen *l){
    if(!Nula(l)){
        if(Atomo(l)){
            printf("%s", l->no.info);
        } else {
            printf("(");
            Exibir(Head(l));
            ListaGen *t = Tail(l);
            while(!Nula(t)){
                printf(" ");
                Exibir(Head(t));
                t = Tail(t);
            }
            printf(")");
        }
    }
}
