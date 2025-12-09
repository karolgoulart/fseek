#include<stdio.h>

long tamanho(char* nomearquivo){
    FILE* arq= fopen(nomearquivo, "r");
    int cont=0;
    
    if(!arq){
        printf(Erro ao abrir o arquivo);
        return 1;
    }
    int c;
    while(c=fgetc(arq) != EOF){
        cont++;
    }
    fclose(arq);
    return cont;
}
