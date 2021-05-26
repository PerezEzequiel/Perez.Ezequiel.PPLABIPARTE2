#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "bicicleta.h"
#include "servicio.h"
#include "fecha.h"
typedef struct
{
    int id;
    int idBicicleta;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

/** \brief Pide datos para crear un trabajo, los valida y devuelve la estructura creada
 *
 * \param nextId int* Id a asignar.
 * \param listaDeBicicletas[] eBicicleta lista de bicicletas.
 * \param cantidadDeBicicletas int tam de la lista de bicicletas.
 * \param listaDeTipos[] eTipo lista de tipos.
 * \param cantidadDeTipos int tam de la lista de tipos.
 * \param listaDeColores[] eColor lista de colores.
 * \param cantidadDeColores int tam de la lista de colores.
 * \param listaDeServicios[] eServicio lista de servicios.
 * \param cantidadDeServicios int tam de la lista de servicios.
 * \return eTrabajo Devuelve la estructura creada y validada.
 *
 */
eTrabajo crearTrabajo(int* nextId,eBicicleta listaDeBicicletas[],int cantidadDeBicicletas,eTipo listaDeTipos[],int cantidadDeTipos,eColor listaDeColores[],int cantidadDeColores,eServicio listaDeServicios[],int cantidadDeServicios);



/** \brief inicializa el todos los isEmpty del array en true
 *
 * \param listaDeTrabajo[] eTrabajo lista recibida de trabajo
 * \param cantidadDeBicicletas int tam de trabajo
 * \return int retorna 1 si, el puntero es diferente de NULL y si el tam es mayor a 0, de lo contrario retorna -1
 *
 */
int inicializarListaDeTrabajos(eTrabajo listaDeTrabajo[], int cantidad);




/** \brief busca en el array, una posicion libre
 *
 * \param listaDeTrabajo[] eTrabajo lista recibida de trabajo
 * \param cantidadDeBicicletas int tam de trabajo
 * \return int retorna diferente de -1, si, el puntero es diferente de NULL, el tam mayor a 0 y si encontro lugar
 *
 */
int buscarTrabajoLibre(eTrabajo listaDeTrabajo[],int cantidad);


/** \brief Agrega en un lugar libre, un trabajo
 *
 * \param listaDeTrabajo[] eTrabajo  lista recibida de trabajo.
 * \param cantidadDeTrabajo int tam de trabajo.
 * \param nextId int* Id a asignar.
 * \param listaDeBicicletas[] eBicicleta lista de bicicletas.
 * \param cantidadDeBicicletas int tam de la lista de bicicletas.
 * \param listaDeTipos[] eTipo lista de tipos.
 * \param cantidadDeTipos int tam de la lista de tipos.
 * \param listaDeColores[] eColor lista de colores.
 * \param cantidadDeColores int tam de la lista de colores.
 * \param listaDeServicios[] eServicio lista de servicios.
 * \param cantidadDeServicios int tam de la lista de servicios.
 * \return int  Retorna -1 si, los punteros son NULL o los tam son menor que 0. De lo contrario, retorna 1.
 *
 */
int altaDeDeTrabajo(eTrabajo listaDeTrabajo[],int cantidadDeTrabajo,int* nextId,eBicicleta listaDeBicicletas[],int cantidadDeBicicletas,eTipo listaDeTipos[],int cantidadDeTipos,eColor listaDeColores[],int cantidadDeColores,eServicio listaDeServicios[],int cantidadDeServicios);




/** \brief Muestra un trabajo
 *
 * \param trabajoRecibido eTrabajo Trabajo recibido
 * \param listaDeBicicletas[] eBicicleta lista de bicicletas
 * \param cantidadDeBicicletas int tam de la lista de bicicletas
 * \param listaDeServicios[] eServicio lista de servicios
 * \param cantidadDeServicios int tam de la lista de servicios
 * \return int Retorna 1 si, los punteros recibidos son diferente de NULL, si el tam es mayor a 0 y si pudo cargar la descripcion de servicio y la marca de bicicleta. De lo contrario, retorna -1.
 *
 */
int mostrarTrabajo(eTrabajo trabajoRecibido,eBicicleta listaDeBicicletas[],int cantidadDeBicicletas,eServicio listaDeServicios[],int cantidadDeServicios);




/** \brief Muestra la lista de trabajo
 *
 * \param listaDeTrabajo[] eTrabajo  lista recibida de trabajo
 * \param cantidadDeTrabajo int tam de trabajo.
 * \param listaDeBicicletas[] eBicicleta lista de bicicletas
 * \param cantidadDeBicicletas int tam de la lista de bicicletas
 * \param listaDeServicios[] eServicio lista de servicios
 * \param cantidadDeServicios int tam de la lista de servicios
 * \return int Retorna 1 si, los punteros recibidos son diferente de NULL, si los tams son mayor a 0. De lo contrario, retorna -1.
 *
 */
int mostrarListaDeTrabajo(eTrabajo listaDeTrabajo[],int cantidadDeTrabajo,eBicicleta listaDeBicicletas[],int cantidadDeBicicletas,eServicio listaDeServicios[],int cantidadDeServicios);


#endif // TRABAJO_H_INCLUDED
