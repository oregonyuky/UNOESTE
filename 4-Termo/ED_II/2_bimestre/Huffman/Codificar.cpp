#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
262228475 - LARISSA VITORIA MACHADO OLIVEIRA
262310236 - LIVIA GOMES DE SOUZA
*/

struct huffmantree
{
    int freq;
    char simb;
    struct huffmantree *dir;
    struct huffmantree *esq;

};
typedef struct huffmantree HTree;

struct caixas
{
	HTree *arv;
	struct caixas *prox;
};
typedef struct caixas Caixa;

struct tabela
{
	char palavra[30], codHuff[15],simbo;
	int freq;
	struct tabela *prox;
};
typedef struct tabela Tabela;

struct tabelab
{
	char palavra[30], codHuff[15],simbo;
};
typedef struct tabelab TabelaB;
struct bits
{
 unsigned char b7:1;
 unsigned char b6:1;
 unsigned char b5:1;
 unsigned char b4:1;
 unsigned char b3:1;
 unsigned char b2:1;
 unsigned char b1:1;
 unsigned char b0:1;
};
union byte
{
 struct bits bi;
 unsigned char num;
};


int contadorSimbolos = 0;

void criaNo(HTree **raiz,char sim)
{
	*raiz = (HTree*) malloc(sizeof(HTree));
	(*raiz)->simb = sim;
	(*raiz)->esq = NULL;
	(*raiz)->dir =NULL;
	(*raiz)->freq = 0;
}

Caixa* criaNoCaixa(HTree *arv) {
    Caixa *novo = (Caixa*) malloc(sizeof(Caixa));
    if (novo == NULL) {
        printf("\nErro ao alocar memoria para a caixa");
        return NULL;
    }
    novo->arv = arv;
    novo->prox = NULL;
    return novo;
}

Tabela* criaNoTabela(char palavra[], int freq) {
    Tabela *novo = (Tabela*) malloc(sizeof(Tabela));
    if (novo == NULL) {
        printf("\nErro ao alocar memoria para a tabela");
        return NULL;
    }
    strcpy(novo->palavra, palavra);
    novo->codHuff[0] = '\0';  // Inicializa o código Huffman como vazio
    novo->simbo = contadorSimbolos++;      
    novo->freq = freq;
    novo->prox = NULL;
    return novo;
}

void inserirOuAtualizarTabela(Tabela **inicio, char palavra[]) {
    Tabela *atual = *inicio;
    Tabela *anterior = NULL;
    int palavraEncontrada = 0;  

    while (atual != NULL) {
        if (strcmp(atual->palavra, palavra) == 0) {
            palavraEncontrada = 1;  
            atual->freq++;          
        }
        anterior = atual;
        atual = atual->prox;
    }

    if (!palavraEncontrada) {
        Tabela *novo = criaNoTabela(palavra, 1);
        if (anterior == NULL) {
            *inicio = novo;
        } else {
            anterior->prox = novo;
        }
    }
}

int isEspaco(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}

int isLetra(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}


void contarFrequenciaArquivo(char nomeArquivo[], Tabela **inicio) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    char palavra[30];
    int i = 0;
    char c;
	    
    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo");
    }else{
    	
	    while ((c = fgetc(arquivo)) != EOF) {
	        if (isEspaco(c)) {
	            if (i > 0) {
	                palavra[i] = '\0';  
	                inserirOuAtualizarTabela(&*inicio, palavra);
	                i = 0;  // reseta o índice para a próxima palavra
	            }
	            char espaco[] = " ";
	            inserirOuAtualizarTabela(&*inicio, espaco);
	        } else if (isLetra(c)) {
	            palavra[i++] = tolower(c);
	        }
	    }
	    // ultima palavra
	    if (i > 0) {
	        palavra[i] = '\0';
	        inserirOuAtualizarTabela(&*inicio, palavra);
	    }
	
	    fclose(arquivo);
	}
}

