#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"
#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int ret = -1;
    FILE *pFile = NULL;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path,"r");
        if(pFile != NULL)
        {
            ret = parser_EmployeeFromText(pFile,pArrayListEmployee);
        }
        fclose(pFile);
    }
    return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int ret = -1;
    FILE *pFile = NULL;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path,"rb");
        if(pFile != NULL)
        {
            ret = parser_EmployeeFromBinary(pFile,pArrayListEmployee);
        }
        fclose(pFile);
    }
    return ret;
}

/** \brief Busca el ultimo id del linkedList y lo guarda en la estructura
 *
 * \param pArrayListEmployee LinkedList*
 * \param
 * \return retorna 0 si esta todo ok o -1 si hay error
 *
 */

int controller_ultimoIdEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmp;
    int auxId;
    int auxIdDos = -1;
    int ret = -1;
    int i;
    int len;
    if(pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        for(i=0 ; i<len ; i++)
        {
            pEmp = (Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(pEmp,&auxId);
            if(auxId > auxIdDos)
            {
                auxIdDos = auxId;
            }
        }
        employe_idInit(auxIdDos);
        ret = 0;
    }
    return ret;
}

/** \brief Busca el id del empleado.
 *
 * \param id es el id a buscar
 * \param posicion es la posicion si encuentra el id.
 * \param pArrayListEmployee LinkedList*.
 * \return retorna 0 si encontro la posicion o -1 si no lo encontro.
 *
 */
