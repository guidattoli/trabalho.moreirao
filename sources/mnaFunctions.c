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
	char buffer[TAMANHO_LIMITE_LINHA],bufferAtoi[10],bufferDouble[50],bufferSIN_DC;
	int inicial, final, contador;
	
	fgets (buffer, TAMANHO_LIMITE_LINHA, arquivo);
	quantidadeNos = atoi(buffer);
	quantidadeElementos = 0;
	while ((fgets (buffer, TAMANHO_LIMITE_LINHA+2, arquivo)) != NULL)
    {
	switch(buffer[0]){
	case 'R':
	  
	(*netlist)[quantidadeElementos].tipoComponente= RESISTOR;
	  
	inicial=final=0;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy((*netlist)[quantidadeElementos].nome, &buffer[inicial], (final-inicial));
	(*netlist)[quantidadeElementos].nome[final]='\0';
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferAtoi, &buffer[inicial], (final-inicial));
	bufferAtoi[final]='\0';
	(*netlist)[quantidadeElementos].noPositivo=atoi(bufferAtoi);
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferAtoi, &buffer[inicial], (final-inicial));
	bufferAtoi[final]='\0';
	(*netlist)[quantidadeElementos].noNegativo=atoi(bufferAtoi);
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferDouble, &buffer[inicial], (final-inicial));
	bufferDouble[final]='\0';
	(*netlist)[quantidadeElementos].valor=atof(bufferAtoi);
	
	quantidadeElementos++;
	
		break;
	case 'L': /* ver caso do acoplamento */
	  
	(*netlist)[quantidadeElementos].tipoComponente= INDUTOR;
	  
	inicial=final=0;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy((*netlist)[quantidadeElementos].nome, &buffer[inicial], (final-inicial));
	(*netlist)[quantidadeElementos].nome[final]='\0';
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferAtoi, &buffer[inicial], (final-inicial));
	bufferAtoi[final]='\0';
	(*netlist)[quantidadeElementos].noPositivo=atoi(bufferAtoi);
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferAtoi, &buffer[inicial], (final-inicial));
	bufferAtoi[final]='\0';
	(*netlist)[quantidadeElementos].noNegativo=atoi(bufferAtoi);
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferDouble, &buffer[inicial], (final-inicial));
	bufferDouble[final]='\0';
	(*netlist)[quantidadeElementos].valor=atof(bufferAtoi);
	
	quantidadeElementos++;
	
		break;
	case 'C':
	
	(*netlist)[quantidadeElementos].tipoComponente= CAPACITOR;
	  
	inicial=final=0;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy((*netlist)[quantidadeElementos].nome, &buffer[inicial], (final-inicial));
	(*netlist)[quantidadeElementos].nome[final]='\0';
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferAtoi, &buffer[inicial], (final-inicial));
	bufferAtoi[final]='\0';
	(*netlist)[quantidadeElementos].noPositivo=atoi(bufferAtoi);
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferAtoi, &buffer[inicial], (final-inicial));
	bufferAtoi[final]='\0';
	(*netlist)[quantidadeElementos].noNegativo=atoi(bufferAtoi);
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferDouble, &buffer[inicial], (final-inicial));
	bufferDouble[final]='\0';
	(*netlist)[quantidadeElementos].valor=atof(bufferAtoi);
	
	quantidadeElementos++;
	
		break;
	case 'E':
	
	(*netlist)[quantidadeElementos].tipoComponente= E;
	  
	inicial=final=0;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy((*netlist)[quantidadeElementos].nome, &buffer[inicial], (final-inicial));
	(*netlist)[quantidadeElementos].nome[final]='\0';
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferAtoi, &buffer[inicial], (final-inicial));
	bufferAtoi[final]='\0';
	(*netlist)[quantidadeElementos].noPositivo=atoi(bufferAtoi);
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferAtoi, &buffer[inicial], (final-inicial));
	bufferAtoi[final]='\0';
	(*netlist)[quantidadeElementos].noNegativo=atoi(bufferAtoi);
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferAtoi, &buffer[inicial], (final-inicial));
	bufferAtoi[final]='\0';
	(*netlist)[quantidadeElementos].noPositivoEntrada=atoi(bufferAtoi);
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferAtoi, &buffer[inicial], (final-inicial));
	bufferAtoi[final]='\0';
	(*netlist)[quantidadeElementos].noNegativoEntrada=atoi(bufferAtoi);
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferDouble, &buffer[inicial], (final-inicial));
	bufferDouble[final]='\0';
	(*netlist)[quantidadeElementos].valor=atof(bufferAtoi);
	
	quantidadeElementos++;
		break;
	case 'F':
	
	(*netlist)[quantidadeElementos].tipoComponente= F;
	  
	inicial=final=0;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy((*netlist)[quantidadeElementos].nome, &buffer[inicial], (final-inicial));
	(*netlist)[quantidadeElementos].nome[final]='\0';
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferAtoi, &buffer[inicial], (final-inicial));
	bufferAtoi[final]='\0';
	(*netlist)[quantidadeElementos].noPositivo=atoi(bufferAtoi);
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferAtoi, &buffer[inicial], (final-inicial));
	bufferAtoi[final]='\0';
	(*netlist)[quantidadeElementos].noNegativo=atoi(bufferAtoi);
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferAtoi, &buffer[inicial], (final-inicial));
	bufferAtoi[final]='\0';
	(*netlist)[quantidadeElementos].noPositivoEntrada=atoi(bufferAtoi);
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferAtoi, &buffer[inicial], (final-inicial));
	bufferAtoi[final]='\0';
	(*netlist)[quantidadeElementos].noNegativoEntrada=atoi(bufferAtoi);
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferDouble, &buffer[inicial], (final-inicial));
	bufferDouble[final]='\0';
	(*netlist)[quantidadeElementos].valor=atof(bufferAtoi);
	
	quantidadeElementos++;
	
		break;
	case 'G':
	  
	(*netlist)[quantidadeElementos].tipoComponente= G;
	  
	inicial=final=0;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy((*netlist)[quantidadeElementos].nome, &buffer[inicial], (final-inicial));
	(*netlist)[quantidadeElementos].nome[final]='\0';
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferAtoi, &buffer[inicial], (final-inicial));
	bufferAtoi[final]='\0';
	(*netlist)[quantidadeElementos].noPositivo=atoi(bufferAtoi);
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferAtoi, &buffer[inicial], (final-inicial));
	bufferAtoi[final]='\0';
	(*netlist)[quantidadeElementos].noNegativo=atoi(bufferAtoi);
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferAtoi, &buffer[inicial], (final-inicial));
	bufferAtoi[final]='\0';
	(*netlist)[quantidadeElementos].noPositivoEntrada=atoi(bufferAtoi);
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferAtoi, &buffer[inicial], (final-inicial));
	bufferAtoi[final]='\0';
	(*netlist)[quantidadeElementos].noNegativoEntrada=atoi(bufferAtoi);
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferDouble, &buffer[inicial], (final-inicial));
	bufferDouble[final]='\0';
	(*netlist)[quantidadeElementos].valor=atof(bufferAtoi);
	
	quantidadeElementos++;  
	
		break;
	case 'H':
	  
	(*netlist)[quantidadeElementos].tipoComponente= H;
	  
	inicial=final=0;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy((*netlist)[quantidadeElementos].nome, &buffer[inicial], (final-inicial));
	(*netlist)[quantidadeElementos].nome[final]='\0';
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferAtoi, &buffer[inicial], (final-inicial));
	bufferAtoi[final]='\0';
	(*netlist)[quantidadeElementos].noPositivo=atoi(bufferAtoi);
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferAtoi, &buffer[inicial], (final-inicial));
	bufferAtoi[final]='\0';
	(*netlist)[quantidadeElementos].noNegativo=atoi(bufferAtoi);
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferAtoi, &buffer[inicial], (final-inicial));
	bufferAtoi[final]='\0';
	(*netlist)[quantidadeElementos].noPositivoEntrada=atoi(bufferAtoi);
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferAtoi, &buffer[inicial], (final-inicial));
	bufferAtoi[final]='\0';
	(*netlist)[quantidadeElementos].noNegativoEntrada=atoi(bufferAtoi);
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferDouble, &buffer[inicial], (final-inicial));
	bufferDouble[final]='\0';
	(*netlist)[quantidadeElementos].valor=atof(bufferAtoi);
	
	quantidadeElementos++;
		break;
	case 'I':
	  
	inicial=final=0;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy((*netlist)[quantidadeElementos].nome, &buffer[inicial], (final-inicial));
	(*netlist)[quantidadeElementos].nome[final]='\0';
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferAtoi, &buffer[inicial], (final-inicial));
	bufferAtoi[final]='\0';
	(*netlist)[quantidadeElementos].noPositivo=atoi(bufferAtoi);
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferAtoi, &buffer[inicial], (final-inicial));
	bufferAtoi[final]='\0';
	(*netlist)[quantidadeElementos].noNegativo=atoi(bufferAtoi);
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferSIN_DC, &buffer[inicial], (final-inicial));
	bufferSIN_DC='\0';
	
	if(!strcmp(bufferSIN_DC,"DC"))
	{ /*parametros dc */
	(*netlist)[quantidadeElementos].tipoComponente= FONTE_CORRENTE_DC;
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferDouble, &buffer[inicial], (final-inicial));
	bufferDouble[final]='\0';
	(*netlist)[quantidadeElementos].valor=atof(bufferAtoi);
	
	}
	else
	  if(!strcmp(bufferSIN_DC,"SIN"))
	  {/*parametros senoidais */
	  (*netlist)[quantidadeElementos].tipoComponente= FONTE_CORRENTE_SIN;
	  

	  }
	  else
	    if(!strcmp(bufferSIN_DC,"PULSE"))
	    { /*paramentros PULSE */
	    (*netlist)[quantidadeElementos].tipoComponente= FONTE_CORRENTE_PULSE;
	    }
	
	/* */
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferDouble, &buffer[inicial], (final-inicial));
	bufferDouble[final]='\0';
	(*netlist)[quantidadeElementos].valor=atof(bufferAtoi);
	
	quantidadeElementos++;
	
		break;
	case 'V':
		break;
	case 'O':
	(*netlist)[quantidadeElementos].tipoComponente= AMPOP;
	  
	inicial=final=0;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy((*netlist)[quantidadeElementos].nome, &buffer[inicial], (final-inicial));
	(*netlist)[quantidadeElementos].nome[final]='\0';
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferAtoi, &buffer[inicial], (final-inicial));
	bufferAtoi[final]='\0';
	(*netlist)[quantidadeElementos].noPositivo=atoi(bufferAtoi);
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferAtoi, &buffer[inicial], (final-inicial));
	bufferAtoi[final]='\0';
	(*netlist)[quantidadeElementos].noNegativo=atoi(bufferAtoi);
	
	inicial=final+1;
	for(contador=inicial;buffer[contador]!=' ';contador++);
	final=contador;
	strncpy(bufferAtoi, &buffer[inicial], (final-inicial));
	bufferAtoi[final]='\0';
	(*netlist)[quantidadeElementos].noPositivoEntrada=atoi(bufferAtoi);
	
	quantidadeElementos++;
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