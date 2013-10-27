/* Fonte da funcao principal */



#include <stdlib.h>
#include <stdio.h>
#include <complex.h>
#include <math.h>
#include <string.h>
#include <errno.h>

#include "mnaMacros.h"
#include "mnaTypes.h"
#include "mnaFunctions.h"



int main(int argc, char *argv[])
{
 
  FILE * escrita;
  FILE * leitura;
  
  int quantidadeNos, quantidadeElementos, tamanhoMatriz, contador;
  elementosNet vetorComponentes[NUMERO_MAX_COMPONENTES+1];
  simulacao informacoes;
  
  double complex sistemaLinear[NUMERO_MAX_COMPONENTES+1][NUMERO_MAX_COMPONENTES+1];
  char variaveis[NUMERO_MAX_COMPONENTES+1];
  
  quantidadeNos=quantidadeElementos=0;

	leitura = fopen (argv[1], "r");
	if(leitura == NULL)
	return ERRO_ABRIR_ARQUIVO;
	  
 /* if(!abreArquivo(argv[1],leitura))
    exit(ERRO_ABRIR_ARQUIVO); */
  
  printf("passei aqui 1 \n");
  
  geraVetorElementos(leitura,&vetorComponentes,quantidadeNos,quantidadeElementos, &informacoes);
  tamanhoMatriz = quantidadeNos + quantidadeElementos + 1;
  
  printf("passei aqui 2 \n");
  
  for(contador=0;contador<quantidadeElementos;contador++)
  printf("Nome :%s\nValor : %lf\n",vetorComponentes[contador].nome,vetorComponentes[contador].valor);
  printf("\n");
  
  
 
 printf("\n");

  return OK;
}