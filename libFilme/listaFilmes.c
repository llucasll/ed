#include "listaFilmes.h"

ListaFilmes * cria(){
    ListaFilmes *l = (ListaFilmes *)malloc(sizeof(ListaFilmes));
    l->total = 0;
    l->prim = NULL;
    l->ult = NULL;
    return l;
}

Filme * busca(ListaFilmes *l, char *titulo, int ano){
    if(l->total == 0) return NULL;
    NFilme * aux = l->prim;
    while(aux && ( (aux->filme->ano!=ano) ||
            (strcmp(aux->filme->titulo, titulo)!=0) ))
        aux = aux->prox;
    if(!aux) return NULL;
    return aux->filme;
}

Filme * busca2(ListaFilmes *l, Filme *f){
    if(l->total == 0) return NULL;
    NFilme * aux = l->prim;
    while(aux && (comparaFilmes(*(aux->filme), *f)==1))
        aux = aux->prox;
    if(!aux) return NULL;
    return aux->filme;
}

ListaFilmes * insere(ListaFilmes *l, Filme *f){
    if(busca(l, f->titulo, f->ano)) return l;
    NFilme *novo = (NFilme *)malloc(sizeof(NFilme));
    novo->filme = f;
    if(l->total == 0){
        novo->prox = NULL;
        novo->ant = NULL;
        l->prim = novo;
        l->ult = novo;
        return l;
    }
    NFilme *aux = l->prim;
    NFilme *menor = ehMenor(*(aux->filme), *f)? aux : novo;
    while(aux && (comparaFilmes(*(menor->filme), *f)==0)){
        aux = aux->prox;
        menor = ehMenor(*(aux->filme), *f)? aux : novo;
    }
    if(!aux){
        l->ult->prox = novo;
        novo->ant = l->ult;
        l->ult = novo;
        novo->prox = NULL;
    }else{
        aux->ant->prox = novo;
        novo->ant = aux->ant;
        aux->ant = novo;
        novo->prox = aux;
    }
    l->total++;
    return l;
}

ListaFilmes * retira(ListaFilmes *l, char *titulo, int ano){
    NFilme *aux = l->prim;
    while(aux && ( (aux->filme->ano!=ano) ||
            (strcmp(aux->filme->titulo, titulo)!=0) ))
        aux = aux->prox;
    if(aux){
        if(aux->ant)
            aux->ant->prox = aux->prox;
        else
            l->prim = aux->prox;
        if(aux->prox)
            aux->prox->ant = aux->ant;
        else
            l->ult = aux->ant;
        aux->prox = NULL;
        aux->ant = NULL;
        l->total--;
        free(aux);
    }
    return l;
}

ListaFilmes * retira2(ListaFilmes *l, Filme *f){
    NFilme *aux = l->prim;
    while(aux && (comparaFilmes(*(aux->filme), *f)==1))
        aux = aux->prox;
    if(aux){
        if(aux->ant)
            aux->ant->prox = aux->prox;
        else
            l->prim = aux->prox;
        if(aux->prox)
            aux->prox->ant = aux->ant;
        else
            l->ult = aux->ant;
        aux->prox = NULL;
        aux->ant = NULL;
        l->total--;
        free(aux);
    }
    return l;
}

void imprime(ListaFilmes *l){
    NFilme *aux = l->prim;
    int i=0;
    while(aux)
        printf("%d. %s (%d)", ++i, aux->filme->titulo,
               aux->filme->ano);
}

void libera(ListaFilmes *l){
    NFilme *aux = l->prim;
    l->ult = NULL;
    while(aux){
        l->prim = aux->prox;
        if(l->total>1)
            aux->prox->ant = NULL;
        aux->prox = NULL;
        free(aux);
        l->total--;
        aux = l->prim;
    }
}
