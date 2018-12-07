#include "persistencia.h"
#include "../filme/listaFilmes.h"

void add(Filme f, int t);
void rm(No no, char* titulo, int ano, int t);
Filme search(No no, char* titulo, int ano);
void update(char* titulo, int ano, char* diretor, char* genero, int duracao);