int controller_buscarEmployeePorId(LinkedList* pArrayListEmployee,int id,int* posicion)
{
    Employee* pEmp;
    int auxId;
    int ret = -1;
    int i;
    int len;
    if(pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        for(i=0 ; i<len ; i++)
        {
            pEmp = (Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(pEmp,&auxId);
            if(auxId == id)
            {
                *posicion = i;
                ret = 0;
            }
        }
    }
    return ret;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return retorna 0 si esta todo ok o -1 si hay error
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* nuevoEmpleado;
    nuevoEmpleado = employee_new();
    int ret = -1;
    char auxNombre[51];
    int auxHoras;
    int auxSueldo;
    if(pArrayListEmployee != NULL)
    {
        if(utn_getValidName(auxNombre) == 0 &&
                utn_getValidInt("\nIngrese horas trabajadas: ","\nError",&auxHoras,0,99999,2) == 0 &&
                utn_getValidInt("\nIngrese sueldo: ","\nError",&auxSueldo,0,99999,2) == 0)
        {
            employee_setId(nuevoEmpleado,generarId());
            employee_setNombre(nuevoEmpleado,auxNombre);
            employee_setHorasTrabajadas(nuevoEmpleado,auxHoras);
            employee_setSueldo(nuevoEmpleado,auxSueldo);

            ll_add(pArrayListEmployee,nuevoEmpleado);
            ret = 0;
        }
    }
    return ret;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return retorna 0 si esta todo ok o -1 si hay error
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmp;
    pEmp = employee_new();
    int ret = -1;
    char auxNombre[51];
    int auxHoras;
    int auxSueldo;
    int auxId;
    int auxPos;
    int opciones;
    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        if(utn_getValidInt("\nIngrese id: ","\nError, no es un id valido",&auxId,0,999999,2) == 0)
        {
            if(controller_buscarEmployeePorId(pArrayListEmployee,auxId,&auxPos) == -1)
            {
                printf("\nError, no es un id valido");
            }
            else
            {
                pEmp = (Employee*)ll_get(pArrayListEmployee,auxPos);
                controller_mostrarEmployeePorId(pArrayListEmployee,auxPos);
                if(utn_getValidInt("\n\tQue desea modificar?\n1.Nombre\n2.Horas trabajadas\n3.Sueldo\n4.Cancelar\nIngrese opcion: ",
                                   "\nError, no es una opcion",&opciones,0,4,2) == 0)
                {
                    do
                    {
                        switch(opciones)
                        {
                        case 1:
                            if(utn_getValidName(auxNombre) == 0)
                            {
                                employee_setNombre(pEmp,auxNombre);
                            }
                            else
                            {
                                printf("\nError en la carga de nombre");
                            }
                            break;
                        case 2:
                            if(utn_getValidInt("\nIngrese horas trabajadas: ","\nError",&auxHoras,0,99999,2)==0)
                            {
                                employee_setHorasTrabajadas(pEmp,auxHoras);
                            }
                            else
                            {
                                printf("\nError en la carga de horas trabajadas");
                            }
                            break;
                        case 3:
                            if(utn_getValidInt("\nIngrese sueldo: ","\nError",&auxSueldo,0,99999,2)==0)
                            {
                                employee_setSueldo(pEmp,auxSueldo);
                            }
                            else
                            {
                                printf("\nError en la carga de sueldo");
                            }
                            break;
                        case 4:
                            break;
                        }
                        utn_getValidInt("\n\tDesea modificar otro dato?\n1.Nombre\n2.Horas trabajadas\n3.Sueldo\n4.Cancelar\nIngrese opcion: ",
                                        "\nError, no es una opcion",&opciones,0,4,2);
                    }
                    while(opciones != 4);
                    ret = 0;
                }
            }
        }
    }
    return ret;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return retorna 0 si esta todo ok o -1 si hay error
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmp;
    pEmp = employee_new();
    int ret = -1;
    int auxId;
    int auxPos;
    int opciones;
    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        if(utn_getValidInt("\nIngrese id: ","\nError, no es un id valido",&auxId,0,999999,2) == 0)
        {
            if(controller_buscarEmployeePorId(pArrayListEmployee,auxId,&auxPos) == -1)
            {
                printf("\nError, no es un id valido");
            }
            else
            {
                pEmp = (Employee*)ll_get(pArrayListEmployee,auxPos);
                controller_mostrarEmployeePorId(pArrayListEmployee,auxPos);
                if(utn_getValidInt("\nDesea eliminar los siguientes datos?\n1.Si\n2.No\n",
                                   "\nError, opcion invalida",&opciones,1,2,2) == 0)
                {
                    switch(opciones)
                    {
                        case 1:
                            employee_delete(pEmp);
                            ll_remove(pArrayListEmployee,auxPos);
                            printf("\nBaja Exitosa");
                            break;
                        case 2:
                            printf("\nCancelacion Exitosa");
                            break;
                    }
                    ret = 0;
                }
            }
        }
    }
    return ret;
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return retorna 0 si esta todo ok o -1 si hay error
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int ret = -1;
    int len;
    if(pArrayListEmployee != NULL)
    {
        if(ll_len(pArrayListEmployee) > 0)
        {
            len = ll_len(pArrayListEmployee);
            for(i=0 ; i<len ; i++)
            {
                controller_mostrarEmployeePorIdEnFila(pArrayListEmployee,i);
            }
            ret = 0;
        }
        else
        {
            printf("No existen datos cargados.");
        }
    }
    return ret;
}
/** \brief Muestra un empleado en fila
 *
 * \param index es el indice de la lista
 * \param pArrayListEmployee LinkedList*
 * \return retorna 0 si esta todo ok o -1 si hay error
 *
 */
