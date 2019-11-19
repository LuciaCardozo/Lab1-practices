#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_mostrarEmployeePorIdEnFila(LinkedList* pArrayListEmployee, int index);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

 int controller_buscarEmployeePorId(LinkedList* pArrayListEmployee,int id,int* posicion);
 int controller_mostrarEmployeePorId(LinkedList* pArrayListEmployee, int index);
 int controller_ultimoIdEmployee(LinkedList* pArrayListEmployee);

#endif // CONTROLLER_H_INCLUDED
