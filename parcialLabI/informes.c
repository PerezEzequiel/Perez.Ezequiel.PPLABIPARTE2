#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datos.h"
#include "informes.h"
#include "menu.h"
#define OK 1
#define ERROR -1
#define TRUE 1
#define FALSE 0


int mostrarBicicletasDeUnColor(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,eTipo listaDeTipos[],int cantidadDeTipos,eColor listaDeColores[],int cantidadDeColores)
{
    int isOk=ERROR;
    int colorElegido;
    char descripcionColorElegido[20];

    if(listaDeBicicletas!=NULL && cantidadDeBicicletas>0 && listaDeTipos!=NULL && cantidadDeTipos>0 && listaDeColores!=NULL && cantidadDeColores>0)
    {
        system("cls");
        printf("\n****Mostrar bicicletas de un color****\n\n");

        mostrarListaDeColores(listaDeColores,cantidadDeColores);
        getInt("Ingrese el ID del color que desea listar: ",&colorElegido,"Error,ingrese un numero");
        while(validarColor(listaDeColores,cantidadDeColores,colorElegido)==ERROR)
        {
            getInt("Error,ID NO VALIDO\nIngrese el ID del color que desea listar: ",&colorElegido,"Error,ingrese un numero");
        }

        cargarDescripcionColor(listaDeColores,cantidadDeColores,colorElegido,descripcionColorElegido);

        system("cls");
        printf("\n****Usted eligio el color %s, las bicicletas que tienen este color son****\n",descripcionColorElegido);
        printf("\n\n");
        printf("ID                   MARCA                TIPO            COLOR          RODAJE\n");
        for(int b=0; b<cantidadDeBicicletas; b++)
        {
            if(listaDeBicicletas[b].idColor==colorElegido)
            {
                mostrarBicicleta(listaDeBicicletas[b],listaDeTipos,cantidadDeTipos,listaDeColores,cantidadDeColores);
            }

        }
        printf("\n\n");
        isOk = OK;
    }
    return isOk;
}

int mostrarBicicletasDeUnTipo(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,eTipo listaDeTipos[],int cantidadDeTipos,eColor listaDeColores[],int cantidadDeColores)
{
    int isOk=ERROR;
    int tipoElegido;
    char descripcionTipoElegido[20];

    if(listaDeBicicletas!=NULL && cantidadDeBicicletas>0 && listaDeTipos!=NULL && cantidadDeTipos>0 && listaDeColores!=NULL && cantidadDeColores>0)
    {
        system("cls");
        printf("\n****Mostrar bicicletas de un tipo****\n\n");

        mostrarListaDeTipos(listaDeTipos,cantidadDeTipos);
        getInt("Ingrese el ID del tipo que desea listar: ",&tipoElegido,"Error,ingrese un numero");
        while(validarTipo(listaDeTipos,cantidadDeTipos,tipoElegido)==ERROR)
        {
            getInt("Error,ID NO VALIDO\nIngrese el ID del tipo que desea listar: ",&tipoElegido,"Error,ingrese un numero");
        }

        cargarDescripcionTipo(listaDeTipos,cantidadDeTipos,tipoElegido,descripcionTipoElegido);

        system("cls");
        printf("\n****Usted eligio el tipo %s, las bicicletas que tienen este tipo son****\n",descripcionTipoElegido);
        printf("\n\n");

        printf("ID                   MARCA                TIPO            COLOR          RODAJE\n");
        for(int b=0; b<cantidadDeBicicletas; b++)
        {

            if(listaDeBicicletas[b].idTipo==tipoElegido && listaDeBicicletas[b].isEmpty == FALSE)
            {
                mostrarBicicleta(listaDeBicicletas[b],listaDeTipos,cantidadDeTipos,listaDeColores,cantidadDeColores);
            }

        }
        printf("\n\n");
        isOk = OK;
    }
    return isOk;
}



