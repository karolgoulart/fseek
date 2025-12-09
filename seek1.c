#include<stdio.h>

#define Tamanho 23;
int main(){
  FILE *arq;
  int linha;
  char idade[4];
  char estado[3];
  int posicao;
  
  arq=fopen("arq.txt", "r");
  if (!arq){
      printf("Erro ao abrir o arquivo.");
      return 1;
  }
  printf("Insira a linha desejada: ");
  scanf("%d", &linha);
  if(linha<=0){
      printf("Registro não encomtrado.");
      fclose(arq);
      return 0;
  }
  posicao= (linha-1)*Tamanho;
  fseek(arq, posicao+10, seek_set);
  if(fread(idade, sizeof(char), 3, arq) !=3){
      printf("Registro não encontrado.");
      fclose(arq);
      return 0;
  }
  fseek(arq, posicao+20, seek_set);
  if(fread(estado, sizeof(char), 2, arq) !=2){
      printf("Registro não encontrado.");
      fclose(arq);
      return 0;
  }
  printf("Idade: %c%c%c \n", idade[0], idade[1], idade[2]);
  printf("Estado: %c%c \n", estado[0], estado[1]);
  
  fclose(arq);
  return 0;
}
