#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

/** \brief Compara 2 fechas analizando si son iguales.
 *
 * \param f1 eFecha fecha 1 recibida
 * \param f2 eFecha fecha 2 recibida
 * \return int Devuelve 1 si, son iguales, de lo contrario, devuelve 0
 *
 */
int compararFecha(eFecha f1, eFecha f2);



/** \brief Muestra una fecha
 *
 * \param fecha eFecha Fecha recibida
 * \return void
 *
 */
void mostrarFecha(eFecha fecha);



#endif // FECHA_H_INCLUDED
