#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#define TF 10
struct tpAluno{
    char ra[30], nome[30];
};
struct tpDisciplina{
    char disciplina[30];
    int codDis;
};
struct tpAlunoDisciplina{
    char ra[30];
    int codDis;
    float nota;
};
void OrdenarAluno(tpAluno Aluno[TF], int TL){
    tpAluno aux;
    for(int i=TL-1;i>=1;i--){
        if(strcmp(Aluno[i-1].nome, Aluno[i].nome)>0){
            aux = Aluno[i];
            Aluno[i] = Aluno[i-1];
            Aluno[i-1] = aux;
        }
    }
}
void OrdenarCodigoDisciplina(tpDisciplina Disciplina[TF], int TP){
    tpDisciplina aux;
    for(int i=TP-1;i>=1;i--){
        if(Disciplina[i-1].codDis>Disciplina[i].codDis){
            aux = Disciplina[i];
            Disciplina[i] = Disciplina[i-1];
            Disciplina[i-1] = aux;
        }
    }
}
void OrdenarAlunoDisciplina(tpAlunoDisciplina AlunoDisciplina[TF], int TQ){
    tpAlunoDisciplina aux;
    for(int i=TQ-1;i>=1;i--){
        if(strcmp(AlunoDisciplina[i-1].ra, AlunoDisciplina[i].ra)>0){
            aux = AlunoDisciplina[i];
            AlunoDisciplina[i] = AlunoDisciplina[i-1];
            AlunoDisciplina[i-1] = aux;
        }
    }
}
int BuscaExaustivaAluno(tpAluno Aluno[TF], char ra[30], int TL){
    int pos=0;
    while(pos<TL && strcmp(Aluno[pos].ra, ra)!=0)
        pos++;
    if(pos<TL)
        return pos;
    return -1;
}
int BuscaExaustivaDisciplinaNum(tpDisciplina Disciplina[TF], int cod, int TP){
    int pos=0;
    while(pos<TP && cod!=Disciplina[pos].codDis)
        pos++;
    if(pos<TP)
        return pos;
    return -1;
}
int BuscaExaustivaDisciplina(tpDisciplina Disciplina[TF], char disciplina[30], int TP){
    int pos=0;
    while(pos<TP && strcmp(Disciplina[pos].disciplina, disciplina)!=0)
        pos++;
    if(pos<TP)
        return pos;
    return -1;
}
int BuscaExaustivaAlunoDisciplina(tpAlunoDisciplina AlunoDisciplina[TF], char ra[30], int cod, int TQ){
    int pos=0;
    while(pos<TQ && (strcmp(ra, AlunoDisciplina[pos].ra)!=0 || cod!=AlunoDisciplina[pos].codDis))
        pos++;
    if(pos<TQ)
        return pos;
    return -1;
}
int BuscaExaustivaAlunoDisciplinaRA(tpAlunoDisciplina AlunoDisciplina[TF], char ra[30], int TQ){
    int pos=0;
    while(pos<TQ && strcmp(ra, AlunoDisciplina[pos].ra)!=0)
        pos++;
    if(pos<TQ)
        return pos;
    return -1;
}
int BuscaExaustivaAlunoDisciplinaCOD(tpAlunoDisciplina AlunoDisciplina[TF], int cod, int TQ){
    int pos=0;
    while(pos<TQ && cod!=AlunoDisciplina[pos].codDis)
        pos++;
    if(pos<TQ)
        return pos;
    return -1;
}
int BuscaExaustivaExluir1(tpAlunoDisciplina AlunoDisciplina[TF], char ra[30], int TQ){
    int pos=0;
    while(pos<TQ && strcmp(ra, AlunoDisciplina[pos].ra)!=0)
        pos++;
    if(pos<TQ)
        return pos;
    return -1;
}
int BuscaExaustivaExcluir2(tpAlunoDisciplina AlunoDisciplina[TF], int pos, int TQ){
    while(pos<TQ && strcmp(AlunoDisciplina[pos].ra, AlunoDisciplina[pos+1].ra)==0)
        pos++;
    if(pos<TQ)
        return pos;
    return -1;  
}
int BuscaExaustivaPrimeiroNome(tpAluno Aluno[TF], char nome[30], int TL, int i){
    int pos=0;
    while(pos<strlen(nome) && pos<strlen(Aluno[i].nome) && Aluno[i].nome[pos] == nome[pos])
        pos++;
    if(pos==strlen(nome) && (Aluno[i].nome[pos]==' ' || Aluno[i].nome[pos]=='\0'))
        return pos;
    return -1;
}
int BuscaExaustivaSobrenome(tpAluno Aluno[TF], char sobrenome[30], int TL, int i){
    int pos=strlen(Aluno[i].nome)-1;
    while(pos>=0 && Aluno[i].nome[pos]!=' ')
        pos--;
    if(pos>=0){
        int pos1=0; pos++;
        while(pos1<strlen(sobrenome) && pos<strlen(Aluno[i].nome) && Aluno[i].nome[pos]==sobrenome[pos1]){
            pos1++;pos++;
        }
        if(pos1==strlen(sobrenome))
            return i;
    }
    return -1;
}
int BuscaExaustivaPrimeiroDisciplina(tpDisciplina Disciplina[TF], char disciplina[30], int TP, int i){
    int pos=0;
    while(pos<strlen(disciplina) && pos<strlen(Disciplina[i].disciplina) && disciplina[pos]==Disciplina[i].disciplina[pos])
        pos++;
    if(pos==strlen(disciplina) && (Disciplina[i].disciplina[pos]==' ' || Disciplina[i].disciplina[pos]=='\0'))
        return pos;
    return -1;
}
char menu(){
    system("cls");
    printf("[A] Cadastrar\n");
    printf("[B] Exibir\n");
    printf("[C] Excluir\n");
    printf("[D] Buscar\n");
    printf("[E] Alternar\n");
    return toupper(getch());
}
char Cadastrar(){
    system("cls");
    printf("[A] Cadastrar aluno\n");
    printf("[B] Cadastrar disciplina\n");
    printf("[C] Cadastrar nota\n");
    return toupper(getch());
}
char Exibir(){
    system("cls");
    printf("[A] Exibir aluno\n");
    printf("[B] Exibir disciplina\n");
    printf("[C] Exibir nota\n");
    printf("[D] Exibir relatorio\n");
    printf("[E] Exibir Reprovados\n");
    printf("[F] Exibir Media abaixo de 6.0\n");
    return toupper(getch());
}
char Exluir(){
    system("cls");
    printf("[A] Excluir aluno\n");
    printf("[B] Excluir disciplina\n");
    printf("[C] Excluir nota\n");
    return toupper(getch());
}
char Buscar(){
    system("cls");
    printf("[A] Buscar todos os RA com primeiro nome\n");
    printf("[B] Buscar todos os RA com sobrenome\n");
    printf("[C] Buscar disciplina\n");
    printf("[D] Buscar nome pela primeira letra\n");
    return toupper(getch());
}
char Alternar(){
    system("cls");
    printf("[A] Alternar o nome\n");
    printf("[B] Alternar o disciplina\n");
    printf("[C] Alternar a nota\n");
    return toupper(getch());
}
void CadastroNome(tpAluno Aluno[TF], int &TL){
    system("cls");
    tpAluno aux;
    int pos;
    if(TL<TF){
        printf("Digite o RA:\n");
        gets(aux.ra);
        while(TL<TF && strcmp(aux.ra, "\0")!=0){
            pos = BuscaExaustivaAluno(Aluno, aux.ra, TL);
            if(pos==-1){
                printf("Digite o nome:\n");
                gets(aux.nome);
                Aluno[TL++] = aux;
                OrdenarAluno(Aluno, TL);
            }
            else
                printf("Ja esta cadastrado\n");
            if(TL<TF){
                printf("Digite o RA:\n");
                gets(aux.ra);
            }
        }
    }
    else
        printf("Nao tem mais espaco\n");
    getch();
}
void CadastroDisciplina(tpDisciplina Disciplina[TF], int &TP){
    system("cls");
    tpDisciplina aux;
    int pos;
    if(TP<TF){
        printf("Digite o codigo\n");
        fflush(stdin);
        scanf("%d", &aux.codDis);
        while(TP<TF && aux.codDis>0){
            pos = BuscaExaustivaDisciplinaNum(Disciplina, aux.codDis, TP);
            if(pos==-1){
                printf("Digite o nome da disciplina:\n");
                fflush(stdin);
                gets(aux.disciplina);
                pos = BuscaExaustivaDisciplina(Disciplina, aux.disciplina, TP);
                if(pos==-1){
                    Disciplina[TP++] = aux;
                    OrdenarCodigoDisciplina(Disciplina, TP);
                }
                else
                    printf("ja exite esse nome na disciplina");
            }
            else
                printf("Este codigo ja foi cadastrado");
            if(TP<TF){
                printf("Digite o codigo:\n");
                fflush(stdin);
                scanf("%d", &aux.codDis);
            }
        }
    }
    else
        printf("Nao tem mais espaco");
    getch();
}
void CadastroAlunoDisciplina(tpAluno Aluno[TF], tpDisciplina Disciplina[TF], tpAlunoDisciplina AlunoDisciplina[TF], int TL, int TP, int &TQ){
    system("cls");
    tpAlunoDisciplina aux;
    int pos;
    if(TQ<TF){
        printf("Digite o RA:\n");
        gets(aux.ra);
        while(TQ<TF && strcmp(aux.ra, "\0")!=0){
            pos = BuscaExaustivaAluno(Aluno, aux.ra, TL);
            if(pos!=-1){
                printf("Digite o codigo da disciplina:\n");
                scanf("%d", &aux.codDis);
                pos = BuscaExaustivaDisciplinaNum(Disciplina, aux.codDis, TP);
                if(pos!=-1){
                    pos = BuscaExaustivaAlunoDisciplina(AlunoDisciplina, aux.ra, aux.codDis, TQ);
                    if(pos==-1){
                        printf("Digite a nota:\n");
                        scanf("%f", &aux.nota);
                        AlunoDisciplina[TQ++] = aux;
                        OrdenarAlunoDisciplina(AlunoDisciplina, TQ);
                    }
                    else
                        printf("Nao pode colocar o mesmo RA e mesmo disciplina\n");
                }
                else
                    printf("Nao foi encontrado o codigo da disciplina\n");
            }
            else
                printf("Nao foi encontrado o RA\n");
            if(TQ<TF){
                printf("Digite o RA:\n");
                fflush(stdin);
                gets(aux.ra);
            }
        }
    }
    else
        printf("Nao tem mais espaco\n");
    getch();
}
void ExibirCadastroNome(tpAluno Aluno[TF], int TL){
    system("cls");
    if(TL>0){
        for(int i=0;i<TL;i++){
            printf("RA: %s\n", Aluno[i].ra);
            printf("Nome: %s\n", Aluno[i].nome);
        }
    }
    else
        printf("Sem dados\n");
    getch();
}
void ExibirCadastroDisciplina(tpDisciplina Disciplina[TF], int TP){
    system("cls");
    if(TP>0){
        for(int i=0;i<TP;i++){
            printf("Codigo: %d\n", Disciplina[i].codDis);
            printf("Disciplina: %s\n", Disciplina[i].disciplina);
        }
    }
    else
        printf("Sem dados\n");
    getch();
}
void ExibirCadastroNota(tpAlunoDisciplina AlunoDisciplina[TF], int TQ){
    system("cls");
    if(TQ>0){
        for(int i=0;i<TQ;i++){
            printf("RA: %s \t Codigo: %d \t Nota: %f\n", AlunoDisciplina[i].ra, AlunoDisciplina[i].codDis, AlunoDisciplina[i].nota);
        }
    }
    else
        printf("Sem dados\n");
    getch();
}
void ExibirRelatorio(tpAluno Aluno[TF], tpDisciplina Disciplina[TF], tpAlunoDisciplina AlunoDisciplina[TF], int TL, int TP, int TQ){
    system("cls");
    char cod[30] = " ";
    float total_nota=0;int qtd=0;
    if(TQ>0){
        for(int i=0;i<TQ;i++){
            if(strcmp(cod, AlunoDisciplina[i].ra)!=0){
                for(int j=0;j<TL;j++)
                    if(strcmp(AlunoDisciplina[i].ra, Aluno[j].ra)==0)
                        printf("RA: %s\tNome:%s\n", Aluno[j].ra, Aluno[j].nome);
                strcpy(cod, AlunoDisciplina[i].ra);
            }
            total_nota += AlunoDisciplina[i].nota;qtd++;
            printf("Disciplina: %d - %s \t Nota: %.1f \t Situacao: %s\n", AlunoDisciplina[i].codDis, Disciplina[BuscaExaustivaDisciplinaNum(Disciplina, AlunoDisciplina[i].codDis, TP)].disciplina, AlunoDisciplina[i].nota, (AlunoDisciplina[i].nota>=6.0 ? "Aprovado" : "Reprovado"));
            if(i==TQ-1 || strcmp(AlunoDisciplina[i].ra, AlunoDisciplina[i+1].ra)!=0){
                printf("Media: %.1f\n\n", total_nota/qtd);
                total_nota=0, qtd=0;
            }
        }
    }
    else
        printf("Sem dados\n");
    getch();
}
void ExibirAlunosReprovados(tpAluno Aluno[TF], tpAlunoDisciplina AlunoDisciplina[TF], int TL, int TQ){
    system("cls");
    int reprovados;
    for(int i=0;i<TQ;i++){
        if(AlunoDisciplina[i].nota<6.0)
            reprovados++;
        if(i==TQ-1 || strcmp(AlunoDisciplina[i].ra, AlunoDisciplina[i+1].ra)!=0){
            if(reprovados>=2)
                printf("Nome: %s\tRA: %s\n", Aluno[BuscaExaustivaAluno(Aluno, AlunoDisciplina[i].ra, TL)].nome, AlunoDisciplina[i].ra);
            reprovados=0;
        }
    }
    getch();
}
void ExibirDisciplinaMediaAbaixo(tpDisciplina Disciplina[TF], tpAlunoDisciplina AlunoDisciplina[TF], int TP, int TQ){
    system("cls");
    for(int i=0;i<TP;i++){
        float total_nota=0;
        int qtd=0;
        for(int j=0;j<TQ;j++){
            if(Disciplina[i].codDis == AlunoDisciplina[j].codDis){
                total_nota += AlunoDisciplina[j].nota;
                qtd++;
            }
        }
        if(qtd>0){
            float media = total_nota/qtd;
            if(media<6.0)
                printf("Disciplina: %s\tCodigo: %d\t Media: %.1f\n", Disciplina[i].disciplina, Disciplina[i].codDis, media);
        }
    }
    getch();
}
void ExcluirCadastroNome(tpAluno Aluno[TF], tpAlunoDisciplina AlunoDisciplina[TF], int &TL, int &TQ){
    system("cls");
    tpAluno aux;
    int pos, pos1;
    if(TL>0){
        printf("Digite o RA do aluno que queira remover:\n");
        gets(aux.ra);
        while(TL>0 && strcmp(aux.ra, "\0")!=0){
            pos = BuscaExaustivaAluno(Aluno, aux.ra, TL);
            if(pos!=-1){
                for(int i=pos;i<TL-1;i++){
                    Aluno[i] = Aluno[i+1];
                }
                TL--;
            }
            else{
                printf("Nao ha esse RA\n");
            }
            pos = BuscaExaustivaExluir1(AlunoDisciplina, aux.ra, TQ);
            if(pos!=-1){
                pos1 = BuscaExaustivaExcluir2(AlunoDisciplina, pos, TQ);
                int largura = pos1-pos;
                if(pos1!=-1){
                    for(int i=pos;i<TQ-largura;i++)
                        AlunoDisciplina[i] = AlunoDisciplina[i+largura+1];
                }
                TQ -= largura+1;
            }
            if(TL>0){
                printf("Digite o RA do aluno que queira remover:\n");
                gets(aux.ra);
            }
        }
    }
    else
        printf("Nao tem aluno para voce exluir\n");
    getch();
}
void ExcluirCadastroDisciplina(tpDisciplina Disciplina[TF], tpAlunoDisciplina AlunoDisciplina[TF], int &TP, int &TQ){
    system("cls");
    tpDisciplina aux;
    int pos;
    if(TP>0){
        printf("Digite o codigo da materia que voce queira excluir:\n");
        scanf("%d", &aux.codDis);
        while(TP>0 && aux.codDis>0){
            pos = BuscaExaustivaDisciplinaNum(Disciplina, aux.codDis, TP);
            if(pos!=-1){
                for(int i=pos;i<TP-1;i++)
                    Disciplina[i] = Disciplina[i+1];
                TP--;
            }
            for(int i=0;i<TQ;i++){
                while(pos<TQ && AlunoDisciplina[pos].codDis!=aux.codDis)
                    pos++;
                if(pos<TQ){
                    for(int j=pos;j<TQ-1;j++){
                        AlunoDisciplina[j] = AlunoDisciplina[j+1];
                    }
                    TQ--;
                }
            }
            if(TP>0){
                printf("Digite o codigo da materia que voce queira excluir:\n");
                scanf("%d", &aux.codDis);
            }
        }
    }
    else
        printf("Nao tem codigo de disciplina para voce excluir\n");
    getch();
}
void ExcluirCadastroNota(tpAlunoDisciplina AlunoDisciplina[TF], int &TQ){
    system("cls");
    tpAlunoDisciplina aux;
    int pos;
    if(TQ>0){
        printf("Digite o RA primeiro:\n");
        fflush(stdin);
        gets(aux.ra);
        while(TQ>0 && strcmp(aux.ra, "\0")!=0){
            pos = BuscaExaustivaAlunoDisciplinaRA(AlunoDisciplina, aux.ra, TQ);
            if(pos!=-1){
                printf("Digite agora o codigo da disciplina para excluir:\n");
                fflush(stdin);
                scanf("%d", &aux.codDis);
                pos = BuscaExaustivaAlunoDisciplina(AlunoDisciplina, aux.ra, aux.codDis, TQ);
                if(pos!=-1){
                    for(int i=pos;i<TQ-1;i++)
                        AlunoDisciplina[i] = AlunoDisciplina[i+1];
                    TQ--;
                }
                else
                    printf("Esse codigo nao esta cadastrado no relatorio\n");
            }
            else
                printf("Este RA nao esta cadastrado no relatorio\n");
            if(TQ>0){
                printf("Digite o RA primeiro:\n");
                fflush(stdin);
                gets(aux.ra);
            }
        }
    }
    else
        printf("Nao tem ra e nem cod para excluir\n");
    getch();
}
void BuscarNome(tpAluno Aluno[TF], int TL){
    system("cls");
    char nome[30], tecla;
    int pos;
    if(TL>0){
        do{
            printf("Digite o nome da pessoa:\n");
            fflush(stdin);
            gets(nome);
            for(int i=0;i<TL;i++){
                pos = BuscaExaustivaPrimeiroNome(Aluno, nome, TL, i);
                if(pos!=-1)
                    printf("Nome: %s\t\tRA: %s\n", Aluno[i].nome, Aluno[i].ra);
            }
            printf("Deseja continuar? <s/n>\n");
            tecla = toupper(getch());
        }while(tecla=='S');
    }
    else
        printf("Nao tem nenhuma informacao\n");
    getch();
}
void BuscarSobrenomeNome(tpAluno Aluno[TF], int TL) {
    system("cls");
    char sobrenome[30], tecla;
    int pos;
    if(TL>0){
        do{
            printf("Digite o sobrenome da pessoa:\n");
            fflush(stdin);
            gets(sobrenome);
            /*
            for(int i = 0; i < TL; i++){
                int pos = 0, j=0;
                while(Aluno[i].nome[j] != '\0' && Aluno[i].nome[j] != ' ')
                    j++;
                if(Aluno[i].nome[j] == ' ')
                    j++;
                while(pos < strlen(sobrenome) && Aluno[i].nome[j + pos] == sobrenome[pos])
                    pos++;
                if(pos == strlen(sobrenome) && (Aluno[i].nome[j + pos] == ' ' || Aluno[i].nome[j + pos] == '\0'))
                    printf("Nome: %s\t\tRA: %s\n", Aluno[i].nome, Aluno[i].ra);
                else
                    printf("Nao tem nenhuma pessoa com esse sobrenome\n");
            }
            */
            for(int i=0;i<TL;i++){
                pos = BuscaExaustivaSobrenome(Aluno, sobrenome, TL, i);
                if(pos!=-1){
                    printf("Nome: %s\tRA:%s\n", Aluno[pos].nome, Aluno[pos].ra);
                }
            }
            printf("Deseja continuar? <s/n>\n");
            tecla = toupper(getch());
        }while(tecla=='S');
    }else
        printf("Sem dados\n");
    getch();
}
void BuscarDisciplina(tpDisciplina Disciplina[TF], int TP){
    system("cls");
    char disciplina[30], tecla;
    int pos;
    if(TP>0){
        do{
            printf("Digite primeiro nome da disciplina:\n");
            fflush(stdin);
            gets(disciplina);
            for(int i=0;i<TP;i++){
                pos = BuscaExaustivaPrimeiroDisciplina(Disciplina, disciplina, TP, i);
                if(pos!=-1)
                    printf("Disciplina: %s\t\tCodigo: %d\n",Disciplina[i].disciplina, Disciplina[i].codDis);
            }
            printf("Deseja continuar? <s/n>\n");
            tecla = toupper(getch());
        }while(tecla=='S');
    }
    else
        printf("Nao tem nenhuma informacao\n");
    getch();
}
void BuscarPrimeiraLetra(tpAluno Aluno[TF], int TL){
    system("cls");
    char letra, tecla;
    if(TL>0){
        do{
            printf("Digite uma letra:\n");
            letra = toupper(getch());
            for(int i=0;i<TL;i++){
                if(toupper(Aluno[i].nome[0])==letra)
                    printf("Nome: %s\tRA: %s\n", Aluno[i].nome, Aluno[i].ra);
            }
            printf("Deseja continuar? <s/n>\n");
            tecla = toupper(getch());
        }while(tecla=='S');
    }
    else
        printf("Sem dados\n");
    getch();
}
void AlternarNome(tpAluno Aluno[TF], int TL){
    system("cls");
    char ra[30], nome[30], tecla;
    int pos;
    if(TL>0){
        do{
            printf("Digite o RA do aluno:\n");
            gets(ra);
            pos = BuscaExaustivaAluno(Aluno, ra, TL);
            if(pos!=-1){
                printf("Digite o nome para alterar:\n");
                gets(nome);
                strcpy(Aluno[pos].nome, nome);
            }
            printf("Deseja continuar? <s/n>\n");
            tecla = toupper(getch());
        }while(tecla=='S');
    }
    else
        printf("Nao tem nenhuma informacao\n");
    getch();
}
void AlterarDisciplina(tpDisciplina Disciplina[TF], int TP){
    system("cls");
    int codDis, pos;
    char disciplina[30], tecla;
    if(TP>0){
        do{
            printf("Digite o codigo da disciplina:\n");
            scanf("%d", &codDis);
            pos = BuscaExaustivaDisciplinaNum(Disciplina, codDis, TP);
            if(pos!=-1){
                printf("Digite o nome da disciplina para substituir:\n");
                fflush(stdin);
                gets(disciplina);
                strcpy(Disciplina[pos].disciplina, disciplina);
            }
            printf("Deseja continuar? <s/n>\n");
            tecla = toupper(getch());
        }while(tecla=='S');
    }
    else
        printf("Nao tem nenhuma informacao\n");
    getch();
}
void AlterarNota(tpAlunoDisciplina AlunoDisciplina[TF], int TQ){
    system("cls");
    char tecla, ra[30], pos;
    int codDis;
    float nota;
    if(TQ>0){
        do{
            printf("Digite o RA:\n");
            fflush(stdin);
            gets(ra);
            pos = BuscaExaustivaAlunoDisciplinaRA(AlunoDisciplina, ra, TQ);
            if(pos!=-1){
                printf("Digite o codigo da materia:\n");
                scanf("%d", &codDis);
                pos = BuscaExaustivaAlunoDisciplina(AlunoDisciplina, ra, codDis, TQ);
                if(pos!=-1){
                    printf("Digite a nota para substituir:\n");
                    scanf("%f", &nota);
                    AlunoDisciplina[pos].nota = nota;
                }
                else
                    printf("Nao tem esse codigo\n");
            }
            else
                printf("Nao existe esse RA\n");
            printf("Deseja continuar? <s/n>\n");
            tecla = toupper(getch());
        }while(tecla=='S');
    }
    else
        printf("Nao tem nenhuma informacao\n");
    getch();
}
int main(){
    tpAluno Aluno[TF];
    tpDisciplina Disciplina[TF];
    tpAlunoDisciplina AlunoDisciplina[TF];
    int TL=0, TP=0, TQ=0;
    char tecla;
    do{
        tecla = menu();
        switch(tecla){
            case 'A':
                tecla = Cadastrar();
                switch(tecla){
                    case 'A':CadastroNome(Aluno, TL);break;
                    case 'B':CadastroDisciplina(Disciplina, TP);break;
                    case 'C':CadastroAlunoDisciplina(Aluno, Disciplina, AlunoDisciplina, TL, TP, TQ);break;
                }
                break;
            case 'B':
                tecla = Exibir();
                switch(tecla){
                    case 'A':ExibirCadastroNome(Aluno, TL);break;
                    case 'B':ExibirCadastroDisciplina(Disciplina, TP);break;
                    case 'C':ExibirCadastroNota(AlunoDisciplina, TQ);break;
                    case 'D':ExibirRelatorio(Aluno, Disciplina, AlunoDisciplina, TL, TP, TQ);break;
                    case 'E':ExibirAlunosReprovados(Aluno, AlunoDisciplina, TL, TQ);break;
                    case 'F':ExibirDisciplinaMediaAbaixo(Disciplina, AlunoDisciplina, TP, TQ);break;
                }
                break;
            case 'C':
                tecla = Exluir();
                switch(tecla){
                    case 'A':ExcluirCadastroNome(Aluno, AlunoDisciplina, TL, TQ);break;
                    case 'B':ExcluirCadastroDisciplina(Disciplina, AlunoDisciplina, TP, TQ);break;
                    case 'C':ExcluirCadastroNota(AlunoDisciplina, TQ);break;
                }
                break;
            case 'D':
                tecla = Buscar();
                switch(tecla){
                    case 'A':BuscarNome(Aluno, TL);break;
                    case 'B':BuscarSobrenomeNome(Aluno, TL);break;
                    case 'C':BuscarDisciplina(Disciplina, TP);break;
                    case 'D':BuscarPrimeiraLetra(Aluno, TL);break;
                }
                break;
            case 'E':
                tecla = Alternar();
                switch(tecla){
                    case 'A':AlternarNome(Aluno, TL);break;
                    case 'B':AlterarDisciplina(Disciplina, TP);break;
                    case 'C':AlterarNota(AlunoDisciplina, TQ);break;
                }
                break;
        }
    }while(tecla!=27);
}
