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

Filme getFilme(FILE *f){
    void nextString(FILE *f, char *saida, char separador){
        char str[200], c;
        c=fgetc(f);
        if (c==EOF || c=='\n'){
            strcpy(saida,"");
            return;
        }
        sprintf(saida, "%c",c);

        while(c!= EOF){
            c=fgetc(f);
            if (c==separador) break;
            sprintf(str, "%c", c);
            strcat(saida, str);
        }
    }
    Filme novo_filme;
    char nxtStrAuxiliar[81];
    nextString(f, novo_filme.titulo, '/');
    nextString(f, nxtStrAuxiliar, '/');
    novo_filme.ano = atoi(nxtStrAuxiliar);
    nextString(f, novo_filme.diretor, '/');
    nextString(f, novo_filme.genero, '/');
    nextString(f, nxtStrAuxiliar, '\n');
    novo_filme.duracao = atoi(nxtStrAuxiliar);
    return novo_filme;
}
