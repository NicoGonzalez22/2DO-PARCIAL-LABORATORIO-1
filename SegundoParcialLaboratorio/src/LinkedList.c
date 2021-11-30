#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this=(LinkedList*)malloc(sizeof(LinkedList));
    if(this!=NULL)
    {
    	this->size=0;
    	this->pFirstNode=NULL;
    }
    return this;
}

int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
    	returnAux=this->size;
    }
    return returnAux;
}

static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* node=NULL;
	int len=ll_len(this);
	if(this!=NULL && nodeIndex>=0&& nodeIndex<len)
	{
		node=this->pFirstNode;
		for(int i =0;i<nodeIndex;i++)
		{
			node= node->pNextNode;
		}
	}
    return node;
}

static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{

	Node* node;
	Node* nodeAnterior;
	//Node* nodeSiguiente;
    int returnAux=-1;
    int len=ll_len(this);

    if(this!=NULL && nodeIndex>=0 &&nodeIndex<=len)
    {
    	node=(Node*)malloc(sizeof(Node));
    	if(nodeIndex==0)
    	{
    		node->pNextNode=this->pFirstNode; // Guardo la direccion de memoria del primer nodo en nextNode del nodo nuevo
    		this->pFirstNode=node; // Al primer nodo de la lista le guardo la direccion de memoria del nodo nuevo
    	}else
    	{
    		nodeAnterior=getNode(this, nodeIndex-1); // Busco el nodo anterior del que busco
    		node->pNextNode=nodeAnterior->pNextNode; //Al nextNode del nodo nuevo le asigno el valor del nextNode del nodeAux que seria el anterior del que busco
    		nodeAnterior->pNextNode=node; // Una vez guardado la direccion de mmoria de nextNode del nodeAux, asigno el nuevo nodo
    	}
  	    node->pElement=pElement;
    	returnAux=0;
    	this->size++;

    }

    return returnAux;
}

int ll_add(LinkedList* this, void* pElement)
{
    return addNode(this,ll_len(this),pElement);
}

void* ll_get(LinkedList* this, int index)
{
	Node* nodo=NULL;
    void* returnAux = NULL;

    if(this!=NULL && (index >= 0 && index<ll_len(this)))
    {
    	nodo=getNode(this, index);
    	if(nodo!=NULL)
    	{
    		returnAux=nodo->pElement;
    	}
    }
    return returnAux;
}

int ll_set(LinkedList* this, int index,void* pElement)
{
	Node* auxNode;
    int returnAux = -1;

    if(this!=NULL&&index>=0&&index<ll_len(this))
    {	auxNode=getNode(this, index);
    	if(auxNode!=NULL)
		{
			auxNode->pElement=pElement;
			returnAux=0;
    	}
    }
    return returnAux;
}

int ll_remove(LinkedList* this,int index)
{

	int returnAux = -1;
	Node* node;
	Node* nodeAnt;
	Node* nodeSig;
    if(this!=NULL&&index>=0&&index<ll_len(this))
    {
    	node=getNode(this, index);
    	nodeSig=getNode(this, index+1);
    	if(index==0)
    	{
    		this->pFirstNode=nodeSig;
    	}else
    	{
    		nodeAnt=getNode(this, index-1);
    		nodeAnt->pNextNode=nodeSig;
    	}
		free(node);
		returnAux=0;
		this->size--;
    }
    return returnAux;
}

int ll_clear(LinkedList* this)
{

	int returnAux=-1;
    int len;
    if(this!=NULL)
    {
    	len=ll_len(this);
    	if(len!=0)
    	{
			for(int i=0;i<len;i++)
			{
				ll_remove(this,0);
			}
			returnAux=0;
    	}
    }
    return returnAux;
}

int ll_deleteLinkedList(LinkedList* this)
{
	int returnAux=-1;
	if(this!=NULL)
	{
		for(int i =0; i < ll_len(this);i++)
		{
			ll_clear(this);
		}
		free(this);
		returnAux=0;
	}
    return returnAux;
}

