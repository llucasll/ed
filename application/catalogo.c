#include <stdlib.h>
#include <stdio.h>

#include "funcionalidades.h"

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

void inicializa(char *catalogo){
    FILE* fp = fopen(catalogo, "r");
    if(!fp){
        printf("Arquivo nao pode ser aberto.\n");
        exit(1);
    }
    Filme f = getFilme(fp);
    while(f.ano){
        printaArvore();
        //imprimeFilme(f);
        add(f);
        //printf("\nAdicionado\n");
        f = getFilme(fp);
    }
    fclose(fp);
}

void buscaFilme(){
    printf("Titulo: ");
    char titulo[82];
    fgets(titulo, 82, stdin);
    printf("\nAno: ");
    int ano;
    scanf("%d", &ano);
    //printf("%s (%d)", titulo, ano);
    Filme f = search(titulo, ano);
    if(!f.ano) printf("Filme nao encontrado.");
    else imprimeFilme(f);
}

void alteraFilme(){
    printf("Titulo: ");
    char titulo[82];
    fgets(titulo, 82, stdin);
    printf("Ano: ");
    int ano;
    scanf("%d", &ano);
    printf("Diretor: ");
    char diretor[52];
    fgets(diretor, 52, stdin);
    printf("Genero: ");
    char genero[32];
    fgets(genero, 32, stdin);
    printf("Duracao: ");
    int duracao;
    scanf("%d", &duracao);
    //printf("%s - %d - %s - %s - %d", titulo, ano, diretor, genero, duracao);
    update(titulo, ano, diretor, genero, duracao);
}

void listaDiretor(){
    printf("Diretor: ");
    char diretor[52];
    fgets(diretor, 52, stdin);
    //printf("Imprime do diretor \"%s\"", diretor);
    imprime(directedsBy(diretor, getRaiz()));
}

void retiraGenero(){
    printf("Genero: ");
    char genero[32];
    fgets(genero, 32, stdin);
    //printf("Remove genero \"%s\"", genero);
    removeGenre(getRaiz(), genero);
}

int main(){
    int menu(){
        printf("\t0 - Encerrar\n");
        printf("\t1 - Busca filme\n");
        printf("\t2 - Altera filme\n");
        printf("\t3 - Lista filmes por diretor\n");
        printf("\t4 - Retire filmes por gênero\n");
        printf("\nEscolha uma funcao: ");
        int n;
        scanf("%d", &n);
        if((n<1||n>4)&&(n!=-1)) return 0;
        return n;
    }
    int opt;
    char catalogo[100];

    printf("Nome do arquivo: ");
    scanf("%s", &catalogo);
    printf("Fator T: ");
    scanf("%d", &t);
    //catalogo = (char*) malloc(sizeof(char) * 20);
    //sprintf(catalogo, "filmes.txt");
    //t = 2;
    
    inicializa(catalogo);
    system("cls||clear");
    do{
        printaArvore();
        printf("\nFuncoes:\n");
        opt = menu();
        switch(opt){
            case 1:
                buscaFilme();
                break;
            case 2:
                alteraFilme();
                break;
            case 3:
                listaDiretor();
                break;
            case 4:
                retiraGenero();
                break;
            default:
                printf("\nValor invalido.\nPressione qualquer tecla.");
                getc(stdin);
                system("cls||clear");
                break;
        }
    }while(opt);
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
