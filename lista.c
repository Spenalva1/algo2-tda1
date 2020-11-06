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
    if(lista->cantidad == 0){
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
        
    if(posicion >= lista->cantidad)
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
    
    if(!lista || lista->cantidad < 1)
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

void lista_destruir(lista_t* lista){
    free(lista);
}