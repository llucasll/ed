#include "filme.h"

typedef struct{
	FILE *fp;
	int t;
}AB;

AB a;

void add(Filme f);
void rm(char* titulo, int ano);
Filme search(char* titulo, int ano);
void update(char* titulo, int ano, char* diretor, char* genero, int duracao);
