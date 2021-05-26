#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eTipo;



/** \brief Muestra un solo tipo.
 *
 * \param tipoRecibido eTipo tipo a mostrar.
 * \return void
 *
 */
void mostrarTipo(eTipo tipoRecibido);


/** \brief Muestra la lista de tipos
 *
 * \param listaDetipos[] eTipo Lista de tipos recibida.
 * \param cantidad int tam de la lista de tipos.
 * \return int Retorna -1 si, la lista de tipos es NULL o, si la cantidad es menor a 0. De lo contrario, retorna 1
 *
 */
int mostrarListaDeTipos(eTipo listaDetipos[], int cantidad);



/** \brief Busca en la lista el id recibido y carga la descripcion del tipo.
 *
 * \param listaDetipos[] eTipo Lista de tipos recibida.
 * \param cantidad int tam de la lista de tipos.
 * \param idRecibido int Id recibido a buscar
 * \param descripcionDevuelta[] char Devuelve la descripcion encontrada
 * \return int Retorna -1 si, los punteros son NULL, si la cantidad es menor a 0 o, si no se encontro ese id en la lista. De lo contrario, retorna 1
 *
 */
int cargarDescripcionTipo(eTipo listaDeTipos[],int cantidad,int idRecibido,char descripcionDevuelta[]);


/** \brief Recorre la lista, analizando si, el id recibido existe
 *
 * \param listaDetipos[] eTipo Lista de tipos recibida.
 * \param cantidad int tam de la lista de tipos.
 * \param idRecibido int Id recibido a buscar
 * \return int Retorna -1 si, el puntero es NULL, si la cantidad es menor a 0 o, si no se encontro ese id en la lista. De lo contrario, retorna 1
 *
 */
int validarTipo(eTipo listaDetipos[], int cantidad,int idRecibido);

#endif // TIPO_H_INCLUDED
