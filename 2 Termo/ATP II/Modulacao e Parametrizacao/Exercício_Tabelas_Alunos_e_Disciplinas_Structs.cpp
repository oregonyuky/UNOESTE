#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

#define TF 10
struct Aluno {
    char ra[30], nome[30];
};
struct Disciplina {
    int codDis;
    char nome[30];
};
struct AlunoDisciplina {
    char ra[30];
    int codDis;
    float nota;
};
struct Reprovados {
    char ra[30], nome[30];
};
struct Media {
    char ra[30];
};
int buscaExaustiva(Aluno vetAgenda[TF], int TL, char reg[30]) {
    int pos = 0;
    while (pos < TL && strcmp(vetAgenda[pos].ra, reg) != 0)
        pos++;
    if (pos < TL)
        return pos;
    return -1;
}
void bubblesort(Aluno vetAgenda[TF], int TL) {
    Aluno aux;
    int flag = 1, i=0;
    while (TL>1 && flag) {
        flag = 0;
        for (i = 0; i < TL - 1; i++) {
            if (strcmp(vetAgenda[i].nome, vetAgenda[i + 1].nome) > 0) {
                aux = vetAgenda[i];
                vetAgenda[i] = vetAgenda[i + 1];
                vetAgenda[i + 1] = aux;
                flag = 1;
            }
        }
        TL--;
    }
}
char menu() {
    system("cls");
    printf("[A] Cadastrar\n");
    printf("[B] Excluir\n");
    printf("[C] Exibir\n");
    return toupper(_getch());
}
char Cadastrar() {
    system("cls");
    printf("[A] Cadastrar nome e RA:\n");
    printf("[B] Cadastrar o codigo e a disciplina:\n");
    printf("[C] Cadastrar nota:\n");
    return toupper(_getch());
}
char Excluir() {
    system("cls");
    printf("[A] Excluir cadastro de nome e RA\n");
    printf("[B] Excluir cadastro de codigo e disciplina\n");
    printf("[C] Excluir cadastro de nota\n");
    return toupper(_getch());
}
char Exibir() {
    system("cls");
    printf("[A] Exibir nome e RA\n");
    printf("[B] Exibir codigo e disciplina\n");
    printf("[C] Exibir relatorio\n");
    printf("[D] Exibir alunos reprovados\n");
    printf("[E] Exibir alunos que comecam come essa letra\n");
    printf("[F] Exibir alunos com media abaixo de 6\n");
    return toupper(_getch());
}
void CadastroNome(Aluno vetAgenda[TF], int& TL) {
    system("cls");
    Aluno aux;
    int pos;
    printf("Digite o seu ra:\n");
    gets_s(aux.ra);
    while (TL < TF && strcmp(aux.ra, "\0") != 0) {
        pos = buscaExaustiva(vetAgenda, TL, aux.ra);
        if (pos == -1) {
            printf("Digite o seu nome:\n");
            gets_s(aux.nome);
            vetAgenda[TL++] = aux;
        }
        else {
            printf("Ja esta cadastrado\n");
        }
        if (TL < TF) {
            printf("\nDigite o seu RA:\n");
            gets_s(aux.ra);
        }
    }
    if (TL == TF) {
        printf("Nao tem mais espaco\n");
    }
    bubblesort(vetAgenda, TL);
    //_getch();
}
int buscaExaustivaNum(Disciplina vetAgenda1[TF], int TP, int n) {
    int pos = 0;
    while (pos < TP && vetAgenda1[pos].codDis != n)
        pos++;
    if (pos < TP)
        return pos;
    return -1;
}
void CodigoDisciplina(Disciplina vetAgenda1[TF], int& TP) {
    system("cls");
    Disciplina disc;
    int pos;
    printf("Digite o codigo:(pressione 0 para sair)\n");
    scanf("%d", &disc.codDis);
    while (TP < TF && disc.codDis != 0) {
        pos = buscaExaustivaNum(vetAgenda1, TP, disc.codDis);
        if (pos == -1) {
            printf("Digite a disciplina:\n");
            getchar();
            gets_s(disc.nome);
            vetAgenda1[TP++] = disc;
        }
        else {
            printf("ja esta cadastrado\n");
        }
        if (TP < TF) {
            printf("\nDigite o codigo:(pressione 0 para sair)\n");
            scanf("%d", &disc.codDis);
        }
    }
    if (TP == TF)
        printf("Ja nao tem mais espaco\n");
    _getch();
}
void CadastroNota(Aluno vetAgenda[TF], Disciplina vetAgenda1[TF], AlunoDisciplina vetAgenda2[TF], int TL, int TP, int& TQ) {
    system("cls");
    Aluno aux;
    Disciplina aux1;
    AlunoDisciplina aux2;
    int pos;
    printf("Digite o RA:\n");
    getchar();
    gets_s(aux.ra);
    while (TQ < TF && strcmp(aux.ra, "\0") != 0) {
        pos = buscaExaustiva(vetAgenda, TL, aux.ra);
        if (pos != -1) {
            printf("Digite o codigo da disciplina:\n");
            scanf("%d", &aux1.codDis);
            pos = buscaExaustivaNum(vetAgenda1, TP, aux1.codDis);
            if (pos != -1) {
                strcpy(vetAgenda2[TQ].ra, aux.ra);
                vetAgenda2[TQ].codDis = aux1.codDis;
                pos = 0;
                while (pos < TQ && (strcmp(vetAgenda2[pos].ra, vetAgenda2[TQ].ra) != 0 || vetAgenda2[pos].codDis != vetAgenda2[TQ].codDis)) {
                    pos++;
                }
                if (pos < TQ) {
                    printf("Nao pode cadastrar novamente\n");
                }
                else {
                    printf("Digite a nota:\n");
                    scanf("%f", &aux2.nota);
                    vetAgenda2[TQ++].nota = aux2.nota;
                }
            }
            else {
                printf("Disciplina nao encontrada\n");
            }
        }
        else {
            printf("Aluno nao encontrado\n");
        }
        if (TQ < TF) {
            printf("\nDigite o RA:\n");
            getchar();
            gets_s(aux.ra);
        }
    }
    if (TQ == TF) {
        printf("Nao ha mais espaco\n");
    }
    _getch();
}

