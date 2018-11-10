#include "gestorIDs.h"

#define pri 1

FILE* abrir(char* nome){
	if(!dirExiste("data"))
		system("mkdir data");
	
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

#define nome "data/IDs.bin"

void liberarID(unsigned int id){ //adiciona o ID fora de uso no arquivo ids.bin
	FILE* f = abrir(nome);
	
	unsigned int t = fileSize(f)/sizeof(unsigned int);
		
	if(t == 1){
		unsigned int i;
		fread(&i, sizeof(unsigned int), 1, f);
		if(i==id+1){
			rewind(f);
			fwrite(&id, sizeof(unsigned int), 1, f);
		}
		else{
			rewind(f);
			fwrite(&id, sizeof(unsigned int), 1, f);
			fwrite(&i, sizeof(unsigned int), 1, f);
		}
	}
	else{
		unsigned int vet[t+1];
		fread(vet, sizeof(unsigned int), t, f);
		bool existe=false;
		for(int i=0; i<t; i++)
			if(vet[i] == id)
				existe = true;
		//for(int i=0; i<=t; i++)
		//	oin(vet[i])
		if(vet[t-1]<=id)
			existe = true; //nesse caso tbm n é para add
		
		if(!existe){
			vet[t] = vet[t-1];
			vet[t-1] = id;
			//for(int i=0; i<=t; i++)
			//	oin(vet[i])
			rewind(f);
			fwrite(vet, sizeof(unsigned int), t+1, f);
		}
		else printf("A ID não foi liberada, pois já estava livre!\n");
	}
	
	fclose(f);
}

unsigned int getID(void){ //reserva um ID.
	FILE* f = abrir(nome);
	
	unsigned int t = fileSize(f);

	unsigned int id;
	if(t == 0){
		//printf("\nArquivo vazio\n");
		id = pri+1;
		fwrite(&id, sizeof(unsigned int), 1, f);
		id = pri;
	}
	else if(t == sizeof(unsigned int)){
		//printf("\nArquivo com um elemento\n");
		fread(&id, sizeof(unsigned int), 1, f);
		id++;
		rewind(f);
		fwrite(&id, sizeof(unsigned int), 1, f);
		id--;
	}
	else{
		unsigned int vet[t];
		fread(vet, t, 1, f);// t = tamanho * sizeof..
		fclose(f);
		//system("rm "nome);//concatenação automática de strings constantes
		id = vet[0];
		f = fopen(nome, "w+");
		fwrite(vet+1, 1, t-sizeof(unsigned int), f);// t = tamanho * sizeof..
	}
	
	fclose(f);
	return id;
}

