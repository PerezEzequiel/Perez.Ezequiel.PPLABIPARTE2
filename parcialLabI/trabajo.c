#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datos.h"
#include "trabajo.h"
#include "menu.h"
#define OK 1
#define ERROR -1
#define TRUE 1
#define FALSE 0

int inicializarListaDeTrabajos(eTrabajo listaDeTrabajo[], int cantidad)
{
    int isOk = ERROR;
    if(listaDeTrabajo!=NULL && cantidad>0)
    {
        for(int i=0; i<cantidad; i++)
        {
            listaDeTrabajo[i].isEmpty = TRUE;
        }
        isOk = OK;
    }
    return isOk;
}

int buscarTrabajoLibre(eTrabajo listaDeTrabajo[],int cantidad)
{
    int isOk = ERROR;
    if(listaDeTrabajo!=NULL && cantidad>0)
    {
        for(int i=0; i<cantidad; i++)
        {
            if(listaDeTrabajo[i].isEmpty == TRUE)
            {
                isOk = i;
                break;
            }
        }
    }
    return isOk;
}

eTrabajo crearTrabajo(int* nextId,eBicicleta listaDeBicicletas[],int cantidadDeBicicletas,eTipo listaDeTipos[],int cantidadDeTipos,eColor listaDeColores[],int cantidadDeColores,eServicio listaDeServicios[],int cantidadDeServicios)
{
    eTrabajo trabajoAux;

    mostrarListaDeBicicletas(listaDeBicicletas,cantidadDeBicicletas,listaDeTipos,cantidadDeTipos,listaDeColores,cantidadDeColores);
    getInt("Ingrese el id de bicicleta: ", &trabajoAux.idBicicleta,"Error, Ingrese un numero");
    while(validarBicicleta(listaDeBicicletas,cantidadDeBicicletas,trabajoAux.idBicicleta)==ERROR)
    {
        getInt("ID NO VALIDO, Ingrese el id de moto: ", &trabajoAux.idBicicleta,"Error, Ingrese un numero");
    }

    mostrarListaDeServicios(listaDeServicios,cantidadDeServicios);
    getInt("Ingrese el id de servicio: ", &trabajoAux.idServicio,"Error, Ingrese un numero");
    while(validarServicio(listaDeServicios,cantidadDeServicios,trabajoAux.idServicio)==ERROR)
    {
        getInt("ID NO VALIDO, Ingrese el id de servicio: ", &trabajoAux.idServicio,"Error, Ingrese un numero");
    }

    getFecha(&trabajoAux.fecha.dia,&trabajoAux.fecha.mes,&trabajoAux.fecha.anio);

    trabajoAux.id = *nextId;
    *nextId = *nextId + 1;
    trabajoAux.isEmpty = FALSE;

    return trabajoAux;
}


int altaDeDeTrabajo(eTrabajo listaDeTrabajo[],int cantidadDeTrabajo,int* nextId,eBicicleta listaDeBicicletas[],int cantidadDeBicicletas,eTipo listaDeTipos[],int cantidadDeTipos,eColor listaDeColores[],int cantidadDeColores,eServicio listaDeServicios[],int cantidadDeServicios)
{
    int isOk=ERROR;
    int indice;

    if(listaDeTrabajo!=NULL && cantidadDeTrabajo > 0 && nextId!=NULL && listaDeBicicletas != NULL && cantidadDeBicicletas > 0 && listaDeTipos != NULL && cantidadDeTipos > 0 && listaDeColores !=NULL && cantidadDeColores > 0 &&listaDeServicios != NULL && cantidadDeServicios > 0)
    {
        system("cls");
        printf("\n****Alta de trabajo****\n\n");
        indice = buscarTrabajoLibre(listaDeTrabajo,cantidadDeTrabajo);
        if(indice != ERROR)
        {
            printf("Su id sera: %d\n", *nextId);
            listaDeTrabajo[indice] = crearTrabajo(nextId,listaDeBicicletas,cantidadDeBicicletas,listaDeTipos,cantidadDeTipos,listaDeColores,cantidadDeColores,listaDeServicios,cantidadDeServicios);
        }
        else
        {
            printf("No hay lugar en la lista\n\n");
        }
        isOk =OK;
    }

    return isOk;

}

int mostrarTrabajo(eTrabajo trabajoRecibido,eBicicleta listaDeBicicletas[],int cantidadDeBicicletas,eServicio listaDeServicios[],int cantidadDeServicios)
{
    int isOk = ERROR;
    char descripcionServicio[20];
    char marcaBicicleta[20];

    if(listaDeServicios!=NULL && cantidadDeServicios>0 && cargarDescripcionServicio(listaDeServicios,cantidadDeServicios,trabajoRecibido.idServicio,descripcionServicio)== 1 && cargarMarcaBicicleta(listaDeBicicletas,cantidadDeBicicletas,trabajoRecibido.idBicicleta,marcaBicicleta))
    {

        printf("%4d %15s %17s     ",trabajoRecibido.id,marcaBicicleta,descripcionServicio);
        mostrarFecha(trabajoRecibido.fecha);
        printf("\n");
        isOk = OK;
    }
    else
    {
        printf("\nError al mostrar un empleado\n\n");
    }
    return isOk;

}
int mostrarListaDeTrabajo(eTrabajo listaDeTrabajos[],int cantidadDeTrabajo,eBicicleta listaDeBicicletas[],int cantidadDeBicicletas,eServicio listaDeServicios[],int cantidadDeServicios)
{
    int isOk=ERROR;
    char banderaHayEmpleados = 'n';

    if(listaDeTrabajos!=NULL && cantidadDeTrabajo > 0 && listaDeServicios!= NULL && cantidadDeServicios>0 && listaDeBicicletas != NULL && cantidadDeBicicletas>0)
    {
        printf("\n****Lista de trabajos****\n\n");
        printf("ID         MARCA BICICLETA      SERVICIO      FECHA\n");
        for(int i=0; i<cantidadDeTrabajo; i++)
        {
            if(listaDeTrabajos[i].isEmpty == FALSE)
            {
                mostrarTrabajo(listaDeTrabajos[i],listaDeBicicletas,cantidadDeBicicletas,listaDeServicios,cantidadDeServicios);
                banderaHayEmpleados = 's';
            }
        }
        if(banderaHayEmpleados != 's')
        {
            printf("\nNo hay empleados en la lista para mostrar\n\n");
        }
        isOk = OK;
    }
    printf("\n\n");
    return isOk;
}
