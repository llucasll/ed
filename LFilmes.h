#include <stdio.h>
#include <stdlib.h>
#include "Filme.h"

typedef struct no_filme{
    Filme *filme;
    struct no_filme *prox, *ant;
}NFilme;

typedef struct desc_lista{
    int total;
    NFilme *prim, *ult;
}LFilmes;

LFilmes * cria();
Filme * busca(LFilmes *l, char *titulo, int ano);
Filme * busca(LFilmes *l, Filme *f);
LFilmes * insere(LFilmes *l, Filme *f);
LFilmes * retira(LFilmes *l, char *titulo, int ano);
LFilmes * retira(LFilmes *l, Filme *f);
void imprime(LFilmes *l);
void libera(LFilmes *l);
