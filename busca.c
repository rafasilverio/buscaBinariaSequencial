#include <stdio.h>

#define SIZE 10

/*Busca Sequencial*/
int buscaSeq(int*v, int e, int size){
  int i;
  for(i = 0; i < size; i++)
   if(v[i] == e)
    return i;
}

/*Busca Binária iterativa*/
int buscaBinaria(int* v, int e, int size){
 int inicio = 0, fim = SIZE-1;
 int meio;

 while(inicio <= fim){
    meio = (inicio+fim)/2;
   if(v[meio] == e)
    return meio;
   if(v[meio] < e)
    inicio = meio+1;
   else
    fim = meio-1;
 }
 return -1;
}

/*Busca binária recursiva*/
int buscaBinariaRecursiva(int* v, int e, int inicio, int fim){
  if(inicio > fim)
   return -1;
  else{
   int meio = (inicio+fim)/2;
   if(v[meio] == e)
    return meio;
   if(v[meio] < e)
    return buscaBinariaRecursiva(v, e, meio+1, fim);
   else
    return buscaBinariaRecursiva(v, e, inicio, meio-1 );
  }
}

int main(){
 int v[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; 

 /*chamada das funções*/
 printf("Sequencial\n");
 printf("Posicao: %d ", buscaSeq(v, 5, SIZE));
 printf("\n");

 printf("Binaria\n");
 printf("Posicao: %d ", buscaBinaria(v, 5, SIZE));
 printf("\n");
 
 printf("Binaria Recursiva\n");
 printf("Posicao: %d ", buscaBinariaRecursiva(v, 5, 0, SIZE-1));
 printf("\n");

 return 0;
}
