#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"

void em_calcularSueldo(void* p)
{
	// recibo elemento empleado como void.
	// hacer calculo de sueldo y escribirlo en campo sueldo del empleado
	int horas;
	int sueldo = 0;
	if(p != NULL)
    {
        employee_getHorasTrabajadas(p,&horas);
        if(horas > 0 && horas <= 120)
        {
            sueldo = horas*180;
        }
        if(horas > 120 && horas <= 160)
        {
            sueldo = horas*240;
        }
        if(horas > 160 && horas <= 240)
        {
            sueldo = horas*350;
        }
        employee_setSueldo(p,sueldo);
    }
}

int al_map(LinkedList* listaEmpleados,void(*pFunc)(void*))
{
    int ret = -1;
    int i;
    void* pElement;
    if(listaEmpleados != NULL)
    {
        for(i=0 ; i<ll_len(listaEmpleados) ; i++)
        {
            pElement = ll_get(listaEmpleados,i);
            if(pElement != NULL)
            {
                pFunc(pElement);
                ll_set(listaEmpleados,i,pElement);
            }
        }
        ret = 0;
    }
    return ret;
}

LinkedList* al_filter(LinkedList* this,int(*pFunc)(void*))//hacer funcion por criterio.
{
    LinkedList* listaFiltrada;
    void* pAux;
    int i;
    if(this != NULL)
    {
        listaFiltrada = ll_newLinkedList();
        for(i=0 ; i<ll_len(this) ; i++)
        {
            pAux = ll_get(this,i);
            if(pFunc(pAux) == 1)
            {
                ll_add(listaFiltrada,pAux);
            }
        }
    }
   return pAux;//verificar si funciona
}

Empleado* empleado_new()
{
	Empleado* pEmp = (Empleado*)malloc( sizeof(Empleado));

	if(pEmp != NULL){
	   strcpy(pEmp->nombre, "");
	   pEmp->horasTrabajadas = 0;
	   pEmp->sueldo = 0;
	}
	return pEmp;
}

Empleado* empleado_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
	Empleado* pEmp = empleado_new();
	int auxId;
	int auxHoras;
	auxId = atoi(idStr);
	auxHoras = atoi(horasTrabajadasStr);
	if(pEmp != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL)
    {
    	employee_setId(pEmp,auxId);
    	employee_setNombre(pEmp,nombreStr);
        employee_setHorasTrabajadas(pEmp,auxHoras);
    }
    else
    {
        employee_delete(pEmp);
    }
    return pEmp;
}

int employee_delete(Empleado* this)
{
    int ret = -1;
    if(this != NULL)
    {
        free(this);
        ret = 0;
    }
    return ret;
}

int employee_setId(Empleado* this,int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int employee_setNombre(Empleado* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre!=NULL)
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Empleado* this,int horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_setSueldo(Empleado* this,int sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo >= 0)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}

int employee_getId(Empleado* this,int* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

int employee_getNombre(Empleado* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(nombre,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Empleado* this,int* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_getSueldo(Empleado* this,int* sueldo)
{
    int retorno = -1;
    if(this != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}

void menu(int *opcion)
{
    printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
    printf("\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).");
    printf("\n3. Alta de empleado");
    printf("\n4. Modificar datos de empleado");
    printf("\n5. Baja de empleado");
    printf("\n6. Listar empleados");
    printf("\n7. Ordenar empleados");
    printf("\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).");
    printf("\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).");
    printf("\n10. Salir");
    printf("\nIngrese opcion: ");
    scanf("%d",opcion);
}

 /*int generarId(int idMax)
{
    static int idMax=0;
    return idMax++;
}


int swapEmpNombre(void* pEmpUno,void* pEmpDos)
{
    int ret = 0;
    if(strcmp(((Employee*)pEmpUno)->nombre,((Employee*)pEmpDos)->nombre) > 0)
    {
        ret = 1;
    }
    if(strcmp(((Employee*)pEmpUno)->nombre,((Employee*)pEmpDos)->nombre) < 0)
    {
        ret = -1;
    }
    return ret;
}

int swapEmpHorasTrabajadas(void* pEmpUno,void* pEmpDos)
{
    int ret = 0;
    if(((Employee*)pEmpUno)->horasTrabajadas > ((Employee*)pEmpDos)->horasTrabajadas)
    {
        ret = 1;
    }
    if(((Employee*)pEmpUno)->horasTrabajadas < ((Employee*)pEmpDos)->horasTrabajadas)
    {
        ret = -1;
    }
    return ret;
}

int swapEmpSueldo(void* pEmpUno,void* pEmpDos)
{
    int ret = 0;
    if(((Employee*)pEmpUno)->sueldo > ((Employee*)pEmpDos)->sueldo)
    {
        ret = 1;
    }
    if(((Employee*)pEmpUno)->sueldo < ((Employee*)pEmpDos)->sueldo)
    {
        ret = -1;
    }
    return ret;
}

int swapEmpId(void* pEmpUno,void* pEmpDos)
{
    int ret = 0;
    if(((Employee*)pEmpUno)->id > ((Employee*)pEmpDos)->id)
    {
        ret = 1;
    }
    if(((Employee*)pEmpUno)->id < ((Employee*)pEmpDos)->id)
    {
        ret = -1;
    }
    return ret;
}



static int idMax=0;

void employe_idInit(int id)
{
    idMax=id+1;
}

int generarId()
{
    return idMax++;
}*/

