//includes

void inicializa(int t, char *catalogo){ //g
	//while(!feof(f))
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
    int t, opt;
    printf("Entre com um fator T: ");
    scanf("%d", &t);
    system("cls||clear");
    do{
        printf("\nFuncoes:\n");
        opt = menu();
        switch(opt){
            case 0:
                printf("\nValor invalido.\nPressione qualquer tecla.");
                getch();
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
