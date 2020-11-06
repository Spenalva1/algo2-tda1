#include "lista.h"
#include "pa2mm.h"
#include <stdio.h>

void probar_lista_crear_y_destruir(){
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
    
    lista_destruir(lista);
}

void probar_lista_borrar(){
    pa2m_nuevo_grupo("Pruebas borrar última posición");
    lista_t* lista = lista_crear();
    pa2m_afirmar(lista_borrar(NULL) == -1, "Devuelve error si la lista no tiene elementos");
    int primer_valor = 1, segundo_valor = 2, tercer_valor = 3;
    lista_insertar(lista, &primer_valor);
    lista_insertar(lista, &segundo_valor);
    lista_insertar(lista, &tercer_valor);
    pa2m_afirmar(lista->cantidad == 3, "Hay 3 elementos");
    pa2m_afirmar(lista_borrar(NULL) == -1, "Devuelve error si recibe NULL");
    lista_borrar(lista);
    pa2m_afirmar(lista->cantidad == 2, "Hay 2 elementos");
    lista_borrar(lista);
    pa2m_afirmar(lista->cantidad == 1, "Hay 1 elementos");
    lista_borrar(lista);
    pa2m_afirmar(lista->cantidad == 0, "La lista no tiene elementos");
    lista_destruir(lista);
}

void probar_lista_borrar_de_posicion(){
    pa2m_nuevo_grupo("Pruebas borrar en cualquier posición");
    lista_t* lista = lista_crear();
    pa2m_afirmar(lista_borrar_de_posicion(NULL, 0) == -1, "Devuelve error si la lista no tiene elementos");
    int primer_valor = 1, segundo_valor = 2, tercer_valor = 3, cuarto_valor = 4, quinto_valor = 5;
    lista_insertar(lista, &primer_valor);
    lista_insertar(lista, &segundo_valor);
    lista_insertar(lista, &tercer_valor);
    lista_insertar(lista, &cuarto_valor);
    lista_insertar(lista, &quinto_valor);
    pa2m_afirmar(lista_borrar_de_posicion(NULL, 0) == -1, "Devuelve error si recibe NULL");
    pa2m_afirmar(lista->cantidad == 5, "Hay 5 elementos");
    pa2m_afirmar(lista_borrar_de_posicion(lista, 3) == 0, "Borro del medio");
    pa2m_afirmar(lista->cantidad == 4, "Hay 4 elementos");
    pa2m_afirmar(lista_borrar_de_posicion(lista, 0) == 0, "Borro del inicio");
    pa2m_afirmar(lista->cantidad == 3, "Hay 3 elementos");
    pa2m_afirmar(lista_borrar_de_posicion(lista, 0) == 0, "Borro del final");
    pa2m_afirmar(lista->cantidad == 2, "Hay 2 elementos");
    lista_destruir(lista);
}

void probar_lista_elemento_en_posicion(){
    pa2m_nuevo_grupo("Pruebas elemento de cualquier posición");
    lista_t* lista = lista_crear();
    pa2m_afirmar(lista_elemento_en_posicion(NULL, 0) == NULL, "Devuelve NULL si la lista no tiene elementos");
    int primer_valor = 1, segundo_valor = 2, tercer_valor = 3, cuarto_valor = 4, quinto_valor = 5;
    lista_insertar(lista, &primer_valor);
    lista_insertar(lista, &segundo_valor);
    lista_insertar(lista, &tercer_valor);
    lista_insertar(lista, &cuarto_valor);
    lista_insertar(lista, &quinto_valor);
    pa2m_afirmar(lista_elemento_en_posicion(NULL, 0) == NULL, "Devuelve NULL si recibe NULL como lista");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 66) == NULL, "Devuelve NULL si recibe una posicion inexistente de la lista");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 0) == &primer_valor, "Primer valor correcto");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 2) == &tercer_valor, "Ultimo valor correcto");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 4) == &quinto_valor, "Ultimo valor correcto");
    lista_destruir(lista);
}

void probar_lista_ultimo(){
    pa2m_nuevo_grupo("Pruebas ultimo elemento");
    lista_t* lista = lista_crear();
    pa2m_afirmar(lista_ultimo(lista) == NULL, "Devuelve NULL si la lista no tiene elementos");
    int primer_valor = 1, segundo_valor = 2, tercer_valor = 3;
    lista_insertar(lista, &primer_valor);
    pa2m_afirmar(lista_ultimo(NULL) == NULL, "Devuelve NULL si recibe NULL como lista");
    pa2m_afirmar(lista_ultimo(lista) == &primer_valor, "Valor correcto cuando hay 1");
    lista_insertar(lista, &segundo_valor);
    lista_insertar(lista, &tercer_valor);
    pa2m_afirmar(lista_ultimo(lista) == &tercer_valor, "Valor correcto cuando hay 3");
    lista_borrar(lista);
    pa2m_afirmar(lista_ultimo(lista) == &segundo_valor, "Valor correcto Luego de borrar ultimo nodo");
    lista_destruir(lista);
}

void probar_lista_vacia(){
    pa2m_nuevo_grupo("Pruebas lista vacia");
    lista_t* lista = lista_crear();
    pa2m_afirmar(!lista_ultimo(NULL), "Devuelve false si recibe null como lista");
    pa2m_afirmar(lista_vacia(lista), "Esta vacia luego de la creacion")
    int primer_valor = 1;
    lista_insertar(lista, &primer_valor);
    pa2m_afirmar(!lista_vacia(lista), "No esta vacia luego de insertar elemento");
    lista_borrar(lista);
    pa2m_afirmar(lista_vacia(lista), "Esta vacia luego de borrar el elemento insertado")
    lista_destruir(lista);
}

int main(){
    probar_lista_crear_y_destruir();
    probar_lista_insercion();
    probar_lista_insercion_en_posicion();
    probar_lista_borrar();
    probar_lista_borrar_de_posicion();
    probar_lista_elemento_en_posicion();
    probar_lista_ultimo();
    probar_lista_vacia();
    pa2m_mostrar_reporte();
    return 0;
}