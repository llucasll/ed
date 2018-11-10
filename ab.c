#include "ab.h"

void add(Filme f);
void rm(char* titulo, int ano);
Filme search(char* titulo, int ano){
	Filme f;
	int i=0;
	do{
		fread(a.fp, sizeof(Filme), 1, &f);
		i++;
	} while(!filmeCerto(f, titulo, ano) && i<(a.t*2-1));
	
	if(!filmeCerto(f, titulo, ano)){
		
	}
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