int mostrarBicicletasMenorRodado(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,eTipo listaDeTipos[],int cantidadDeTipos,eColor listaDeColores[],int cantidadDeColores)
{
    int isOk=ERROR;
    float rodadoMinimo;

    if(listaDeBicicletas!=NULL && cantidadDeBicicletas>0 && listaDeTipos!=NULL && cantidadDeTipos>0 && listaDeColores!=NULL && cantidadDeColores>0)
    {
        for(int b=0; b<cantidadDeBicicletas; b++)
        {
            if(b == 0 || (listaDeBicicletas[b].isEmpty == FALSE && rodadoMinimo>=listaDeBicicletas[b].rodado))
            {
                rodadoMinimo = listaDeBicicletas[b].rodado;
            }
        }

        system("cls");
        printf("\n****Bicicletas del menor rodado****\n\n");
        printf("RODADO MINIMO: %f\n", rodadoMinimo);
        printf("ID                   MARCA                TIPO            COLOR          RODAJE\n");
        for(int b=0; b<cantidadDeBicicletas; b++)
        {
            if(rodadoMinimo == listaDeBicicletas[b].rodado && listaDeBicicletas[b].isEmpty == FALSE)
            {
                mostrarBicicleta(listaDeBicicletas[b],listaDeTipos,cantidadDeTipos,listaDeColores,cantidadDeColores);
            }
        }

        printf("\n\n");
        isOk=OK;
    }
    return isOk;
}


int mostrarBicicletasPorTipo(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,eTipo listaDeTipos[],int cantidadDeTipos,eColor listaDeColores[],int cantidadDeColores)
{
    int isOk=ERROR;
    char banderaHayBicicleta='n';

    if(listaDeBicicletas!=NULL && cantidadDeBicicletas>0 && listaDeTipos!=NULL && cantidadDeTipos>0 && listaDeColores!=NULL && cantidadDeColores>0)
    {

        system("cls");
        printf("\n****Bicicletas separadas por tipo****\n\n");
        for(int t=0; t<cantidadDeTipos; t++)
        {
            printf("---------------------------------------------------Tipo:%s------------------------------------------------------\n",listaDeTipos[t].descripcion);

            printf("ID                   MARCA                TIPO            COLOR          RODAJE\n");
            for(int b=0; b<cantidadDeBicicletas; b++)
            {
                if(listaDeBicicletas[b].idTipo == listaDeTipos[t].id && listaDeBicicletas[b].isEmpty == FALSE)
                {
                    mostrarBicicleta(listaDeBicicletas[b],listaDeTipos,cantidadDeTipos,listaDeColores,cantidadDeColores);
                    banderaHayBicicleta='s';
                }
            }
            if(banderaHayBicicleta != 's')
            {
                printf("\nNo hay bicicletas de este tipo\n\n");
            }
            printf("----------------------------------------------------------------------------------------------------------------------\n");
        }
        printf("\n\n");
        isOk=OK;
    }

    return isOk;

}


