#include "lib.h"

typedef struct{
	//chave primária composta
	char titulo[82];
	int ano;

	//outros campos
	char diretor[52];
	char genero[32];
	int duracao;
} Filme;

bool filmeCerto(Filme f, char* titulo, int ano);
int comparaFilmes(Filme *a, Filme *b);
bool menor(Filme a, Filme b); //Se a < b, ordenando primeiramente por ano - g
void printaFilme(Filme f);
Filme getFilme(FILE *f); //g

/*
#ifndef basico
	#define basico
	#include "lib.h"
	#undef basico
#endif
*/
