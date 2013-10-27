/* Cabecalho com declaracao dos tipos a serem utilizados nas estruturas */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "mnaMacros.h"

/* typedef struct fonte
	{
	int tipoFonte;  0 - fonte DC; 1 - fonte senoidal ; 2- fonte pulsada 
	char nome[TAMANHO_MAX_NOME_FONTE];
	int noPositivo;
	int noNegativo;
	float nivelDC;
	double amplitudeA;
	double amplitudeB;
	double frequenciaSenoide;
	double fase;
	double tSubida;
	double tDescida;
	double tLigada;
	double periodo;
	struct fonte *proxima;	
	} fonte; */

typedef struct simulacao
	{
	float tempoFinal;
	float passo;
	int nTermos;
	double frequenciaMax;
	} simulacao;

typedef struct elementosNet
	{
	int tipoComponente; /* ver mnaMacros.h */
	char nome[TAMANHO_MAX_NOME_COMPONENTE];
	int noPositivo;
	int noNegativo;
	double valor;
	int noPositivoEntrada;
	int noNegativoEntrada;
	double nivelDC;
	double amplitudeA;
	double amplitudeB;
	double frequenciaSenoide;
	double fase;
	double tSubida;
	double tDescida;
	double tLigada;
	double periodo;
	} elementosNet;
