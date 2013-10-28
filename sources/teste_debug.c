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
  
/* linhas de codigo que estavam na mnaFunctions.c */
  
	char buffer[TAMANHO_LIMITE_LINHA], bufferTmp[TAMANHO_MAX_NOME_COMPONENTE], bufferTmp2[TAMANHO_MAX_NOME_COMPONENTE] ;
	int inicial, final, contador2, achei, achei2, lidos;

  
	quantidadeNos=quantidadeElementos=0;
    
	leitura = fopen (argv[1], "r");
	if(leitura == NULL)
	return ERRO_ABRIR_ARQUIVO;	
  
	
	
	fgets (buffer, TAMANHO_LIMITE_LINHA, leitura);
	quantidadeNos = atoi(buffer);
	quantidadeElementos = lidos = 0;
	while ((fgets (buffer, TAMANHO_LIMITE_LINHA+2, leitura)) != NULL)
    {
	switch(buffer[0]){
	
	case 'R':
	(vetorComponentes[quantidadeElementos]).tipoComponente = RESISTOR ;
	lidos = sscanf(buffer,"%s %i %i %lf",(vetorComponentes[quantidadeElementos]).nome,&(vetorComponentes[quantidadeElementos]).noPositivo,&(vetorComponentes[quantidadeElementos]).noNegativo,&(vetorComponentes[quantidadeElementos]).valor);  
	quantidadeElementos++;
	break;
	
	case 'L': /* ver caso do acoplamento */
	lidos = sscanf(buffer,"%s %s %s %lf",(vetorComponentes[quantidadeElementos]).nome,bufferTmp,bufferTmp2,&(vetorComponentes[quantidadeElementos]).valor);
	
	if(bufferTmp[0]=='L' && bufferTmp2[0]=='L')
	{
	(vetorComponentes[quantidadeElementos]).tipoComponente = ACOPLAMENTO ;
	
	contador2=0;
	achei=achei2=0;
	while(contador2<quantidadeElementos && !achei && !achei2)
		{
		contador2++;
		if((vetorComponentes[contador2]).tipoComponente == INDUTOR)
			{
			if( !strcmp( (vetorComponentes)[contador2].nome, bufferTmp ))
				{
				(vetorComponentes[quantidadeElementos]).noPositivo = (vetorComponentes[contador2]).noPositivo;
				(vetorComponentes[quantidadeElementos]).noNegativo = (vetorComponentes[contador2]).noNegativo;
				achei=1;
				}
			if( !strcmp( (vetorComponentes)[contador2].nome, bufferTmp2 ))
				{
				(vetorComponentes[quantidadeElementos]).noPositivoEntrada = (vetorComponentes[contador2]).noPositivo;
				(vetorComponentes[quantidadeElementos]).noNegativoEntrada = (vetorComponentes[contador2]).noNegativo;
				achei2=1;
				}				
			}
		
		}
	}
	else
	{
	(vetorComponentes[quantidadeElementos]).tipoComponente = INDUTOR ;
	(vetorComponentes[quantidadeElementos]).noPositivo = atoi(bufferTmp);
	(vetorComponentes[quantidadeElementos]).noNegativo = atoi(bufferTmp2);
	}
	quantidadeElementos++;
	
	break;
	
	case 'C':
	(vetorComponentes[quantidadeElementos]).tipoComponente = CAPACITOR ;
	lidos = sscanf(buffer,"%s %i %i %lf",(vetorComponentes[quantidadeElementos]).nome,&(vetorComponentes[quantidadeElementos]).noPositivo,&(vetorComponentes[quantidadeElementos]).noNegativo,&(vetorComponentes[quantidadeElementos]).valor);  
	quantidadeElementos++;
	
	break;
	
	case 'E':
	(vetorComponentes[quantidadeElementos]).tipoComponente = E ;
	lidos = sscanf(buffer,"%s %i %i %i %i %lf",(vetorComponentes[quantidadeElementos]).nome,&(vetorComponentes[quantidadeElementos]).noPositivo,&(vetorComponentes[quantidadeElementos]).noNegativo,&(vetorComponentes[quantidadeElementos]).noPositivoEntrada,&(vetorComponentes[quantidadeElementos]).noNegativoEntrada,&(vetorComponentes[quantidadeElementos]).valor);  
	quantidadeElementos++;
	break;
	
	case 'F':
	(vetorComponentes[quantidadeElementos]).tipoComponente = F ;
	lidos = sscanf(buffer,"%s %i %i %i %i %lf",(vetorComponentes[quantidadeElementos]).nome,&(vetorComponentes[quantidadeElementos]).noPositivo,&(vetorComponentes[quantidadeElementos]).noNegativo,&(vetorComponentes[quantidadeElementos]).noPositivoEntrada,&(vetorComponentes[quantidadeElementos]).noNegativoEntrada,&(vetorComponentes[quantidadeElementos]).valor);  
	quantidadeElementos++;
	break;
	
	case 'G':
	(vetorComponentes[quantidadeElementos]).tipoComponente = G ;
	lidos = sscanf(buffer,"%s %i %i %i %i %lf",(vetorComponentes[quantidadeElementos]).nome,&(vetorComponentes[quantidadeElementos]).noPositivo,&(vetorComponentes[quantidadeElementos]).noNegativo,&(vetorComponentes[quantidadeElementos]).noPositivoEntrada,&(vetorComponentes[quantidadeElementos]).noNegativoEntrada,&(vetorComponentes[quantidadeElementos]).valor);  
	quantidadeElementos++; 
	break;
	
	case 'H':
	(vetorComponentes[quantidadeElementos]).tipoComponente = H ;
	lidos = sscanf(buffer,"%s %i %i %i %i %lf",(vetorComponentes[quantidadeElementos]).nome,&(vetorComponentes[quantidadeElementos]).noPositivo,&(vetorComponentes[quantidadeElementos]).noNegativo,&(vetorComponentes[quantidadeElementos]).noPositivoEntrada,&(vetorComponentes[quantidadeElementos]).noNegativoEntrada,&(vetorComponentes[quantidadeElementos]).valor);  
	quantidadeElementos++;
	break;
	
	case 'I':
	lidos = sscanf(buffer,"%*s %*i %*i %s",bufferTmp);
	if(!strcmp("DC",bufferTmp))
		{
		(vetorComponentes[quantidadeElementos]).tipoComponente = FONTE_CORRENTE_DC ;
		sscanf(buffer,"%s %i %i %*s %lf",(vetorComponentes[quantidadeElementos]).nome,&(vetorComponentes[quantidadeElementos]).noPositivo,&(vetorComponentes[quantidadeElementos]).noNegativo,&(vetorComponentes[quantidadeElementos]).valor);
		}
	if(!strcmp("SIN",bufferTmp))
		{
		(vetorComponentes[quantidadeElementos]).tipoComponente = FONTE_CORRENTE_SIN ;
		sscanf(buffer,"%s %i %i %*s %lf %lf %lf %*s %*s %lf %*s",(vetorComponentes[quantidadeElementos]).nome,&(vetorComponentes[quantidadeElementos]).noPositivo,&(vetorComponentes[quantidadeElementos]).noNegativo,&(vetorComponentes[quantidadeElementos]).nivelDC,&(vetorComponentes[quantidadeElementos]).valor,&(vetorComponentes[quantidadeElementos]).frequenciaSenoide,&(vetorComponentes[quantidadeElementos]).fase);
		}
	if(!strcmp("PULSE",bufferTmp))
		{
		(vetorComponentes[quantidadeElementos]).tipoComponente = FONTE_CORRENTE_PULSE ;
		sscanf(buffer,"%s %i %i %*s %lf %lf %*s %lf %lf %lf %lf %*s",(vetorComponentes[quantidadeElementos]).nome,&(vetorComponentes[quantidadeElementos]).noPositivo,&(vetorComponentes[quantidadeElementos]).noNegativo,&(vetorComponentes[quantidadeElementos]).amplitudeA,&(vetorComponentes[quantidadeElementos]).amplitudeB,&(vetorComponentes[quantidadeElementos]).tSubida,&(vetorComponentes[quantidadeElementos]).tDescida,&(vetorComponentes[quantidadeElementos]).tLigada,&(vetorComponentes[quantidadeElementos]).periodo);
		}
	quantidadeElementos++;
	break;
	
	case 'V':	
	lidos = sscanf(buffer,"%*s %*i %*i %s",bufferTmp);
	if(!strcmp("DC",bufferTmp))
		{
		(vetorComponentes[quantidadeElementos]).tipoComponente = FONTE_TENSAO_DC ;
		sscanf(buffer,"%s %i %i %*s %lf",(vetorComponentes[quantidadeElementos]).nome,&(vetorComponentes[quantidadeElementos]).noPositivo,&(vetorComponentes[quantidadeElementos]).noNegativo,&(vetorComponentes[quantidadeElementos]).valor);
		}
	if(!strcmp("SIN",bufferTmp))
		{
		(vetorComponentes[quantidadeElementos]).tipoComponente = FONTE_TENSAO_SIN ;
		sscanf(buffer,"%s %i %i %*s %lf %lf %lf %*s %*s %lf %*s",(vetorComponentes[quantidadeElementos]).nome,&(vetorComponentes[quantidadeElementos]).noPositivo,&(vetorComponentes[quantidadeElementos]).noNegativo,&(vetorComponentes[quantidadeElementos]).nivelDC,&(vetorComponentes[quantidadeElementos]).valor,&(vetorComponentes[quantidadeElementos]).frequenciaSenoide,&(vetorComponentes[quantidadeElementos]).fase);
		}
	if(!strcmp("PULSE",bufferTmp))
		{
		(vetorComponentes[quantidadeElementos]).tipoComponente = FONTE_TENSAO_PULSE ;
		sscanf(buffer,"%s %i %i %*s %lf %lf %*s %lf %lf %lf %lf %*s",(
		vetorComponentes[quantidadeElementos]).nome,&(vetorComponentes[quantidadeElementos]).noPositivo,&(vetorComponentes[quantidadeElementos]).noNegativo,&(vetorComponentes[quantidadeElementos]).amplitudeA,&(vetorComponentes[quantidadeElementos]).amplitudeB,&(vetorComponentes[quantidadeElementos]).tSubida,&(vetorComponentes[quantidadeElementos]).tDescida,&(vetorComponentes[quantidadeElementos]).tLigada,&(vetorComponentes[quantidadeElementos]).periodo);
		}
	quantidadeElementos++;
	break;
	
	case 'O':
	(vetorComponentes[quantidadeElementos]).tipoComponente = AMPOP ;
	lidos = sscanf(buffer,"%s %i %i %i %i",(vetorComponentes[quantidadeElementos]).nome,&(vetorComponentes[quantidadeElementos]).noPositivo,&(vetorComponentes[quantidadeElementos]).noNegativo,&(vetorComponentes[quantidadeElementos]).noPositivoEntrada,&(vetorComponentes[quantidadeElementos]).noNegativoEntrada);  
	quantidadeElementos++;
	break;
	
	case '*':
	break;
	
	case '.':
	lidos = sscanf(buffer,".TRAN %f %f %s",&(informacoes).tempoFinal,&(informacoes).passo,bufferTmp);
	if (lidos != 3 && lidos == 2)
	{
	
		(informacoes).nTermos=0;
		(informacoes).frequenciaMax=1/( 2 * (informacoes.passo));
	}
	else
	(informacoes).nTermos=atoi(bufferTmp);
	break;
	
	
	}

	
}

