#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datawarehouse.h"
#define OK 1
#define ERROR -1
#define TRUE 1
#define FALSE 0

char nombres[10][20] =
{
    "Donato",
    "Carmen",
    "Chepi",
    "Alex",
    "German",
    "Maria",
    "Damian",
    "Daniel",
    "Andrea",
    "Candela"
};

char apellidos[10][20] =
{
    "Perez",
    "Baus",
    "Gonzalez",
    "Diaz",
    "Villegas",
    "Iturri",
    "Oviego",
    "Vargas",
    "Espinosa",
    "Barreto"
};

char sexos[10] =
{
    'm',
    'f',
    'f',
    'm',
    'm',
    'f',
    'm',
    'm',
    'f',
    'f'
};

char telefonos[10][21]=
{
    {"43018809"},
    {"43031509"},
    {"43091289"},
    {"43020582"},
    {"43070128"},
    {"43062921"},
    {"43018195"},
    {"43051191"},
    {"43036633"},
    {"43094688"}
};

int edades[10] = {56,71,39,52,45,44,58,38,29,25};

float sueldos[10] = {10000,12000,1100,13200,11500,10000,12000,1100,13200,11500};

eFecha fechas[10]=
{
    {26,4,2019},
    {18,6,2020},
    {11,10,2016},
    {29,4,2014},
    {13,3,2013},
    {15,9,2008},
    {2,12,2018},
    {6,11,2017},
    {16,3,2018},
    {19,1,2011}

};




eFecha fechas2[]=
{
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {2,1,2021},
    {2,1,2021},
    {2,1,2021},
    {2,1,2021},
    {2,1,2021},
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {4,1,2021},
    {4,1,2021},
    {4,1,2021},
    {4,1,2021},
    {4,1,2021},
    {4,1,2021}

};


eFecha fechasTrabajo[]=
{
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {2,1,2021},
    {2,1,2021},
    {2,1,2021},
    {2,1,2021},
    {2,1,2021},
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {4,1,2021},
    {4,1,2021},
    {4,1,2021},
    {4,1,2021},
    {4,1,2021},
    {4,1,2021}
};




int hardcodearTipos(eTipo listaDeTipos[],int cantidad)
{
    int isOk = ERROR;
    char descripcion[4][20]= {"Rutera","Carrera","Mountain","BMX"};
    int id[4] = {1000,1001,1002,1003};

    if(listaDeTipos!=NULL && cantidad > 0)
    {
        for(int i=0; i<cantidad; i++)
        {
            listaDeTipos[i].id = id[i];
            strcpy(listaDeTipos[i].descripcion,descripcion[i]);
        }
        isOk = OK;
    }
    return isOk;
}

int hardcodearColores(eColor listaDeColores[],int cantidad)
{
    int isOk = ERROR;
    char nombreColor[5][20]= {"Gris","Negro","Blanco","Azul","Rojo"};
    int id[5] = {5000,5001,5002,5003,5004};

    if(listaDeColores!=NULL && cantidad > 0)
    {
        for(int i=0; i<cantidad; i++)
        {
            listaDeColores[i].id = id[i];
            strcpy(listaDeColores[i].nombreColor,nombreColor[i]);
        }
        isOk = OK;
    }
    return isOk;
}

////////////////////////////////////////////////////////////////////

int idServicio[]= {2000,2001,2002,2003};
char descripcionServicio[4][20] =
{
    {"Limpieza"},
    {"Parche"},
    {"Centrado"},
    {"Cadena"},
};

float precioServicio[]= {250,300,400,350};

int hardcodearServicios(eServicio listaDeServicios[], int cantidadDeServicios)
{
    int isOk = ERROR;
    if(listaDeServicios!=NULL && cantidadDeServicios > 0)
    {
        for(int i=0; i<cantidadDeServicios; i++)
        {
            listaDeServicios[i].id = idServicio[i];
            strcpy(listaDeServicios[i].descripcion,descripcionServicio[i]);
            listaDeServicios[i].precio = precioServicio[i];
        }
        isOk =OK;
    }
    return isOk;
}


///////////////////////////////////////////////////////

char marcasBicicleta[10][20]=
{
    {"Olmo"},
    {"Vairo"},
    {"Venzo"},
    {"TopMega"},
    {"Raleight"},
    {"Trinx"},
    {"Pepe"},
    {"Trek"},
    {"Giant"},
    {"Cube"}

};

float rodados[]= {20,26,27.5,29,27.5,29,20,29,26,26};
int idColor[]= {5001,5002,5003,5002,5001,5000,5004,5004,5004,5001};
int idTipo[]= {1001,1002,1003,1002,1001,1000,1003,1001,1000,1002};


int hardcodearBicicletas(eBicicleta listaDeBicicletas[],int cantidad,int cantidadCargar,int* pNextId)
{
    int isOk = ERROR;
    if(listaDeBicicletas!=NULL && cantidad > 0 && cantidadCargar<= cantidad && pNextId !=NULL)
    {
        for(int i=0; i<cantidadCargar; i++)
        {
            listaDeBicicletas[i].id = *pNextId;
            *pNextId = *pNextId + 1;
            listaDeBicicletas[i].idTipo = idTipo[i];
            listaDeBicicletas[i].idColor = idColor[i];
            strcpy(listaDeBicicletas[i].marca,marcasBicicleta[i]);
            listaDeBicicletas[i].rodado = rodados[i];
            listaDeBicicletas[i].isEmpty = FALSE;
        }
        isOk =OK;
    }
    return isOk;
}


/////////////////////////////////////////////////////////////////////////////////////////////////

int idBicicletas[]={20000,20001,20002,20003,20004,20005,20006,20007,20008,20009};
int idServicios[]={2000,2001,2002,2003,2003,2002,2001,2000,2001,2002};

int hardcodearTrabajos(eTrabajo listaDeTrabajos[],int cantidad,int cantidadCargar,int* pNextId)
{
    int isOk = ERROR;
    if(listaDeTrabajos!=NULL && cantidad > 0 && cantidadCargar<= cantidad && pNextId !=NULL)
    {
        for(int i=0; i<cantidadCargar; i++)
        {
            listaDeTrabajos[i].id = *pNextId;
            *pNextId = *pNextId + 1;
            listaDeTrabajos[i].idBicicleta = idBicicletas[i];
            listaDeTrabajos[i].idServicio = idServicios[i];
            listaDeTrabajos[i].fecha = fechas2[i];
            listaDeTrabajos[i].isEmpty = FALSE;
        }
        isOk =OK;
    }
    return isOk;
}

