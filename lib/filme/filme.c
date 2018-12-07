#include "filme.h"

Filme filmeInvalido = {"", 0, "", "", 0};

// Diz se eh esse o filme
bool checaFilme(Filme f, char* titulo, int ano){
	return ((!strcmp(f.titulo, titulo) && f.ano == ano));
}

bool comparaFilmes(Filme a, Filme b){
    return (!strcmp(a.titulo, b.titulo) && (a.ano == b.ano));
}

bool ehMenor(Filme a, Filme b){
	if(a.ano!=b.ano) return a.ano<b.ano;
	int t = strcmp(a.titulo, b.titulo);
	if(!t || t==1) return false;
	return true;
}

void imprimeFilme(Filme f){
	printf("%s (%d) - %s - %s - %d mins.", f.titulo,
			f.ano, f.diretor, f.genero, f.duracao);
}

Filme getFilme(FILE *f){
    void nextString(FILE *f, char *saida, char separador){
        char c = fgetc(f);
        int i;
        for(i=0; !feof(f) && c!=separador; i++){
            saida[i] = c;
            c = fgetc(f);
        }
        saida[i] = '\0';
    }
    Filme novo_filme;
    char nxtStrAuxiliar[82];
    nextString(f, novo_filme.titulo, '/');
    nextString(f, nxtStrAuxiliar, '/');
    novo_filme.ano = atoi(nxtStrAuxiliar);
    nextString(f, novo_filme.diretor, '/');
    nextString(f, novo_filme.genero, '/');
    nextString(f, nxtStrAuxiliar, '\n');
    novo_filme.duracao = atoi(nxtStrAuxiliar);
    return novo_filme;
}
