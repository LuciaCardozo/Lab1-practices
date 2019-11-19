#include "LinkedList.h"
#include "Employee.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados)
{
    int ret = 0;
    char aux[3][128];
    Empleado* pEmp;
    FILE* pFile = NULL;
    if(fileName!=NULL && listaEmpleados!=NULL)
    {
        pFile = fopen(fileName,"r");
        if(pFile != NULL)
        {
            fscanf(pFile,"%[^,],%[^,],%[^\n]\n",*(aux),*(aux+1),*(aux+2));
            do
            {
                fscanf(pFile,"%[^,],%[^,],%[^\n]\n",*(aux),*(aux+1),*(aux+2));
                pEmp=empleado_newParametros(*(aux),*(aux+1),*(aux+2));
                if(pEmp!=NULL)
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
