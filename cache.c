//
// Created by Usuario on 11/9/2023.
//

#include "cache.h"
#include "malloc.h"
#include "stdio.h"

Pagina * hash[NUMERODEPAGINAS];

Pagina * newPagina (int numero){

    Pagina * aux = NULL;
    aux = malloc(sizeof(Pagina));

    if (aux == NULL){
        printf("No hay espacio de memoria suficiente.");
        exit (-1);
    }
    else{
        aux->numeroDePagina = numero;
        aux->sig = NULL;
        aux->ant = NULL;
    }
    return aux;
}

Cache * newCache (int capacidad){
    Cache * aux = NULL;
    aux = malloc(sizeof(Cache));

    if (aux == NULL){
        printf("No hay espacio de memoria suficiente.");
        exit (-1);
    }
    else{
        aux->capacidad = capacidad;
        aux->tam = 0;
        aux->cache = NULL;
    }
    return aux;
}

void inicializarHash (){

    for (int i = 0 ; i < NUMERODEPAGINAS ; i++){
        hash[i]=NULL;//creo un puntero hash con la cantidad de paginas
    }

}

Pagina * solicitarPagina (Cache * cache, int numeroDePagina) { //solicita una pagina a la cache

    Pagina * aux = hash[numeroDePagina];

    if (aux == NULL) {//la pagina no existe, la creo

        aux = newPagina(numeroDePagina); //aux es una nueva pagina

        if (cache->capacidad == cache->tam){ {//la cache esta llena

            eliminar(cache);
        }

        apilar(cache, aux);//si hay espacio, apilo

    } else {//la pagina existe en el hash, lo inserto en la cache

        if (cache->cache != aux) {
            aux->ant->sig = aux->sig;
        }
        if (aux->sig!=NULL) {
            aux->sig->ant = aux->ant;
        }

        cache->tam--;
        apilar(cache, aux);
    }
}
return aux;
}

void apilar (Cache * cache, Pagina * paginaAInsertar) {

    if (cache->cache == NULL){//la cache esta vacia

        cache->cache->ant = paginaAInsertar; //inserto la primera pagina
    }

    paginaAInsertar->sig = cache->cache;
    paginaAInsertar->ant = NULL;
    cache->cache = paginaAInsertar;
    hash[paginaAInsertar->numeroDePagina] = paginaAInsertar; // lo inserto en el hash
    cache->tam++; //aumento en la tamanio de cache

}
void eliminar (Cache * cache) {

    Pagina * aux = cache->cache;

    if (aux != NULL){ //la cache no esta vacia

        for (;aux->sig != NULL; aux=aux->sig){}
        aux->ant->sig=NULL;
        hash[aux->numeroDePagina]=NULL;
        free(aux);
        cache->tam --;
    }
}
void imprimir (Cache * cache){

    Pagina * aux = cache->cache;

    printf ("\n Paginas de la cache:\n");

    while(aux->sig != NULL){

        printf ("%d\t", aux->numeroDePagina);
        aux = aux->sig;

    }
}