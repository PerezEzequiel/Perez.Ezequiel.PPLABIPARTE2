#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "datawarehouse.h"

/** \brief Pide y muestra bicicletas de un color
 *
 * \param listaDeBicicletas[] eBicicleta Lista de bicicletas
 * \param cantidadDeBicicletas int Tam de la lista de bicicletas
 * \param listaDeTipos[] eTipo Lista de Tipos
 * \param cantidadDeTipos int Tam de la lista de tipos
 * \param listaDeColores[] eColor Lista de colores
 * \param cantidadDeColores int Tam de la lista de colores
 * \return int Retorna 1 si, los punteros son diferente de NULL y los tams mayor a 0.
 *
 */
int mostrarBicicletasDeUnColor(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,eTipo listaDeTipos[],int cantidadDeTipos,eColor listaDeColores[],int cantidadDeColores);




/** \brief Pide y muestra bicicletas de un tipo
 *
 * \param listaDeBicicletas[] eBicicleta Lista de bicicletas
 * \param cantidadDeBicicletas int Tam de la lista de bicicletas
 * \param listaDeTipos[] eTipo Lista de Tipos
 * \param cantidadDeTipos int Tam de la lista de tipos
 * \param listaDeColores[] eColor Lista de colores
 * \param cantidadDeColores int Tam de la lista de colores
 * \return int Retorna 1 si, los punteros son diferente de NULL y los tams mayor a 0.
 *
 */
int mostrarBicicletasDeUnTipo(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,eTipo listaDeTipos[],int cantidadDeTipos,eColor listaDeColores[],int cantidadDeColores);





/** \brief Muestra la/las bicicleta/s de menor rodado.
 *
 * \param listaDeBicicletas[] eBicicleta Lista de bicicletas
 * \param cantidadDeBicicletas int Tam de la lista de bicicletas
 * \param listaDeTipos[] eTipo Lista de Tipos
 * \param cantidadDeTipos int Tam de la lista de tipos
 * \param listaDeColores[] eColor Lista de colores
 * \param cantidadDeColores int Tam de la lista de colores
 * \return int Retorna 1 si, los punteros son diferente de NULL y los tams mayor a 0.
 *
 */
int mostrarBicicletasMenorRodado(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,eTipo listaDeTipos[],int cantidadDeTipos,eColor listaDeColores[],int cantidadDeColores);




/** \brief Muestra el listado de bicicletas separadas por tipo.
 *
 * \param listaDeBicicletas[] eBicicleta Lista de bicicletas
 * \param cantidadDeBicicletas int Tam de la lista de bicicletas
 * \param listaDeTipos[] eTipo Lista de Tipos
 * \param cantidadDeTipos int Tam de la lista de tipos
 * \param listaDeColores[] eColor Lista de colores
 * \param cantidadDeColores int Tam de la lista de colores
 * \return int Retorna 1 si, los punteros son diferente de NULL y los tams mayor a 0.
 *
 */
int mostrarBicicletasPorTipo(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,eTipo listaDeTipos[],int cantidadDeTipos,eColor listaDeColores[],int cantidadDeColores);





/** \brief Pide un tipo y un color y lista las bicicletas con esas caracteristicas
 *
 * \param listaDeBicicletas[] eBicicleta Lista de bicicletas
 * \param cantidadDeBicicletas int Tam de la lista de bicicletas
 * \param listaDeTipos[] eTipo Lista de Tipos
 * \param cantidadDeTipos int Tam de la lista de tipos
 * \param listaDeColores[] eColor Lista de colores
 * \param cantidadDeColores int Tam de la lista de colores
 * \return int Retorna 1 si, los punteros son diferente de NULL y los tams mayor a 0.
 *
 */
int contarBicicletasDeUnTipoYcolor(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,eTipo listaDeTipos[],int cantidadDeTipos,eColor listaDeColores[],int cantidadDeColores);





/** \brief Muestra los colores mas elegidos de la lista.
 *
 * \param listaDeBicicletas[] eBicicleta Lista de bicicletas
 * \param cantidadDeBicicletas int Tam de la lista de bicicletas
 * \param listaDeTipos[] eTipo Lista de Tipos
 * \param cantidadDeTipos int Tam de la lista de tipos
 * \param listaDeColores[] eColor Lista de colores
 * \param cantidadDeColores int Tam de la lista de colores
 * \return int Retorna 1 si, los punteros son diferente de NULL y los tams mayor a 0.
 *
 */
int mostrarColoresMasElegidos(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,eTipo listaDeTipos[],int cantidadDeTipos,eColor listaDeColores[],int cantidadDeColores);





