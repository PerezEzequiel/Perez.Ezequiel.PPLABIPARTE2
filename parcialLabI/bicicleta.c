#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datos.h"
#include "bicicleta.h"
#include "menu.h"
#define OK 1
#define ERROR -1
#define TRUE 1
#define FALSE 0


int inicializarListaBicicletas(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas)
{
    int isOk = ERROR;
    if(listaDeBicicletas!=NULL && cantidadDeBicicletas>0)
    {
        for(int i=0; i<cantidadDeBicicletas; i++)
        {
            listaDeBicicletas[i].isEmpty = TRUE;
        }
        isOk = OK;
    }
    return isOk;
}


int buscarBicicletaLibre(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas)
{
    int isOk = ERROR;
    if(listaDeBicicletas!=NULL && cantidadDeBicicletas>0)
    {
        for(int i=0; i<cantidadDeBicicletas; i++)
        {
            if(listaDeBicicletas[i].isEmpty == TRUE)
            {
                isOk = i;
                break;
            }
        }
    }
    return isOk;
}

eBicicleta crearBicicleta(int* nextId,eTipo listaDeTipos[],int cantidadDeTipos, eColor listaDeColores[],int cantidadDeColores)
{
    float rodadoAux[5]= {20,26,27.5,29};
    eBicicleta auxBicicleta;

    getString("Ingrese la marca de bicicleta: ","ERROR, ingrese solo numeros o una palabra mas corta",auxBicicleta.marca,20);


    mostrarListaDeTipos(listaDeTipos,cantidadDeTipos);

    getInt("Ingrese el id de tipo: ", &auxBicicleta.idTipo,"Error, Ingrese un numero");
    while(validarTipo(listaDeTipos,cantidadDeTipos,auxBicicleta.idTipo)==ERROR)
    {
        getInt("Error no existe ese id en la lista,ingrese el id de tipo: ", &auxBicicleta.idTipo,"Error, Ingrese un numero");
    }

    mostrarListaDeColores(listaDeColores,cantidadDeColores);

    getInt("Ingrese el id de color: ", &auxBicicleta.idColor,"Error, Ingrese un numero");
    while(validarColor(listaDeColores,cantidadDeColores,auxBicicleta.idColor)==ERROR)
    {
        getInt("Error no existe ese id en la lista,ingrese el id de color: ", &auxBicicleta.idColor,"Error, Ingrese un numero");
    }

    getFloat("Ingrese rodado 20-26-27.5-29: ",&auxBicicleta.rodado,"Error, Ingrese un numero");
    while(validarRodado(rodadoAux,5,auxBicicleta.rodado) == ERROR)
    {
        getFloat("Ingrese un rodado valido,ingrese otra vez rodado 20-26-27.5-29: ",&auxBicicleta.rodado,"Error, Ingrese un numero");

    }

    auxBicicleta.id = *nextId;
    *nextId = *nextId + 1;
    auxBicicleta.isEmpty = FALSE;

    return auxBicicleta;
}


int altaDeBicicleta(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,eTipo listaDeTipos[],int cantidadDeTipos, eColor listaDeColores[],int cantidadDeColores,int* nextId)
{
    int isOk=ERROR;
    int indice;

    if(listaDeBicicletas!=NULL && cantidadDeBicicletas > 0 && listaDeTipos != NULL && cantidadDeTipos>0 && listaDeColores != NULL && cantidadDeColores>0 && nextId !=NULL)
    {
        system("cls");
        printf("\n****Alta de bicicletas****\n");
        indice = buscarBicicletaLibre(listaDeBicicletas,cantidadDeBicicletas);
        if(indice != -1)
        {
            printf("Su id sera: %d\n", *nextId);
            listaDeBicicletas[indice] = crearBicicleta(nextId,listaDeTipos,cantidadDeTipos,listaDeColores,cantidadDeColores);
            isOk = OK;
        }
        else
        {
            printf("No hay lugar\n\n");
        }
    }

    return isOk;
}

