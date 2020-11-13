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
    int primer_valor = 1, segundo_valor = 2, tercer_valor = 3;
    pa2m_afirmar(lista_insertar(NULL, &primer_valor) == -1, "Insertar devuelve error si recive NULL como lista");
    pa2m_afirmar(lista_insertar(lista, &primer_valor) == 0, "Insertar primer elemento sin error.");
    pa2m_afirmar(lista_elementos(lista) == 1, "Cantidad igual a 1 al insertar primer elemento.");
    pa2m_afirmar(lista->nodo_inicio != NULL, "Nodo inicio distinto de null porque ya existe un nodo");
    pa2m_afirmar(lista->nodo_fin != NULL, "Nodo fin distinto de null porque ya existe un nodo");
    pa2m_afirmar(lista->nodo_inicio->elemento == &primer_valor, "Elemento del primer nodo igual al elemento ingresado");
    pa2m_afirmar(lista->nodo_fin->elemento == lista->nodo_inicio->elemento, "Primer elemento igual al a ultima cuando hay 1 solo elemento");
    pa2m_afirmar(lista_insertar(lista, &segundo_valor) == 0, "Insertar segundo elemento sin error.");
    pa2m_afirmar(lista_elementos(lista) == 2, "La lista tiene 2 elementos.");
    pa2m_afirmar(lista->nodo_fin->elemento == &segundo_valor, "2do elemento correcto");
    lista_insertar(lista, &tercer_valor);
    pa2m_afirmar(lista_elementos(lista) == 3, "La lista tiene 3 elementos");
    pa2m_afirmar(lista->nodo_fin->elemento == &tercer_valor, "3er elemento correcto");

    lista_destruir(lista);
}

void probar_lista_insercion_en_posicion(){
    pa2m_nuevo_grupo("Pruebas insercion en posicion");
    lista_t* lista = lista_crear();
    int primer_valor = 1, segundo_valor = 2, tercer_valor = 3, cuarto_valor = 4, quinto_valor = 5, sexto_valor = 6;
    lista_insertar(lista, &primer_valor);
    lista_insertar(lista, &segundo_valor);
    lista_insertar(lista, &tercer_valor);

    pa2m_afirmar(lista_insertar_en_posicion(NULL, &cuarto_valor, 0) == -1, "Insertar en posicion devuelve error si recive NULL como lista");
    pa2m_afirmar(lista_insertar_en_posicion(lista, &cuarto_valor, 0) == 0, "Insertar al inicio.");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 0) == &cuarto_valor, "Primer elemento correcto");
    pa2m_afirmar(lista_insertar_en_posicion(lista, &quinto_valor, 99) == 0, "Insertar al final.");
    pa2m_afirmar(lista_elemento_en_posicion(lista, lista_elementos(lista) - 1) == &quinto_valor, "Último elemento correcto");
    pa2m_afirmar(lista_insertar_en_posicion(lista, &sexto_valor, 2) == 0, "Insertar al medio.");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 2) == &sexto_valor, "Elemento del medio correcto");
    pa2m_afirmar(lista_elementos(lista) == 6, "Se actualiza la cantidad correctamente");
    
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
    pa2m_afirmar(lista_elementos(lista) == 3, "Hay 3 elementos");
    pa2m_afirmar(lista_borrar(NULL) == -1, "Devuelve error si recibe NULL");
    pa2m_afirmar(lista_borrar(lista) == 0, "Borro ultimo elemento");
    pa2m_afirmar(lista_elementos(lista) == 2, "Hay 2 elementos");
    pa2m_afirmar(lista_borrar(lista) == 0, "Borro ultimo elemento");
    pa2m_afirmar(lista_elementos(lista) == 1, "Hay 1 elementos");
    pa2m_afirmar(lista_borrar(lista) == 0, "Borro ultimo elemento");
    pa2m_afirmar(lista_elementos(lista) == 0, "La lista no tiene elementos");
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
    pa2m_afirmar(lista_elementos(lista) == 5, "Hay 5 elementos");
    pa2m_afirmar(lista_borrar_de_posicion(lista, 3) == 0, "Borro del medio");
    pa2m_afirmar(lista_elementos(lista) == 4, "Hay 4 elementos");
    pa2m_afirmar(lista_borrar_de_posicion(lista, 0) == 0, "Borro del inicio");
    pa2m_afirmar(lista_elementos(lista) == 3, "Hay 3 elementos");
    pa2m_afirmar(lista_borrar_de_posicion(lista, 0) == 0, "Borro del final");
    pa2m_afirmar(lista_elementos(lista) == 2, "Hay 2 elementos");
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
    pa2m_afirmar(!lista_ultimo(NULL), "Devuelve true si recibe null como lista");
    pa2m_afirmar(lista_vacia(lista), "Esta vacia luego de la creacion")
    int primer_valor = 1;
    lista_insertar(lista, &primer_valor);
    pa2m_afirmar(!lista_vacia(lista), "No esta vacia luego de insertar elemento");
    lista_borrar(lista);
    pa2m_afirmar(lista_vacia(lista), "Esta vacia luego de borrar el elemento insertado")
    lista_destruir(lista);
}

