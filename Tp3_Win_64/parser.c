#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* pEmp;
	char aux[4][128];
	int ret = 0;
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",*(aux),*(aux+1),*(aux+2),*(aux+3));
		while(!feof(pFile))
		{
		    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",*(aux),*(aux+1),*(aux+2),*(aux+3));
			pEmp = employee_newParametros(*(aux),*(aux+1),*(aux+2),*(aux+3));
			if(pEmp != NULL)
			{
				if(!ll_add(pArrayListEmployee,pEmp))
                {
                    //printf("\n%s----%s----%s----%s",*(aux),*(aux+1),*(aux+2),*(aux+3));
                    ret++;
                }
			}
			else
			{
			    employee_delete(pEmp);
				printf("\nError, no se cargaron los datos");
			}
		}
	}
    return ret;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo databin.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee *pEmp;
    int ret = 0;
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        do
        {
            pEmp = employee_new();
            if(pEmp != NULL)
            {
                if(fread(pEmp,sizeof(Employee),1,pFile))
                {
                    if(!ll_add(pArrayListEmployee,pEmp))
                    {
                        ret++;
                    }
                }
            }
            else
            {
                employee_delete(pEmp);
                printf("\nError, no se cargaron los datos");
            }
        }
        while(!feof(pFile));
    }
    return ret;
}
