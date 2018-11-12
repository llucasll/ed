#include "filme.h"
#include "gestorIDs.h"

typedef struct{
	int id, idPai;
	
	bool ehFolha;
	
	int tam;
	Filme *filmes;
}No;

// NAVEGAR NA ÁRVORE
No getRaiz(void); // ALOCA FILHOS!
No getFilho(No pai, char pos); // ALOCA FILHOS!
No getPai(No filho); // ALOCA FILHOS!
void save(No n); // DESALOCA FILHOS!

// REARRANJAR A ÁRVORE
No criaNo(void); // cria um novo No em disco (tam=0), e ALOCA FILHOS! Se não existir, cria e devolve a raíz
void apagaNo(No no); // DESALOCA FILHOS!

// REORGANIZAR IRMÃOS
No* getFilhos(No no); // ALOCA 2t-1 FILHOS!, mas preenche apenas no.tam+1, e retorna
void updateFilhos(No* filhos, No pai); //salva pai.tam+1 filhos, e DESALOCA FILHOS!