void probar_lista_elementos(){
    pa2m_nuevo_grupo("Pruebas lista vacia");
    lista_t* lista = lista_crear();
    pa2m_afirmar(lista_elementos(NULL) == 0, "Devuelve 0 si recibe null como lista");
    int primer_valor = 1, segundo_valor = 2;
    lista_insertar(lista, &primer_valor);
    pa2m_afirmar(lista_elementos(lista) == 1, "La lista tiene 1 elemento");
    lista_insertar(lista, &segundo_valor);
    pa2m_afirmar(lista_elementos(lista) == 2, "La lista tiene 2 elemento");
    lista_borrar(lista);
    pa2m_afirmar(lista_elementos(lista) == 1, "La lista vuelve a tener 1 elemento luego de borrar el ultimo");
    lista_destruir(lista);
}

void probar_lista_apilar(){
    pa2m_nuevo_grupo("Pruebas apilar");
    lista_t* lista = lista_crear();
    int primer_valor = 1, segundo_valor = 2;
    pa2m_afirmar(lista_apilar(NULL, &primer_valor) == -1, "Devuelve -1 si recibe null como lista");
    pa2m_afirmar(lista_apilar(lista, &primer_valor) == 0, "Se apila el primer elemento");
    pa2m_afirmar(lista_elementos(lista) == 1, "La lista tiene 1 elemento");
    pa2m_afirmar(lista_tope(lista) == &primer_valor, "El último elemento de la lista es correcto");
    pa2m_afirmar(lista_apilar(lista, &segundo_valor) == 0, "Se apila el segundo elemento");
    pa2m_afirmar(lista_elementos(lista) == 2, "La lista tiene 2 elementos");
    pa2m_afirmar(lista_tope(lista) == &segundo_valor, "El último elemento de la lista es correcto");
    lista_destruir(lista);
}

void probar_lista_desapilar(){
    pa2m_nuevo_grupo("Pruebas desapilar");
    lista_t* lista = lista_crear();
    pa2m_afirmar(lista_desapilar(NULL) == -1, "Devuelve error si la lista no tiene elementos");
    int primer_valor = 1, segundo_valor = 2, tercer_valor = 3;
    lista_apilar(lista, &primer_valor);
    lista_apilar(lista, &segundo_valor);
    lista_apilar(lista, &tercer_valor);
    pa2m_afirmar(lista_elementos(lista) == 3, "Hay 3 elementos");
    pa2m_afirmar(lista_desapilar(NULL) == -1, "Devuelve error si recibe NULL");
    pa2m_afirmar(lista_desapilar(lista) == 0, "Desapilo elemento");
    pa2m_afirmar(lista_elementos(lista) == 2, "Hay 2 elementos");
    pa2m_afirmar(lista_desapilar(lista) == 0, "Desapilo elemento");
    pa2m_afirmar(lista_elementos(lista) == 1, "Hay 1 elementos");
    pa2m_afirmar(lista_desapilar(lista) == 0, "Desapilo elemento");
    pa2m_afirmar(lista_elementos(lista) == 0, "La lista no tiene elementos");
    lista_destruir(lista);
}

