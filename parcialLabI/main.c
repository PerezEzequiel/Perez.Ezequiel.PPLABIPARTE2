#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "datos.h"
#include "informes.h"
#define TBICICLETAS 20
#define TCOLOR 5
#define TTIPO 4
#define TSERVICIO 4
#define TTRABAJO 20

int main()
{
    int contador=0;
    char opcion;
    char bandera = 'n';

    char banderaInforme = 'n';
    int opcionInformes;

    int nextIdBicicleta=20000;
    int nextidTrabajo=50000;
    eBicicleta listaDeBicicletas[TBICICLETAS];
    eColor listaDeColores[TCOLOR];
    eTipo listaDeTipos[TTIPO];
    eServicio listaDeServicios[TSERVICIO];
    eTrabajo listaDeTrabajos[TTRABAJO];


    hardcodearColores(listaDeColores,TCOLOR);
    hardcodearTipos(listaDeTipos,TTIPO);
    hardcodearServicios(listaDeServicios,TSERVICIO);

    inicializarListaBicicletas(listaDeBicicletas, TBICICLETAS);
    inicializarListaDeTrabajos(listaDeTrabajos,TTRABAJO);
    hardcodearBicicletas(listaDeBicicletas,TBICICLETAS,10,&nextIdBicicleta);
    hardcodearTrabajos(listaDeTrabajos,TTRABAJO,10,&nextidTrabajo);


    do
    {

        contarBicicletas(listaDeBicicletas,TBICICLETAS,&contador);
        system("cls");
        mostrarMenuChar("\n****Primer Parcial Lab I A****\n\nA. Alta bicicleta\nB. Modificar bicicleta\nC. Baja bicicleta\nD. Listar bicicletas\nE. Listar tipos\nF. Listar colores\nG. Listar Servicios\nH. Alta trabajo\nI. Listar trabajos\nJ. Informes\nK. Salir\nQue desea hacer?: ",&opcion);

        switch(opcion)
        {
        case 'a':
            if(altaDeBicicleta(listaDeBicicletas,TBICICLETAS,listaDeTipos,TTIPO,listaDeColores,TCOLOR,&nextIdBicicleta))
            {
                printf("Alta con exito\n");
            }

            break;
        case 'b':
            if(contador > 0)
            {
                system("cls");
                if(modificarBicicleta(listaDeBicicletas,TBICICLETAS,listaDeTipos,TTIPO,listaDeColores,TCOLOR))
                {
                    printf("Modificacion exitosa\n");
                }
            }
            else
            {
                printf("\nError, cargue una bicicleta\n\n");
            }
            break;
        case 'c':
            if(contador > 0)
            {
                system("cls");
                if(bajaDeBicicleta(listaDeBicicletas,TBICICLETAS,listaDeTipos,TTIPO,listaDeColores,TCOLOR))
                {
                    printf("Baja exitosa\n");
                }
            }
            else
            {
                printf("\nError, cargue una bicicleta\n\n");
            }
            break;
        case 'd':
            if(contador > 0)
            {
                system("cls");
                if(ordenarBicicletasPorTipoYrodado(listaDeBicicletas,TBICICLETAS,0) && mostrarListaDeBicicletas(listaDeBicicletas,TBICICLETAS,listaDeTipos,TTIPO,listaDeColores,TCOLOR))
                {
                    printf("Muestra con exito\n");
                }
            }
            else
            {
                printf("\nError, cargue una bicicleta\n\n");
            }
            break;
        case 'e':
            system("cls");
            if(mostrarListaDeTipos(listaDeTipos,TTIPO))
            {
                printf("Muestra con exito\n");
            }
            break;
        case 'f':
            system("cls");
            if(mostrarListaDeColores(listaDeColores,TCOLOR))
            {
                printf("Muestra con exito\n");
            }
            break;
        case 'g':
            system("cls");
            if(mostrarListaDeServicios(listaDeServicios,TSERVICIO))
            {
                printf("Muestra con exito\n");
            }
            break;
        case 'h':
            if(contador > 0)
            {
                system("cls");
                if(altaDeDeTrabajo(listaDeTrabajos,TTRABAJO,&nextidTrabajo,listaDeBicicletas,TBICICLETAS,listaDeTipos,TTIPO,listaDeColores,TCOLOR,listaDeServicios,TSERVICIO))
                {
                    printf("Alta con exito\n");
                }
            }
            else
            {
                printf("\nError, cargue una bicicleta\n\n");
            }
            break;
        case 'i':

            if(contador > 0)
            {
                system("cls");
                if(mostrarListaDeTrabajo(listaDeTrabajos,TTRABAJO,listaDeBicicletas,TBICICLETAS,listaDeServicios,TSERVICIO))
                {
                    printf("Muestra de trabajos exitosa\n");
                }
            }
            else
            {
                printf("\nError, cargue una bicicleta\n\n");
            }
            break;
        case 'j':
            if(contador>0)
            {
                do
                {
                    banderaInforme='n';
                    system("cls");

                    mostrarMenuInt("\n****INFORMES****\n\n1- Mostrar bicicletas del color seleccionado por el usuario.\n2- Mostrar bicicletas de un tipo seleccionado.\n3- Informar la o las bicicletas de menor rodado.\n4- Mostrar un listado de las bicicletas separadas por tipo.\n5- Elegir un color y un tipo y contar cuantas bicicletas hay de ese color y ese tipo.\n6- Mostrar el o los colores mas elegidos por los clientes.\n7- Pedir una bicicleta y mostrar todos los trabajos que se le hicieron a la misma.\n8- Pedir una bicicleta e informar la suma de los importes de los servicios que se le hicieron a la misma.\n9- Pedir un servicio y mostrar las bicicletas a las que se les realizo ese servicio y la fecha.\n10- Pedir una fecha y mostrar todos los servicios realizados en la misma.\n11- Salir de informes\nQue desea hacer? ",&opcionInformes);
                    switch(opcionInformes)
                    {
                    case 1:
                        if(mostrarBicicletasDeUnColor(listaDeBicicletas,TBICICLETAS,listaDeTipos,TTIPO,listaDeColores,TCOLOR))
                        {
                            printf("Informe numero 1 mostrado con exito\n\n");
                        }
                        break;
                    case 2:
                        if(mostrarBicicletasDeUnTipo(listaDeBicicletas,TBICICLETAS,listaDeTipos,TTIPO,listaDeColores,TCOLOR))
                        {
                            printf("Informe numero 2 mostrado con exito\n\n");
                        }
                        break;
                    case 3:
                        if(mostrarBicicletasMenorRodado(listaDeBicicletas,TBICICLETAS,listaDeTipos,TTIPO,listaDeColores,TCOLOR))
                        {
                            printf("Informe numero 3 mostrado con exito\n\n");
                        }
                        break;
                    case 4:
                        if(mostrarBicicletasPorTipo(listaDeBicicletas,TBICICLETAS,listaDeTipos,TTIPO,listaDeColores,TCOLOR))
                        {
                            printf("Informe numero 4 mostrado con exito\n\n");
                        }
                        break;
                    case 5:
                        if(contarBicicletasDeUnTipoYcolor(listaDeBicicletas,TBICICLETAS,listaDeTipos,TTIPO,listaDeColores,TCOLOR))
                        {
                            printf("Informe numero 5 mostrado con exito\n\n");
                        }
                        break;
                    case 6:
                        if(mostrarColoresMasElegidos(listaDeBicicletas,TBICICLETAS,listaDeTipos,TTIPO,listaDeColores,TCOLOR))
                        {
                            printf("Informe numero 6 mostrado con exito\n\n");
                        }
                        break;
                    case 7:
                        if(mostrarTrabajosDeUnaBicicleta(listaDeBicicletas,TBICICLETAS,listaDeTipos,TTIPO,listaDeColores,TCOLOR,listaDeTrabajos,TTRABAJO,listaDeServicios,TSERVICIO))
                        {
                            printf("Informe numero 7 mostrado con exito\n\n");
                        }
                        break;
                    case 8:
                        if(mostrarSumaImportesBicicleta(listaDeBicicletas,TBICICLETAS,listaDeTipos,TTIPO,listaDeColores,TCOLOR,listaDeTrabajos,TTRABAJO,listaDeServicios,TSERVICIO))
                        {
                            printf("Informe numero 8 mostrado con exito\n\n");
                        }
                        break;
                    case 9:
                        if(mostrarBicicletasYfechaDeUnServicio(listaDeBicicletas,TBICICLETAS,listaDeTipos,TTIPO,listaDeColores,TCOLOR,listaDeTrabajos,TTRABAJO,listaDeServicios,TSERVICIO))
                        {
                            printf("Informe numero 9 mostrado con exito\n\n");
                        }
                        break;
                    case 10:
                        if(mostrarServiciosDeUnaFecha(listaDeBicicletas,TBICICLETAS,listaDeTipos,TTIPO,listaDeColores,TCOLOR,listaDeTrabajos,TTRABAJO,listaDeServicios,TSERVICIO))
                        {
                            printf("Informe numero 10 mostrado con exito\n\n");
                        }
                        break;
                    case 11:
                        getCaracter("Desea salir?s/n: ",&banderaInforme,"Error, ingrese un caracter: ","Error ingrese s/n",'s','n');
                        break;
                    default:
                        printf("\nNo existe esa opcion\n");
                        break;
                    }
                    if(banderaInforme!='s')
                    {
                        system("pause");
                    }
                }
                while(banderaInforme != 's');
            }
            else
            {
                printf("\nNo se puede utilizar esta opcion, primero cargue una bicicleta\n\n");
            }
            break;
        case 'k':
            getCaracter("Desea salir?s/n:",&bandera,"Error, ingrese un caracter: ","Error ingrese s/n",'s','n');
            break;
        default:
            printf("No existe esa opcion\n\n");
            break;
        }
        system("pause");
        contador = 0;
    }
    while(bandera != 's');

    return 0;
}