/* parte interna, termina aqui */

fclose(leitura);
  
  tamanhoMatriz = quantidadeNos + quantidadeElementos + 1;
  
/* Teste da funcao de leitura do arquivo */  
  
  for(contador=0;contador<quantidadeElementos;contador++)
  {
  if(vetorComponentes[contador].tipoComponente == RESISTOR || vetorComponentes[contador].tipoComponente == CAPACITOR || vetorComponentes[contador].tipoComponente == INDUTOR)
	printf("Nome :%s\nNo A: %i   No B: %i\nValor : %lf\n",vetorComponentes[contador].nome,vetorComponentes[contador].noPositivo,vetorComponentes[contador].noNegativo,vetorComponentes[contador].valor);
  if(vetorComponentes[contador].tipoComponente == FONTE_CORRENTE_PULSE)
	printf("Nome :%s\nNo A: %i   No B: %i\nAmp A : %lf Amp B : %lf\nT. Subida: %lf T. Descida :%lf T. Ligada : %lf Periodo : %lf",
	vetorComponentes[contador].nome,vetorComponentes[contador].noPositivo,vetorComponentes[contador].noNegativo,vetorComponentes[contador].amplitudeA,vetorComponentes[contador].amplitudeB,vetorComponentes[contador].tSubida,vetorComponentes[contador].tDescida,vetorComponentes[contador].tLigada,vetorComponentes[contador].periodo);
  if(vetorComponentes[contador].tipoComponente == FONTE_TENSAO_SIN)
	printf("Nome :%s\nNo A: %i   No B: %i\nNivel DC : %lf Amp : %lf Freq.: %lf Angulo :%lf\n",
	vetorComponentes[contador].nome,vetorComponentes[contador].noPositivo,vetorComponentes[contador].noNegativo,vetorComponentes[contador].nivelDC,vetorComponentes[contador].valor,vetorComponentes[contador].frequenciaSenoide,vetorComponentes[contador].fase);
  
  }
  printf("\n");
  
  printf("Tempo Final :%f\nPasso : %f\nNumero Termos : %i\nFreq. Max : %lf",informacoes.tempoFinal,informacoes.passo,informacoes.nTermos,informacoes.frequenciaMax);
  printf("\n");
  
/* Fim do Teste da funcao de leitura do arquivo */  
 
 printf("\n");

  return OK;
}