#include "libFilme/abPersistencia.h"
#include "libFilme/listaFilmes.h"

No add(Filme f, int t);
No rm(No no, char* titulo, int ano, int t);
Filme search(No no, char* titulo, int ano);
void update(char* titulo, int ano, char* diretor, char* genero, int duracao);
