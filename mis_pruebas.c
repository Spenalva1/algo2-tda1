#include "lista.h"
#include "pa2mm.h"
#include <stdio.h>

void probar_lista_crear(){
    pa2m_nuevo_grupo("Pruebas crear lista:");
    lista_t* lista = lista_crear();
    pa2m_afirmar(lista != NULL, "Puntero a lista distinto de null.")
    pa2m_afirmar(lista->nodo_inicio == NULL, "Puntero a nodo inicio inicializado en NULL.")
    pa2m_afirmar(lista->nodo_fin == NULL, "Puntero a nodo fin inicializado en NULL.")
    lista_destruir(lista);
}

void probar_lista_insercion(){
    pa2m_nuevo_grupo("Pruebas insercion en lista:");
    lista_t* lista = lista_crear();
    int primer_valor = 5;
    double segundo_valor = 2.3;
    char* tercer_valor = "insercion";
    pa2m_afirmar(lista_insertar(NULL, &primer_valor) == -1, "Insertar devuelve error si recive NULL como lista");
    pa2m_afirmar(lista_insertar(lista, &primer_valor) == 0, "Insertar primer elemento sin error.");
    pa2m_afirmar(lista->cantidad == 1, "Cantidad igual a 1 al insertar primer elemento.");
    pa2m_afirmar(lista->nodo_inicio != NULL, "Nodo inicio distinto de null porque ya existe un nodo");
    pa2m_afirmar(lista->nodo_fin != NULL, "Nodo fin distinto de null porque ya existe un nodo");
    pa2m_afirmar(lista->nodo_inicio->elemento == &primer_valor, "Elemento del primer nodo igual al elemento ingresado");
    pa2m_afirmar(lista->nodo_fin->elemento == lista->nodo_inicio->elemento, "Primer elemento igual al a ultima cuando hay 1 solo elemento");
    pa2m_afirmar(lista_insertar(lista, &segundo_valor) == 0, "Insertar segundo elemento sin error.");
    pa2m_afirmar(lista->cantidad == 2, "La lista tiene 2 elementos.");
    pa2m_afirmar(lista->nodo_fin->elemento == &segundo_valor, "2do elemento correcto");
    lista_insertar(lista, &tercer_valor);
    pa2m_afirmar(lista->cantidad == 3, "La lista tiene 3 elementos");
    pa2m_afirmar(lista->nodo_fin->elemento == &tercer_valor, "3er elemento correcto");

    for(int i = 0; i < 3; i++)
        lista_borrar(lista);
    lista_destruir(lista);
}

void probar_lista_insercion_en_posicion(){ //PROBAR MEJOR CUANDO PUEDA ACCERDER A ELEMENTOS DE LA LISTA
    pa2m_nuevo_grupo("Pruebas insercion en posicion");
    lista_t* lista = lista_crear();
    int primer_valor = 1, segundo_valor = 2, tercer_valor = 3, cuarto_valor = 4, quinto_valor = 5, sexto_valor = 6;
    lista_insertar(lista, &primer_valor);
    lista_insertar(lista, &segundo_valor);
    lista_insertar(lista, &tercer_valor);

    pa2m_afirmar(lista_insertar_en_posicion(NULL, &cuarto_valor, 0) == -1, "Insertar en posicion devuelve error si recive NULL como lista");
    pa2m_afirmar(lista_insertar_en_posicion(lista, &cuarto_valor, 0) == 0, "Insertar al inicio.");
    pa2m_afirmar(lista_insertar_en_posicion(lista, &quinto_valor, 99) == 0, "Insertar al final.");
    pa2m_afirmar(lista_insertar_en_posicion(lista, &sexto_valor, 2) == 0, "Insertar al medio.");
    pa2m_afirmar(lista->cantidad == 6, "Se actualiza la cantidad correctamente");
    
    for(int i = 0; i < 6; i++)
        lista_borrar(lista);
    lista_destruir(lista);
}

void probar_lista_borrar(){
    //VAMO POR ACA
}

int main(){
    probar_lista_crear();
    probar_lista_insercion();
    probar_lista_insercion_en_posicion();
    probar_lista_borrar();
    pa2m_mostrar_reporte();
    return 0;
}