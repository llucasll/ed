#include "../libFilme/lib.h"
#include "../libFilme/gestorIDs.h"

int main(void){
	int op;
	printf("\nComeçando:\n");
	while(op = getInt("\nDigite 1 para novo ID, 2 para liberar uma ID, e 0 para finalizar: ")){
		if(op == 1)
			printf("Número obtido: %d\n", getID());
		else{
			int n;
			liberarID(n = getInt("Qual o ID que você quer liberar? "));
			printf("A ID %d foi registrada e está disponível novamente.\n", n);
		}
	}
	if(op==0) printf("Encerrando...\n");
	else oin(op)
}
