#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
#include "linkedList.h"
typedef struct
{
    int idVenta;
    char cuit[20];
    char fecha[12];
    char tipo[50];
    int cantidad;
    float precio;
}Ventas;

Ventas* venta_new();
Ventas* venta_newParametros(char* idStr,char* fechaStr,char* tipoStr,char* cantidadStr,char* precioStr,char* cuitStr);
int venta_delete(Ventas* this);
int venta_setId(Ventas* this,int id);
int venta_setCuit(Ventas* this,char* cuit);
int venta_setFecha(Ventas* this,char* fecha);
int venta_setTipo(Ventas* this,char* tipo);
int venta_setCantidad(Ventas* this,int cantidad);
int venta_setPrecio(Ventas* this,float precio);

int venta_getId(Ventas* this,int* id);
int venta_getCuit(Ventas* this,char* cuit);
int venta_getFecha(Ventas* this,char* fecha);
int venta_getTipo(Ventas* this,char* tipo);
int venta_getCantidad(Ventas* this,int* cantidad);
int venta_getPrecio(Ventas* this,float* precio);

int ll_count(LinkedList* this,int(*fn)(void*));

int em_calcular(void* p);
int em_calcularVentasMayorA150(void* p);
int em_calcularVentasMayorA300(void* p);
int em_calcularPolaroidReveladas(void* p);

#endif // VENTAS_H_INCLUDED