int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    void* node;


    if(this!=NULL)
    {
    	for(int i=0;i<ll_len(this);i++)
    	{
    		node=ll_get(this, i); // usar la funcion get
    		if(node==pElement)
    		{
    			returnAux=i;
    			break;
    		}
    	}
    }
    return returnAux;
}

int ll_isEmpty(LinkedList* this)
{
	int returnAux=-1;
	if(this!=NULL)
	{
		returnAux=1;
		if(ll_len(this)>0)
		{
			returnAux=0;
		}
	}
    return returnAux;
}

int ll_push(LinkedList* this, int index, void* pElement)
{
    return addNode(this, index, pElement);
}

void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this!=NULL&&index>=0&&index<=ll_len(this))
    {
    	returnAux=ll_get(this, index);
    	ll_remove(this, index);
    }
    return returnAux;
}

int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	returnAux=0;
    	if(!ll_isEmpty(this))
    	{
    		returnAux=0;
    		for(int i=0;i<ll_len(this);i++)
    		{
    			if(ll_indexOf(this, pElement)==i)
    			{
    				returnAux=1;
    				break;
    			}
    		}
    	}
    }
    return returnAux;
}

int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux =-1;
    void* pElement;

    if(this!=NULL&&this2!=NULL)
    {
    	returnAux=0;
    	for(int i=0; i<ll_len(this2);i++)
    	{
    		pElement=ll_get(this2, i);
    		if((ll_contains(this,pElement))!=1)
    		{
    			returnAux=0;
    			break;
    		}
    	}
    }
    return returnAux;
}

LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pElement;
    int len=ll_len(this);
    if(this!=NULL&&from>=0&&from<=len&&to>from&&to<=len)
    {
    	cloneArray=ll_newLinkedList();
    	for(int i=from;i<to;i++)
    	{
    		pElement=ll_get(this, i);
    		ll_add(cloneArray, pElement);
    	}
    }
    return cloneArray;
}

LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this!=NULL)
    {
    	cloneArray=ll_subList(this,0,ll_len(this));
    }
    return cloneArray;
}

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;

    void* ElementoNodeUno=NULL;
    void* ElementoNodeDos=NULL;
    int len;

    if (this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
    	len = ll_len(this);
        for(int i=0;i<len;i++)
        {
        	for(int j=i+1;j<len;j++)
        	{
        		ElementoNodeUno=ll_get(this,i);
        		ElementoNodeDos=ll_get(this,j);
        		if(order==0&&(pFunc(ElementoNodeUno,ElementoNodeDos))==-1)
        		{
        			ll_set(this,i,ElementoNodeDos);
        			ll_set(this,j,ElementoNodeUno);
        		}
        		else if(order==1&&(pFunc(ElementoNodeUno,ElementoNodeDos))==1)
        		{
        			ll_set(this, i,ElementoNodeDos);
        			ll_set(this,j,ElementoNodeUno);
        		}
        	}
        }
        returnAux = 0;
    }
    return returnAux;
}


LinkedList* ll_filter(LinkedList* this,int(*fn)(void* element))
{
	LinkedList* ListaFiltrada;
	void* libro;
	if(this!=NULL&&fn!=NULL)
	{
		ListaFiltrada=ll_newLinkedList();
		for(int i=0;i<ll_len(this);i++)
		{
			libro=(eLibro*)ll_get(this, i);
			if((fn(libro))==1)
			{
				ll_add(ListaFiltrada, libro);
			}
		}
	}
	return ListaFiltrada;
}


int ll_count(LinkedList* this,int(*fn)(void* element))
{
	int contador=0;
	void* libro;
	for(int i=0;i<ll_len(this);i++)
	{
		libro=(eLibro*)ll_get(this, i);
		if((fn(libro))==1)
		{
			contador++;
		}
	}
	return contador;
}


void ll_map(LinkedList*this,int(*fn)(void* ))
{

	if(this!=NULL)
	{
		for(int i=0;i<ll_len(this);i++)
		{
			fn(ll_get(this, i));
		}
	}
}



