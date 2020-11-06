#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

#define SIN_ERROR 0
#define ERROR -1

lista_t* lista_crear(){
    lista_t* lista = malloc(sizeof(lista_t));
    if(!lista)
        return NULL;
    lista->cantidad = 0;
    lista->nodo_inicio = NULL;
    lista->nodo_fin = NULL;
    return lista;
}

int lista_insertar(lista_t* lista, void* elemento){
    if(!lista)
        return ERROR;
    nodo_t* nodo = malloc(sizeof(nodo_t));
    if(!nodo)
        return ERROR;
    nodo->elemento = elemento;
    nodo->siguiente = NULL;
    if(lista_vacia(lista)){
        lista->nodo_inicio = nodo;
        lista->nodo_fin = nodo;
    }else{
        lista->nodo_fin->siguiente = nodo;
        lista->nodo_fin = nodo;
    }
    lista->cantidad++;
    return SIN_ERROR;
}

int lista_insertar_en_posicion(lista_t* lista, void* elemento , size_t posicion){
    if(!lista)
        return ERROR;
        
    if(posicion >= lista->cantidad || lista_vacia(lista))
        return lista_insertar(lista, elemento);

    nodo_t* nodo_nuevo = malloc(sizeof(nodo_t));
    if(!nodo_nuevo)
        return ERROR;

    nodo_nuevo->elemento = elemento;

    if(posicion == 0){
        nodo_nuevo->siguiente = lista->nodo_inicio;
        lista->nodo_inicio = nodo_nuevo;
    }else{
        nodo_t* nodo_de_lista = lista->nodo_inicio;

        for(int i = 0; i < posicion - 1; i++){              // no se si con iterador se podra mejorar
            nodo_de_lista = nodo_de_lista->siguiente;
        }

        nodo_nuevo->siguiente = nodo_de_lista->siguiente;
        nodo_de_lista->siguiente = nodo_nuevo;
    }

    lista->cantidad++;    
    return SIN_ERROR;
}

int lista_borrar(lista_t* lista){
    if(!lista)
        return ERROR;
    if(lista_vacia(lista))
        return ERROR;

    if(lista->cantidad > 1){
        nodo_t* nodo_de_lista = lista->nodo_inicio;
        for(int i = 0; i < lista->cantidad - 2; i++){              // no se si con iterador se podrá mejorar
            nodo_de_lista = nodo_de_lista->siguiente;
        }
        free(nodo_de_lista->siguiente);
        nodo_de_lista->siguiente = NULL;
        lista->nodo_fin = nodo_de_lista;
    } else{
        free(lista->nodo_inicio);
        lista->nodo_inicio = NULL;
        lista->nodo_fin = NULL;
    }

    lista->cantidad--;

    return SIN_ERROR;
}


/*
*
*/

void destruir_nodos(nodo_t* nodo){
    if(!nodo)
        return;

    if(nodo->siguiente)
        destruir_nodos(nodo->siguiente);
        
    free(nodo);
}

void lista_destruir(lista_t* lista){
    destruir_nodos(lista->nodo_inicio);
    free(lista);
}

int lista_borrar_de_posicion(lista_t* lista, size_t posicion){
    if(!lista)
        return ERROR;
    if(lista_vacia(lista))
        return ERROR;
    
    if((posicion >= (lista->cantidad - 1)) || (lista->cantidad == 1))
        return lista_borrar(lista);

    if(posicion == 0){
        nodo_t* nodo_a_liberar = lista->nodo_inicio;
        lista->nodo_inicio = nodo_a_liberar->siguiente;
        free(nodo_a_liberar);
    } else {
        nodo_t* nodo_de_lista = lista->nodo_inicio;
        for(int i = 0; i < posicion - 1; i++){              // no se si con iterador se podrá mejorar
            nodo_de_lista = nodo_de_lista->siguiente;
        }
        nodo_t* nodo_a_liberar = nodo_de_lista->siguiente;
        nodo_de_lista->siguiente = nodo_a_liberar->siguiente;
        free(nodo_a_liberar);
    }

    lista->cantidad--;
    
    return SIN_ERROR;
}

void* lista_elemento_en_posicion(lista_t* lista, size_t posicion){
    if(!lista)
        return NULL;
    if(lista_vacia(lista))
        return NULL;
    if(posicion >= lista->cantidad)
        return NULL;
    nodo_t* nodo_de_lista = lista->nodo_inicio;
    for(int i = 0; i < posicion; i++){              // no se si con iterador se podrá mejorar
        nodo_de_lista = nodo_de_lista->siguiente;
    }
    return nodo_de_lista->elemento;
}

void* lista_ultimo(lista_t* lista){
    if(!lista)
        return NULL;
    if(lista_vacia(lista))
        return NULL;
    return lista->nodo_fin->elemento;
}

bool lista_vacia(lista_t* lista){
    if(!lista)
        return false;
    return !(lista->cantidad);
}