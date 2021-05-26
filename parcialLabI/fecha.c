#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fecha.h"
#include "datos.h"
#define OK 1
#define ERROR -1

int compararFecha(eFecha f1, eFecha f2)
{
    int esIgual=0;
    if(f1.dia == f2.dia && f1.mes == f2.mes && f1.anio == f2.anio)
    {
        esIgual=1;
    }
    return esIgual;
}

void mostrarFecha(eFecha fecha)
{
    printf("%02d/%02d/%02d\n",fecha.dia,fecha.mes,fecha.anio);
}
