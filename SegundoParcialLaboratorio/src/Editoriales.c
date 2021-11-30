#include "Editoriales.h"

eEditorial* editorial_nueva()
{
	eEditorial* editorial=NULL;
	editorial=(eEditorial*)malloc(sizeof(eEditorial));
	return editorial;
}

eEditorial* editorial_nuevaConParametros(char* idEditorial,char* nombreEditorial)
{
	eEditorial* editorial=editorial_nueva();
	if(editorial!=NULL)
	{
		editorial->idEditorial=atoi(idEditorial);
		strcpy(editorial->nombreEditorial,nombreEditorial);
	}
	return editorial;
}

int editorial_ObtenerIdEditorial(eEditorial* editoriales,int* idEditorial)
{
	int retorno=-1;
	if(editoriales!=NULL&&idEditorial!=NULL)
	{
		retorno=0;
		*idEditorial=editoriales->idEditorial;
	}
	return retorno;
}


int CargarNombreArchivoEditoriales(char archivo[])
{
	int retorno=-1;
	printf("ARCHIVOS DISPONIBLES: \n"
			"-->Libros\n"
			"-->Editoriales\n");
	CargarString(archivo, "Ingrese el nombre del archivo que desee: ","ERROR! Ingrese nuevamente el nombre del archivo: ");
	strcat(archivo,".csv");
	if(strcmp(archivo,"editoriales.csv")==0)
	{
		retorno=0;
	}
	while(strcmp(archivo,"editoriales.csv")!=0)
	{
		CargarString(archivo, "El nombre que ingreso, no pertenece a ningun archivo, ingrese nuevamente: : ","ERROR! Ingrese nuevamente el nombre del archivo: ");
		strcat(archivo,".csv");
		retorno=0;
	}
	return retorno;
}

int editorial_ObtenerNombreEditorial(eEditorial* editoriales,char* nombreEditorial)
{
	int retorno=-1;
	if(editoriales!=NULL&&nombreEditorial!=NULL)
	{
		retorno=0;
		strcpy(nombreEditorial,editoriales->nombreEditorial);
	}
	return retorno;
}

int editorial_EstablecerIdEditorial(eEditorial* editoriales,int idEditorial)
{
	int retorno=-1;
	if(editoriales!=NULL)
	{
		retorno=0;
		editoriales->idEditorial=idEditorial;
	}
	return retorno;
}
int editorial_EstablecerNombreEditorial(eEditorial* editoriales,char* nombreEditorial)
{
	int retorno=-1;
	if(editoriales!=NULL&&nombreEditorial!=NULL)
	{
		retorno=0;
		strcpy(editoriales->nombreEditorial,nombreEditorial);
	}
	return retorno;
}