int controller_mostrarEmployeePorIdEnFila(LinkedList* pArrayListEmployee, int index)
{
    Employee* pEmp;
    int auxId;
    char auxNombre[128];
    int auxHorasTrabajadas;
    int auxSueldo;
    int ret = -1;
    if(pArrayListEmployee != NULL && index >= 0 && index < ll_len(pArrayListEmployee))
    {
        pEmp = (Employee*)ll_get(pArrayListEmployee,index);
        employee_getId(pEmp,&auxId);
        employee_getNombre(pEmp,auxNombre);
        employee_getHorasTrabajadas(pEmp,&auxHorasTrabajadas);
        employee_getSueldo(pEmp,&auxSueldo);
        printf("%d,%s,%d,%d\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
        ret = 0;
    }
    return ret;
}

/** \brief Muestra un empleado
 *
 * \param index es el indice de la lista
 * \param pArrayListEmployee LinkedList*
 * \return retorna 0 si esta todo ok o -1 si hay error
 *
 */
int controller_mostrarEmployeePorId(LinkedList* pArrayListEmployee, int index)
{

    Employee* pEmp;
    int ret = -1;
    char auxNombre[128];
    int auxId;
    int auxSueldo;
    int auxHoras;
    int len = ll_len(pArrayListEmployee);
    if(pArrayListEmployee != NULL && index >= 0 && index < len)
    {
        pEmp = (Employee*)ll_get(pArrayListEmployee,index);
        employee_getId(pEmp,&auxId);
        employee_getNombre(pEmp,auxNombre);
        employee_getHorasTrabajadas(pEmp,&auxHoras);
        employee_getSueldo(pEmp,&auxSueldo);
        printf("\nId: %d\nNombre: %s\nHoras trabajadas: %d\nSueldo: %d\n",auxId,auxNombre,auxHoras,auxSueldo);
        ret = 0;
    }
    return ret;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int order;
    int ret = -1;
    if(pArrayListEmployee != NULL)
    {
        if(utn_getValidInt("\nQue desea ordenar?\n1-Nombre\n2-Horas trabajadas\n3-Sueldo\nIngrese opcion: ",
                           "\nError",&opcion,1,3,2)==0)
        {
            if(utn_getValidInt("\n\tModo de ordenamiento\n1-Ascendente\n2-Descendente\nIngrese opcion: ","\nError",&order,1,2,2)==0)
            {
                if(order == 2)
                {
                    order = 0;
                }
                switch(opcion)
                {
                    case 1:
                        ll_sort(pArrayListEmployee,swapEmpNombre,order);
                        controller_ListEmployee(pArrayListEmployee);
                        break;
                    case 2:
                        ll_sort(pArrayListEmployee,swapEmpHorasTrabajadas,order);
                        controller_ListEmployee(pArrayListEmployee);
                        break;
                    case 3:
                        ll_sort(pArrayListEmployee,swapEmpSueldo,order);
                        controller_ListEmployee(pArrayListEmployee);
                        break;
                }
                ret = 0;
            }
        }
    }
    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    Employee* pEmp;
    FILE* pFile;
    int auxId;
    char auxNombre[128];
    int auxHoras;
    int auxSueldo;
    int i;
    int ret = 0;
    int len;
    pFile = fopen(path,"w");
    if(pArrayListEmployee != NULL && pFile != NULL)
    {
        len = ll_len(pArrayListEmployee);
        fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
        for(i=0; i<len; i++)
        {
            pEmp=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(pEmp,&auxId);
            employee_getNombre(pEmp,auxNombre);
            employee_getHorasTrabajadas(pEmp,&auxHoras);
            employee_getSueldo(pEmp,&auxSueldo);
            fprintf(pFile,"%d,%s,%d,%d\n",auxId,auxNombre,auxHoras,auxSueldo);
            ret++;
        }
        //printf("\n%d",ret);
        fclose(pFile);
    }
    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    Employee* pEmp;
    FILE* pFile;
    int i;
    int ret = 0;
    int len;
    pFile = fopen(path,"wb");
    if(pArrayListEmployee != NULL && pFile != NULL)
    {
        len = ll_len(pArrayListEmployee);
        for(i=0;i<len;i++)
        {
            pEmp = (Employee*)ll_get(pArrayListEmployee,i);
            fwrite(pEmp,sizeof(Employee),1,pFile);
            ret++;
        }
        fclose(pFile);
    }
    return ret;
}

