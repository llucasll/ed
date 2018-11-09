#include "filmes.h"

Filme getFilme(FILE *f); //g
void nextString(FILE *f, char *saida, char *separador); //l
void inicializa(int i, char *catalogo){ //g
	//while(!feof(f))
}

bool isDirectedBy(Filme f, char *diretor); //l
ListaFilmes directedsBy(char *diretor, AB *a); //l

bool isFromGenre(Filme f, char *genero); //detecta substring - l
void removeGenre(AB *a, char *genero); //l
