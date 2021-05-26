#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];
}eColor;

/** \brief Muestra un solo color.
 *
 * \param colorRecibido eColor Servicio a mostrar.
 * \return void
 *
 */
void mostrarColor(eColor colorRecibido);




/** \brief Muestra la lista de colores.
 *
 * \param listaDeServicios[] eColor Lista de colores recibida.
 * \param cantidad int tam de la lista de colores.
 * \return int Retorna -1 si, la lista de colores es NULL o, si la cantidad es menor a 0. De lo contrario, retorna 1.
 *
 */
int mostrarListaDeColores(eColor listaDeDeColores[], int cantidad);





/** \brief Busca en la lista el id recibido y carga la descripcion del color.
 *
 * \param listaDeServicios[] eColor Lista de colores recibida.
 * \param cantidad int tam de la lista de colores.
 * \param idRecibido int Id recibido a buscar.
 * \param descripcionDevuelta[] char Devuelve la descripcion encontrada.
 * \return int Retorna -1 si, los punteros son NULL, si la cantidad es menor a 0 o, si no se encontro ese id en la lista. De lo contrario, retorna 1.
 *
 */
int cargarDescripcionColor(eColor listaDeColores[],int cantidad,int idRecibido,char descripcionDevuelta[]);



/** \brief Recorre la lista, analizando si, el id recibido existe.
 *
 * \param listaDeServicios[] eColor Lista de colores recibida.
 * \param cantidad int tam de la lista de colores.
 * \param idRecibido int Id recibido a buscar.
 * \return int Retorna -1 si, el puntero es NULL, si la cantidad es menor a 0 o, si no se encontro ese id en la lista. De lo contrario, retorna 1.
 *
 */
int validarColor(eColor listaDeDeColores[], int cantidad,int idRecibido);

#endif // COLOR_H_INCLUDED
