#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"
#define OK 1
#define ERROR -1

void mostrarServicio(eServicio servicioRecibido)
{
    printf("%5d %15s %15.2f\n",servicioRecibido.id,servicioRecibido.descripcion,servicioRecibido.precio);
}
int mostrarListaDeServicios(eServicio listaDeServicios[], int cantidad)
{
    int isOk=ERROR;
    if(listaDeServicios!=NULL && cantidad>0)
    {
        printf("\n****Lista de servicios****\n\n");
        printf("  ID        DESCRIPCION        PRECIO\n");
        for(int i=0;i<cantidad;i++)
        {
            mostrarServicio(listaDeServicios[i]);
        }
        printf("\n\n");
        isOk =OK;
    }
    return isOk;
}

int validarServicio(eServicio listaDeServicios[],int cantidad, int idRecibido)
{
    int isOk = ERROR;

    if(listaDeServicios!=NULL && cantidad>0)
    {
        for(int i=0;i<cantidad;i++)
        {
            if(listaDeServicios[i].id == idRecibido)
            {
                isOk = OK;
            }
        }
    }
    return isOk;
}

int cargarDescripcionServicio(eServicio listaDeServicios[],int cantidad,int idRecibido,char descripcionDevuelta[])
{
    int isOk=ERROR;
    if(listaDeServicios!=NULL && cantidad > 0 && descripcionDevuelta != NULL)
    {
        for(int i=0;i<cantidad;i++)
        {
            if(listaDeServicios[i].id == idRecibido)
            {
                strcpy(descripcionDevuelta,listaDeServicios[i].descripcion);
                isOk=OK;
            }
        }
    }
    return isOk;
}
