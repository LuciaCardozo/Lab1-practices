#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ventas.h"

Ventas* venta_new()
{
	Ventas* pVen = (Ventas*)malloc( sizeof(Ventas));

	if(pVen != NULL)
    {
	   strcpy(pVen->cuit, "");
	   pVen->idVenta = 0;
	   strcpy(pVen->fecha, "");
	   strcpy(pVen->tipo, "");
	   pVen->precio = 0;
	}
	return pVen;
}

Ventas* venta_newParametros(char* idStr,char* fechaStr,char* tipoStr,char* cantidadStr,char* precioStr,char* cuitStr)
{
	Ventas* pVen = venta_new();
	int auxId;
	float auxPrecio;
	int auxCantidad;
	auxId = atoi(idStr);
	auxPrecio = atof(precioStr);
	auxCantidad = atoi(cantidadStr);
	if(pVen != NULL && idStr != NULL  && fechaStr && tipoStr != NULL && precioStr != NULL)
    {
    	venta_setId(pVen,auxId);
    	venta_setCuit(pVen,cuitStr);
        venta_setFecha(pVen,fechaStr);
        venta_setTipo(pVen,tipoStr);
        venta_setPrecio(pVen,auxPrecio);
        venta_setCantidad(pVen,auxCantidad);
    }
    else
    {
        venta_delete(pVen);
    }
    return pVen;
}

int venta_delete(Ventas* this)
{
    int ret = -1;
    if(this != NULL)
    {
        free(this);
        ret = 0;
    }
    return ret;
}

int venta_setId(Ventas* this,int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->idVenta = id;
        retorno = 0;
    }
    return retorno;
}

int venta_setCuit(Ventas* this,char* cuit)
{
    int retorno = -1;
    if(this != NULL && cuit!=NULL)
    {
        strncpy(this->cuit,cuit,sizeof(this->cuit));
        retorno = 0;
    }
    return retorno;
}

int venta_setFecha(Ventas* this,char* fecha)
{
    int retorno = -1;
    if(this != NULL && fecha != NULL)
    {
        strncpy(this->fecha,fecha,sizeof(this->fecha));
        retorno = 0;
    }
    return retorno;
}

int venta_setTipo(Ventas* this,char* tipo)
{
    int retorno = -1;
    if(this != NULL && tipo != NULL)
    {
        strncpy(this->tipo,tipo,sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}

int venta_setCantidad(Ventas* this,int cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad >= 0)
    {
        this->cantidad = cantidad;
        retorno = 0;
    }
    return retorno;
}

int venta_setPrecio(Ventas* this,float precio)
{
    int retorno = -1;
    if(this != NULL && precio >= 0)
    {
        this->precio = precio;
        retorno = 0;
    }
    return retorno;
}

int venta_getId(Ventas* this,int* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        *id = this->idVenta;
        retorno = 0;
    }
    return retorno;
}

int venta_getCuit(Ventas* this,char* cuit)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(cuit,this->cuit,sizeof(this->cuit));
        retorno = 0;
    }
    return retorno;
}

int venta_getFecha(Ventas* this,char* fecha)
{
    int retorno = -1;
    if(this != NULL && fecha != NULL)
    {
        strncpy(fecha,this->fecha,sizeof(this->fecha));
        retorno = 0;
    }
    return retorno;
}

int venta_getTipo(Ventas* this,char* tipo)
{
    int retorno = -1;
    if(this != NULL && tipo != NULL)
    {
        strncpy(tipo,this->tipo,sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}

int venta_getCantidad(Ventas* this,int* cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad > 0)
    {
        *cantidad = this->cantidad;
        retorno = 0;
    }
    return retorno;
}

int venta_getPrecio(Ventas* this,float* precio)
{
    int retorno = -1;
    if(this != NULL && precio >= 0)
    {
        *precio = this->precio;
        retorno = 0;
    }
    return retorno;
}

int em_calcular(void* p)
{

    int auxCantidad;
    int ret=0;
	if(p != NULL)
    {
        venta_getCantidad(p,&auxCantidad);
        if(auxCantidad > 0)
        {
            //suma=suma+auxCantidad;
            ret = auxCantidad;
        }
           // venta_setCantidad(p,suma);
    }
    return ret;
}

int em_calcularVentasMayorA150(void* p)
{
    int auxCantidad;
    float auxPrecio;
    float contador = 0;
    int ret = 0;
	if(p != NULL)
    {
        venta_getPrecio(p,&auxPrecio);
        venta_getCantidad(p,&auxCantidad);
        if(auxPrecio > 0 && auxCantidad > 0)
        {
            contador=auxPrecio*(float)auxCantidad;
            if(contador>150)
            {
                ret = 1;
            }
        }
    }
    return ret;
}

int em_calcularVentasMayorA300(void* p)
{
    int auxCantidad;
    float auxPrecio;
    float contador = 0;
    int ret = 0;
	if(p != NULL)
    {
        venta_getPrecio(p,&auxPrecio);
        venta_getCantidad(p,&auxCantidad);
        if(auxPrecio > 0 && auxCantidad > 0)
        {
            contador=auxPrecio*(float)auxCantidad;
            if(contador>300)
            {
                ret = 1;
            }
        }
    }
    return ret;
}

int em_calcularPolaroidReveladas(void* p)
{
    //char auxTipo[50];
    //int auxCantidad;
    Ventas* pAux;
    pAux=(Ventas*)p;
    int ret = 0;
	if(p != NULL)
    {
        //venta_getTipo(p,auxTipo);
        //venta_getCantidad(p,&auxCantidad);
        if((pAux->cantidad > 0 && strcmp(pAux->tipo,"POLAROID_11x9")==0) || strcmp(pAux->tipo,"POLAROID_10x10")==0)
        {
                ret=pAux->cantidad;
        }
    }
    return ret;
}

int ll_count(LinkedList* this,int(*fn)(void*))
{
    int ret = 0;
    int i;
    void* pElement;
    int cantidad=0;
    if(this != NULL)
    {
        for(i=0 ; i<ll_len(this) ; i++)
        {
            pElement = ll_get(this,i);
            if(pElement != NULL)
            {
                 if(fn(pElement)!=0)
                 {
                   cantidad = cantidad+fn(pElement);
                 }
            }
        }
        ret = cantidad;
    }
    return ret;
}
