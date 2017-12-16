/*
IMPLEMENTACION DE LA LIBRERIA DEL TAD COLA ESTATICA (TADColaEst.h)
AUTOR: Edgardo Adrián Franco Martínez (C) Septiembre 2013
VERSIÓN: 1.4

DESCRIPCIÓN: TAD cola o Queue.
Estructura de datos en la que se cumple:
Los elementos se insertan en un extremo (el posterior) y 
la supresiones tienen lugar en el otro extremo (frente).

OBSERVACIONES: Hablamos de una Estructura de datos estática cuando 
se le asigna una cantidad fija de memoria para esa estructura 
antes de la ejecución del programa. 

COMPILACIÓN PARA GENERAR EL CÓDIGO OBJETO: gcc -c TADColaEst.c
*/

//LIBRERAS
#include "TADColaEst.h"
#include<stdlib.h>

//DEFINICIÓN DE FUNCIONES

/*
void Initialize(cola *c);
Descripción: Inicializar cola (Iniciar una cola para su uso)
Recibe: cola *c (Referencia a la cola "c" a operar)
Devuelve:
Observaciones: El usuario a creado una cola y c tiene la referencia a ella, 
si esto no ha pasado se ocasionara un error.
*/
void Initialize(cola * c)
{
	c->frente = -1;
	c->final = -1;
	c->num_elem=0;
	return;
}

/*
void Queue(cola * c, elemento e);
Descripción: Recibe una cola y agrega un elemento al final de ella.
Recibe: cola *c (Referencia a la cola "c" a operar) elemento e (Elemento a encolar)
Devuelve:
Observaciones: El usuario a creado una cola y ha sido inicializada y c tiene la referencia a ella, 
si esto no ha pasado se ocasionara un error.
*/
void Queue(cola * c, elemento e)
{
	//Si la cola esta vacia
	if (c->frente == -1 && c-> final == -1)
	{
		c->frente++;
		c->final++;
		c->elementos[c->final] = e;		
	}
	//Si la cola aún no se desborda
	else if(c->final+1!=MAX_ELEMENT)
	{
		c->final++;
		c->elementos[c->final] = e;
	}
	//Si la cola se desborda
	else
	{
		printf("\nERROR: Desbordamiento de cola");
		exit(1);
	}	
	
	//Incrementar el número de elementos en la cola 
	c->num_elem++;
	
	return;
}

/*
elemento Dequeue(cola * c);
Descripción: Recibe una cola y devuelve el elemento que se encuentra al 
frente de esta, quitándolo de la cola.
Recibe: cola *c (Referencia a la cola "c" a operar)
Devuelve: elemento (Elemento desencolado)
Observaciones: El usuario a creado una cola y la cola tiene elementos, si no 
se genera un error y se termina el programa.
*/
elemento Dequeue(cola * c)
{
	int i;
	elemento e;//Elemento a retornar 
	
	//Si la cola esta vacia (Subdesbordamiento de cola)
	if(c->frente==-1&&c->final==-1)
	{
		printf("\nERROR:Subdesbordamiento de cola");
		exit(1);
	}
	//Si la cola tiene elementos
	else
	{
		//Guardar el elemento a retornar
		e = c->elementos[c->frente];
		
		//Recorrer los elementos del arreglo (Avanzar los elementos de la cola)
		for (i = c->frente; i < c->final; i++)
		{
			c->elementos[i] = c->elementos[i + 1];
		}
		
		//Restar uno al indice final de la cola
		c->final--;
		
		//Si la cola queda vacia (c->final era 0 y paso a -1)
		if (c->final == -1)
		{
			c->frente = -1; //Colocar el frente en -1 para indicar una cola vacia
		}
	}
	//Decrementar el número de elementos en la cola 
	c->num_elem--;
	
	//Retornar al elemento
	return e;
}

/*
boolean Empty(cola * c);
Descripción: Recibe una cola y TRUE si la cola esta vacia y FALSE en caso contrario
Recibe: cola *c (Referencia a la cola "c" a verificar)
Devuelve: boolean TRUE O FALSE
Observaciones: El usuario a creado una cola y la cola fue correctamente inicializada
*/
boolean Empty(cola * c)
{
	return (c->frente == -1 && c->final == -1) ? TRUE : FALSE;
}

/*
elemento Front(cola * c);
Descripción: Recibe una cola y devuelve el elemento que se encuentra al frente de esta.
Recibe: cola *c (Referencia a la cola "c")
Devuelve: elemento del frente de la cola
Observaciones: El usuario a creado una cola,la cola fue correctamente inicializada, esta 
tiene elementos de lo contrario devolvera ERROR. *No se modifica el TAD
*/
elemento Front(cola * c)
{
	return c->elementos[c->frente];
}

/*
elemento Final(cola * c);
Descripción: Recibe una cola y devuelve el elemento que se encuentra al final de esta.
Recibe: cola *c (Referencia a la cola "c")
Devuelve: elemento del final de la cola
Observaciones: El usuario a creado una cola,la cola fue correctamente inicializada, esta 
tiene elementos de lo contrario devolvera ERROR. *No se modifica el TAD
*/
elemento Final(cola * c)
{
	return c->elementos[c->final];
}

/*
int Size(cola * c);
Descripción: Recibe una cola y devuelve el número de elemento que se encuentran en esta.
Recibe: cola *c (Referencia a la cola "c")
Devuelve: int (Tamaño de la cola)
Observaciones: El usuario a creado una cola,la cola fue correctamente inicializada, esta 
*No se modifica el TAD
*/
int Size(cola * c)
{
	return c->num_elem;
}

/*
void Destroy(cola * c);
Descripción: Recibe una cola y la libera completamente.
Recibe: cola *c (Referencia a la cola "c" a operar)
Devuelve:
Observaciones: La cola se destruye y se inicializa.
*/
void Destroy(cola * c)
{
	c->frente = c->final = -1;
	c->num_elem=0;
}