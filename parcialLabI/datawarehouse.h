#ifndef DATAWAREHOUSE_H_INCLUDED
#define DATAWAREHOUSE_H_INCLUDED
#include "trabajo.h"


/** \brief Hardcodea la lista de tipos
 *
 * \param listaDeTipos[] eTipo Lista recibida de tipos a hardcodear
 * \param cantidad int Tam de la lista recibida
 * \return int Retorna 1 si, el puntero es diferente de NULL y si la cantidad es mayor a 0.
 *
 */
int hardcodearTipos(eTipo listaDeTipos[],int cantidad);





/** \brief Hardcodea la lista de colores
 *
 * \param listaDeTipos[] eColor Lista recibida de colores a hardcodear
 * \param cantidad int Tam de la lista recibida
 * \return int Retorna 1 si, el puntero es diferente de NULL y si la cantidad es mayor a 0.
 *
 */
int hardcodearColores(eColor listaDeColores[],int cantidad);





/** \brief Hardcodea la lista de servicios
 *
 * \param listaDeTipos[] eServicio Lista recibida de servicios a hardcodear
 * \param cantidad int Tam de la lista recibida
 * \return int Retorna 1 si, el puntero es diferente de NULL y si la cantidad es mayor a 0.
 *
 */
int hardcodearServicios(eServicio listaDeServicios[],int cantidad);





/** \brief Hardcodea la lista de bicicletas
 *
 * \param listaDeBicicletas[] eBicicleta Lista recibida de bicicletas a hardcodear.
 * \param cantidad int Tam de la lista total de bicicletas.
 * \param cantidadCargar int  Tam de la lista que se va a cargar.
 * \param pNextId int* Id a asignar.
 * \return int Retorna 1 si, los punteros son diferente de NULL, si el parametro "cantidad" es mayor a 0 y, si el parametro "cantidadCargar" es menor o igual al parametro "cantidad". De lo contrario, retorna -1.
 *
 */
int hardcodearBicicletas(eBicicleta listaDeBicicletas[],int cantidad,int cantidadCargar,int* pNextId);




/** \brief Hardcodea la lista de trabajos
 *
 * \param listaDeTrabajos[] eTrabajo Lista recibida de trabajos a hardcodear.
 * \param cantidad int Tam de la lista total de trabajos.
 * \param cantidadCargar int  Tam de la lista que se va a cargar.
 * \param pNextId int* Id a asignar.
 * \return int Retorna 1 si, los punteros son diferente de NULL, si el parametro "cantidad" es mayor a 0 y, si el parametro "cantidadCargar" es menor o igual al parametro "cantidad". De lo contrario, retorna -1.
 *
 */
int hardcodearTrabajos(eTrabajo listaDeTrabajos[],int cantidad,int cantidadCargar,int* pNextId);

#endif // DATAWAREHOUSE_H_INCLUDED
