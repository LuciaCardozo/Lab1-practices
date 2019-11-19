#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    int cantidadDeEmpleadoLeidosTxt;
    int cantidadDeEmpleadoLeidosBin;
    do{
        menu(&option);
        switch(option)
        {
            case 1:
                ll_clear(listaEmpleados);
                cantidadDeEmpleadoLeidosTxt=controller_loadFromText("data.csv",listaEmpleados);
                if(cantidadDeEmpleadoLeidosTxt!=-1)
                {
                    printf("\nSe abrio: %d Archivos\n",cantidadDeEmpleadoLeidosTxt);
                    controller_ultimoIdEmployee(listaEmpleados);
                }
                else
                {
                    printf("\nError, no se puedo cargar los datos\n");
                }
                break;
            case 2:
                ll_clear(listaEmpleados);
                cantidadDeEmpleadoLeidosBin=controller_loadFromBinary("data.bin",listaEmpleados);
                if(cantidadDeEmpleadoLeidosBin!=-1)
                {
                    printf("\nSe abrio: %d Archivos\n",cantidadDeEmpleadoLeidosBin);
                    controller_ultimoIdEmployee(listaEmpleados);
                }
                else
                {
                    printf("\nError, no se puedo cargar los datos\n");
                }
                break;
            case 3:
                if(controller_addEmployee(listaEmpleados)!=-1)
                {
                    printf("\nAlta Exitosa\n");
                }
                else
                {
                    printf("\nError, no se pudo cargar los datos\n");
                }
                break;
            case 4:
                controller_editEmployee(listaEmpleados);
                break;
            case 5:
                controller_removeEmployee(listaEmpleados);
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:
                controller_sortEmployee(listaEmpleados);
                break;
            case 8:
                printf("\nSe cargo: %d Archivos\n",controller_saveAsText("data.csv",listaEmpleados));
                break;
            case 9:
                printf("\nSe cargo: %d Archivos\n",controller_saveAsBinary("data.bin",listaEmpleados));
                break;
            case 10:
                break;
            default:
                printf("\nError, no es una opcion\n");
                break;
        }
    }while(option != 10);
    return 0;
}