/** \brief Muestra los trabajos que se realizaron en una bicicleta
 *
 * \param listaDeBicicletas[] eBicicleta Lista de bicicletas
 * \param cantidadDeBicicletas int Tam de la lista de bicicletas
 * \param listaDeTipos[] eTipo Lista de Tipos
 * \param cantidadDeTipos int Tam de la lista de tipos
 * \param listaDeColores[] eColor eColor Lista de colores
 * \param cantidadDeColores int int Tam de la lista de colores
 * \param listaDeTrabajos[] eTrabajo Lista de trabajos
 * \param cantidadDeTrabajos int Tam de la lista de trabajos
 * \param listaDeServicios[] eServicio Lista de servicios
 * \param cantidadDeServicios int Tam de la lista de servicios
 * \return int Retorna 1 si, los punteros son diferente de NULL y los tams mayor a 0.
 *
 */
int mostrarTrabajosDeUnaBicicleta(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,eTipo listaDeTipos[],int cantidadDeTipos,eColor listaDeColores[],int cantidadDeColores,eTrabajo listaDeTrabajos[],int cantidadDeTrabajos,eServicio listaDeServicios[], int cantidadDeServicios);



/** \brief Muestra la suma de los importes de los trabjos que se realizaron en una bicicleta
 *
 * \param listaDeBicicletas[] eBicicleta Lista de bicicletas
 * \param cantidadDeBicicletas int Tam de la lista de bicicletas
 * \param listaDeTipos[] eTipo Lista de Tipos
 * \param cantidadDeTipos int Tam de la lista de tipos
 * \param listaDeColores[] eColor eColor Lista de colores
 * \param cantidadDeColores int int Tam de la lista de colores
 * \param listaDeTrabajos[] eTrabajo Lista de trabajos
 * \param cantidadDeTrabajos int Tam de la lista de trabajos
 * \param listaDeServicios[] eServicio Lista de servicios
 * \param cantidadDeServicios int Tam de la lista de servicios
 * \return int Retorna 1 si, los punteros son diferente de NULL y los tams mayor a 0.
 *
 */
int mostrarSumaImportesBicicleta(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,eTipo listaDeTipos[],int cantidadDeTipos,eColor listaDeColores[],int cantidadDeColores,eTrabajo listaDeTrabajos[],int cantidadDeTrabajos,eServicio listaDeServicios[], int cantidadDeServicios);



/** \brief Pide un servicio y muestra las bicicletas en las que se realizaron dicho servicio(con la fecha).
 *
 * \param listaDeBicicletas[] eBicicleta Lista de bicicletas
 * \param cantidadDeBicicletas int Tam de la lista de bicicletas
 * \param listaDeTipos[] eTipo Lista de Tipos
 * \param cantidadDeTipos int Tam de la lista de tipos
 * \param listaDeColores[] eColor eColor Lista de colores
 * \param cantidadDeColores int int Tam de la lista de colores
 * \param listaDeTrabajos[] eTrabajo Lista de trabajos
 * \param cantidadDeTrabajos int Tam de la lista de trabajos
 * \param listaDeServicios[] eServicio Lista de servicios
 * \param cantidadDeServicios int Tam de la lista de servicios
 * \return int Retorna 1 si, los punteros son diferente de NULL y los tams mayor a 0.
 *
 */
int mostrarBicicletasYfechaDeUnServicio(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,eTipo listaDeTipos[],int cantidadDeTipos,eColor listaDeColores[],int cantidadDeColores,eTrabajo listaDeTrabajos[],int cantidadDeTrabajos,eServicio listaDeServicios[], int cantidadDeServicios);




/** \brief Pide un servicio y muestra las bicicletas en las que se realizaron dicho servicio(con la fecha).
 *
 * \param listaDeBicicletas[] eBicicleta Lista de bicicletas
 * \param cantidadDeBicicletas int Tam de la lista de bicicletas
 * \param listaDeTipos[] eTipo Lista de Tipos
 * \param cantidadDeTipos int Tam de la lista de tipos
 * \param listaDeColores[] eColor eColor Lista de colores
 * \param cantidadDeColores int int Tam de la lista de colores
 * \param listaDeTrabajos[] eTrabajo Lista de trabajos
 * \param cantidadDeTrabajos int Tam de la lista de trabajos
 * \param listaDeServicios[] eServicio Lista de servicios
 * \param cantidadDeServicios int Tam de la lista de servicios
 * \return int Retorna 1 si, los punteros son diferente de NULL y los tams mayor a 0.
 *
 */
int mostrarServiciosDeUnaFecha(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,eTipo listaDeTipos[],int cantidadDeTipos,eColor listaDeColores[],int cantidadDeColores,eTrabajo listaDeTrabajos[],int cantidadDeTrabajos,eServicio listaDeServicios[], int cantidadDeServicios);

#endif // INFORMES_H_INCLUDED
