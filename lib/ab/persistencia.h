#include "../filme/filme.h"

typedef struct{
	int id;
	
	bool ehFolha;
	
	int tam;
	Filme *filmes;
}No;

// REPRESENTAÇÃO DE UM NÓ QUE NÃO EXISTE
extern No vazio; // {0, true, 0, NULL}

// NAVEGAR NA ÁRVORE
No getRaiz(void); // ALOCA FILMES!
void atualizaRaiz(No n);
No getFilho(No pai, char pos); // ALOCA FILMES!
No getPai(No filho); // ALOCA FILMES!
void save(No n); // DESALOCA FILMES!
No reload(No n);

// REARRANJAR A ÁRVORE
No criaNo(void); // cria um novo No (tam=0), e ALOCA FILMES! NÃO USE PARA OBTER A RAÍZ (use a getRaiz)
void apagaNo(No no); // DESALOCA FILMES!

// REORGANIZAR IRMÃOS
No* getFilhos(No no); // ALOCA 2t-1 FILMES!, mas preenche apenas no.tam+1, e retorna
void updateFilhos(No* filhos, No pai); //salva pai.tam+1 filhos, e DESALOCA FILMES!
