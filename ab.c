#include "ab.h"

void add(Filme f);

void rm(char* titulo, int ano);

Filme search(No no, char* titulo, int ano){
	if(!no) return NULL;
	Filme ref;
	strcpy(ref.titulo, titulo);
	ref.ano = ano;
	Filme* filmes;
    int i=0;
	for(i=0 ; i < no.tam ; i++){
        filmes = no.filmes;
        if(!ehMenor(filmes[i], ref)) break;
    }
    if(i < no.tam && comparaFilmes(&filmes[i], &ref)) return filmes[i];
    if(no.ehFolha) return NULL;
    return search(getFilho(no, i), titulo, ano);
}

void update(char* titulo, int ano, char* diretor, char* genero, int duracao);

/*
const int t = 2;

typedef struct ArvB{
  int nchaves, folha, *chave;
  struct ArvB **filho;
}TAB;

TAB *Cria(int t);
TAB *Libera(TAB *a);
void Imprime(TAB *a, int andar);
TAB *Busca(TAB* x, int ch);
TAB *Divisao(TAB *x, int i, TAB* y, int t);
TAB *Insere_Nao_Completo(TAB *x, int k, int t);
TAB *Insere(TAB *T, int k, int t);
TAB* remover(TAB* arv, int ch, int t);
TAB* retira(TAB* arv, int k, int t);
int testar(int argc, char *argv[]);
*/
