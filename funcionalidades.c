#include "filmes.h"

#include <string.h>

bool isDirectedBy(Filme f, char *diretor){
    if(!strcmp(f.diretor,diretor))
        return true;
    return false;
}

ListaFilmes directedsBy(char *diretor, AB *a); //l

bool isFromGenre(Filme f, char *genero){
    if(!strstr(f.genero,genero))
        return false;
    return true;
}

void removeGenre(No *a, char *genero){
	for(int i=0; i<a.tam; i++){
		// TODO
	}
}
