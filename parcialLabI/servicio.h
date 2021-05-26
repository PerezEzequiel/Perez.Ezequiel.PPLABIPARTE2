#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    float precio;
}eServicio;

/** \brief Muestra un solo servicio.
 *
 * \param servicioRecibido eServicio Servicio a mostrar.
 * \return void
 *
 */
void mostrarServicio(eServicio servicioRecibido);




/** \brief Muestra la lista de servicios
 *
 * \param listaDeServicios[] eServicio Lista de servicios recibida.
 * \param cantidad int tam de la lista de servicios.
 * \return int Retorna -1 si, la lista de servicios es NULL o, si la cantidad es menor a 0. De lo contrario, retorna 1
 *
 */
int mostrarListaDeServicios(eServicio listaDeServicios[], int cantidad);



/** \brief Busca en la lista el id recibido y carga la descripcion del servicio.
 *
 * \param listaDeServicios[] eServicio Lista de servicios recibida.
 * \param cantidad int tam de la lista de servicios.
 * \param idRecibido int Id recibido a buscar
 * \param descripcionDevuelta[] char Devuelve la descripcion encontrada
 * \return int Retorna -1 si, los punteros son NULL, si la cantidad es menor a 0 o, si no se encontro ese id en la lista. De lo contrario, retorna 1
 *
 */
int cargarDescripcionServicio(eServicio listaDeServicios[],int cantidad,int idRecibido,char descripcionDevuelta[]);



/** \brief Recorre la lista, analizando si, el id recibido existe
 *
 * \param listaDeServicios[] eServicio Lista de servicios recibida.
 * \param cantidad int tam de la lista de servicios.
 * \param idRecibido int Id recibido a buscar
 * \return int Retorna -1 si, el puntero es NULL, si la cantidad es menor a 0 o, si no se encontro ese id en la lista. De lo contrario, retorna 1
 *
 */
int validarServicio(eServicio listaDeServicios[],int cantidad, int idRecibido);

#endif // SERVICIO_H_INCLUDED
