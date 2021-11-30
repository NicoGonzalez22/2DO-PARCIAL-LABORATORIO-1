/*
 * Libros.h
 *
 *  Created on: 29 nov 2021
 *      Author: Usuario
 */

#ifndef LIBROS_H_
#define LIBROS_H_
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Editoriales.h"
typedef struct
{
	int id;
	char titulo[100];
	char autor[100];
	int precio;
	int idEditorial;
}eLibro;

eLibro* libro_nuevo();
eLibro* libro_NuevoConParametros(char* id,char* titulo,char* autor,char* precio,char* idEditorial);

/// @fn int CargarNombreArchivoLibro(char*)
/// @brief  recibe por parametro un string y lo compara segun el criterio dentro de la funcion
///
/// @param archivo Nombre del archivo a comparar
/// @return retorna 0 si son iguales, -1 si no son iguales
int CargarNombreArchivoLibro(char* archivo);


int libros_ObetenerId(eLibro* libros,int* id);
int libros_ObetenerTitulo(eLibro* libros,char* titulo);
int libros_ObetenerAutor(eLibro* libros,char* autor);
int libros_ObetenerPrecio(eLibro* libros,int* precio);
int libros_ObetenerIdEditorial(eLibro* libros,int* idEditorial);

int libros_EstablecerId(eLibro* libros,int id);
int libros_EstablecerTitulo(eLibro* libros,char* titulo);
int libros_EstablecerAutor(eLibro* libros,char* autor);
int libros_EstablecerPrecio(eLibro* libros,int precio);
int libros_EstablecerIdEditorial(eLibro* libros,int idEditorial);

/// @fn int filtrarEditorialMINOTAURO(void*)
/// @brief  recibe por parametro un elemento que comprara si contiene el id de la editorial MINOTAURO
///
/// @param elemento
/// @return retorna 1 si lo tiene o 0 si no lo tiene
int filtrarEditorialMINOTAURO(void* elemento);


///@fn int compararPorNombres(void*, void*)
/// @brief Compara dos nombres de los elementos recibidos por parametro
///
/// @param elementoUno elemento Uno
/// @param elementoDos elemento Dos
/// @return retorna <0 si el elemento Uno es menor que el elemento dos ==0 si son iguales o >0 si el elemento dos es mas grande que el elemento uno
int compararPorNombres(void* elementoUno,void*elementoDos);


/// @fn int contarCantidadDeEditorial(void*)
/// @brief
///
/// @param element
/// @return
int contarCantidadDeEditorial(void* element);

/// @fn int DeterminarDescuento(void*)
/// @brief  recibe un elemento y compara los datos de este, si los datos recibidos son los necesarios para aplicar el descuento
/// hace la operacion necesaria el aplica el descuento
/// @param element
/// @return retorna -1 si no fue efecuado ningun descuento o 0 si fue efectuado algun descuento
int DeterminarDescuento(void* element);


#endif /* LIBROS_H_ */
