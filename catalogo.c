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

    //TODO
    //printf("Nome do arquivo: ");
    //scanf("%s", catalogo);
    //printf("Fator T: ");
    //scanf("%d", &t);
    catalogo = (char*) malloc(sizeof(char) * 20);
    sprintf(catalogo, "filmes.txt");
    t = 2;

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
            case 1:
                printf("Dummy 1");
                break;
            case 2:
                printf("Dummy 2");
                break;
            case 3:
                printf("Dummy 3");
                break;
            case 4:
                printf("Dummy 4");
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
