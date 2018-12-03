#include <stdlib.h>
#include <stdio.h>

#include "funcionalidades.h"

void inicializa(char *catalogo){
    FILE* fp = fopen(catalogo, "r");
    Filme f = getFilme(fp);
    while(f.ano){
        atualizaRaiz(add(f, t));
        f = getFilme(fp);
    }
}

int main(){
    int menu(){
        printf("\t1 - Busca filme\n");
        printf("\t2 - Altera filme\n");
        printf("\t3 - Lista filmes por diretor\n");
        printf("\t4 - Retire filmes por gênero\n");
        printf("\nEscolha uma funcao: ");
        int n;
        scanf("%d", &n);
        if((n<1||n>4)&&(n!=-1))
            return 0;
        return n;
    }
    int opt;
    char* catalogo;

    printf("Nome do arquivo: ");
    scanf("%s", catalogo);
    printf("Fator T: ");
    scanf("%d", &t);
    //catalogo = (char*) malloc(sizeof(char) * 20);
    //sprintf(catalogo, "filmes.txt");
    //t = 2;

    inicializa(catalogo);
    system("cls||clear");
    do{
        printf("\nFuncoes:\n");
        opt = menu();
        switch(opt){
            case 0:
                printf("\nValor invalido.\nPressione qualquer tecla.");
                getc(stdin);
                system("cls||clear");
                break;
            case 1: //Busca filme
                printf("Titulo: ");
                char titulo[82];
                fgets(titulo, 82, stdin);
                printf("Ano: ");
                int ano;
                scanf("%d", &ano);
                Filme f = search(getRaiz(), titulo, ano);
                if(!f.ano) printf("Filme nao encontrado.");
                else imprimeFilme(f);
                break;
            case 2: //Altera filme
                printf("Titulo: ");
                char titulo[82];
                fgets(titulo, 82, stdin);
                printf("Ano: ");
                int ano;
                scanf("%d", &ano);
                char diretor[52];
                fgets(diretor, 52, stdin);
                char genero[32];
                fgets(genero, 32, stdin);
                int duracao;
                scanf("%d", duracao);
                update(titulo, ano, diretor, genero, duracao);
                break;
            case 3: // Lista por diretor
                printf("Diretor: ");
                char diretor[52];
                fgets(diretor, 52, stdin);
                imprime(directedsBy(diretor, getRaiz()));
                break;
            case 4: // Retira por gênero
                printf("Genero: ");
                char genero[32];
                fgets(genero, 32, stdin);
                removeGenre(getRaiz(), genero);
                break;
        }
    }while(opt!=-1);
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