void ordenarTabelaPorFrequencia(Tabela **inicio) {
    if (*inicio != NULL || (*inicio)->prox != NULL) {
        Tabela *ordenada = NULL; 
        Tabela *aux;
	
	    while (*inicio != NULL) {
	        Tabela *noAtual = *inicio; 
	        *inicio = (*inicio)->prox; 
	
	        // insere noAtual na lista ordenada na posição correta
	        if (ordenada == NULL || noAtual->freq < ordenada->freq) {
	            noAtual->prox = ordenada;
	            ordenada = noAtual;
	        } else {
	            aux = ordenada;
	            while (aux->prox != NULL && aux->prox->freq < noAtual->freq) {
	                aux = aux->prox;
	            }
	            noAtual->prox = aux->prox;
	            aux->prox = noAtual;
	        }
	    }
	
	    *inicio = ordenada;
    }
}

void inserirOrdenadoCaixa(Caixa **inicio, HTree *arv) {
    Caixa *novo = criaNoCaixa(arv);
    Caixa *atual;
    if (novo != NULL) {
	    if (*inicio == NULL || arv->freq < (*inicio)->arv->freq) {
	        novo->prox = *inicio;
	        *inicio = novo;
	    } else {
	        atual = *inicio;
	        while (atual->prox != NULL && atual->prox->arv->freq < arv->freq) {
	            atual = atual->prox;
	        }
	        novo->prox = atual->prox;
	        atual->prox = novo;
	    }
    }
}

// criar a lista de caixas a partir da tabela de frequências
void criarListaCaixa(Tabela *inicioTabela, Caixa **inicioCaixa) {
    Tabela *atual = inicioTabela;
    while (atual != NULL) {
        HTree *novoArv;
        criaNo(&novoArv, atual->simbo); 
        novoArv->freq = atual->freq;         
        inserirOrdenadoCaixa(&*inicioCaixa, novoArv); 
        atual = atual->prox;
    }
}

void imprimirListaCaixa(Caixa *inicio) {
    Caixa *atual = inicio;
    while (atual != NULL) {
        printf("\nSimbolo: '%d', Frequencia: %d", atual->arv->simb, atual->arv->freq);
        atual = atual->prox;
    }
}

void imprimirTabela(Tabela *inicio) {
    Tabela *atual = inicio;
    printf("\n| %-5s | %-15s | %-10s | %-10s |\n", "Simbolo", "Palavra", "Frequencia", "Codigo Huffman");
    printf("|-------|-----------------|------------|--------------|\n");

    while (atual != NULL) {
        if (strlen(atual->codHuff) > 0) {
            printf("| %-5d | %-15s | %-10d | %-12s |\n", atual->simbo, atual->palavra, atual->freq, atual->codHuff);
        } else {
            printf("| %-5d | %-15s | %-10d | %-12s |\n", atual->simbo, atual->palavra, atual->freq, "-");
        }
        atual = atual->prox;
    }
}


//  inserir uma árvore na lista de caixas de forma ordenada
void inserirArvoreOrdenada(Caixa **inicio, HTree *novaArvore) {
    Caixa *novoCaixa = criaNoCaixa(novaArvore);
    if (*inicio == NULL || novaArvore->freq < (*inicio)->arv->freq) {
        novoCaixa->prox = *inicio;
        *inicio = novoCaixa;
    } else {
        Caixa *atual = *inicio;
        while (atual->prox != NULL && atual->prox->arv->freq < novaArvore->freq) {
            atual = atual->prox;
        }
        novoCaixa->prox = atual->prox;
        atual->prox = novoCaixa;
    }
}

HTree* gerarArvoreHuffman(Caixa **inicioCaixa) {
    while (*inicioCaixa != NULL && (*inicioCaixa)->prox != NULL) {
        
		// remove as duas caixas com menor frequência
        Caixa *primeira = *inicioCaixa;
        Caixa *segunda = primeira->prox;
        *inicioCaixa = segunda->prox; 

        
        HTree *novaArvore = (HTree*) malloc(sizeof(HTree));
        novaArvore->freq = primeira->arv->freq + segunda->arv->freq;
        novaArvore->simb = '#'; 
        novaArvore->esq = primeira->arv;
        novaArvore->dir = segunda->arv;

        inserirArvoreOrdenada(inicioCaixa, novaArvore);
    }

    if (*inicioCaixa != NULL) 
		return (*inicioCaixa)->arv;
	else
		return NULL;
}

