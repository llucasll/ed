#include "filmes.h"

bool isDirectedBy(Filme f, char *diretor); //l
ListaFilmes directedsBy(char *diretor, AB *a); //l

bool isFromGenre(Filme f, char *genero); //detecta substring - l
void removeGenre(AB *a, char *genero); //l
