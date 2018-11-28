#include "filme.h"

bool checaFilme(Filme* f, char* titulo, int ano){
	return ((!strcmp(f->titulo, titulo) && f.ano == ano);
}


bool comparaFilmes(Filme *a, Filme *b){
    return (!strcmp(a->titulo, b->titulo) && (a->ano == b->ano));
}

/*
bool comparaFilmes(Filme *a, Filme *b){
	return !( strcmp(a->titulo, b->titulo) || (a.ano != b.ano) ||
			strcmp(a->diretor, b->diretor) ||
			strcmp(a->genero, b->genero) || (a.duracao != b.duracao) );
}*/

bool ehMenor(Filme* a, Filme* b){
	if(a.ano!=b.ano) return a.ano<b.ano;
	int t = strcmp(a->titulo, b->titulo);
	if(!t || t==1) return false;
	return true;
}

void imprimeFilme(Filme* f){
	printf("%s (%d) - %s - %s - %d mins.", f->titulo,
			f.ano, f->diretor, f->genero, f.duracao);
}

void nextString(FILE *f, char *saida, char *separador); //TODO (l)
Filme getFilme(FILE *f); //TODO (g)

void erro(int e){
	switch(e){
		case 0:
			return;
		case 1:
			printf("\nErro de abertura de arquivo!\n\n");
			break;
		default:
			printf("\nErro %d desconhecido!\n\n", e);
			break;
	}
	exit(e);
}
