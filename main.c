//suponiendo una cache LRU, defina la funcion solicitar pagina

#include <stdio.h>
#include "cache.h"

int main() {

    Cache * cachenueva = newCache(6);

    inicializarHash();

    solicitarPagina(cachenueva,12);
    imprimir(cachenueva);
    solicitarPagina(cachenueva,2);
    imprimir(cachenueva);
    solicitarPagina(cachenueva,1);
    imprimir(cachenueva);
    solicitarPagina(cachenueva,5);
    imprimir(cachenueva);
    solicitarPagina(cachenueva,8);
    imprimir(cachenueva);
    solicitarPagina(cachenueva,10);
    imprimir(cachenueva);
    solicitarPagina(cachenueva,17);
    imprimir(cachenueva);



    return 0;
}