void ExibirCadastro(Aluno vetAgenda[TF], int TL) {
    system("cls");
    for (int i = 0; i < TL; i++) {
        printf("Nome: %s\n", vetAgenda[i].nome);
        printf("Ra: %s\n\n", vetAgenda[i].ra);
    }
    _getch();
}
void ExibirCDisc(Disciplina vetAgenda1[TF], int TP) {
    system("cls");
    for (int i = 0; i < TP; i++) {
        printf("Codigo: %d\n", vetAgenda1[i].codDis);
        printf("Disciplina: %s\n\n", vetAgenda1[i].nome);
    }
    _getch();
}
void ExibirRelatorio(Aluno vetAgenda[TF], Disciplina vetAgenda1[TF], AlunoDisciplina vetAgenda2[TF], int TL, int TP, int TQ) {
    system("cls");
    char cod[30] = "", aux[30];
    int reprovado = 0, qtd = 0;
    float total_nota = 0;
    for (int i = 0; i < TQ; i++) {
        if (strcmp(cod, vetAgenda2[i].ra) != 0) {
            strcpy(cod, vetAgenda2[i].ra);
            printf("\nRA: %s \t", vetAgenda2[i].ra);
            for (int j = 0; j < TL; j++) {
                if (strcmp(vetAgenda2[i].ra, vetAgenda[j].ra) == 0) {
                    strcpy(aux, vetAgenda[j].nome);
                    printf("Nome: %s\n", vetAgenda[j].nome);
                }
            }
        }
        printf("Disciplina: %d - ", vetAgenda2[i].codDis);
        for (int j = 0; j < TP; j++) {
            if (vetAgenda2[i].codDis == vetAgenda1[j].codDis)
                printf("%s \t", vetAgenda1[j].nome);
        }
        printf("Nota: %.1f \t Situacao: %s\n", vetAgenda2[i].nota, (vetAgenda2[i].nota >= 6.0 ? "aprovado" : "reprovado"));
    }
    _getch();
}
void DeterminadaLetra(Aluno vetAgenda[TF], int TL) {
    system("cls");
    char letra;
    printf("Digite a letra para exibir todos os nomes que comecam com essa letra:\n");
    letra = toupper(_getch());
    for (int i = 0; i < TL; i++) {
        if (toupper(vetAgenda[i].nome[0]) == letra) {
            printf("Nome: %s\n", vetAgenda[i].nome);
        }
    }
    _getch();
}
void ExibirReprovado(Aluno vetAgenda[TF], AlunoDisciplina vetAgenda2[TF], Reprovados vetReprovado[TF], int TL, int TM, int TQ, int& TG) {
    system("cls");
    int reprovado = 0;
    for (int i = 0; i < TQ; i++) {
        if (vetAgenda2[i].nota < 6.0)
            reprovado++;
        if (i == TQ - 1 || strcmp(vetAgenda2[i + 1].ra, vetAgenda2[i].ra) != 0) {
            if (reprovado >= 2) {
                strcpy(vetReprovado[TG++].ra, vetAgenda2[i].ra);
            }
            reprovado = 0;
        }
    }
    for (int i = 0; i < TG; i++) {
        for (int j = 0; j < TL; j++) {
            if (strcmp(vetAgenda[j].ra, vetReprovado[i].ra) == 0) {
                printf("Nome: %s\n", vetAgenda[j].nome);
                strcpy(vetReprovado[i].ra, "");
            }
        }
    }
    _getch();
}
void ExibirMedia(Aluno vetAgenda[TF], AlunoDisciplina vetAgenda2[TF], Media vetMedia6[TF], int TQ, int& TM, int TL) {
    system("cls");
    char cod[30] = "";
    int total_nota = 0, qtd = 0;
    for (int i = 0; i < TQ; i++) {
        total_nota += vetAgenda2[i].nota;
        qtd++;
        if (i == TQ - 1 || strcmp(vetAgenda2[i + 1].ra, vetAgenda2[i].ra) != 0) {
            if (total_nota / qtd < 6)
                strcpy(vetMedia6[TM++].ra, vetAgenda2[i].ra);
            total_nota = 0;
            qtd = 0;
        }
    }
    for (int i = 0; i < TM; i++) {
        for (int j = 0; j < TL; j++) {
            if (strcmp(vetAgenda[j].ra, vetMedia6[i].ra) == 0) {
                printf("Nome: %s\n", vetAgenda[j].nome);
                strcpy(vetMedia6[i].ra, "");
            }
        }
    }

    _getch();
}
void ExcluirCadastroNome(Aluno vetAgenda[TF], int& TL) {
    system("cls");
    Aluno aux;
    char tecla;
    int pos;
    if (TL != 0) {
        do {
            printf("Digite o Ra para exluir:\n");
            fflush(stdin);
            gets_s(aux.ra);
            pos = buscaExaustiva(vetAgenda, TL, aux.ra);
            if (pos != -1) {
                for (int i = pos; i < TL - 1; i++) {
                    vetAgenda[i] = vetAgenda[i + 1];
                }
                TL--;
            }
            else {
                printf("Nao existe esse Ra que voce digitou\n");
            }
            printf("Deseja continuar? <s/n>\n");
            fflush(stdin);
            tecla = toupper(_getch());
        } while (tecla == 'S' && TL > 0);
    }
    else
        printf("Nao tem RA para exluir\n");
    _getch();
}
void ExcluirCodigoDisciplina(Disciplina vetAgenda1[TF], int& TP) {
    system("cls");
    Disciplina aux;
    char tecla;
    int pos;
    if (TP != 0) {
        do {
            printf("Digite o codigo da disciplina para excluir:\n");
            scanf("%d", &aux.codDis);
            pos = buscaExaustivaNum(vetAgenda1, TP, aux.codDis);
            if (pos == -1) {
                for (int i = pos; i < TP - 1; i++) {
                    vetAgenda1[i] = vetAgenda1[i + 1];
                }
                TP--;
            }
            printf("Deseja continuar? <s/n>");
            fflush(stdin);
            tecla = toupper(_getch());
        } while (tecla == 'S' && TP > 0);
    }
    else
        printf("Nao tem codigo da disciplina para excluir:\n");
    _getch();
}
void ExcluirCadastroNota(Aluno vetAgenda[TF], Disciplina vetAgenda1[TF], AlunoDisciplina vetAgenda2[TF], int TL, int TP, int& TQ) {
    system("cls");
    Aluno aux;
    Disciplina aux1;
    AlunoDisciplina aux2;
    char tecla;
    int pos;
    if (TQ > 0) {
        do {
            printf("Digite o RA para excluir:\n");
            fflush(stdin);
            gets_s(aux.ra);
            pos = buscaExaustiva(vetAgenda, TL, aux.ra);
            if (pos == -1) {
                printf("Digite o codigo para excluir:\n");
                scanf("%d", &aux1.codDis);
                pos = buscaExaustivaNum(vetAgenda1, TP, aux1.codDis);
                if (pos != -1) {
                    for (int i = pos; i < TQ - 1; i++) {
                        vetAgenda2[i] = vetAgenda2[i + 1];
                    }
                    TQ--;
                }
            }
            printf("Deseja continuar? <s/n>\n");
            fflush(stdin);
            tecla = toupper(_getch());
        } while (tecla == 'S' && TQ > 0);
    }
    else
        printf("Nao tem ra, codigo e nota para exluir\n");
    _getch();
}
int main() {
    char tecla, tecla1;
    AlunoDisciplina vetAgenda2[TF];
    Disciplina vetAgenda1[TF];
    Aluno vetAgenda[TF];
    Reprovados vetReprovados[TF];
    Media vetMedia6[TF];
    int TL = 0, TP = 0, TQ = 0, TG = 0, TM = 0;
    do {
        tecla = menu();
        if (tecla == 'A') {
            tecla1 = Cadastrar();
            switch (tecla1) {
            case 'A':CadastroNome(vetAgenda, TL); break;
            case 'B':CodigoDisciplina(vetAgenda1, TP); break;
            case 'C':CadastroNota(vetAgenda, vetAgenda1, vetAgenda2, TL, TP, TQ); break;
            }
            _getch();
        }
        else if (tecla == 'B') {
            tecla1 = Excluir();
            switch (tecla1) {
            case 'A':ExcluirCadastroNome(vetAgenda, TL); break;
            case 'B':ExcluirCodigoDisciplina(vetAgenda1, TP); break;
            case 'C':ExcluirCadastroNota(vetAgenda, vetAgenda1, vetAgenda2, TL, TP, TQ); break;
            }
            _getch();
        }
        else {
            tecla1 = Exibir();
            switch (tecla1) {
            case 'A':ExibirCadastro(vetAgenda, TL); break;
            case 'B':ExibirCDisc(vetAgenda1, TP); break;
            case 'C':ExibirRelatorio(vetAgenda, vetAgenda1, vetAgenda2, TL, TP, TQ); break;
            case 'D':ExibirReprovado(vetAgenda, vetAgenda2, vetReprovados, TL, TM, TQ, TG); break;
            case 'E':DeterminadaLetra(vetAgenda, TL); break;
            case 'F':ExibirMedia(vetAgenda, vetAgenda2, vetMedia6, TQ, TM, TL); break;
            }
            _getch();
        }
    } while (tecla != 27);
}
