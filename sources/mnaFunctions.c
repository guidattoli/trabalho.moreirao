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

void geraVetorElementos(FILE *arquivo,elementosNet (*netlist)[NUMERO_MAX_COMPONENTES+1],int quantidadeNos,int quantidadeElementos, simulacao *informacoes)
{
	char buffer[TAMANHO_LIMITE_LINHA], bufferTmp[TAMANHO_MAX_NOME_COMPONENTE], bufferTmp2[TAMANHO_MAX_NOME_COMPONENTE] ;
	int inicial, final, contador, achei, achei2, lidos;
	
	
	fgets (buffer, TAMANHO_LIMITE_LINHA, arquivo);
	quantidadeNos = atoi(buffer);
	quantidadeElementos = lidos = 0;
	while ((fgets (buffer, TAMANHO_LIMITE_LINHA+2, arquivo)) != NULL)
    {
	switch(buffer[0]){
	
	case 'R':
	(*netlist[quantidadeElementos]).tipoComponente = RESISTOR ;
	lidos = sscanf(buffer,"%s %i %i %lf",(*netlist[quantidadeElementos]).nome,&(*netlist[quantidadeElementos]).noPositivo,&(*netlist[quantidadeElementos]).noNegativo,&(*netlist[quantidadeElementos]).valor);  
	quantidadeElementos++;
	break;
	
	case 'L': /* ver caso do acoplamento */
	lidos = sscanf(buffer,"%s %s %s %lf",(*netlist[quantidadeElementos]).nome,bufferTmp,bufferTmp2,&(*netlist[quantidadeElementos]).valor);
	
	if(bufferTmp[0]=='L' && bufferTmp2[0]=='L')
	{
	(*netlist[quantidadeElementos]).tipoComponente = ACOPLAMENTO ;
	
	contador=0;
	achei=achei2=0;
	while(contador<quantidadeElementos && !achei && !achei2)
		{
		contador++;
		if((*netlist[contador]).tipoComponente == INDUTOR)
			{
			if( !strcmp( (*netlist)[contador].nome, bufferTmp ))
				{
				(*netlist[quantidadeElementos]).noPositivo = (*netlist[contador]).noPositivo;
				(*netlist[quantidadeElementos]).noNegativo = (*netlist[contador]).noNegativo;
				achei=1;
				}
			if( !strcmp( (*netlist)[contador].nome, bufferTmp2 ))
				{
				(*netlist[quantidadeElementos]).noPositivoEntrada = (*netlist[contador]).noPositivo;
				(*netlist[quantidadeElementos]).noNegativoEntrada = (*netlist[contador]).noNegativo;
				achei2=1;
				}				
			}
		
		}
	}
	else
	{
	(*netlist[quantidadeElementos]).tipoComponente = INDUTOR ;
	(*netlist[quantidadeElementos]).noPositivo = atoi(bufferTmp);
	(*netlist[quantidadeElementos]).noPositivo = atoi(bufferTmp2);
	}
	quantidadeElementos++;
	
	break;
	
	case 'C':
	(*netlist[quantidadeElementos]).tipoComponente = CAPACITOR ;
	lidos = sscanf(buffer,"%s %i %i %lf",(*netlist[quantidadeElementos]).nome,&(*netlist[quantidadeElementos]).noPositivo,&(*netlist[quantidadeElementos]).noNegativo,&(*netlist[quantidadeElementos]).valor);  
	quantidadeElementos++;
	
	break;
	
	case 'E':
	(*netlist[quantidadeElementos]).tipoComponente = E ;
	lidos = sscanf(buffer,"%s %i %i %i %i %lf",(*netlist[quantidadeElementos]).nome,&(*netlist[quantidadeElementos]).noPositivo,&(*netlist[quantidadeElementos]).noNegativo,&(*netlist[quantidadeElementos]).noPositivoEntrada,&(*netlist[quantidadeElementos]).noNegativoEntrada,&(*netlist[quantidadeElementos]).valor);  
	quantidadeElementos++;
	break;
	
	case 'F':
	(*netlist[quantidadeElementos]).tipoComponente = F ;
	lidos = sscanf(buffer,"%s %i %i %i %i %lf",(*netlist[quantidadeElementos]).nome,&(*netlist[quantidadeElementos]).noPositivo,&(*netlist[quantidadeElementos]).noNegativo,&(*netlist[quantidadeElementos]).noPositivoEntrada,&(*netlist[quantidadeElementos]).noNegativoEntrada,&(*netlist[quantidadeElementos]).valor);  
	quantidadeElementos++;
	break;
	
	case 'G':
	(*netlist[quantidadeElementos]).tipoComponente = G ;
	lidos = sscanf(buffer,"%s %i %i %i %i %lf",(*netlist[quantidadeElementos]).nome,&(*netlist[quantidadeElementos]).noPositivo,&(*netlist[quantidadeElementos]).noNegativo,&(*netlist[quantidadeElementos]).noPositivoEntrada,&(*netlist[quantidadeElementos]).noNegativoEntrada,&(*netlist[quantidadeElementos]).valor);  
	quantidadeElementos++; 
	break;
	
	case 'H':
	(*netlist[quantidadeElementos]).tipoComponente = H ;
	lidos = sscanf(buffer,"%s %i %i %i %i %lf",(*netlist[quantidadeElementos]).nome,&(*netlist[quantidadeElementos]).noPositivo,&(*netlist[quantidadeElementos]).noNegativo,&(*netlist[quantidadeElementos]).noPositivoEntrada,&(*netlist[quantidadeElementos]).noNegativoEntrada,&(*netlist[quantidadeElementos]).valor);  
	quantidadeElementos++;
	break;
	
	case 'I':
	lidos = sscanf(buffer,"%*s %*i %*i %s",bufferTmp);
	if(!strcmp("DC",bufferTmp))
		{
		(*netlist[quantidadeElementos]).tipoComponente = FONTE_CORRENTE_DC ;
		sscanf(buffer,"%s %i %i %*s %lf",(*netlist[quantidadeElementos]).nome,&(*netlist[quantidadeElementos]).noPositivo,&(*netlist[quantidadeElementos]).noNegativo,&(*netlist[quantidadeElementos]).valor);
		}
	if(!strcmp("SIN",bufferTmp))
		{
		(*netlist[quantidadeElementos]).tipoComponente = FONTE_CORRENTE_SIN ;
		sscanf(buffer,"%s %i %i %*s %lf %lf %lf %*s %*s %lf %*s",(*netlist[quantidadeElementos]).nome,&(*netlist[quantidadeElementos]).noPositivo,&(*netlist[quantidadeElementos]).noNegativo,&(*netlist[quantidadeElementos]).nivelDC,&(*netlist[quantidadeElementos]).valor,&(*netlist[quantidadeElementos]).frequenciaSenoide,&(*netlist[quantidadeElementos]).fase);
		}
	if(!strcmp("PULSE",bufferTmp))
		{
		(*netlist[quantidadeElementos]).tipoComponente = FONTE_CORRENTE_PULSE ;
		sscanf(buffer,"%s %i %i %*s %lf %lf %*s %lf %lf %lf %lf %*s",(*netlist[quantidadeElementos]).nome,&(*netlist[quantidadeElementos]).noPositivo,&(*netlist[quantidadeElementos]).noNegativo,&(*netlist[quantidadeElementos]).amplitudeA,&(*netlist[quantidadeElementos]).amplitudeB,&(*netlist[quantidadeElementos]).tSubida,&(*netlist[quantidadeElementos]).tDescida,&(*netlist[quantidadeElementos]).tLigada,&(*netlist[quantidadeElementos]).periodo);
		}
	quantidadeElementos++;
	break;
	
	case 'V':	
	lidos = sscanf(buffer,"%*s %*i %*i %s",bufferTmp);
	if(!strcmp("DC",bufferTmp))
		{
		(*netlist[quantidadeElementos]).tipoComponente = FONTE_TENSAO_DC ;
		sscanf(buffer,"%s %i %i %*s %lf",(*netlist[quantidadeElementos]).nome,&(*netlist[quantidadeElementos]).noPositivo,&(*netlist[quantidadeElementos]).noNegativo,&(*netlist[quantidadeElementos]).valor);
		}
	if(!strcmp("SIN",bufferTmp))
		{
		(*netlist[quantidadeElementos]).tipoComponente = FONTE_TENSAO_SIN ;
		sscanf(buffer,"%s %i %i %*s %lf %lf %lf %*s %*s %lf %*s",(*netlist[quantidadeElementos]).nome,&(*netlist[quantidadeElementos]).noPositivo,&(*netlist[quantidadeElementos]).noNegativo,&(*netlist[quantidadeElementos]).nivelDC,&(*netlist[quantidadeElementos]).valor,&(*netlist[quantidadeElementos]).frequenciaSenoide,&(*netlist[quantidadeElementos]).fase);
		}
	if(!strcmp("PULSE",bufferTmp))
		{
		(*netlist[quantidadeElementos]).tipoComponente = FONTE_TENSAO_PULSE ;
		sscanf(buffer,"%s %i %i %*s %lf %lf %*s %lf %lf %lf %lf %*s",(*netlist[quantidadeElementos]).nome,&(*netlist[quantidadeElementos]).noPositivo,&(*netlist[quantidadeElementos]).noNegativo,&(*netlist[quantidadeElementos]).amplitudeA,&(*netlist[quantidadeElementos]).amplitudeB,&(*netlist[quantidadeElementos]).tSubida,&(*netlist[quantidadeElementos]).tDescida,&(*netlist[quantidadeElementos]).tLigada,&(*netlist[quantidadeElementos]).periodo);
		}
	quantidadeElementos++;
	break;
	
	case 'O':
	(*netlist[quantidadeElementos]).tipoComponente = AMPOP ;
	lidos = sscanf(buffer,"%s %i %i %i %i",(*netlist[quantidadeElementos]).nome,&(*netlist[quantidadeElementos]).noPositivo,&(*netlist[quantidadeElementos]).noNegativo,&(*netlist[quantidadeElementos]).noPositivoEntrada,&(*netlist[quantidadeElementos]).noNegativoEntrada);  
	quantidadeElementos++;
	break;
	
	case '*':
	break;
	
	case '.':
	lidos = sscanf(buffer,"%*s %f %f %i",&(*informacoes).tempoFinal,&(*informacoes).passo,&(*informacoes).nTermos);
	if (lidos != 2 && lidos == 1)
	{
		(*informacoes).nTermos=0;
		(*informacoes).frequenciaMax=1/(2*(*informacoes).passo);
	}
	break;
	
	
	}

	
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