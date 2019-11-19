#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
#include "LinkedList.h"

struct S_Empleado
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
};
typedef struct S_Empleado Empleado;
int al_map(LinkedList* listaEmpleados,void(*pFunc)(void*));
void em_calcularSueldo(void* p);
Empleado* empleado_new();
Empleado* empleado_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);
int employee_delete(Empleado* this);
int employee_setId(Empleado* this,int id);
int employee_setNombre(Empleado* this,char* nombre);
int employee_setHorasTrabajadas(Empleado* this,int horasTrabajadas);
int employee_setSueldo(Empleado* this,int sueldo);
int employee_getId(Empleado* this,int* id);
int employee_getNombre(Empleado* this,char* nombre);
int employee_getHorasTrabajadas(Empleado* this,int* horasTrabajadas);
int employee_getSueldo(Empleado* this,int* sueldo);
void menu(int *opcion);

#endif // EMPLOYEE_H_INCLUDED
