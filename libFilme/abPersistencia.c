#include "abPersistencia.h"

/*
void init(int t){
	a.fp = fopen("data/raiz.bin", "r+");
	a.t = t;
	
	if(!a.fp)
		exit(1); //TODO é isso mesmo?
}
*/

//Apenas nesse arquivo
void getFileName(int id, char* no, char* filhos);
No getNoByID(int id);


No getRaiz(void);
No getFilho(No n, char pos);
No getPai(No n);
void save(No n);

No getNoByID(int id);
int* getFilhos(No* no); //aloca 2t-1 id's de filho
void updateFilhos(int* filhos, No pai){ //salva pai.tam+1 filhos no modo w+, e desaloca os filhos
	char arq[50];
	FILE* f = fopen(getFileName(pai.id, NULL, arq), "w+");
	fwrite(filhos, pai.tam+1, sizeof(int), f);
	fclose(f);
	free(filhos);
}

void getFileName(int id, char* no, char* filhos){
	//TODO
}