void exibeArv(HTree *a) {
    int i;
    static int n = -1;
    
    if (a != NULL){
        n++;  
    
	    exibeArv(a->dir);
	
	    for (i = 0; i < 8 * n; i++) {
	        printf(" ");
	    }
	    
	    if (a->esq == NULL && a->dir == NULL) {
	        printf("(%d, %d)\n", a->simb, a->freq); 
	    }
	    else {
	        printf("(#, %d)\n", a->freq);  
	    }
	
	    exibeArv(a->esq);
	
	    n--; 
	}
}

void gerarCodigoHuffman(HTree *no, char *codigo, int pos, Tabela *tabela) {
    if (no != NULL) {
	    if (no->esq == NULL && no->dir == NULL) {
	    	// se for uma folha
	        codigo[pos] = '\0';  
	        Tabela *atual = tabela;
	        int flag = 0;
	        while (atual != NULL && flag == 0) {
	            if (atual->simbo == no->simb) {
	                strcpy(atual->codHuff, codigo); 
	                flag = 1;
	            }
	            atual = atual->prox;
	        }
	    }else{
	    	if (no->esq != NULL) {
		        codigo[pos] = '0';
		        gerarCodigoHuffman(no->esq, codigo, pos + 1, tabela);
		    }
		    if (no->dir != NULL) {
		        codigo[pos] = '1';
		        gerarCodigoHuffman(no->dir, codigo, pos + 1, tabela);
		    }
		}  
    }
}

void gravarTabelaBinario(char *nomeArquivo, Tabela *inicioTabela) {
    FILE *arquivo = fopen(nomeArquivo, "wb");
    TabelaB tab;
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para gravacao\n");
    }else{
    	Tabela *atual = inicioTabela;
	    while (atual != NULL) {
	      
	        tab.simbo = atual->simbo;
	        strcpy(tab.palavra,atual->palavra);  
	        strcpy(tab.codHuff,atual->codHuff);
			fwrite(&tab,sizeof(TabelaB),1, arquivo);  
	
	        atual = atual->prox;
	    }
	
	    fclose(arquivo);
	    printf("\n\nTabela gravada com sucesso no arquivo binario!!\n");
	}
}


void buscarHuffman(char palavra[30], Tabela *inicio, char codHuff[15])
{
	while(inicio != NULL && strcmp(inicio->palavra,palavra) != 0)
		inicio = inicio->prox;
	
	if(inicio != NULL)
		strcpy(codHuff,inicio->codHuff);
}

void limpaB(byte *B)
{
	(*B).bi.b0 = 0;
	(*B).bi.b1 = 0;
	(*B).bi.b2 = 0;
	(*B).bi.b3 = 0;
	(*B).bi.b4 = 0;
	(*B).bi.b5 = 0;
	(*B).bi.b6 = 0;
	(*B).bi.b7 =0;
}

void mostrar(byte B)
{
	printf("\nbyte - ");
	printf("%d",B.bi.b0);
	printf("%d",B.bi.b1);
 	printf("%d",B.bi.b2);
	printf("%d",B.bi.b3);
	printf("%d",B.bi.b4);
	printf("%d",B.bi.b5);
	printf("%d",B.bi.b6);
	printf("%c",B.bi.b7);
	printf("\n");
}

