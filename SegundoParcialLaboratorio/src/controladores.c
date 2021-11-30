#ifndef CONTROLADORES_C_
#define CONTROLADORES_C_
#include "controladores.h"


int controlador_CargarLibros(char* pFile, LinkedList* listaLibros)
{
	int retorno;
	FILE* archivo;
	archivo=fopen(pFile,"r");

	if(archivo!=NULL)
	{
		parser_LibrosFromText(archivo, listaLibros);
		printf("Datos cargados con exito!\n");
		retorno=0;
		fclose(archivo);
	}else
	{
		retorno=-1;
		printf("No se puede abrir el archivo! :c\n");
	}
	return retorno;
}

int controlador_CargarEditoriales(char* pFile,LinkedList* listaEditoriales)
{
	int retorno;
	FILE* archivo;
	archivo=fopen(pFile,"r");
	if(archivo!=NULL)
	{
		parser_EditorialesFromText(archivo, listaEditoriales);
		printf("Datos cargados con exito!\n");
		retorno=0;
		fclose(archivo);
	}else
	{
		retorno=-1;
		printf("No se puede abrir el archivo! :c\n");
	}
	return retorno;
}

int controlador_ImprimirListaLibros(LinkedList* listaLibros,LinkedList* listaEditoriales)
{
	eLibro* libro;
	eEditorial* editorial;
	int retorno;
	retorno=-1;
	if(listaLibros!=NULL&&listaEditoriales!=NULL)
	{
		printf("ID LIBRO|                NOMBRE LIBRO             |              AUTOR            |   PRECIO  |       EDITORIAL     |\n");
		for(int i=0;i<ll_len(listaLibros);i++)
		{
			libro=ll_get(listaLibros, i);
			for(int j=0;j<ll_len(listaEditoriales);j++)
			{
				editorial=ll_get(listaEditoriales,j);
				if(editorial->idEditorial==libro->idEditorial)
				{
					break;
				}
			}
			printf("%8d| %40s| %30s| %10d| %20s|\n",libro->id,libro->titulo,libro->autor,libro->precio,editorial->nombreEditorial);
		}
		retorno=0;
	}
	return retorno;
}


void AplicarDescuentos(LinkedList* listaLibros,LinkedList* editoriales)
{
	LinkedList* listaAux;
	if(listaLibros!=NULL&&editoriales!=NULL)
	{
	listaAux=ll_clone(listaLibros);
	ll_map(listaAux,DeterminarDescuento);
	controlador_GuardarLista("mapeado.csv", listaAux);
	}
}



#endif /* CONTROLADORES_C_ */
