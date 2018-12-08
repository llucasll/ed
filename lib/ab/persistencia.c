#include "persistencia.h"

#include "persistenciaAux.h"

/*
void init(int t){
	FILE* f = fopen("data/meta.dat", "w");
	
	if(!f)
		erro(1); //TODO é isso mesmo?
	else{
		fwrite(&t, sizeof(int), 1, f);
		fclose(f);
	}
}
*/

/*
n.id = id;
n.idPai = id;
n.ehFolha = true;
n.tam = 0;
n.filmes = (Filme*) NULL;
*/

No vazio = {0, true, 0, NULL};

No getRaiz(void){
	return getNoByID(getRaizID());
}
void atualizaRaiz(No no){
	putIntToFile("data/raiz.id", no.id);
}

No getFilho(No n, char pos){
	if(n.ehFolha)
		return vazio;
	
	char r[50];
	getFileName(n.id, (char*)NULL, r);
	FILE* refs = fopen(r, "r");
	
	fseek(refs, pos*sizeof(int), SEEK_SET);
	int id;
	fread(&id, sizeof(int), 1, refs);
	
	if(id == -1)
		return vazio;
	else
		return getNoByID(id);
}
No getPai(No n){
	if(n.id == getRaizID())
		return vazio;
	else
		return getNoByID(getPaiID(n.id)); // Créditos Eduardo Canellas
}
void save(No n){
	char d[50], r[50];
	getFileName(n.id, d, r);
	
	/*	
	printf("save\n");
	oin(n.id)
	
	inspectNo(n);
	*/
	/*
	printf(".%s.\n", n.filmes[0].titulo);
	inspectNo(n);
	printf(".%s.\n", n.filmes[0].titulo);
	*/
	
	if(n.ehFolha){
		FILE* refs = fopen(r, "w");
		if(refs)
			fclose(refs);
	}
	
	//printf(".%s.\n", n.filmes[0].titulo);
	FILE* dados = fopen(d, "w");
	//oin(n.tam*sizeof(Filme));
	//oin(sizeof(Filme));
	//printf(".%s.\n", n.filmes[0].titulo);
	if(dados){
		fwrite(n.filmes, sizeof(Filme), n.tam, dados);
		fclose(dados);
	}
	else erro(1);
	free(n.filmes);
}
No reload(No n){
	return getNoByID(n.id);
}

No* getFilhos(No no){ //aloca 2t-1 id's de filho
	No* resp = (No*) malloc(sizeof(No)*(2*t-1));
	if(no.tam)
		for(int i=0; i<=no.tam; i++)
			resp[i] = getFilho(no, i);
	return resp;
}
void updateFilhos(No* filhos, No pai){ //salva pai.tam+1 filhos no modo w+, e desaloca os filhos
	if(pai.ehFolha){
		printf("Não é possível atualizar os filhos para a folha de ID %d\n", pai.id);
		return;
	}
	char r[50];
	getFileName(pai.id, (char*)NULL, r);
	FILE* refs = fopen(r, "w");
	if(refs){
		for(int i=0; i<=pai.tam; i++){
			fwrite(&filhos[i].id, sizeof(int), 1, refs);	
			//setPaiID(filhos[i].id, pai.id);
			//if(filho[i].id != -1)
			//save(filhos[i]); // TODO salvar também?
		}
		fclose(refs);
		free(filhos);
	}
	else erro(1);
	
	//if(pai.id == 1) oin(23)
	//No pai2 = getNoByID(pai.id); // A função que chama updateFilhos pode não ter salvo ainda/não querer salvar
	//pai.ehFolha = false;
	//save(pai);
	//free(pai.filmes);
}

No criaNo(void){ // cria um novo No (tam=0), e ALOCA FILMES! NÃO USE PARA OBTER A RAÍZ (use a getRaiz)
	No n = vazio;
	n.id = getID();
	n.filmes = (Filme*) malloc(sizeof(Filme) * (2*t-1));
	return n;
}
// Créditos a Eduardo Canellas
void apagaNo(No no){ // DESALOCA FILMES!
	char d[50], r[50];
	getFileName(no.id, d, r);
	apagarArquivo(d);
	apagarArquivo(r);
}

/*
ids.bin
raiz.id
0.node
0.refs
1.node
1.refs
*/

