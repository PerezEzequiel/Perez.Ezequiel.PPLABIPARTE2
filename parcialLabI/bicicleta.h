#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

#include "color.h"
#include "tipo.h"

typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    float rodado;
    int isEmpty;
}eBicicleta;



/** \brief inicializa el todos los isEmpty de la lista en true.
 *
 * \param listaDeBicicletas[] eBicicleta lista recibida de bicicletas.
 * \param cantidadDeBicicletas int tam de bicicletas.
 * \return int retorna 1 si, el puntero es diferente de NULL y si el tam es mayor a 0, de lo contrario retorna -1.
 *
 */
int inicializarListaBicicletas(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas);




/** \brief busca en la lista, una posicion libre.
 *
 * \param listaDeBicicletas[] eBicicleta lista recibida de bicicletas.
 * \param cantidadDeBicicletas int tam de bicicletas.
 * \return int retorna diferente de -1 si, el puntero es diferente de NULL, el tam mayor a 0 y si encontro lugar.
 *
 */
int buscarBicicletaLibre(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas);


/** \brief Crea y valida una bicicleta.
 *
 * \param nextId int* id a asignar.
 * \param listaDeTipos[] eTipo lista recibida de tipos.
 * \param cantidadDeTipos int tam de tipos.
 * \param listaDeColores[] eColor  lista recibida de colores.
 * \param cantidadDeColores int tam de colores.
 * \return eBicicleta retorna una bicicleta.
 *
 */
eBicicleta crearBicicleta(int* nextId,eTipo listaDeTipos[],int cantidadDeTipos, eColor listaDeColores[],int cantidadDeColores);


/** \brief Agrega en un lugar libre, una bicicleta.
 *
 * \param listaDeBicicletas[] eBicicleta lista recibida de bicicletas.
 * \param cantidadDeBicicletas int tam de bicicleta.
 * \param listaDeTipos[] eTipo lista recibida de tipos.
 * \param cantidadDeTipos int tam de tipos.
 * \param listaDeColores[] eColor lista recibida de colores.
 * \param cantidadDeColores int tam de colores.
 * \param nextId int* id a asginar.
 * \return int  Retorna -1 si, los punteros son NULL o los tam son menor que 0. De lo contrario, retorna 1.
 *
 */
int altaDeBicicleta(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,eTipo listaDeTipos[],int cantidadDeTipos, eColor listaDeColores[],int cantidadDeColores,int* nextId);




/** \brief Busca una bicicleta por el parametro id recibido.
 *
 * \param listaDeBicicletas[] eBicicleta  lista recibida de bicicletas.
 * \param cantidadDeBicicletas int tam de bicicleta.
 * \param idRecibido int id a buscar
 * \return int Retorna diferente de -1 si, el puntero es diferente de NULL, el tam mayor a 0 y si encontro una posicion con ese id
 *
 */
int buscarBicicletaPorId(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,int idRecibido);


/** \brief Muestra una sola bicicleta.
 *
 * \param bicicletaRecibida eBicicleta Bicicleta recibida.
 * \param listaDeTipos[] eTipo  lista recibida de tipos.
 * \param cantidadDeTipos int tam de tipos.
 * \param listaDeColores[] eColor eColor lista recibida de colores.
 * \param cantidadDeColores int int tam de colores.
 * \return int Retorna -1 si no pudo mostrar esa bicicleta(punteros igual a NULL o tam menor a 0 o no se pudo cargar la descripcion), de lo contrario devuelve 1.
 *
 */
int mostrarBicicleta(eBicicleta bicicletaRecibida,eTipo listaDeTipos[],int cantidadDeTipos,eColor listaDeColores[],int cantidadDeColores);


/** \brief Muestra la lista de bicicletas.
 *
 * \param listaDeBicicletas[] eBicicleta lista recibida de bicicletas.
 * \param cantidadDeBicicletas int tam de bicicleta.
 * \param listaDeTipos[] eTipo lista recibida de tipos.
 * \param cantidadDeTipos int  tam de tipos.
 * \param listaDeColores[] eColor lista recibida de colores.
 * \param cantidadDeColores int tam de colores.
 * \return int Retorna 1 si los punteros sin diferente de NULL y los tam mayor a 0, de lo contrario retorna -1.
 *
 */
int mostrarListaDeBicicletas(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,eTipo listaDeTipos[],int cantidadDeTipos, eColor listaDeColores[],int cantidadDeColores);



/** \brief Busca en el listado, una bicicleta existente por id.
 *
 * \param listaDeBicicletas[] eBicicleta lista recibida de bicicletas.
 * \param cantidadDeBicicletas int tam de bicicletas.
 * \param idRecibido int Id que se recibe para buscar en el listado.
 * \return int Retorna -1 si no se encontro ese id en el listado, de lo contrario, devuelve la posicion en la que esta situada la bicicleta.
 *
 */
