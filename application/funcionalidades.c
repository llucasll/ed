#include "funcionalidades.h"

#include <string.h>

bool isDirectedBy(Filme f, char *diretor){
    if(!strcmp(f.diretor,diretor))
        return true;
    return false;
}
/*
ListaFilmes* directedsBy(char *diretor, No a){
    ListaFilmes* recursive_insertion(ListaFilmes* l, No a){
        int i;
        for(i=0; i<a.tam; i++){
            if (isDirectedBy(a.filmes[i], diretor)){
                l = insere(l, a.filmes[i]);
            }
            if(!a.ehFolha) l = recursive_insertion(l, getFilho(a, i));
        }
        if(!a.ehFolha) l = recursive_insertion(l, getFilho(a, i));
        return l;
    }
    ListaFilmes * lfilmes = cria();
    lfilmes = recursive_insertion(lfilmes, a);
    return lfilmes;
}
*/
bool isFromGenre(Filme f, char *genero){
    if(!strstr(f.genero,genero))
        return false;
    return true;
}

void removeGenre(No a, char* genero){
    if(!a.tam) return;
    int i=0, qtd_filmes_retirados=0;
    for(i=0 ; i < a.tam ; i++){
        if (isFromGenre(a.filmes[i], genero)){
            rm(a, a.filmes[i].titulo, a.filmes[i].genero, t);
            qtd_filmes_retirados++;
        }
        removeGenre(getFilho(a, i),genero);
    }
    removeGenre(getFilho(a, i), genero);
    a.tam -= qtd_filmes_retirados;
}
