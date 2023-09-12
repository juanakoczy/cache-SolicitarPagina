//
// Created by Usuario on 11/9/2023.
//

#ifndef CACHE_SOLICITARPAGINA_CACHE_H
#define CACHE_SOLICITARPAGINA_CACHE_H
#define NUMERODEPAGINAS 100

typedef struct pagina{

    int numeroDePagina;
    struct pagina * ant;
    struct pagina *sig;

}Pagina;

typedef struct cache{

    Pagina * cache;
    int tam;
    int capacidad;

}Cache;

Pagina * newPagina (int numero);
Cache * newCache (int capacidad);
void inicializarHash ();

Pagina * solicitarPagina (Cache * cache, int numeroDePagina);
void apilar (Cache * cache, Pagina * paginaAInsertar);//apila siempre adelante  o arriba (pila)
void eliminar (Cache * cache);// Solo recibe cache porque siempre elimina la ultima pagina (cola)
void imprimir (Cache * cache);

#endif //CACHE_SOLICITARPAGINA_CACHE_H
