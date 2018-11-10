#include "filme.h"

/*
typedef struct{
	//chave primária composta
	char titulo[82];
	int ano;

	//outros campos
	char diretor[52];
	char genero[32];
	int duracao;
} Filme;
*/

bool filmeCerto(Filme f, char* titulo, int ano);

// 0-iguais, 1-diferentes
int comparaFilmes(Filme *a, Filme *b){
    if((strcmp(a->titulo, b->titulo)==0) &&
        a->ano == b->ano)
        return 0;
    return 1;
}

bool menor(Filme a, Filme b); //Se a < b, ordenando primeiramente por ano - g

void printaFilme(Filme f);

void nextString(FILE *f, char *saida, char *separador); //l
Filme getFilme(FILE *f); //g
