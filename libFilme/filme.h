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

bool checaFilme(Filme f, char* titulo, int ano);
bool comparaFilmes(Filme *a, Filme *b); //true se são iguais
bool ehMenor(Filme a, Filme b); //Se a < b, ordenando primeiramente por ano - g
void imprimeFilme(Filme f);
Filme getFilme(FILE *f);

int t;

/*
#ifndef basico
	#define basico
	#include "lib.h"
	#undef basico
#endif
*/

/*
	if(a.ano < b.ano)
		return true;
	else if(a.ano == ano)
		return strcmp(a.titulo, b.titulo) < 0;
	else return false;
*/

