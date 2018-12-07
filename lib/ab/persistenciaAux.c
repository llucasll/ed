#include "persistenciaAux.h"

#include "persistencia.h"

Filme* alocaFilmes(void){
	return (Filme*) malloc(sizeof(Filme) * (2*t-1));
}

No getNoByID(int id){
	char d[50], r[50];
	getFileName(id, d, r);
	FILE* dados = fopen(d, "r");
	FILE* refs = fopen(r, "r");
	
	No n;
	if(!dados){
		if(id == 0){
			No raiz = vazio;
			raiz.filmes = (Filme*) malloc(sizeof(Filme) * (2*t-1));
			return raiz;
		}
		else return vazio;
	}
	else{
		n.id = id;
		n.ehFolha = refs? !(fileSize(refs)/sizeof(int)) : true;
		n.tam = fileSize(dados)/sizeof(Filme);
		n.filmes = (Filme*) malloc(sizeof(Filme) * (2*t-1));
		fread(n.filmes, sizeof(Filme), n.tam, dados);
	}
	
	if(dados) fclose(dados);
	if(refs) fclose(refs);
	return n;
}

int getPaiID(int filho){
	
}
void setPaiID(int filho, int pai){
	
}

void getFileName(int id, char* no, char* filhos){
	char s[100], aux[100];
	
	// Créditos a Eduardo Canellas
	sprintf(s, "%d", id);
	int tam = strlen(s);
	for(int i=0; i<tam-1; i++) s[i] = '_';
	sprintf(s+tam-1, "%d", id);
	
	if(no){
		sprintf(aux, "data/%s.node", s);
		strcpy(no,aux);
	}
	if(filhos){
		sprintf(aux, "data/%s.refs", s);
		strcpy(filhos,aux);
	}
}
