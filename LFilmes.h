#include <stdio.h>
#include <stdlib.h>
#include "Filme.h"

typedef struct no_filme{
    Filme* filme;
    struct no_filme* prox,* ant;
}NFilme;

typedef struct desc_lista{
    int total;
    NFilme* prim,* ult;
}Filmes;

Filmes* cria();
Filme* busca(Filmes* l, char* titulo, int ano);
Filme* busca(Filmes* l, Filme* f);
Filmes* insere(Filmes* l, Filme* f);
Filmes* retira(Filmes* l, char* titulo, int ano);
Filmes* retira(Filmes* l, Filme* f);
void imprime(Filmes* l);
void libera(Filmes* l);
