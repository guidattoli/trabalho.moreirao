/* Funcoes */

#include "mnaMacros.h"
#include "mnaTypes.h"
#include "mnaFunctions.h"

int abreArquivo(char *argumento,FILE *arquivo)
{
	arquivo = fopen (argumento, "r");
	if(arquivo == NULL)
	return ERRO_ABRIR_ARQUIVO;
	return OK;	
}

void geraVetorElementos(FILE *arquivo,elementosNet (*netlist)[NUMERO_MAX_COMPONENTES+1],int quantidadeNos,int quantidadeElementos)
{
	char buffer[TAMANHO_LIMITE_LINHA];
	int inicial, final, contador;
	
	fgets (buffer, TAMANHO_LIMITE_LINHA, arquivo);
	quantidadeNos = atoi(buffer);
	quantidadeElementos = 0;
	while ((fgets (buffer, TAMANHO_LIMITE_LINHA, arquivo)) != NULL)
    {
	switch(buffer[0]){
	case 'R':
	inicial=final=0;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy((*netlist)[quantidadeElementos].nome, &buffer[inicial], (final-inicial))
		break;
	case 'L':
		break;
	case 'C':
		break;
	case 'E':
		break;
	case 'F':
		break;
	case 'G':
		break;
	case 'H':
		break;
	case 'I':
		break;
	case 'V':
		break;
	case 'O':
		break;
	case '*':
		break;
	}
/*	fprintf (escrita, "%s", nome); */
	
}
}

void aplicaEstampaDC(elementosNet (*netlist)[NUMERO_MAX_COMPONENTES+1][NUMERO_MAX_COMPONENTES+1], elementosNet *componente)
{
	switch((*componente).tipoComponente){
	case RESISTOR:
		break;
	case INDUTOR:
		break;
	case CAPACITOR:
		break;
	case ACOPLAMENTO:
		break;
	case AMPOP:
		break;
	}
}



void inicializaNetlist(elementosNet (*netlist)[NUMERO_MAX_COMPONENTES+1][NUMERO_MAX_COMPONENTES+1])
{
	int linha, coluna;
	for(linha=0;linha<NUMERO_MAX_COMPONENTES;linha++)
		{
		for(coluna=0;coluna<NUMERO_MAX_COMPONENTES;coluna++)
			{
			(*netlist)[linha][coluna].valor = 0;
			}
		}
}