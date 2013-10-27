/* Funcoes */

int abreArquivo(char *argumento,FILE *arquivo);
void aplicaEstampaDC(elementosNet (*netlist)[NUMERO_MAX_COMPONENTES+1][NUMERO_MAX_COMPONENTES+1], elementosNet *componente);
void inicializaNetlist(elementosNet (*netlist)[NUMERO_MAX_COMPONENTES+1][NUMERO_MAX_COMPONENTES+1]);
void geraVetorElementos(FILE *arquivo,elementosNet (*netlist)[NUMERO_MAX_COMPONENTES+1],int quantidadeNos,int quantidadeElementos, simulacao *informacoes);