void armazenaB(byte *B,int *bt, char codHuff[15], char *flag, FILE *Ptr)
{
	int i=0;
	
	while(codHuff[i] != '\0')
	{
		if(*bt == 0)
		{
			(*B).bi.b0 = codHuff[i];
		}
		else
		{
			if(*bt == 1)
			{
				(*B).bi.b1 = codHuff[i];
			}
			else
			{
				if(*bt == 2)
				{
					(*B).bi.b2 = codHuff[i];
				}
				else
				{
					if(*bt == 3)
					{
						(*B).bi.b3 = codHuff[i];	
					}
					else
					{
						if(*bt == 4)
						{
							(*B).bi.b4 = codHuff[i];
						}
						else
						{
							if(*bt == 5)
							{
								(*B).bi.b5 = codHuff[i];
							}
							else
							{
								if(*bt == 6)
								{
									(*B).bi.b6 = codHuff[i];
								}
								else
								{
									(*B).bi.b7 = codHuff[i];
								}
								
							}
						}
					}
				}
			}
		}
		(*bt)++;
		
		i++;
		if(*bt == 8)
		{
			fwrite(&(*B),sizeof(byte),1,Ptr);
			limpaB(&(*B));
			*bt = 0;
		}
	}
	
	if(*flag == '1')
	{
		if(*bt > 0)
		{
			fwrite(&(*B),sizeof(byte),1,Ptr);
			limpaB(&(*B));
			
		}
	}
}

void exibirFraseCodificada(char *nomeArq)
{
	FILE *Ptr = fopen("fraseCodificada", "rb");
	byte B;
	
	printf("\n\nFrase Codificada:\n\n");
	
	fread(&B,sizeof(byte),1,Ptr);
	while(!feof(Ptr))
	{
		printf("%d",B.bi.b0);
		printf("%d",B.bi.b1);
	 	printf("%d",B.bi.b2);
		printf("%d",B.bi.b3);
		printf("%d",B.bi.b4);
		printf("%d",B.bi.b5);
		printf("%d",B.bi.b6);
		printf("%d",B.bi.b7);
		fread(&B,sizeof(byte),1,Ptr);
	}
	fclose(Ptr);
}

void codificarFrase(Tabela *inicio, char *frase)
{
	FILE *Ptr = fopen("fraseCodificada", "w");
	char palavra[30], codHuff[15], codHuffEsp[15],flag = 0;
	int i=0,j=0,bt = 0;
	byte B;
	
	limpaB(&B);
	
	buscarHuffman(" ",inicio,codHuffEsp);
	
	while(frase[i] != '\0')
	{
		if(frase[i] == ' ' || frase[i+1] == '\0')
		{
			if(frase[i+1] == '\0')
			{
				palavra[j] = frase[i];
				j++;
				flag = '1';
			}
			
			palavra[j] = '\0';
			
			buscarHuffman(palavra,inicio,codHuff);
			
			armazenaB(&B,&bt,codHuff,&flag,Ptr);
			if(flag != '1')
				armazenaB(&B,&bt,codHuffEsp,&flag,Ptr);

			
			j = -1;
		}
		else
		{
			palavra[j] = frase[i];
		}
		i++;
		j++;
	}
	fclose(Ptr);
	exibirFraseCodificada("fraseCodificada");
}

int main() {
    Tabela *inicioTabela = NULL;
    char codigo[100];
    HTree *arvoreHuffman = NULL;
    Caixa *inicioCaixa = NULL;
    contarFrequenciaArquivo("teste.txt", &inicioTabela);
    
	//printf("Tabela antes da ordenacao:\n");
    //imprimirTabela(inicioTabela);

    ordenarTabelaPorFrequencia(&inicioTabela);
    
    printf("\n\nTabela apos a ordenacao:");
    imprimirTabela(inicioTabela);

    criarListaCaixa(inicioTabela, &inicioCaixa);

    //printf("\n\nLista de caixas ordenada:");
    //imprimirListaCaixa(inicioCaixa);
    
    arvoreHuffman = gerarArvoreHuffman(&inicioCaixa);
    //printf("\nArvore de Huffman:\n");
    //exibeArv(arvoreHuffman);

    
    // Gera os códigos de Huffman
    gerarCodigoHuffman(arvoreHuffman, codigo, 0, inicioTabela);
    
    printf("\nTabela de Huffman com os codigos:\n");
    imprimirTabela(inicioTabela);
    
    codificarFrase(inicioTabela,"de manha os passaros cantavam sem parar trazendo uma sensacao de paz");
    gravarTabelaBinario("Tabela",inicioTabela);

    return 0;
}
