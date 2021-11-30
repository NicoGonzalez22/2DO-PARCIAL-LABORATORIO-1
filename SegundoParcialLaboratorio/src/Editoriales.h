#ifndef EDITORIALES_H_
#define EDITORIALES_H_
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "biblotecaMia.h"
typedef struct
{
	int idEditorial;
	char nombreEditorial[100];
}eEditorial;

eEditorial* editorial_nueva();
eEditorial* editorial_nuevaConParametros(char* idEditorial,char* nombreEditorial);

/// @fn int CargarNombreArchivoLibro(char*)
/// @brief  recibe por parametro un string y lo compara segun el criterio dentro de la funcion
///
/// @param archivo Nombre del archivo a comparar
/// @return retorna 0 si son iguales, -1 si no son iguales
int CargarNombreArchivoEditoriales(char* archivo);

int editorial_ObtenerIdEditorial(eEditorial* editoriales,int* idEditorial);
int editorial_ObtenerNombreEditorial(eEditorial* editoriales,char* nombreEditorial);

int editorial_EstablecerIdEditorial(eEditorial* editoriales,int idEditorial);
int editorial_EstablecerNombreEditorial(eEditorial* editoriales,char* nombreEditorial);

#endif /* EDITORIALES_H_ */
