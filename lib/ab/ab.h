#include "persistencia.h"
#include "../filme/listaFilmes.h"

void add(Filme f);
void rm(char* titulo, int ano);
Filme search(char* titulo, int ano);
void update(char* titulo, int ano, char* diretor, char* genero, int duracao);
