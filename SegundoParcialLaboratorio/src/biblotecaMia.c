#include "biblotecaMia.h"

char PedirString(char cadena[],char mensaje[])
{
	printf("%s",mensaje);
	//fflush(stdin);
	scanf("%s",cadena);
	return *cadena;
}

int ValidarString(char nombre[])
{
	int valido;
	int i;
	int j;
	j=0;
	i=0;
	valido=1;
	while(nombre[j]!='\0')
	{
		nombre[j]=tolower(nombre[j]);
		j++;
	}

	while(nombre[i]!='\0'&&(valido==1))
	{
		if(isalpha(nombre[i])!=0||nombre[i]=='?')
		{
			valido=1;
		}else
		{
			valido=0;
		}
		i++;
	}
	return valido;
}

int CargarString(char nombre[],char mensaje[],char mensajeError[])
{
	int retorno=1;;
	if(mensaje!=NULL&&mensajeError!=NULL)
	{
		*nombre=PedirString(nombre,mensaje);

		while(ValidarString(nombre)==0)
		{
			*nombre=PedirString(nombre,mensajeError);
		}
		retorno=0;
	}
	return retorno;
}

int CargarEnteroChar(char entero[],char mensaje[],char mensajeError[])
{
	int retorno=-1;
	if(mensaje!=NULL&&mensajeError!=NULL)
	{
		PedirString(entero,mensaje);

		while(ValidarEntero(entero)==0)
		{
			PedirString(entero,mensajeError);
		}
		 retorno=0;
	}
	return retorno;
}

int ValidarEntero(char numero[])
{
	int i=0;
	int valido;
	valido=1;
	while(numero[i]!='\0'&&(valido==1))
	{
		if(isdigit(numero[i])!=0)
		{
			valido=1;
		}else
		{
			valido=0;
		}

		i++;
	}
	return valido;
}
int CargarEntero(char mensaje[],char mensajeError[])
{
	char entero[50];
	int enteroFinal;
	if(mensaje!=NULL&&mensajeError!=NULL)
	{
		PedirString(entero,mensaje);
		while(ValidarEntero(entero)==0)
		{
			PedirString(entero,mensajeError);
		}
		 enteroFinal=atoi(entero);
	}
	return enteroFinal;
}

int CargarEnteroConMaxYMin(char mensaje[],char mensajeError[],int min,int max)
{
	char entero[50];
	int enterofinal;
	int valido;
	valido=1;
	if(mensaje!=NULL&&mensajeError!=NULL&&min<max)
	{
		while(valido>0)
		{

			PedirString(entero,mensaje);
			while(ValidarEntero(entero)==0)
			{
				PedirString(entero,mensajeError);
			}
			enterofinal=atoi(entero);
			if(enterofinal<min||enterofinal>max)
			{
				valido=2;
			}else
			{
				valido=0;
			}
		}

	}
	return enterofinal;
}

void ImprimirCincoDatosPrimeroIntUltimosDosInt(int datoUno,char datoDos[],char datoTres[],int datoCuatro,int datoCinco)
{
	printf("|%15d |%15s |%20s |%15d |%15d|\n",datoUno,datoDos,datoTres,datoCuatro,datoCinco);
}

void ImprimirCincoDatosString(char datoUno[],char datoDos[],char datoTres[],char datoCuatro[],char datoCinco[])
{
	printf("|%15s |%15s |%20s |%15s |%15s|\n",datoUno,datoDos,datoTres,datoCuatro,datoCinco);
}

void ImprimirDosDatos(char datoUno[],char datoDos[])
{
	printf("|%15s |%15s |\n",datoUno,datoDos);
}

void ImprimirDosDatosPrimeroIntSegundoChar(int datoUno,char datoDos[])
{
	printf("|%15d |%15s |\n",datoUno,datoDos);
}
