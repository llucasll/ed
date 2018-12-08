#include "lib.h"

int getInt(char* s){
	printf("%s", s);
	int x;
	scanf("%d", &x);
	return x;
}

char* getString(char* s, int tamMax){
	printf("%s", s);
	char *x = (char*) malloc(sizeof(char)*tamMax);
	scanf("%s", x);
	return x;
}

int fileSize2(FILE* f){
	int tmp = ftell(f);
	fseek(f, SEEK_END, 0);
	int t = ftell(f);
	fseek(f, SEEK_SET, tmp);
	return t;
}

int fileSize(FILE* f){
	if(!f) return 0;
	int tmp = ftell(f);
	rewind(f);

	int nada;
	int i;
	for(i=0; !feof(f); i++)
		fread(&nada, 1, 1, f);
	i--;

	fseek(f, SEEK_SET, tmp);
	return i;
}
/*
bool dirExiste(char* nome){
	#include <dirent.h>
	#include <errno.h>

	DIR* dir = opendir(nome);
	if (dir){
		// Directory exists.
		closedir(dir);
		return true;
	}
	else if (ENOENT == errno){
		// Directory does not exist.
		closedir(dir);
		return false;
	}
	else{
		// opendir() failed for some other reason.
		exit(10);
	}
}
*/
FILE* abrir(char* nome){
	//if(!dirExiste("data"))
	//	system("mkdir data");

	FILE* f = fopen(nome, "r+"); // modo que preserva o conteúdo
	if(!f) f = fopen(nome, "w+"); // modo que cria novo arquivo, se não existe (ou apaga o conteúdo, se existir)

	if(!f){
		printf("Erro ao abrir o arquivo: %s", nome);
		exit(1);
	}

	/*
	#include <errno.h>
	printf("%d", errno);
	*/

	return f;
}

int getIntFromFile(char* file){
	FILE* f = fopen(file, "r");
	if(!f)
		return -1;
	else{
		int i;
		if(!fscanf(f, "%d", &i))
			return -1;
		fclose(f);
		return i;
	}
}
void putIntToFile(char* file, int i){
	FILE* f = fopen(file, "w");
	if(!f) erro(1);
	else{
		fprintf(f, "%d", i);
		fclose(f);
	}
}

void apagarArquivo(char* file){
	FILE* f = fopen(file, "w");
	if(f) fclose(f);
}