int contarBicicletasDeUnTipoYcolor(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,eTipo listaDeTipos[],int cantidadDeTipos,eColor listaDeColores[],int cantidadDeColores)
{
    int isOk=ERROR;
    int colorElegido;
    char descripcionColorElegido[20];


    int tipoElegido;
    char descripcionTipoElegido[20];

    int contador=0;


    if(listaDeBicicletas!=NULL && cantidadDeBicicletas>0 && listaDeTipos!=NULL && cantidadDeTipos>0 && listaDeColores!=NULL && cantidadDeColores>0)
    {
        system("cls");
        printf("\n****Cantidad de bicicletas de un color y un tipo****\n\n");

        mostrarListaDeColores(listaDeColores,cantidadDeColores);
        getInt("Ingrese el ID del color que desea listar: ",&colorElegido,"Error,ingrese un numero");
        while(validarColor(listaDeColores,cantidadDeColores,colorElegido)==ERROR)
        {
            getInt("Error,ID NO VALIDO\nIngrese el ID del color que desea listar: ",&colorElegido,"Error,ingrese un numero");
        }
        cargarDescripcionColor(listaDeColores,cantidadDeColores,colorElegido,descripcionColorElegido);


        mostrarListaDeTipos(listaDeTipos,cantidadDeTipos);
        getInt("Ingrese el ID del tipo que desea listar: ",&tipoElegido,"Error,ingrese un numero");
        while(validarTipo(listaDeTipos,cantidadDeTipos,tipoElegido)==ERROR)
        {
            getInt("Error,ID NO VALIDO\nIngrese el ID del tipo que desea listar: ",&tipoElegido,"Error,ingrese un numero");
        }

        cargarDescripcionTipo(listaDeTipos,cantidadDeTipos,tipoElegido,descripcionTipoElegido);

        for(int b=0; b<cantidadDeBicicletas; b++)
        {
            if(listaDeBicicletas[b].idColor == colorElegido && listaDeBicicletas[b].idTipo == tipoElegido && listaDeBicicletas[b].isEmpty == FALSE)
            {
                contador++;
            }
        }
        system("cls");
        printf("\nUsted eligio el color %s y el tipo %s, la cantidad de bicicletas con estas caracteristicas es: %d", descripcionColorElegido,descripcionTipoElegido,contador);
        printf("\n\n");
        isOk = OK;
    }
    return isOk;
}


int mostrarColoresMasElegidos(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,eTipo listaDeTipos[],int cantidadDeTipos,eColor listaDeColores[],int cantidadDeColores)
{
    int isOk=ERROR;
    int contadorColores[cantidadDeColores];
    int max;

    if(listaDeBicicletas!=NULL && cantidadDeBicicletas>0 && listaDeTipos!=NULL && cantidadDeTipos>0 && listaDeColores!=NULL && cantidadDeColores>0)
    {
        system("cls");
        printf("\n****Los colores mas elegidos****\n\n");

        for(int c=0; c<cantidadDeColores; c++)
        {
            contadorColores[c] = 0;
            for(int b=0; b<cantidadDeBicicletas; b++)
            {
                if(listaDeColores[c].id == listaDeBicicletas[b].idColor)
                {
                    contadorColores[c]++;
                }
            }
        }

        for(int c=0; c<cantidadDeColores; c++)
        {
            if(c==0 || max<=contadorColores[c])
            {
                max = contadorColores[c];
            }
        }

        printf("  ID        DESCRIPCION\n");
        for(int c=0; c<cantidadDeColores; c++)
        {
            if(max == contadorColores[c])
            {
                mostrarColor(listaDeColores[c]);
            }
        }

        printf("\n\n");
        isOk = OK;
    }


    return isOk;
}



int mostrarTrabajosDeUnaBicicleta(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,eTipo listaDeTipos[],int cantidadDeTipos,eColor listaDeColores[],int cantidadDeColores,eTrabajo listaDeTrabajos[],int cantidadDeTrabajos,eServicio listaDeServicios[], int cantidadDeServicios)
{
    int isOk=ERROR;
    int bicicletaElegida;
    int indice;
    char banderaHayTrabajo='n';



    if(listaDeBicicletas!=NULL && cantidadDeBicicletas>0 && listaDeTipos!=NULL && cantidadDeTipos>0 && listaDeColores!=NULL && cantidadDeColores>0 && listaDeTrabajos != NULL && cantidadDeTrabajos>0 && listaDeServicios != NULL && cantidadDeServicios > 0)
    {
        system("cls");
        printf("\n****Trabajos de una bicicleta****\n\n");

        mostrarListaDeBicicletas(listaDeBicicletas,cantidadDeBicicletas,listaDeTipos,cantidadDeTipos,listaDeColores,cantidadDeColores);
        getInt("Ingrese el ID de la bicicleta: ",&bicicletaElegida,"Error, ingrese un numero");


        indice = buscarBicicletaPorId(listaDeBicicletas,cantidadDeBicicletas,bicicletaElegida);
        while(indice==ERROR)
        {
            getInt("ERROR, Ingrese el ID de la bicicleta: ",&bicicletaElegida,"Error, ingrese un numero");
            indice = buscarBicicletaPorId(listaDeBicicletas,cantidadDeBicicletas,bicicletaElegida);
        }

        system("cls");
        printf("\n****Bicicleta elegida****\n\n");
        printf("ID                   MARCA                TIPO            COLOR          RODAJE\n");
        mostrarBicicleta(listaDeBicicletas[indice],listaDeTipos,cantidadDeTipos,listaDeColores,cantidadDeColores);


        printf("\n\n****Trabajos de la bicicleta elegida****\n\n");
        printf("ID         MARCA BICICLETA      SERVICIO      FECHA\n");
        for(int t=0; t<cantidadDeTrabajos; t++)
        {

            if(listaDeTrabajos[t].idBicicleta == bicicletaElegida && listaDeTrabajos[t].isEmpty ==  FALSE)
            {
                mostrarTrabajo(listaDeTrabajos[t],listaDeBicicletas,cantidadDeBicicletas,listaDeServicios,cantidadDeServicios);
                banderaHayTrabajo = 's';
            }
        }
        if(banderaHayTrabajo!='s')
        {
            printf("\nNo hay trabajos en esta bicicleta");
        }
        printf("\n\n");

        isOk = OK;

    }
    return isOk;
}



