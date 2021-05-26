#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"
#define OK 1
#define ERROR -1


void mostrarTipo(eTipo tipoRecibido)
{
    printf("%5d %15s\n",tipoRecibido.id,tipoRecibido.descripcion);
}
int mostrarListaDeTipos(eTipo listaDetipos[], int cantidad)
{
    int isOk=ERROR;
    if(listaDetipos!=NULL && cantidad>0)
    {
        printf("\n****Lista de tipos****\n\n");
        printf("  ID        DESCRIPCION\n");
        for(int i=0;i<cantidad;i++)
        {
            mostrarTipo(listaDetipos[i]);
        }
        printf("\n\n");
        isOk =OK;
    }
    return isOk;
}

int cargarDescripcionTipo(eTipo listaDeTipos[],int cantidad,int idRecibido,char descripcionDevuelta[])
{
    int isOk=ERROR;
    if(listaDeTipos!=NULL && cantidad > 0 && descripcionDevuelta != NULL)
    {
        for(int i=0;i<cantidad;i++)
        {
            if(listaDeTipos[i].id == idRecibido)
            {
                strcpy(descripcionDevuelta,listaDeTipos[i].descripcion);
                isOk = OK;
            }
        }
    }
    return isOk;
}

int validarTipo(eTipo listaDetipos[], int cantidad,int idRecibido)
{
    int isOk=ERROR;
    if(listaDetipos!=NULL && cantidad > 0)
    {
        for(int i=0;i<cantidad;i++)
        {
            if(listaDetipos[i].id == idRecibido)
            {
                isOk = OK;
                break;
            }
        }
    }
    return isOk;
}