int mostrarBicicleta(eBicicleta bicicletaRecibida,eTipo listaDeTipos[],int cantidadDeTipos,eColor listaDeColores[],int cantidadDeColores)
{
    int isOk = ERROR;
    char descripcionColor[20];
    char descripcionTipo[20];

    if(listaDeTipos!=NULL && cantidadDeTipos>0 && listaDeColores!=NULL && cantidadDeColores>0 && cargarDescripcionColor(listaDeColores,cantidadDeColores,bicicletaRecibida.idColor,descripcionColor)== 1 && cargarDescripcionTipo(listaDeTipos,cantidadDeTipos,bicicletaRecibida.idTipo,descripcionTipo)==1)
    {

        printf("%4d %20s %20s %15s %14.1f\n",bicicletaRecibida.id,bicicletaRecibida.marca,descripcionTipo,descripcionColor,bicicletaRecibida.rodado);
        isOk = OK;
    }
    else
    {
        printf("\nError al mostrar un empleado\n\n");
    }
    return isOk;
}

int mostrarListaDeBicicletas(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,eTipo listaDeTipos[],int cantidadDeTipos, eColor listaDeColores[],int cantidadDeColores)
{
    int isOk=ERROR;
    char banderaHayEmpleados = 'n';

    if(listaDeBicicletas!=NULL && cantidadDeBicicletas > 0 && listaDeTipos != NULL && cantidadDeTipos>0 && listaDeColores != NULL && cantidadDeColores>0 )
    {
        printf("\n****Lista de bicicletas****\n\n");
        printf("ID                   MARCA                TIPO            COLOR          RODAJE\n");
        for(int i=0; i<cantidadDeBicicletas; i++)
        {
            if(listaDeBicicletas[i].isEmpty == FALSE)
            {
                mostrarBicicleta(listaDeBicicletas[i],listaDeTipos,cantidadDeTipos,listaDeColores,cantidadDeColores);
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


int buscarBicicletaPorId(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,int idRecibido)
{
    int indice = ERROR;
    if(listaDeBicicletas!=NULL && cantidadDeBicicletas > 0)
    {
        for(int i=0; i<cantidadDeBicicletas; i++)
        {
            if(listaDeBicicletas[i].isEmpty == FALSE && listaDeBicicletas[i].id == idRecibido)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}


int modificarBicicleta(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,eTipo listaDeTipos[],int cantidadDeTipos, eColor listaDeColores[],int cantidadDeColores)
{
    int isOk = ERROR;
    int idElegido;
    int indice;
    char respuestaModificar;
    eBicicleta bicicletaAuxiliar;
    char respuestaMenu;

    char banderaImpactarCambios = 'n';
    char banderaSalirMenu='n';


    float rodadoAux[5]= {20,26,27.5,29};


    if(listaDeBicicletas != NULL && cantidadDeBicicletas>0 && listaDeTipos != NULL && cantidadDeTipos > 0 && listaDeColores != NULL && cantidadDeColores > 0)
    {
        system("cls");
        printf("\nModificacion de moto\n\n");

        mostrarListaDeBicicletas(listaDeBicicletas,cantidadDeBicicletas,listaDeTipos,cantidadDeTipos,listaDeColores,cantidadDeColores);

        getInt("Ingrese el id del empleado que desea modificar: ",&idElegido,"Error, ingrese un numero");

        indice = buscarBicicletaPorId(listaDeBicicletas,cantidadDeBicicletas,idElegido);
        while(indice == ERROR)
        {
            getInt("Error, ese id no existe en la lista.\nIngrese el id del empleado que desea modificar: ",&idElegido,"Error, ingrese un numero");
            indice = buscarBicicletaPorId(listaDeBicicletas,cantidadDeBicicletas,idElegido);
        }

        printf("\n");
        if(!mostrarBicicleta(listaDeBicicletas[indice],listaDeTipos,cantidadDeTipos,listaDeColores,cantidadDeColores))
        {
            printf("Error\n\n\n");
        }
        printf("\n");

        getCaracter("Desea modificar esta bicicleta?s/n: ",&respuestaModificar,"Error, ingrese un caracter","Error ingrese s o n",'s','n');

        if(respuestaModificar == 's')
        {
            bicicletaAuxiliar = listaDeBicicletas[indice];
            do
            {
                system("cls");
                printf("\n\n");
                printf("ID                   MARCA                TIPO            COLOR          RODAJE\n");
                mostrarBicicleta(bicicletaAuxiliar,listaDeTipos,cantidadDeTipos,listaDeColores,cantidadDeColores);
                printf("\n\n");
                mostrarMenuChar("A. Tipo\nB. Rodado\nC. Salir\nQue desea modificar?: ",&respuestaMenu);
                switch(respuestaMenu)
                {
                case 'a':
                    mostrarListaDeTipos(listaDeTipos,cantidadDeTipos);

                    getInt("Ingrese el id de tipo: ", &bicicletaAuxiliar.idTipo,"Error, Ingrese un numero");
                    while(validarTipo(listaDeTipos,cantidadDeTipos,bicicletaAuxiliar.idTipo)==ERROR)
                    {
                        getInt("Error no existe ese id en la lista,ingrese el id de tipo: ", &bicicletaAuxiliar.idTipo,"Error, Ingrese un numero");
                    }
                    break;
                case 'b':
                    getFloat("Ingrese rodado 20-26-27.5-29: ",&bicicletaAuxiliar.rodado,"Error, Ingrese un numero");
                    while(validarRodado(rodadoAux,5,bicicletaAuxiliar.rodado) == ERROR)
                    {
                        getFloat("Ingrese un rodado valido,ingrese otra vez rodado 20-26-27.5-29: ",&bicicletaAuxiliar.rodado,"Error, Ingrese un numero");
                    }
                    break;
                case 'c':
                    getCaracter("Desea Salir?s/n: ",&banderaSalirMenu,"Error, ingrese un caracter","Error ingrese s o n",'s','n');
                    if(banderaSalirMenu == 's')
                    {
                        getCaracter("Desea impactar los cambios?s/n: ",&banderaImpactarCambios,"Error, ingrese un caracter","Error ingrese s o n",'s','n');
                        if(banderaImpactarCambios == 's')
                        {
                            listaDeBicicletas[indice] = bicicletaAuxiliar;
                        }
                    }
                    break;
                    system("pause");

                }
            }
            while(banderaSalirMenu != 's');
        }
        isOk = OK;

    }
    return isOk;
}

int bajaDeBicicleta(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,eTipo listaDeTipos[],int cantidadDeTipos, eColor listaDeColores[],int cantidadDeColores)
{
    int isOk = ERROR;
    int idElegido;
    int indice;
    char respuestaEliminar;


    if(listaDeBicicletas != NULL && cantidadDeBicicletas>0 && listaDeTipos != NULL && cantidadDeTipos > 0 && listaDeColores != NULL && cantidadDeColores > 0)
    {
        system("cls");
        printf("\nModificacion de bicicletas\n\n");

        mostrarListaDeBicicletas(listaDeBicicletas,cantidadDeBicicletas,listaDeTipos,cantidadDeTipos,listaDeColores,cantidadDeColores);

        getInt("Ingrese el id de la bicicleta que desea eliminar: ",&idElegido,"Error, ingrese un numero");

        indice = buscarBicicletaPorId(listaDeBicicletas,cantidadDeBicicletas,idElegido);
        while(indice == ERROR)
        {
            getInt("Error, ese id no existe en la lista.\nIngrese el id bicicleta que desea modificar: ",&idElegido,"Error, ingrese un numero");
            indice = buscarBicicletaPorId(listaDeBicicletas,cantidadDeBicicletas,idElegido);
        }

        if(!mostrarBicicleta(listaDeBicicletas[indice],listaDeTipos,cantidadDeTipos,listaDeColores,cantidadDeColores))
        {
            printf("Error\n\n\n");
        }

        getCaracter("Desea eliminar esta bicicleta?s/n: ",&respuestaEliminar,"Error, ingrese un caracter","Error ingrese s o n",'s','n');

        if(respuestaEliminar == 's')
        {
            listaDeBicicletas[indice].isEmpty = TRUE;
        }
        isOk = OK;
    }
    return isOk;
}


int validarRodado(float arrayDeRodadosValidos[],int cantidad,float rodadoRecibido)
{
    int existe=ERROR;
    if(arrayDeRodadosValidos != NULL && cantidad > 0)
    {
        for(int i=0; i<cantidad; i++)
        {
            if(arrayDeRodadosValidos[i]==rodadoRecibido)
            {
                existe = OK;
                break;
            }
        }
    }
    return existe;
}

int validarBicicleta(eBicicleta listaDeBicicletas[], int cantidad,int idRecibido)
{
    int isOk=ERROR;
    if(listaDeBicicletas!=NULL && cantidad>0)
    {
        for(int i=0; i<cantidad; i++)
        {
            if(listaDeBicicletas[i].id == idRecibido)
            {
                isOk = OK;
            }
        }
    }
    return isOk;
}

int cargarMarcaBicicleta(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,int idRecibido, char marcaDevuelta[])
{
    int isOk = ERROR;
    if(listaDeBicicletas!=NULL && cantidadDeBicicletas > 0 && marcaDevuelta != NULL)
    {
        for(int i=0; i<cantidadDeBicicletas; i++)
        {
            if(listaDeBicicletas[i].isEmpty == FALSE && listaDeBicicletas[i].id==idRecibido)
            {
                strcpy(marcaDevuelta,listaDeBicicletas[i].marca);
                isOk = OK;
            }
        }
    }
    return isOk;
}

int ordenarBicicletasPorTipoYrodado(eBicicleta listaDeBicicletas[], int cantidad,int order)
{
    int isOk = ERROR;
    eBicicleta bicicletaAux;

    if(listaDeBicicletas!=NULL && cantidad > 0 && (order == 1 || order == 0))
    {
        for(int i=0; i<cantidad-1; i++)
        {
            for(int j=i+1; j<cantidad; j++)
            {
                if((order == 1 && listaDeBicicletas[i].idTipo > listaDeBicicletas[j].idTipo) || (order == 1 && listaDeBicicletas[i].idTipo == listaDeBicicletas[j].idTipo && listaDeBicicletas[i].rodado > listaDeBicicletas[j].rodado))
                {
                    bicicletaAux = listaDeBicicletas[i];
                    listaDeBicicletas[i] = listaDeBicicletas[j];
                    listaDeBicicletas[j] = bicicletaAux;
                }
                else if((order == 0 && listaDeBicicletas[i].idTipo < listaDeBicicletas[j].idTipo) || (order == 0 && listaDeBicicletas[i].idTipo == listaDeBicicletas[j].idTipo && listaDeBicicletas[i].rodado < listaDeBicicletas[j].rodado))
                {
                    bicicletaAux = listaDeBicicletas[i];
                    listaDeBicicletas[i] = listaDeBicicletas[j];
                    listaDeBicicletas[j] = bicicletaAux;
                }
            }
        }
        isOk = OK;
    }
    return isOk;
}

int contarBicicletas(eBicicleta listaDeBicicletas[],int cantidad,int* cont)
{
    int isOk = ERROR;
    if(listaDeBicicletas!=NULL && cantidad > 0 && cont != NULL)
    {
        for(int i=0; i<cantidad; i++)
        {
            if(listaDeBicicletas[i].isEmpty == FALSE)
            {
                *cont = *cont+1;
            }
        }
        isOk = OK;
    }
    return isOk;
}