int buscarBicicletaPorId(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,int idRecibido);





/** \brief Modifica tipo y rodaje de una bicicleta.
 *
 * \param listaDeBicicletas[] eBicicleta lista recibida de bicicletas.
 * \param cantidadDeBicicletas int tam de bicicletas.
 * \param listaDeTipos[] eTipo lista recibida de tipos.
 * \param cantidadDeTipos int tam de tipos.
 * \param listaDeColores[] eColor lista recibida de colores.
 * \param cantidadDeColores int tam de colores.
 * \return int Retorna -1 si los punteros son NULL o si los tams son menor a 0. De lo contrario retorna 1.
 *
 */
int modificarBicicleta(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,eTipo listaDeTipos[],int cantidadDeTipos, eColor listaDeColores[],int cantidadDeColores);





/** \brief Elimina una bicicleta de la lista (isEmpty = 1).
 *
 * \param listaDeBicicletas[] eBicicleta lista recibida de bicicletas.
 * \param cantidadDeBicicletas int tam de bicicletas.
 * \param listaDeTipos[] eTipo lista recibida de tipos.
 * \param cantidadDeTipos int tam de tipos.
 * \param listaDeColores[] eColor lista recibida de colores.
 * \param cantidadDeColores int tam de colores.
 * \return int Retorna -1 si los punteros son NULL o si los tams son menor a 0. De lo contrario retorna 1.
 *
 */
int bajaDeBicicleta(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,eTipo listaDeTipos[],int cantidadDeTipos, eColor listaDeColores[],int cantidadDeColores);





/** \brief Valida si el rodado recibido por parametros, es valido a los rodados exigidos.
 *
 * \param arrayDeRodadosValidos[] float Lista de rodados validos.
 * \param cantidad int Tam de los rodados validos.
 * \param rodadoRecibido float Rodado a validar.
 * \return int Retorna -1 si, el puntero es NULL, si el tam es menor a 0 o, si no es valido el rodadoRecibido. De lo contrario retorna 1.
 *
 */
int validarRodado(float arrayDeRodadosValidos[],int cantidad,float rodadoRecibido);





/** \brief Valida si existe la bicicleta recibida(Id de la bicicleta) en la lista.
 *
 * \param listaDeBicicletas[] eBicicleta lista recibida de bicicletas.
 * \param cantidad int tam de bicicletas.
 * \param idRecibido int Id recibido a buscar.
 * \return int Retorna -1 si, el puntero es NULL, si el tam es menor a 0 o, si no existe esa bicicleta. De lo contrario retorna 1.
 *
 */
int validarBicicleta(eBicicleta listaDeBicicletas[], int cantidad,int idRecibido);



/** \brief Carga la marca de la bicicleta recibida por id en una cadena recibida.
 *
 * \param listaDeBicicletas[] eBicicleta  lista recibida de bicicletas.
 * \param cantidadDeBicicletas int tam de bicicletas.
 * \param idRecibido int Id recibido de la bicicleta a cargar marca.
 * \param marcaDevuelta[] char Cadena recibida para almacenar la marca.
 * \return int Retorna -1 si, los punteros son NULL, si el tam es menor a 0 o si no existe esa bicicleta. De lo contrario retorna 1.
 *
 */
int cargarMarcaBicicleta(eBicicleta listaDeBicicletas[], int cantidadDeBicicletas,int idRecibido, char marcaDevuelta[]);


/** \brief Ordena la lista por tipo y rodado.
 *
 * \param listaDeBicicletas[] eBicicleta  lista recibida de bicicletas.
 * \param cantidad int tam de bicicletas.
 * \param order int orden, 1(asc) 0(desc).
 * \return int Retorna -1 si, el puntero es NULL, si el tam es menor a 0 o si el orden recibido es diferende 1 o 0. De lo contrario retorna 1.
 *
 */
int ordenarBicicletasPorTipoYrodado(eBicicleta listaDeBicicletas[], int cantidad,int order);



/** \brief Cuenta las bicicletas que hay en la lista (isEmpty = 0).
 *
 * \param listaDeBicicletas[] eBicicleta  lista recibida de bicicletas.
 * \param cantidad int tam de bicicletas.
 * \param cont int* Puntero donde se almacena la cantidad de bicicletas en la lista.
 * \return int Retorna -1 si, los punteros son NULL, si el tam es menor a 0. De lo contrario retorna 1.
 *
 */
int contarBicicletas(eBicicleta listaDeBicicletas[],int cantidad,int* cont);


#endif // BICICLETA_H_INCLUDED
