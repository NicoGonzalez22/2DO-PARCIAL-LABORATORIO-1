#ifndef CONTROLADORES_H_
#define CONTROLADORES_H_
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

/// @fn int controlador_CargarLibros(char*, LinkedList*)
/// @brief lee los datos del archivo libros y los guarda en una linkedlist
///
/// @param pFile
/// @param listaLibros
/// @return retorna 0 si pudo hacer todos bien o -1 si algo fallo
int controlador_CargarLibros(char* pFile, LinkedList* listaLibros);

/// @fn int controlador_CargarEditoriales(char*, LinkedList*)
/// @brief lee los datos del archivo editoriales y los guarda en una linkedlist
///
/// @param pFile
/// @param listaEditoriales
/// @return retorna 0 si pudo hacer todos bien o -1 si algo fallo
int controlador_CargarEditoriales(char* pFile,LinkedList* listaEditoriales);


/// @fn int controlador_ImprimirListaLibros(LinkedList*, LinkedList*)
/// @brief Imprime los datos de los libros con los nombres de las editoriales segun el idEditorial del libro
///
/// @param listaLibros
/// @param listaEditoriales
/// @return 0 salio todo bien , -1 lista null o algun fallo
int controlador_ImprimirListaLibros(LinkedList* listaLibros,LinkedList* listaEditoriales);


/// @fn int controlador_GuardarLista(char*, LinkedList*)
/// @brief Guarda la lista recibida por parametro en un archivo con el nombre recibido por parametro
///
/// @param path nombre del archivo
/// @param lista lista a guardar
/// @return
int controlador_GuardarLista(char* path , LinkedList* lista);


/// @fn void AplicarDescuentos(LinkedList*, LinkedList*)
/// @brief Utiliza las listas recibidas por parametro para aplicar los descuentos segun los id
/// de los libros y guarda la lista completa con todos los descuentos incluidos en un archivo mapeado.csv
/// @param listaLibros
/// @param editoriales
void AplicarDescuentos(LinkedList* listaLibros,LinkedList* editoriales);

#endif /* CONTROLADORES_H_ */
