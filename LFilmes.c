#include <stdio.h>
#include <stdlib.h>
#include "Filme.h"

Filmes* cria(){
    Filmes* l = (Filmes* )malloc(sizeof(Filmes));
    l.total = 0;
    l->prim = NULL;
    l->ult = NULL;
    return l;
}

// 0-iguais, 1-diferentes
int comparaFilmes(Filme* a, Filme* b){
    if((strcmp(a->titulo, b->titulo)==0) &&
        a->ano == b->ano)
        return 0;
    return 1;
}

Filme* busca(Filmes* l, char* titulo, int ano){
    if(l.total == 0) return NULL;
    NFilme* aux = l.prim;
    while(aux && ( (aux->filme->ano!=ano) ||
            (strcmp(aux->filme->titulo, titulo)!=0) ))
        aux = aux->prox;
    if(!aux) return NULL;
    return aux->filme;
}

Filme* busca(Filmes* l, Filme* f){
    if(l.total == 0) return NULL;
    NFilme* aux = l.prim;
    while(aux && (comparaFilmes(aux->filme, f)==1))
        aux = aux->prox;
    if(!aux) return NULL;
    return aux->filme;
}

Filmes* insere(Filmes* l, Filme* f){
    if(busca(l, f)) return l;
    NFilme* novo = (NFilme* )malloc(sizeof(NFilme));
    novo->filme = f;
    if(l.total == 0){
        novo->prox = NULL;
        novo->ant = NULL;
        l.prim = novo;
        l.ult = novo;
        return l;
    }
    NFilme* aux = l.prim;
    NFilme* menor = menor(aux->filme, f);
    while(aux && (comparaFilmes(menor, f)==0)){
        aux = aux->prox;
        menor = menor(aux->filme, f);
    }
    if(!aux){
        l.ult->prox = novo;
        novo->ant = l.ult;
        l.ult = novo;
        novo->prox = NULL;
    }else{
        aux->ant->prox = novo;
        novo->ant = aux->ant;
        aux->ant = novo;
        novo->prox = aux;
    }
    l.total++;
    return l;
}

Filmes* retira(Filmes* l, char* titulo, int ano){
    NFilme* aux = l.prim;
    while(aux && ( (aux->filme->ano!=ano) ||
            (strcmp(aux->filme->titulo, titulo)!=0) ))
        aux = aux->prox;
    if(aux){
        if(aux->ant)
            aux->ant->prox = aux->prox;
        else
            l.prim = aux->prox;
        if(aux->prox)
            aux->prox->ant = aux->ant;
        else
            l.ult = aux->ant;
        aux->prox = NULL;
        aux->ant = NULL;
        l.total--;
        free(aux);
    }
    return l;
}

Filmes* retira(Filmes* l, Filme* f){
    NFilme* aux = l.prim;
    while(aux && (comparaFilmes(aux->filme, f)==1))
        aux = aux->prox;
    if(aux){
        if(aux->ant)
            aux->ant->prox = aux->prox;
        else
            l.prim = aux->prox;
        if(aux->prox)
            aux->prox->ant = aux->ant;
        else
            l.ult = aux->ant;
        aux->prox = NULL;
        aux->ant = NULL;
        l.total--;
        free(aux);
    }
    return l;
}

void imprime(Filmes* l){
    NFilme* aux = l.prim;
    int i=0;
    while(aux)
        printf("%d. %s (%d)", ++i, aux->filme->titulo,
               aux->filme->ano);
}

void libera(Filmes* l){
    NFilme* aux = l.prim;
    l.ult = NULL;
    while(aux){
        l.prim = aux->prox;
        if(l.total>1)
            aux->prox->ant = NULL;
        aux->prox = NULL;
        free(aux);
        l.total--;
        aux = l.prim;
    }
}
