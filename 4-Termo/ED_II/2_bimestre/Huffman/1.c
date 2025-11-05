#include <stdio.h>
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

int main(void)
{
    unsigned char vet[] = {1,1,1,1,1,0,0,0,1,0,0,0,0,0,1,1,1,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0};
    unsigned char vet2[32];
    int tl=32, i;
    FILE *ptrArq = fopen("codificacao.dat", "ab");
    struct bits uval;
    for(i=0;i<tl; ){
        uval.b0 = vet[i++];
        uval.b1 = vet[i++];
        uval.b2 = vet[i++];
        uval.b3 = vet[i++];
        uval.b4 = vet[i++];
        uval.b5 = vet[i++];
        uval.b6 = vet[i++];
        uval.b7 = vet[i++];
        fwrite(&uval, sizeof(unsigned char), 1, ptrArq);
    }
    fclose(ptrArq);
    ptrArq = fopen("codificacao.dat", "rb");
    fread(&uval, sizeof(unsigned char), 1, ptrArq);
    i=0;
    while(!feof(ptrArq)){
        vet2[i++] = uval.b0;
        vet2[i++] = uval.b1;
        vet2[i++] = uval.b2;
        vet2[i++] = uval.b3;
        vet2[i++] = uval.b4;
        vet2[i++] = uval.b5;
        vet2[i++] = uval.b6;
        vet2[i++] = uval.b7;
        fread(&uval, sizeof(unsigned char), 1, ptrArq);
    }
    fclose(ptrArq);
    for(i=0;i<tl;i++)
        printf("%d", vet2[i]);
}
