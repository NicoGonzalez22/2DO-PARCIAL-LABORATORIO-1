#include "Libros.h"

eLibro* libro_nuevo()
{
	eLibro* libro=NULL;
	libro=(eLibro*)malloc(sizeof(eLibro));
	return libro;
}
eLibro* libro_NuevoConParametros(char* id,char* titulo,char* autor,char* precio,char* idEditorial)
{
	eLibro* libro=libro_nuevo();
	if(libro!=NULL)
	{
		libro->id=atoi(id);
		strcpy(libro->titulo,titulo);
		strcpy(libro->autor,autor);
		libro->precio=atoi(precio);
		libro->idEditorial=atoi(idEditorial);
	}
	return libro;
}

int CargarNombreArchivoLibro(char archivo[])
{
	int retorno=-1;
	printf("ARCHIVOS DISPONIBLES: \n"
			"-->Libros\n"
			"-->Editoriales\n");
	CargarString(archivo, "Ingrese el nombre del archivo que desee: ","ERROR! Ingrese nuevamente el nombre del archivo: ");
	strcat(archivo,".csv");
	if(strcmp(archivo,"libros.csv")==0)
	{
		retorno=0;
	}
	while(strcmp(archivo,"libros.csv")!=0)
	{
		CargarString(archivo, "El nombre que ingreso, no pertenece a ningun archivo, ingrese nuevamente: : ","ERROR! Ingrese nuevamente el nombre del archivo: ");
		strcat(archivo,".csv");
		retorno=0;
	}
	return retorno;
}



int libros_ObetenerId(eLibro* libros,int* id)
{
	int retorno=-1;
	if(libros!=NULL&&id!=NULL)
	{
		retorno=0;
		*id=libros->id;
	}
	return retorno;
}

int libros_ObetenerTitulo(eLibro* libros,char* titulo)
{
	int retorno=-1;
	if(libros!=NULL&&titulo!=NULL)
	{
		retorno=0;
		strcpy(titulo,libros->titulo);
	}
	return retorno;
}

int libros_ObetenerAutor(eLibro* libros,char* autor)
{
	int retorno=-1;
	if(libros!=NULL&&autor!=NULL)
	{
		retorno=0;
		strcpy(autor,libros->autor);
	}
	return retorno;
}

int libros_ObetenerPrecio(eLibro* libros,int* precio)
{
	int retorno=-1;
	if(libros!=NULL&&precio!=NULL)
	{
		retorno=0;
		*precio=libros->precio;
	}
	return retorno;
}

int libros_ObetenerIdEditorial(eLibro* libros,int* idEditorial)
{
	int retorno=-1;
	if(libros!=NULL&&idEditorial!=NULL)
	{
		retorno=0;
		*idEditorial=libros->idEditorial;
	}
	return retorno;
}

int libros_EstablecerId(eLibro* libros,int id)
{
	int retorno=-1;
	if(libros!=NULL)
	{
		retorno=0;
		libros->id=id;
	}
	return retorno;
}

int libros_EstablecerTitulo(eLibro* libros,char* titulo)
{
	int retorno=-1;
	if(libros!=NULL&&titulo!=NULL)
	{
		retorno=0;
		strcpy(libros->titulo,titulo);
	}
	return retorno;
}

int libros_EstablecerAutor(eLibro* libros,char* autor)
{
	int retorno=-1;
	if(libros!=NULL&&autor!=NULL)
	{
		retorno=0;
		strcpy(libros->titulo,autor);
	}
	return retorno;
}

int libros_EstablecerPrecio(eLibro* libros,int precio)
{
	int retorno=-1;
	if(libros!=NULL)
	{
		retorno=0;
		libros->precio=precio;
	}
	return retorno;
}

int libros_EstablecerIdEditorial(eLibro* libros,int idEditorial)
{
	int retorno=-1;
	if(libros!=NULL)
	{
		retorno=0;
		libros->idEditorial=idEditorial;
	}
	return retorno;
}


int filtrarEditorialMINOTAURO(void* elemento)
{
	int retorno=0;
	eLibro* libroAux;
	if(elemento!=NULL)
	{
		libroAux=(eLibro*)elemento;
		if(libroAux->idEditorial==4)
		{
			retorno=1;
		}
	}
	return retorno;
}

int compararPorNombres(void* elementoUno,void*elementoDos)
{
		eLibro* libroUno;
		eLibro* libroDos;
	if(elementoUno!=NULL&&elementoDos!=NULL)
	{
		libroUno=(eLibro*)elementoUno;
		libroDos=(eLibro*)elementoDos;
	}
	return strcmp(libroUno->autor,libroDos->autor);
}

int contarCantidadDeEditorial(void* element)
{
	int retorno=0;
	eLibro* libro=(eLibro*)element;
	if(libro->idEditorial==4)
	{
		retorno=1;
	}
	return retorno;
}



int DeterminarDescuento(void* element)
{
	int retorno=0;
	eLibro* libro;
	libro=(eLibro*)element;
	int descuento=0;
	int aplicarDescuento;
	if(libro->idEditorial==1&&libro->precio>=300)
	{
		descuento=20;
		retorno=1;
	}else
	{
		if(libro->idEditorial==2&&libro->precio>=200)
		{
			descuento=10;
			retorno=1;
		}
	}
	if(descuento!=0)
	{
	aplicarDescuento=(libro->precio*descuento)/100;
	libro->precio=libro->precio-aplicarDescuento;
	}
	return retorno;
}
