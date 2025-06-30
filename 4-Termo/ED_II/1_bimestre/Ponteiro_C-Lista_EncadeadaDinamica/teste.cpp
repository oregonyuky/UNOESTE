#include <stdio.h>
#include <string.h>

int main() {
    char frase[] = "um;dois,dois;tres,tres;quatro,quatro;cinco";

    char *saveptr1;
    char *saveptr2;

    char *token = strtok_r(frase, ",", &saveptr1);
    while (token) {
        char *seg = strtok_r(token, ";", &saveptr2);
        int i=0;
        char sobrenome[30], name[30];
        while (seg) {
            if(!i)strcpy(sobrenome, seg);
            else strcpy(name, seg);
            seg = strtok_r(NULL, ";", &saveptr2);
            i++;
        }
        printf("%s %s\n", sobrenome, name);
        token = strtok_r(NULL, ",", &saveptr1);
    }

    return 0;
}

