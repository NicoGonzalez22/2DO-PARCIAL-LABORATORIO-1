#include <stdio.h>
#include <stdlib.h>
#include "biblotecaMia.h"
#include "controladores.h"
int main(void) {
	setbuf(stdout,NULL);
	char archivoLibro[40];
	char archivoEditorial[40];
	int contadorLibro=0;
	int contadorEditorial=0;
	LinkedList* listaLibros=ll_newLinkedList();
	LinkedList* listaEditoriales=ll_newLinkedList();
	LinkedList* listaFiltrada=ll_newLinkedList();
	LinkedList* listaConDescuentos=ll_newLinkedList();
	int opcion;

	do
	{
		printf("1-Cargar libros\n"
				"2-Cargar editoriales\n"
				"3-Ordenar lista de libros por Autor, de mandea ascendente\n"
				"4-Lista Libros\n"
				"5-Guardar lista con libros editorial 'MINOTAURO' \n"
				"6-Aplicar descuentos para las editoriales PLANETA y SIGLO XXI EDITORES\n");

		opcion=CargarEnteroConMaxYMin("Ingrese la opcion que desee", "ERROR!Ingrese nuevamente la opcion que desee", 1, 10);

		switch(opcion)
		{
		case 1:
			if((CargarNombreArchivoLibro(archivoLibro))==0&&contadorLibro==0)
			{
				controlador_CargarLibros(archivoLibro, listaLibros);
				contadorLibro++;
			}
			break;
		case 2:
			if((CargarNombreArchivoEditoriales(archivoEditorial))==0&&contadorEditorial==0)
			{
				controlador_CargarEditoriales(archivoEditorial, listaEditoriales);
				contadorEditorial++;
			}
			break;
		case 3:
			if(contadorLibro==1&&contadorEditorial==1)
			{
				ll_sort(listaLibros, compararPorNombres, 1);
			}else
			{
				printf("Primero debe cargar el archivo de libros y de editoriales\n");
			}
			break;
		case 4:
			if(contadorLibro==1&&contadorEditorial==1)
			{
				controlador_ImprimirListaLibros(listaLibros, listaEditoriales);
			}else
			{
				printf("Primero debe cargar el archivo de libros y de editoriales\n");
			}
			break;
		case 5:
			if(contadorLibro==1&&contadorEditorial==1)
			{
			listaFiltrada=(LinkedList*)ll_filter(listaLibros,filtrarEditorialMINOTAURO);
			controlador_GuardarLista("ListaFiltrada.csv", listaFiltrada);
			}else
			{
				printf("Primero debe cargar el archivo de libros y de editoriales\n");
			}
			break;
		case 6:
			if(contadorLibro==1&&contadorEditorial==1)
			{
				AplicarDescuentos(listaLibros, listaEditoriales);
			}else
			{
				printf("Primero debe cargar el archivo de libros y de editoriales\n");
			}
			break;
		case 7:
			controlador_CargarLibros("mapeado.csv", listaConDescuentos);
			controlador_ImprimirListaLibros(listaConDescuentos, listaEditoriales);
			break;

		}
	}while(opcion>0&&opcion<11);
	return EXIT_SUCCESS;
}
