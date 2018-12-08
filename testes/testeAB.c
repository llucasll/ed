#include <stdio.h>

#include "../lib/filme/filme.h"
#include "../lib/ab/ab.h"

#define easy false

void printaFilme(Filme val, int nivel){
	for(int i=0; i<nivel; i++)
		printf("\t");
	//if(menor)
		//printf("\e[31m");
	//else
		printf("\e[32m");
	//if(val)
		printf("%d - %s\n", val.ano, val.titulo);
	//else
		//printf("*\n");
	printf("\e[m");
}

void inspectNo(No no){
	printf("ID: %d\n", no.id);
	bool ehFolha = no.ehFolha;
	no.ehFolha = true;
	printaNo(no, 0);
	no.ehFolha = ehFolha;
}

void printaNo(No raiz, int nivel){//Printa Arvore Interno
	if(raiz.id == -1) return;
	for(int i=0; i<raiz.tam; i++){
		if(!raiz.ehFolha)
			printaNo(getFilho(raiz, i), nivel+1);
		printaFilme(raiz.filmes[i], nivel);
	}
	if(!raiz.ehFolha)
		printaNo(getFilho(raiz, raiz.tam), nivel+1);
	if(nivel)
		free(raiz.filmes);
}
void printaArvore(void){
	//printf("\ec\n");
	
	No raiz = getRaiz();
	if(raiz.tam == 0){
		printf("\nÁrvore vazia!\n");
	}
	else{
		printf("\nÁrvore:\n");
		printaNo(raiz, 0);
		free(raiz.filmes);
	}
	printf("\n");
}

Filme f;

void getTitulo(int ano){
	printf("Digite o titulo do filme:\n> ");
	scanf("%s", f.titulo);
	f.ano = ano;
}

int main(void){
	int i;
	printf("\ec\n");
	t=2;
	/*
	char* v = malloc(1);
	oin(v[4])
	oi//free(v);
	free(v+1);
	*/
	do{
		//printf("printaarvore\n");
		printaArvore();
		printf("Digite o ano do filme(negativo = remover, 0 = encerrar):\n> ");
		scanf("%d",&i);
		if(!i) break;
		
		if(easy){
			sprintf(f.titulo, "%d", i);
			f.ano = i;
		}
		else
			getTitulo(i);
		
		/*
		f.ano = i = 2000;
		strcpy(f.titulo, "Funcionou!");
		*/
		
		if(i>0)
			add(f);
		else
			rm(f.titulo, -i);
		
		//printf("Niveis: %d\n", niveis(raiz));
		//printf("Elementos: %d\n\n", contar(raiz));
	} while(i);
	//libera(&raiz);
	printf("\n");
}

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