int mostrarSumaImportesBicicleta(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,eTipo listaDeTipos[],int cantidadDeTipos,eColor listaDeColores[],int cantidadDeColores,eTrabajo listaDeTrabajos[],int cantidadDeTrabajos,eServicio listaDeServicios[], int cantidadDeServicios)
{
    int isOk=ERROR;
    int bicicletaElegida;
    int indice;
    float acumuladorPrecios=0;



    if(listaDeBicicletas!=NULL && cantidadDeBicicletas>0 && listaDeTipos!=NULL && cantidadDeTipos>0 && listaDeColores!=NULL && cantidadDeColores>0 && listaDeTrabajos != NULL && cantidadDeTrabajos>0 && listaDeServicios != NULL && cantidadDeServicios > 0)
    {
        system("cls");
        printf("\n****Importes de servicios de una bicicleta****\n\n");

        mostrarListaDeBicicletas(listaDeBicicletas,cantidadDeBicicletas,listaDeTipos,cantidadDeTipos,listaDeColores,cantidadDeColores);
        getInt("Ingrese el ID de la bicicleta: ",&bicicletaElegida,"Error, ingrese un numero");


        indice = buscarBicicletaPorId(listaDeBicicletas,cantidadDeBicicletas,bicicletaElegida);
        while(indice==ERROR)
        {
            getInt("ERROR, Ingrese el ID de la bicicleta: ",&bicicletaElegida,"Error, ingrese un numero");
            indice = buscarBicicletaPorId(listaDeBicicletas,cantidadDeBicicletas,bicicletaElegida);
        }

        system("cls");
        printf("\n****Bicicleta elegida****\n\n");
        printf("ID                   MARCA                TIPO            COLOR          RODAJE\n");
        mostrarBicicleta(listaDeBicicletas[indice],listaDeTipos,cantidadDeTipos,listaDeColores,cantidadDeColores);

        for(int t=0; t<cantidadDeTrabajos; t++)
        {
            for(int s=0; s<cantidadDeServicios; s++)
            {
                if(listaDeTrabajos[t].idBicicleta == bicicletaElegida && listaDeTrabajos[t].isEmpty ==  FALSE && listaDeTrabajos[t].idServicio == listaDeServicios[s].id)
                {
                    acumuladorPrecios = listaDeServicios[s].precio + acumuladorPrecios;
                }
            }
        }
        printf("\nLa suma de los importes de los servicios de esta bicicleta es: %.2f",acumuladorPrecios);
        printf("\n\n");

        isOk = OK;

    }
    return isOk;
}