void probar_lista_tope(){
    pa2m_nuevo_grupo("Pruebas lista tope");
    lista_t* lista = lista_crear();
    pa2m_afirmar(lista_tope(lista) == NULL, "Devuelve NULL si la lista no tiene elementos");
    int primer_valor = 1, segundo_valor = 2, tercer_valor = 3;
    lista_apilar(lista, &primer_valor);
    pa2m_afirmar(lista_tope(NULL) == NULL, "Devuelve NULL si recibe NULL como lista");
    pa2m_afirmar(lista_tope(lista) == &primer_valor, "Valor correcto cuando hay 1");
    lista_apilar(lista, &segundo_valor);
    lista_apilar(lista, &tercer_valor);
    pa2m_afirmar(lista_tope(lista) == &tercer_valor, "Valor correcto cuando hay 3");
    lista_desapilar(lista);
    pa2m_afirmar(lista_tope(lista) == &segundo_valor, "Valor correcto Luego de borrar ultimo nodo");
    lista_destruir(lista);
}


void probar_lista_encolar(){
    pa2m_nuevo_grupo("Pruebas encolar");
    lista_t* lista = lista_crear();
    int primer_valor = 1, segundo_valor = 2;
    pa2m_afirmar(lista_encolar(NULL, &primer_valor) == -1, "Devuelve -1 si recibe null como lista");
    pa2m_afirmar(lista_encolar(lista, &primer_valor) == 0, "Se encola el primer elemento");
    pa2m_afirmar(lista_elementos(lista) == 1, "La lista tiene 1 elemento");
    pa2m_afirmar(lista_tope(lista) == &primer_valor, "El primer elemento de la lista es correcto");
    pa2m_afirmar(lista_encolar(lista, &segundo_valor) == 0, "Se encola el segundo elemento");
    pa2m_afirmar(lista_elementos(lista) == 2, "La lista tiene 2 elementos");
    pa2m_afirmar(lista_tope(lista) == &segundo_valor, "El primer elemento de la lista es correcto");
    lista_destruir(lista);
}

void probar_lista_desencolar(){
    pa2m_nuevo_grupo("Pruebas desencolar");
    lista_t* lista = lista_crear();
    pa2m_afirmar(lista_desencolar(NULL) == -1, "Devuelve error si la lista no tiene elementos");
    int primer_valor = 1, segundo_valor = 2, tercer_valor = 3;
    lista_encolar(lista, &primer_valor);
    lista_encolar(lista, &segundo_valor);
    lista_encolar(lista, &tercer_valor);
    pa2m_afirmar(lista_elementos(lista) == 3, "Hay 3 elementos");
    pa2m_afirmar(lista_desencolar(NULL) == -1, "Devuelve error si recibe NULL");
    pa2m_afirmar(lista_desencolar(lista) == 0, "desencolo elemento");
    pa2m_afirmar(lista_elementos(lista) == 2, "Hay 2 elementos");
    pa2m_afirmar(lista_desencolar(lista) == 0, "desencolo elemento");
    pa2m_afirmar(lista_elementos(lista) == 1, "Hay 1 elementos");
    pa2m_afirmar(lista_desencolar(lista) == 0, "desencolo elemento");
    pa2m_afirmar(lista_elementos(lista) == 0, "La lista no tiene elementos");
    lista_destruir(lista);
}

