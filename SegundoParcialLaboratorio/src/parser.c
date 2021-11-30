#include "parser.h"

int parser_LibrosFromText(FILE* pFile , LinkedList* listaLibros)
{
	int retorno=-1;
	eLibro* libro;
	char id[20];
	char titulo[100];
	char autor[100];
	char precio[20];
	char idEditorial[20];

	if(pFile!=NULL&&listaLibros!=NULL)
	{

		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,titulo,autor,precio,idEditorial);

			libro = libro_NuevoConParametros(id, titulo, autor, precio,idEditorial);
			if(libro!=NULL&&libro->id!=0)
			{
				ll_add(listaLibros,libro);
			}
		}
		retorno=0;
	}
    return retorno;
}

int parser_EditorialesFromText(FILE* pFile , LinkedList* listaEditoriales)
{
	int retorno=-1;
	eEditorial* editorial;
	char idEditorial[20];
	char nombreEditorial[100];
	if(pFile!=NULL&&listaEditoriales!=NULL)
	{

		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^\n]\n",idEditorial,nombreEditorial);

			editorial = editorial_nuevaConParametros(idEditorial, nombreEditorial);
			if(editorial!=NULL&&editorial->idEditorial!=0)
			{
				ll_add(listaEditoriales,editorial);
			}
		}
		retorno=0;
	}
    return retorno;
}

int controlador_GuardarLista(char* path , LinkedList* lista)
{
    FILE* pArchivo;
    int len;
    eLibro* libro;
    len = ll_len(lista);
    pArchivo = fopen(path,"w");
    if (pArchivo == NULL)
    {
        pArchivo = fopen(path,"w");
    }
    if (len>0)
    {
        for (int i=0;i<len;i++)
        {
        libro = ll_get(lista,i);
        fprintf(pArchivo,"%d,%s,%s,%d,%d\n",libro->id,libro->titulo,libro->autor,libro->precio,libro->idEditorial);
        }
    }
    fclose(pArchivo);
    return 1;
}
