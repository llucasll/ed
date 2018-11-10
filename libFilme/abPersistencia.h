#include "filme.h"
#include "gestorIDs.h"

typedef struct{
	int id;
	
	bool ehFolha;
	
	int tam;
	Filme *filmes;
}No;

/*
void init(int t){
	a.fp = fopen("data/raiz.bin", "r+");
	a.t = t;
	
	if(!a.fp)
		exit(1); //TODO é isso mesmo?
}
*/

No getRaiz(void);
No getFilho(No n, char pos);
No getPai(No n);
void save(No n);

No getNoByID(int id);
int* getFilhos(No* no); //aloca 2t-1 id's de filho
void updateFilhos(int* filhos, No pai); //salva pai.tam+1 filhos, e desaloca os filhos
void getFileName(int id, char* no, char* filhos);

/*
bool ehFolha(No n);
No getPai(No n);
char tamanhoNo(No n);
Filme getFilme(char pos);
No getFilho(No n, char pos);
*/
