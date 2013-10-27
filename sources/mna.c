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
  
  int linha2, coluna2;
  int quantidadeNos;
  elementosNet matrizComponentes[NUMERO_MAX_COMPONENTES+1][NUMERO_MAX_COMPONENTES+1];
  elementosNet *componenteAtual;
  fonte        matrizFontes[NUMERO_MAX_COMPONENTES+1];


  
 inicializaNetlist(&matrizComponentes);

 	
	for(linha2=0;linha2<5;linha2++)
		{
		for(coluna2=0;coluna2<5;coluna2++)
			{
			printf("%f   ",matrizComponentes[linha2][coluna2].valor);
			}
		printf("\n");
		}
 
 printf("\n");

  return OK;
}