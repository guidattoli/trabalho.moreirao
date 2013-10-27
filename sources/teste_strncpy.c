/* Fonte da funcao principal */



#include <stdlib.h>
#include <stdio.h>
#include <complex.h>
#include <math.h>
#include <string.h>
#include <errno.h>



int main(int argc, char *argv[])
{
 
  char fonte[]="123456789\0";
  char destino1[4];
  char destino2[4];
  
  strncpy(destino1,fonte,3);
  destino1[3]='\0';
  strncpy(destino2,&fonte[7],3);
  
  printf("fonte: %s\ndestino1: %s\ndestino2: %s\n",fonte,destino1,destino2);

  
  
  

  return 0;
}