#include "funcionalidades.h"

#include <string.h>

bool isDirectedBy(Filme f, char *diretor){
    if(!strcmp(f.diretor,diretor))
        return true;
    return false;
}

ListaFilmes* directedsBy(char* diretor, No a){
    ListaFilmes* recursive_insertion(ListaFilmes* l, No a){
        if(!a.tam) return l;
        int i;
        for(i=0; i<a.tam; i++){
            l = recursive_insertion(l, getFilho(a, i));
            if(isDirectedBy(a.filmes[i], diretor))
                l = insere(l, a.filmes[i]);
        }
        l = recursive_insertion(l, getFilho(a, i));
        return l;
    }
    ListaFilmes* lfilmes = cria();
    lfilmes = recursive_insertion(lfilmes, a);
    return lfilmes;
}

bool isFromGenre(Filme f, char *genero){
    if(!strstr(f.genero,genero))
        return false;
    return true;
}

void removeGenre(No a, char* genero){
    if(!a.tam) return;
    int i;
    for(i=0 ; i < a.tam ; i++){
        removeGenre(getFilho(a, i), genero);  
        if(isFromGenre(a.filmes[i], genero))
            rm(a.filmes[i].titulo, a.filmes[i].ano);
    }
    removeGenre(getFilho(a, i), genero);
}
