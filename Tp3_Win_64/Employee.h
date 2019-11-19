#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char *sueldo);
int employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

void menu(int *opcion);
int generarId(void);
void employe_idInit(int id);
int swapEmpId(void* pEmpUno,void* pEmpDos);
int swapEmpNombre(void* pEmp1,void* pEmp2);
int swapEmpHorasTrabajadas(void* pEmp1,void* pEmp2);
int swapEmpSueldo(void* pEmp1,void* pEmp2);

#endif // employee_H_INCLUDED