int mostrarBicicletasYfechaDeUnServicio(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,eTipo listaDeTipos[],int cantidadDeTipos,eColor listaDeColores[],int cantidadDeColores,eTrabajo listaDeTrabajos[],int cantidadDeTrabajos,eServicio listaDeServicios[], int cantidadDeServicios)
{
    int isOk=ERROR;
    int servicioElegido;
    char descripcionServicio[25];

    if(listaDeBicicletas!=NULL && cantidadDeBicicletas>0 && listaDeTipos!=NULL && cantidadDeTipos>0 && listaDeColores!=NULL && cantidadDeColores>0 && listaDeTrabajos != NULL && cantidadDeTrabajos>0 && listaDeServicios != NULL && cantidadDeServicios > 0)
    {
        system("cls");
        printf("\n****Mostrar bicicletas de un servicio****\n\n");

        mostrarListaDeServicios(listaDeServicios,cantidadDeServicios);

        getInt("Ingrese el ID del servicio que desea: ",&servicioElegido,"Error, ingrese un numero");
        while(validarServicio(listaDeServicios,cantidadDeServicios,servicioElegido)==ERROR)
        {
            getInt("ERROR,Ingrese el ID del servicio que desea: ",&servicioElegido,"Error, ingrese un numero");
        }

        system("cls");
        cargarDescripcionServicio(listaDeServicios,cantidadDeServicios,servicioElegido,descripcionServicio);
        printf("\n****Usted eligio el servicio: %s****\n", descripcionServicio);


        printf("------------------------------------------------------------------------------------------------------\n");
        for(int t=0; t<cantidadDeTrabajos; t++)
        {
            for(int b=0; b<cantidadDeBicicletas; b++)
            {
                if(listaDeBicicletas[b].id == listaDeTrabajos[t].idBicicleta && listaDeTrabajos[t].isEmpty == FALSE && listaDeTrabajos[t].idServicio == servicioElegido)
                {
                    printf("                                fecha: ");
                    mostrarFecha(listaDeTrabajos[t].fecha);
                    printf("\nID                   MARCA                TIPO            COLOR          RODAJE\n");
                    mostrarBicicleta(listaDeBicicletas[b],listaDeTipos,cantidadDeTipos,listaDeColores,cantidadDeColores);
                    printf("------------------------------------------------------------------------------------------------------\n");
                }
            }
        }
        printf("\n\n");
        isOk = OK;
    }

    return isOk;
}




int mostrarServiciosDeUnaFecha(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,eTipo listaDeTipos[],int cantidadDeTipos,eColor listaDeColores[],int cantidadDeColores,eTrabajo listaDeTrabajos[],int cantidadDeTrabajos,eServicio listaDeServicios[], int cantidadDeServicios)
{
    int isOk=ERROR;
    eFecha fechaAux;
    char bandera = 'n';

    if(listaDeBicicletas!=NULL && cantidadDeBicicletas>0 && listaDeTipos!=NULL && cantidadDeTipos>0 && listaDeColores!=NULL && cantidadDeColores>0 && listaDeTrabajos != NULL && cantidadDeTrabajos>0 && listaDeServicios != NULL && cantidadDeServicios > 0)
    {
        system("cls");
        printf("\n****Mostrar servicios de una fecha****\n\n");
        getFecha(&fechaAux.dia,&fechaAux.mes,&fechaAux.anio);

        system("cls");
        printf("\nFecha ingresada: ");
        mostrarFecha(fechaAux);
        printf("\n\n****Los servicios realizados en la fecha son****\n\n");

        printf("  ID        DESCRIPCION        PRECIO\n");
        for(int t=0; t<cantidadDeTrabajos; t++)
        {
            for(int s=0; s<cantidadDeServicios; s++)
            {
                if(listaDeTrabajos[t].isEmpty == FALSE && listaDeTrabajos[t].idServicio == listaDeServicios[s].id && compararFecha(listaDeTrabajos[t].fecha,fechaAux))
                {
                        mostrarServicio(listaDeServicios[s]);
                        bandera = 's';
                }
            }
        }
        if(bandera!='s')
        {
            printf("\nNo se realizaron servicios en esta fecha\n");
        }
        printf("\n\n");

        isOk = OK;

    }
    return isOk;
}


