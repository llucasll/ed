#include "abPersistencia.h"

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

//Apenas nesse arquivo
void getFileName(int id, char* no, char* filhos);
No getNoByID(int id);
int getPaiID(int filho);
void setPaiID(int filho, int pai);

No getRaiz(void){
	return getNoByID(0);
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
	return getNoByID(id);
}
No getPai(No n){
	if(n.id == 0)
		return vazio;
	
	return getNoByID(getPaiID(n.id)); // Créditos Eduardo Canellas
}
void save(No n){
	char d[50], r[50];
	getFileName(n.id, d, r);
	
	if(n.ehFolha){
		FILE* refs = fopen(r, "w");
		if(refs)
			fclose(refs);
	}
	
	FILE* dados = fopen(d, "w");
	if(dados){
		fwrite(n.filmes, sizeof(Filme), n.tam, dados);
		fclose(dados);
	}
	else erro(1);
	free(n.filmes);
}

No* getFilhos(No no){ //aloca 2t-1 id's de filho
	No* resp = (No*) malloc(sizeof(No)*(2*t-1));
	for(int i=0; i<=no.tam; i++)
		resp[i] = getFilho(no, i);
	return resp;
}
void updateFilhos(No* filhos, No pai){ //salva pai.tam+1 filhos no modo w+, e desaloca os filhos
	char r[50];
	getFileName(pai.id, (char*)NULL, r);
	FILE* refs = fopen(r, "w");
	if(refs){
		for(int i=0; i<=pai.tam; i++){
			fwrite(&filhos[i].id, sizeof(int), 1, refs);	
			setPaiID(filhos[i].id, pai.id);
			//save(filhos[i]); // TODO salvar também?
		}
		fclose(refs);
		free(filhos);
	}
	else erro(1);
	
	No pai2 = getNoByID(pai.id); // A função que chama updateFilhos pode não ter salvo ainda/não querer salvar
	pai2.ehFolha = false;
	save(pai2);
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
	FILE* dados = fopen(d, "w");
	FILE* refs = fopen(r, "w");
	
	if(dados) fclose(dados);
	if(refs) fclose(refs);
}
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
void getFileName(int id, char* no, char* filhos){
	char s[100], aux[100];
	
	// Créditos a Eduardo Canellas
	sprintf(s, "%d", id);
	int tam = strlen(s);
	for(int i=0; i<tam-1; i++) s[i] = '~';
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
int getPaiID(int filho){
	
}
void setPaiID(int filho, int pai){
	
}
