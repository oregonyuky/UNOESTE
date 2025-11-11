void insereR(kdTree **raiz, int ponto[k], int n){
    int d;
    if(!*raiz)*raiz = Cria_no(ponto);
    else{
        d = n%k;
        if(ponto[d] < (*raiz)->ponto[d])insereR(&(*raiz)->esq, ponto, n+1);
        else insereR(&(*raiz)->dir, ponto, n+1);
    }
}