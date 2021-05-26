#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"
#define OK 1
#define ERROR -1

void mostrarColor(eColor colorRecibido)
{
    printf("%5d %15s\n",colorRecibido.id,colorRecibido.nombreColor);
}
int mostrarListaDeColores(eColor listaDeDeColores[], int cantidad)
{
    int isOk=ERROR;
    if(listaDeDeColores!=NULL && cantidad>0)
    {
        printf("\n****Lista de colores****\n\n");
        printf("  ID        DESCRIPCION\n");
        for(int i=0;i<cantidad;i++)
        {
            mostrarColor(listaDeDeColores[i]);
        }
        printf("\n\n");
        isOk =OK;
    }
    return isOk;
}


int cargarDescripcionColor(eColor listaDeColores[],int cantidad,int idRecibido,char descripcionDevuelta[])
{
    int isOk = ERROR;
    if(listaDeColores!=NULL && cantidad>0 && descripcionDevuelta != NULL)
    {
        for(int i=0;i<cantidad;i++)
        {
            if(listaDeColores[i].id == idRecibido)
            {
                strcpy(descripcionDevuelta,listaDeColores[i].nombreColor);
                isOk = OK;
            }
        }
    }
    return isOk;
}

int validarColor(eColor listaDeDeColores[], int cantidad,int idRecibido)
{
    int isOk=ERROR;
    if(listaDeDeColores!=NULL && cantidad > 0)
    {
        for(int i=0;i<cantidad;i++)
        {
            if(listaDeDeColores[i].id == idRecibido)
            {
                isOk = OK;
                break;
            }
        }
    }
    return isOk;
}
