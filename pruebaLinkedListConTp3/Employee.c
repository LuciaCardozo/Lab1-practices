#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Employee.h"

Employee* employee_new()
{
	Employee* pEmp = (Employee*)malloc( sizeof(Employee));

	if(pEmp != NULL){
	   strcpy(pEmp->nombre, "");
	   pEmp->horasTrabajadas = 0;
	   pEmp->sueldo = 0;
	}
	return pEmp;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char *sueldo)
{
	Employee* pEmp=employee_new();
	int auxId;
	int auxHoras;
	int auxSueldo;
	auxId=atoi(idStr);
	auxHoras=atoi(horasTrabajadasStr);
	auxSueldo=atoi(sueldo);
	if(pEmp!=NULL && idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldo!=NULL)
    {
    	employee_setId(pEmp,auxId);
    	employee_setNombre(pEmp,nombreStr);
    	employee_setHorasTrabajadas(pEmp,auxHoras);
    	employee_setSueldo(pEmp,auxSueldo);

    }
    else
    {
        employee_delete(pEmp);
    }
    return pEmp;
}

int employee_delete(Employee* this)
{
    int ret=-1;
    if(this!=NULL)
    {
        free(this);
        ret=0;
    }
    return ret;
}

int employee_setId(Employee* this,int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre!=NULL)
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo >= 0)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(nombre,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
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
}*/


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
}
