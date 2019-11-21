#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "parser.h"
#include "ventas.h"
int generarArchivoInformes(char* fileName,LinkedList* listaEmpleados);

int main()
{
    LinkedList* listaEmpleados;
    listaEmpleados = ll_newLinkedList();
    if(parserText("data.csv",listaEmpleados)==1)
    {
        if(generarArchivoInformes("informes.txt",listaEmpleados)==1)
        {
            printf("\nSe genero un archivo informes.txt\n");
        }
    }

    return 0;
}

int generarArchivoInformes(char* fileName,LinkedList* listaEmpleados)
{
    int ret = 0;
    int reveladas;
    int reveladasPolaroid;
    int ventasMayorUno;
    int ventasMayorDos;
    FILE* pFile;
    if(fileName != NULL && listaEmpleados != NULL)
    {
        pFile = fopen(fileName,"w");
        fprintf(pFile,"Informe de Ventas\n");
        if(pFile != NULL)
        {
            reveladas = ll_count(listaEmpleados,em_calcular);
            ventasMayorUno = ll_count(listaEmpleados,em_calcularVentasMayorA150);
            ventasMayorDos = ll_count(listaEmpleados,em_calcularVentasMayorA300);
            reveladasPolaroid = ll_count(listaEmpleados,em_calcularPolaroidReveladas);
            fprintf(pFile,"Cantidad de fotos reveledas totales: %d\n",reveladas);
            fprintf(pFile,"Cantidad de ventas por un monto mayor a $150: %d\n",ventasMayorUno);
            fprintf(pFile,"Cantidad de ventas por un monto mayor a $300: %d\n",ventasMayorDos);
            fprintf(pFile,"Cantidad de fotos polaroids reveladas: %d\n",reveladasPolaroid);
        }
        fclose(pFile);
        ret = 1;
    }
    return ret;
}
