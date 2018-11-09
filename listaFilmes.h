#include <stdio.h>
#include <stdlib.h>
#include "filme.h"

typedef struct no_filme{
    Filme *filme;
    struct no_filme *prox, *ant;
}NFilme;

typedef struct desc_lista{
    int total;
    NFilme *prim, *ult;
}ListaFilmes;

ListaFilmes * cria();
Filme * busca(ListaFilmes *l, char *titulo, int ano);
Filme * busca(ListaFilmes *l, Filme *f);
ListaFilmes * insere(ListaFilmes *l, Filme *f);
ListaFilmes * retira(ListaFilmes *l, char *titulo, int ano);
ListaFilmes * retira(ListaFilmes *l, Filme *f);
void imprime(ListaFilmes *l);
void libera(ListaFilmes *l);
