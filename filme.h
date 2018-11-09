typedef struct{
	//chave primária composta
	char titulo[82];
	int ano;

	//outros campos
	char diretor[52];
	char genero[32];
	int duracao;
} Filme;

bool menor(Filme a, Filme b); //Se a < b, ordenando primeiramente por ano - g
void printaFilme(Filme f);

#ifndef basico
	#define basico
	#include "basico.h"
	#undef basico
#endif