void probar_lista_primero(){
    pa2m_nuevo_grupo("Pruebas lista primero");
    lista_t* lista = lista_crear();
    pa2m_afirmar(lista_primero(lista) == NULL, "Devuelve NULL si la lista no tiene elementos");
    int primer_valor = 1, segundo_valor = 2;
    lista_encolar(lista, &primer_valor);
    lista_encolar(lista, &segundo_valor);
    pa2m_afirmar(lista_primero(NULL) == NULL, "Devuelve NULL si recibe NULL como lista");
    pa2m_afirmar(lista_primero(lista) == &primer_valor, "Valor correcto con 2 elementos");
    lista_desencolar(lista);
    pa2m_afirmar(lista_primero(lista) == &segundo_valor, "Valor correcto luego de eliminar el que estaba al inicio");
    lista_destruir(lista);
}

void probar_iterador_externo(){
    pa2m_nuevo_grupo("pruebas iterador externo");
    lista_t* lista = lista_crear();
    lista_iterador_t* iterador = lista_iterador_crear(NULL);
    int primer_valor = 1, segundo_valor = 2, tercer_valor = 3, cuarto_valor = 4, quinto_valor = 5, sexto_valor = 6;
    lista_insertar(lista, &primer_valor);
    lista_insertar(lista, &segundo_valor);
    lista_insertar(lista, &tercer_valor);
    lista_insertar(lista, &cuarto_valor);
    lista_insertar(lista, &quinto_valor);
    lista_insertar(lista, &sexto_valor);
    pa2m_afirmar(iterador == NULL, "Iterador apunta a NULL cuando lista_iterador_crear recibe NULL");
    iterador = lista_iterador_crear(lista);
    pa2m_afirmar(iterador != NULL, "Iterador apunta a un valor no nulo cuando lista_iterador_crear recibe una lista valida");
    pa2m_afirmar(iterador->lista == lista, "Iterador->lista apunta a la lista indicada");
    pa2m_afirmar(iterador->corriente == lista->nodo_inicio, "Iterador->corriente apunta al nodo_inicio de la lista");
    pa2m_afirmar(lista_iterador_tiene_siguiente(iterador), "Iterador tiene siguiente elemente al cual iterar")
    while(lista_iterador_tiene_siguiente(iterador)){
        printf("    Valor del elemento: %i\n", *(int*)(lista_iterador_elemento_actual(iterador)));
        lista_iterador_avanzar(iterador);
    }
    pa2m_afirmar(iterador->corriente == NULL, "Iterador->corriente es nulo cuando ya recorrio toda la lista");
    pa2m_afirmar(!lista_iterador_tiene_siguiente(iterador), "Iterador no tiene siguiente elemente al cual iterar")
    lista_iterador_destruir(iterador);
    lista_destruir(lista);
}


bool mostrar_hasta_un_3(void* elemento, void* contador){
    if(elemento)
        printf("Posicion %i: %i\n", (*(int*)contador), *(int*)elemento);
    (*(int*)contador)++;
    return *(int*)elemento != 3;
}

void probar_iterador_interno(){
    pa2m_nuevo_grupo("Pruebas iterador interno");
    lista_t* lista = lista_crear();
    int primer_valor = 1, segundo_valor = 2, tercer_valor = 3, cuarto_valor = 4, quinto_valor = 5, sexto_valor = 6;
    printf("Imprimo del 1 al 3 inclusive\n");
    lista_insertar(lista, &primer_valor);
    lista_insertar(lista, &segundo_valor);
    lista_insertar(lista, &tercer_valor);
    lista_insertar(lista, &cuarto_valor);
    lista_insertar(lista, &quinto_valor);
    lista_insertar(lista, &sexto_valor);
    int i = 0;
    size_t iteraciones = lista_con_cada_elemento(lista, mostrar_hasta_un_3, &i);
    pa2m_afirmar(i==3 && iteraciones == 3, "Se mostraron 3 elementos en 3 iteraciones");
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
    probar_lista_elementos();
    probar_lista_apilar();
    probar_lista_desapilar();
    probar_lista_tope();
    probar_lista_encolar();
    probar_lista_desencolar();
    probar_lista_primero();
    probar_iterador_externo();
    probar_iterador_interno();
    pa2m_mostrar_reporte();
    return 0;
}