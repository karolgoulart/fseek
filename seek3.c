#include<stdio.h>

int main (){
    FILE* arq= fopen("arq.txt", "r+");
    long tamanho;
    long meio;
    char* resto;
    if(!arq){
        printf("Erro ao abrir o arquivo!");
        return 1;
    }
    fseek(arq, 0, seek_end);
    tamanho= ftell(arq);
    
    meio= tamanho/2;
    
    fseek(arq, meio, seek_set);
    resto = malloc(tamanho - meio + 1);
    fread(resto, sizeof(char), tamanho-meio, arq);
    
    fseek(arq, meio, seek_set);
    fwrite("|meio|", sizeof(char), 6, arq);
    fwrite(resto, sizeof(char), tamanho-meio, arq);
    
    free(resto);
    fclose(arq);
    
    return 0;
}
