#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "linkedList.h"
#include "ventas.h"

int parserText(char* fileName, LinkedList* listaEmpleados)
{
    int ret = 0;
    char aux[6][128];
    Ventas* pEmp;
    FILE* pFile = NULL;
    if(fileName != NULL && listaEmpleados != NULL)
    {
        pFile = fopen(fileName,"r");
        if(pFile != NULL)
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",*(aux),*(aux+1),*(aux+2),*(aux+3),*(aux+4),*(aux+5));
            do
            {
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",*(aux),*(aux+1),*(aux+2),*(aux+3),*(aux+4),*(aux+5));
                pEmp = venta_newParametros(*(aux),*(aux+1),*(aux+2),*(aux+3),*(aux+4),*(aux+5));
               // printf("\n%s, %s, %s, %s, %s, %s",*(aux),*(aux+1),*(aux+2),*(aux+3),*(aux+4),*(aux+5));
                if(pEmp != NULL)
                {
                    if(!ll_add(listaEmpleados,pEmp))
                    {
                        ret = 1;
                    }
                }
            }while(!feof(pFile));
        }
        fclose(pFile);
    }

    return ret; // OK
}
